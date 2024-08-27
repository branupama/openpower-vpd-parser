#include "vpd_tool.hpp"

#include "constants.hpp"
#include "types.hpp"
#include "utils.hpp"

#include <iostream>

namespace vpd
{
int VpdTool::readKeyword(const std::string& i_fruPath,
                         const std::string& i_recordName,
                         const std::string& i_keywordName,
                         const bool i_onHardware,
                         const std::string& i_fileToSave)
{
    int l_rc = -1;
    try
    {
        types::DbusVariantType l_keywordValue;
        if (i_onHardware)
        {
            // TODO: uncomment when implementation of the API goes in
            /*l_keywordValue = utils::readKeywordFromHardware(
                constants::vpdManagerService,
               constants::vpdManagerObjectPath,
                constants::vpdManagerIntfName, i_fruPath,
                make_tuple(i_recordName, i_keywordName));*/
        }
        else
        {
            std::string l_inventoryObjectPath(constants::baseInventoryPath +
                                              i_fruPath);

            l_keywordValue = utils::readDbusProperty(
                constants::inventoryManagerService, l_inventoryObjectPath,
                constants::ipzVpdIntf + i_recordName, i_keywordName);
        }

        if (const auto l_value =
                std::get_if<types::BinaryVector>(&l_keywordValue))
        {
            const std::string& l_keywordStrValue =
                utils::getPrintableValue(*l_value);

            if (i_fileToSave.empty())
            {
                nlohmann::json l_resultInJson = nlohmann::json::object({});
                nlohmann::json l_keywordValInJson = nlohmann::json::object({});

                l_keywordValInJson.emplace(i_keywordName, l_keywordStrValue);
                l_resultInJson.emplace(i_fruPath, l_keywordValInJson);

                utils::printJson(l_resultInJson);
            }
            else
            {
                // TODO: Write result to a given file path.
            }
            l_rc = 0;
        }
        else
        {
            // TODO: Enable logging when verbose is enabled.
            // std::cout << "Invalid data type received." << std::endl;
        }
    }
    catch (const std::exception& l_ex)
    {
        // TODO: Enable logging when verbose is enabled.
        /*std::cerr << "Read keyword's value for FRU path: " << i_fruPath
                  << ", Record: " << i_recordName
                  << ", Keyword: " << i_keywordName
                  << ", failed with exception: " << l_ex.what() << std::endl;*/
    }
    return l_rc;
}
} // namespace vpd
