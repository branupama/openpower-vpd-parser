# Backup and Restore Config JSON File Documentation

This README documents the purpose, structure, and usage of backup and restore JSON files
used for backing up or restoring the system VPD. It includes descriptions of mandatory fields, expected
formats, and examples to understand and extend for system VPD.

---

## source
This section specifies where the system VPD source path resides, it is the mandatory field for backup and restore.
This section specify either hardwarePath or inventoryPath of the source. 

## destination
This section specifies where the system VPD is back up, it is the mandatory field for backup and restore.
This section contains either hardwarePath or inventoryPath of the destination. If destination has inventoryPath which means backup is present on the
BMC cache otherwise if its a hardwarePath which means system VPD is backup up on another FRU's EEPROM path.

## type
This section specifies the VPD format, represents its IPZ or keyword VPD type.

## backupMap
This section allows us to list system VPD keywords needs to be backup and restored. contains source/destination record/keyword details.

### sourceRecord
Contains source record name in case if its IPZ type

### sourceKeyword
Contains source keyword name.

### destinationRecord
Contains source record name in case if its IPZ type.

### destinationKeyword
Contains the destination keyword name

### defaultValue
Contains default value for this particular record's keyword.

### isPelRequired
Flag to specify log a PEL is required if default value found on the source and destination for this keyword.

### isManufactureResetRequired
This flag will be used with vpd-tool with mfgClean command to reset the keyword value to default.

