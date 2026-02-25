# Backup and Restore Config JSON File Documentation

This README documents the purpose, structure, and usage of backup and restore JSON files
used for backing up or restoring the system VPD. It includes descriptions of mandatory fields, expected
formats, and examples to understand and extend VPD for system.

---

## source
This section specifies where the source/main system VPD resides, it is the mandatory field for backup and restore.
This section will have hardwarePath or inventoryPath of the source. 

## destination
This section specifies where the system VPD is backed up, it is the mandatory field for backup and restore.
This section contains either hardwarePath or inventoryPath of the destination. If destination has inventoryPath which means backup is present on the
BMC cache otherwise if its a hardwarePath which means system VPD is backed up on another FRU's EEPROM.

## type
This section specifies the VPD format, represents its IPZ or keyword VPD type.
Note: currently only IPZ VPD's backup and restore is supported.

## backupMap
This section allows us to list system VPD keywords needs to be backup or restored. This section contains list of source/destination record/keyword details.

### sourceRecord
Contains source record name.

### sourceKeyword
Contains source keyword name.

### destinationRecord
Contains source record name.

### destinationKeyword
Contains the destination keyword name.

### defaultValue
Contains default value for the keyword.

### isPelRequired
Flag to specify whether to log a PEL is required if default value found on both the source and destination keyword.

### isManufactureResetRequired
This flag will be used with vpd-tool with mfgClean command to reset the keyword value to its default.

