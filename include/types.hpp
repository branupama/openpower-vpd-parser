#pragma once

#include <sdbusplus/asio/property.hpp>
#include <sdbusplus/server.hpp>
#include <unordered_map>

namespace vpd
{
namespace types
{
using BinaryVector = std::vector<uint8_t>;

// This covers mostly all the data type supported over Dbus for a property.
// clang-format off
using DbusVariantType = std::variant<
    std::vector<std::tuple<std::string, std::string, std::string>>,
    std::vector<std::string>,
    std::vector<double>,
    std::string,
    int64_t,
    uint64_t,
    double,
    int32_t,
    uint32_t,
    int16_t,
    uint16_t,
    uint8_t,
    bool,
    BinaryVector,
    std::vector<uint32_t>,
    std::vector<uint16_t>,
    sdbusplus::message::object_path,
    std::tuple<uint64_t, std::vector<std::tuple<std::string, std::string, double, uint64_t>>>,
    std::vector<std::tuple<std::string, std::string>>,
    std::vector<std::tuple<uint32_t, std::vector<uint32_t>>>,
    std::vector<std::tuple<uint32_t, size_t>>,
    std::vector<std::tuple<sdbusplus::message::object_path, std::string,
                           std::string, std::string>>
 >;

using MapperGetObject =
    std::vector<std::pair<std::string, std::vector<std::string>>>;

/* A type for holding the innermost map of property::value.*/
using IPZKwdValueMap = std::unordered_map<std::string, std::string>;
/*IPZ VPD Map of format <Record name, <keyword, value>>*/
using IPZVpdMap = std::unordered_map<std::string, IPZKwdValueMap>;

/*Value types supported by Keyword VPD*/
using KWdVPDValueType = std::variant<BinaryVector,std::string, size_t>;
/* This hold map of parsed data of keyword VPD type*/
using KeywordVpdMap = std::unordered_map<std::string, KWdVPDValueType>;

/**
 * Type to hold keyword::value map of a VPD.
 * Variant can be extended to support additional type.
*/
using VPDKWdValueMap = std::variant<IPZKwdValueMap, KeywordVpdMap>;

/* Map<Property, Value>*/
using PropertyMap = std::map<std::string, DbusVariantType>;
/* Map<Interface<Property, Value>>*/
using InterfaceMap = std::map<std::string, PropertyMap>;
using ObjectMap = std::map<sdbusplus::message::object_path, InterfaceMap>;

using KwSize = uint8_t;
using RecordId = uint8_t;
using RecordSize = uint16_t;
using RecordType = uint16_t;
using RecordOffset = uint16_t;
using RecordLength = uint16_t;
using ECCOffset = uint16_t;
using ECCLength = uint16_t;
using PoundKwSize = uint16_t;

using RecordOffsetList = std::vector<uint32_t>;

using VPDMapVariant = std::variant<IPZVpdMap, KeywordVpdMap>;

using HWVerList = std::vector<std::pair<std::string, std::string>>;
/**
 * Map of <systemIM, pair<Default version, vector<HW version, JSON suffix>>>
*/
using SystemTypeMap =
    std::unordered_map<std::string, std::pair<std::string, HWVerList>>;

} // namespace types
} // namespace vpd