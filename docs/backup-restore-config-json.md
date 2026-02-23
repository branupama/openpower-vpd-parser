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
This section specifies the VPD format, represents its IPZ or keyword type.

