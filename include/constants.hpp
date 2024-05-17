#pragma once

#include "types.hpp"

#include <cstdint>
#include <iostream>
namespace vpd
{
namespace constants
{
static constexpr uint8_t IPZ_DATA_START = 11;
static constexpr uint8_t IPZ_DATA_START_TAG = 0x84;
static constexpr uint8_t IPZ_RECORD_END_TAG = 0x78;

static constexpr uint8_t KW_VPD_DATA_START = 0;
static constexpr uint8_t KW_VPD_START_TAG = 0x82;
static constexpr uint8_t KW_VPD_PAIR_START_TAG = 0x84;
static constexpr uint8_t ALT_KW_VPD_PAIR_START_TAG = 0x90;
static constexpr uint8_t KW_VPD_END_TAG = 0x78;
static constexpr uint8_t KW_VAL_PAIR_END_TAG = 0x79;

static constexpr auto DDIMM_11S_BARCODE_START = 416;
static constexpr auto DDIMM_11S_BARCODE_START_TAG = "11S";
static constexpr auto DDIMM_11S_FORMAT_LEN = 3;
static constexpr auto DDIMM_11S_BARCODE_LEN = 26;
static constexpr auto PART_NUM_LEN = 7;
static constexpr auto SERIAL_NUM_LEN = 12;
static constexpr auto CCIN_LEN = 4;
static constexpr auto CONVERT_MB_TO_KB = 1024;
static constexpr auto CONVERT_GB_TO_KB = 1024 * 1024;

static constexpr auto SPD_BYTE_2 = 2;
static constexpr auto SPD_BYTE_3 = 3;
static constexpr auto SPD_BYTE_4 = 4;
static constexpr auto SPD_BYTE_6 = 6;
static constexpr auto SPD_BYTE_12 = 12;
static constexpr auto SPD_BYTE_13 = 13;
static constexpr auto SPD_BYTE_18 = 18;
static constexpr auto SPD_BYTE_234 = 234;
static constexpr auto SPD_BYTE_235 = 235;
static constexpr auto SPD_BYTE_BIT_0_3_MASK = 0x0F;
static constexpr auto SPD_BYTE_MASK = 0xFF;
static constexpr auto SPD_MODULE_TYPE_DDIMM = 0x0A;
static constexpr auto SPD_DRAM_TYPE_DDR5 = 0x12;
static constexpr auto SPD_DRAM_TYPE_DDR4 = 0x0C;

static constexpr auto LAST_KW = "PF";
static constexpr auto POUND_KW = '#';
static constexpr auto MB_YEAR_END = 4;
static constexpr auto MB_MONTH_END = 7;
static constexpr auto MB_DAY_END = 10;
static constexpr auto MB_HOUR_END = 13;
static constexpr auto MB_MIN_END = 16;
static constexpr auto MB_RESULT_LEN = 19;
static constexpr auto MB_LEN_BYTES = 8;
static constexpr auto UUID_LEN_BYTES = 16;
static constexpr auto UUID_TIME_LOW_END = 8;
static constexpr auto UUID_TIME_MID_END = 13;
static constexpr auto UUID_TIME_HIGH_END = 18;
static constexpr auto UUID_CLK_SEQ_END = 23;
static constexpr auto MAC_ADDRESS_LEN_BYTES = 6;
static constexpr auto ONE_BYTE = 1;
static constexpr auto TWO_BYTES = 2;

static constexpr auto VALUE_0 = 0;
static constexpr auto VALUE_1 = 1;
static constexpr auto VALUE_2 = 2;
static constexpr auto VALUE_3 = 3;
static constexpr auto VALUE_4 = 4;
static constexpr auto VALUE_5 = 5;
static constexpr auto VALUE_6 = 6;
static constexpr auto VALUE_7 = 7;
static constexpr auto VALUE_8 = 8;

static constexpr auto MASK_BYTE_BITS_01 = 0x03;
static constexpr auto MASK_BYTE_BITS_345 = 0x38;
static constexpr auto MASK_BYTE_BITS_012 = 0x07;
static constexpr auto MASK_BYTE_BITS_567 = 0xE0;
static constexpr auto MASK_BYTE_BITS_01234 = 0x1F;

static constexpr auto SHIFT_BITS_0 = 0;
static constexpr auto SHIFT_BITS_3 = 3;
static constexpr auto SHIFT_BITS_5 = 5;

constexpr auto pimPath = "/xyz/openbmc_project/inventory";
constexpr auto pimIntf = "xyz.openbmc_project.Inventory.Manager";
constexpr auto ipzVpdInf = "com.ibm.ipzvpd.";
constexpr auto kwdVpdInf = "com.ibm.ipzvpd.VINI";
constexpr auto kwdCCIN = "CC";

static constexpr auto BD_YEAR_END = 4;
static constexpr auto BD_MONTH_END = 7;
static constexpr auto BD_DAY_END = 10;
static constexpr auto BD_HOUR_END = 13;

// To be explicitly used for string comparision.
static constexpr auto STR_CMP_SUCCESS = 0;

/** Map holds the IBM system IPZ VPD keywords info which can be
 * restored at standby and also can be used to reset keywords to its
 * defaults at manufacturing.
 * {Record:{Keyword, Default value, Is PEL required on restore failure,
 * Is MFG reset required, Backup record name, Backup keyword name }}
 */
static const types::IBMIpzBackupMap IBMSystemIpzBackupMap{
    {"VSYS",
     {types::IpzKeywordInfo("BR", {0x20, 0x20}, true, true, "VSBK", "BR"),
      types::IpzKeywordInfo("TM",
                            {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20},
                            true, true, "VSBK", "TM"),
      types::IpzKeywordInfo("SE", {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20},
                            true, true, "VSBK", "SE"),
      types::IpzKeywordInfo("SU", {0x20, 0x20, 0x20, 0x20, 0x20, 0x20}, true,
                            true, "VSBK", "SU"),
      types::IpzKeywordInfo("RB", {0x20, 0x20, 0x20, 0x20}, true, true, "VSBK",
                            "RB"),
      types::IpzKeywordInfo("WN",
                            {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
                             0x20, 0x20, 0x20, 0x20},
                            true, true, "VSBK", "WN"),
      types::IpzKeywordInfo("RG", {0x20, 0x20, 0x20, 0x20}, true, true, "VSBK",
                            "RG"),
      types::IpzKeywordInfo("FV",
                            {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
                             0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
                             0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
                             0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20},
                            false, true, "VSBK", "FV")}},
    {"VCEN",
     {types::IpzKeywordInfo("FC",
                            {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20},
                            true, false, "VSBK", "FC"),
      types::IpzKeywordInfo("SE", {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20},
                            true, true, "VSBK", "ES")}},
    {"LXR0",
     {types::IpzKeywordInfo("LX",
                            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
                            true, false, "VSBK", "LX")}},
    {"UTIL",
     {types::IpzKeywordInfo("D0", {0x00}, true, true, "VSBK", "D0"),
      types::IpzKeywordInfo("D1", {0x00}, false, true, "VSBK", "D1"),
      types::IpzKeywordInfo("F0",
                            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
                            false, true, "VSBK", "F0"),
      types::IpzKeywordInfo("F5",
                            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
                            false, true, "VSBK", "F5"),
      types::IpzKeywordInfo("F6",
                            {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
                            false, true, "VSBK", "F6")}}};

// Holds the different system specific VPD backup information map.
static const types::BackupMap VpdBackupMap{{"IBMSystemBackupMap", IBMSystemIpzBackupMap}};
} // namespace constants
} // namespace vpd
