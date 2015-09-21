/*
*********************************************************************************************************
*                                             uC/FS V4
*                                     The Embedded File System
*
*                         (c) Copyright 2008-2010; Micrium, Inc.; Weston, FL
*
*               All rights reserved. Protected by international copyright laws.
*
*               uC/FS is provided in source form to registered licensees ONLY.  It is
*               illegal to distribute this source code to any third party unless you receive
*               written permission by an authorized Micrium representative.  Knowledge of
*               the source code may NOT be used to develop a similar product.
*
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*
*               You can contact us at www.micrium.com.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                  FILE SYSTEM ERROR CODE MANAGEMENT
*
* Filename      : fs_err.h
* Version       : V4.04
* Programmer(s) : AHFAI
*                 FBJ
*                 BAN
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                               EXTERNS
*********************************************************************************************************
*/

#ifdef   FS_ERR_MODULE
#define  FS_ERR_EXT
#else
#define  FS_ERR_EXT  extern
#endif


/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                       FILE SYSTEM ERROR CODES
*
* Note(s) : (1) All generic file system error codes are #define'd in 'fs_err.h';
*               Any device-specific     error codes are #define'd in device-specific header files.
*********************************************************************************************************
*/

#define  FS_ERR_NONE                                       0u

#define  FS_ERR_STR_NONE                                          "No error"

#define  FS_ERR_INVALID_ARG                               10u   /* Invalid argument.                                    */
#define  FS_ERR_INVALID_CFG                               11u   /* Invalid configuration.                               */
#define  FS_ERR_INVALID_CHKSUM                            12u   /* Invalid checksum.                                    */
#define  FS_ERR_INVALID_LEN                               13u   /* Invalid length.                                      */
#define  FS_ERR_INVALID_TIME                              14u   /* Invalid date/time.                                   */
#define  FS_ERR_INVALID_TIMESTAMP                         15u   /* Invalid timestamp.                                   */
#define  FS_ERR_INVALID_TYPE                              16u   /* Invalid object type.                                 */
#define  FS_ERR_MEM_ALLOC                                 17u   /* Mem could not be alloc'd.                            */
#define  FS_ERR_NULL_ARG                                  18u   /* Arg(s) passed NULL val(s).                           */
#define  FS_ERR_NULL_PTR                                  19u   /* Ptr arg(s) passed NULL ptr(s).                       */
#define  FS_ERR_OS                                        20u   /* OS err.                                              */
#define  FS_ERR_OVF                                       21u   /* Value too large to be stored in type.                */
#define  FS_ERR_EOF                                       22u   /* EOF reached.                                         */

#define  FS_ERR_STR_INVALID_ARG                                   "Invalid arg"
#define  FS_ERR_STR_INVALID_CFG                                   "Invalid cfg"
#define  FS_ERR_STR_INVALID_CHKSUM                                "Invalid checksum"
#define  FS_ERR_STR_INVALID_LEN                                   "Invalid length"
#define  FS_ERR_STR_INVALID_TIME                                  "Invalid date/time"
#define  FS_ERR_STR_INVALID_TIMESTAMP                             "Invalid timestamp"
#define  FS_ERR_STR_INVALID_TYPE                                  "Invalid object type"
#define  FS_ERR_STR_MEM_ALLOC                                     "Memory could not be allocated"
#define  FS_ERR_STR_NULL_ARG                                      "Arg(s) passed NULL val(s)"
#define  FS_ERR_STR_NULL_PTR                                      "Ptr arg(s) passed NULL ptr(s)"
#define  FS_ERR_STR_OS                                            "OS err"
#define  FS_ERR_STR_OVF                                           "Value too large to be stored in type"
#define  FS_ERR_STR_EOF                                           "EOF reached"


#define  FS_ERR_WORKING_DIR_NONE_AVAIL                    30u   /* No working dir avail.                                */
#define  FS_ERR_WORKING_DIR_INVALID                       31u   /* Working dir invalid.                                 */

#define  FS_ERR_STR_WORKING_DIR_NONE_AVAIL                        "No working dir avail"
#define  FS_ERR_STR_WORKING_DIR_INVALID                           "Working dir invalid"

/*
*********************************************************************************************************
*                                         BUFFER ERROR CODES
*********************************************************************************************************
*/

#define  FS_ERR_BUF_NONE_AVAIL                           100u   /* No buf avail.                                        */

#define  FS_ERR_STR_BUF_NONE_AVAIL                                "No buf avail"

/*
*********************************************************************************************************
*                                          CACHE ERROR CODES
*********************************************************************************************************
*/

#define  FS_ERR_CACHE_INVALID_MODE                       200u   /* Mode specified invalid.                              */
#define  FS_ERR_CACHE_INVALID_SEC_TYPE                   201u   /* Sector type specified invalid.                       */
#define  FS_ERR_CACHE_TOO_SMALL                          202u   /* Cache specified too small.                           */

#define  FS_ERR_STR_CACHE_INVALID_MODE                            "Mode specified invalid"
#define  FS_ERR_STR_CACHE_INVALID_SEC_TYPE                        "Sector type specified invalid"
#define  FS_ERR_STR_CACHE_TOO_SMALL                               "Cache specified too small"

/*
*********************************************************************************************************
*                                         DEVICE ERROR CODES
*********************************************************************************************************
*/

#define  FS_ERR_DEV                                      300u   /* Device access error.                                 */
#define  FS_ERR_DEV_ALREADY_OPEN                         301u   /* Device already open.                                 */
#define  FS_ERR_DEV_CHNGD                                302u   /* Device has changed.                                  */
#define  FS_ERR_DEV_FIXED                                303u   /* Device is fixed (cannot be closed).                  */
#define  FS_ERR_DEV_FULL                                 304u   /* Device is full (no space could be allocated).        */
#define  FS_ERR_DEV_INVALID                              310u   /* Invalid device.                                      */
#define  FS_ERR_DEV_INVALID_CFG                          311u   /* Invalid dev cfg.                                     */
#define  FS_ERR_DEV_INVALID_ECC                          312u   /* Invalid ECC.                                         */
#define  FS_ERR_DEV_INVALID_IO_CTRL                      313u   /* I/O control invalid.                                 */
#define  FS_ERR_DEV_INVALID_LOW_FMT                      314u   /* Low format invalid.                                  */
#define  FS_ERR_DEV_INVALID_LOW_PARAMS                   315u   /* Invalid low-level device parameters.                 */
#define  FS_ERR_DEV_INVALID_MARK                         316u   /* Invalid mark.                                        */
#define  FS_ERR_DEV_INVALID_NAME                         317u   /* Invalid device name.                                 */
#define  FS_ERR_DEV_INVALID_OP                           318u   /* Invalid operation.                                   */
#define  FS_ERR_DEV_INVALID_SEC_NBR                      319u   /* Invalid device sec nbr.                              */
#define  FS_ERR_DEV_INVALID_SEC_SIZE                     320u   /* Invalid device sec size.                             */
#define  FS_ERR_DEV_INVALID_SIZE                         321u   /* Invalid device size.                                 */
#define  FS_ERR_DEV_INVALID_UNIT_NBR                     322u   /* Invalid device unit nbr.                             */
#define  FS_ERR_DEV_IO                                   323u   /* Device I/O error.                                    */
#define  FS_ERR_DEV_NONE_AVAIL                           324u   /* No device avail.                                     */
#define  FS_ERR_DEV_NOT_OPEN                             325u   /* Device not open.                                     */
#define  FS_ERR_DEV_NOT_PRESENT                          326u   /* Device not present.                                  */
#define  FS_ERR_DEV_TIMEOUT                              327u   /* Device timeout.                                      */
#define  FS_ERR_DEV_UNIT_NONE_AVAIL                      328u   /* No unit avail.                                       */
#define  FS_ERR_DEV_UNIT_ALREADY_EXIST                   329u   /* Unit already exists.                                 */
#define  FS_ERR_DEV_UNKNOWN                              330u   /* Unknown.                                             */
#define  FS_ERR_DEV_VOL_OPEN                             331u   /* Vol open on dev.                                     */

#define  FS_ERR_STR_DEV                                           "Dev access err"
#define  FS_ERR_STR_DEV_ALREADY_OPEN                              "Dev already open"
#define  FS_ERR_STR_DEV_CHNGD                                     "Dev has chgd"
#define  FS_ERR_STR_DEV_FIXED                                     "Dev is fixed (cannot be closed)"
#define  FS_ERR_STR_DEV_FULL                                      "Dev is full (no space could be alloc'd)"
#define  FS_ERR_STR_DEV_INVALID                                   "Invalid dev"
#define  FS_ERR_STR_DEV_INVALID_CFG                               "Cfg invalid"
#define  FS_ERR_STR_DEV_INVALID_ECC                               "ECC invalid"
#define  FS_ERR_STR_DEV_INVALID_IO_CTRL                           "I/O control invalid"
#define  FS_ERR_STR_DEV_INVALID_LOW_FMT                           "Low format invalid"
#define  FS_ERR_STR_DEV_INVALID_LOW_PARAMS                        "Invalid low-level dev params"
#define  FS_ERR_STR_DEV_INVALID_MARK                              "Mark invalid"
#define  FS_ERR_STR_DEV_INVALID_NAME                              "Invalid dev name"
#define  FS_ERR_STR_DEV_INVALID_OP                                "Invalid op"
#define  FS_ERR_STR_DEV_INVALID_SEC_NBR                           "Invalid dev sec nbr"
#define  FS_ERR_STR_DEV_INVALID_SEC_SIZE                          "Invalid dev sec size"
#define  FS_ERR_STR_DEV_INVALID_SIZE                              "Invalid dev size"
#define  FS_ERR_STR_DEV_INVALID_UNIT_NBR                          "Invalid dev unit nbr"
#define  FS_ERR_STR_DEV_IO                                        "Device I/O error"
#define  FS_ERR_STR_DEV_NONE_AVAIL                                "No device avail"
#define  FS_ERR_STR_DEV_NOT_OPEN                                  "Dev not open"
#define  FS_ERR_STR_DEV_NOT_PRESENT                               "Dev not present"
#define  FS_ERR_STR_DEV_NOT_USED                                  "Dev not used"
#define  FS_ERR_STR_DEV_TIMEOUT                                   "Dev timeout"
#define  FS_ERR_STR_DEV_UNIT_NONE_AVAIL                           "No unit avail"
#define  FS_ERR_STR_DEV_UNIT_ALREADY_EXIST                        "Unit already exists"
#define  FS_ERR_STR_DEV_UNKNOWN                                   "Unknown"
#define  FS_ERR_STR_DEV_VOL_OPEN                                  "Vol open on device"

/*
*********************************************************************************************************
*                                      DEVICE DRIVER ERROR CODES
*********************************************************************************************************
*/

#define  FS_ERR_DEV_DRV_ALREADY_ADDED                    400u   /* Dev drv already added.                               */
#define  FS_ERR_DEV_DRV_INVALID_NAME                     401u   /* Invalid dev drv name.                                */
#define  FS_ERR_DEV_DRV_NO_TBL_POS_AVAIL                 402u   /* No pos avail in dev drv tbl.                         */

#define  FS_ERR_STR_DEV_DRV_ALREADY_ADDED                         "Dev drv already added"
#define  FS_ERR_STR_DEV_DRV_INVALID_NAME                          "Invalid dev drv name"
#define  FS_ERR_STR_DEV_DRV_NO_TBL_POS_AVAIL                      "No pos avail in dev drv tbl"

/*
*********************************************************************************************************
*                                        DIRECTORY ERROR CODES
*********************************************************************************************************
*/

#define  FS_ERR_DIR_ALREADY_OPEN                         500u   /* Directory already open.                              */
#define  FS_ERR_DIR_DIS                                  501u   /* Directory module disabled.                           */
#define  FS_ERR_DIR_FULL                                 502u   /* Directory is full.                                   */
#define  FS_ERR_DIR_NONE_AVAIL                           503u   /* No directory  avail.                                 */
#define  FS_ERR_DIR_NOT_OPEN                             504u   /* Directory not open.                                  */

#define  FS_ERR_STR_DIR_ALREADY_OPEN                              "Dir already open"
#define  FS_ERR_STR_DIR_DIS                                       "Dir module dis'd"
#define  FS_ERR_STR_DIR_FULL                                      "Dir is full"
#define  FS_ERR_STR_DIR_NONE_AVAIL                                "No dir avail"
#define  FS_ERR_STR_DIR_NOT_USED                                  "Dir not used"
#define  FS_ERR_STR_DIR_NOT_OPEN                                  "Dir not open"

/*
*********************************************************************************************************
*                                           ECC ERROR CODES
*********************************************************************************************************
*/

#define  FS_ERR_ECC_CORRECTABLE                          600u   /* Correctable ECC error.                               */
#define  FS_ERR_ECC_UNCORRECTABLE                        601u   /* Uncorrectable ECC error.                             */

/*
*********************************************************************************************************
*                                          ENTRY ERROR CODES
*********************************************************************************************************
*/

#define  FS_ERR_ENTRIES_SAME                             700u   /* Paths specify same file system entry.                */
#define  FS_ERR_ENTRIES_TYPE_DIFF                        701u   /* Paths do not both specify files OR directories.      */
#define  FS_ERR_ENTRIES_VOLS_DIFF                        702u   /* Paths specify file system entries on different vols. */
#define  FS_ERR_ENTRY_CORRUPT                            703u   /* File system entry is corrupt.                        */
#define  FS_ERR_ENTRY_EXISTS                             704u   /* File system entry exists.                            */
#define  FS_ERR_ENTRY_INVALID                            705u   /* File system entry invalid.                           */
#define  FS_ERR_ENTRY_NOT_DIR                            706u   /* File system entry NOT a directory.                   */
#define  FS_ERR_ENTRY_NOT_EMPTY                          707u   /* File system entry NOT empty.                         */
#define  FS_ERR_ENTRY_NOT_FILE                           708u   /* File system entry NOT a file.                        */
#define  FS_ERR_ENTRY_NOT_FOUND                          709u   /* File system entry NOT found.                         */
#define  FS_ERR_ENTRY_PARENT_NOT_FOUND                   710u   /* Entry parent NOT found.                              */
#define  FS_ERR_ENTRY_PARENT_NOT_DIR                     711u   /* Entry parent NOT a directory.                        */
#define  FS_ERR_ENTRY_RD_ONLY                            712u   /* File system entry marked read-only.                  */
#define  FS_ERR_ENTRY_ROOT_DIR                           713u   /* File system entry is a root directory.               */
#define  FS_ERR_ENTRY_TYPE_INVALID                       714u   /* File system entry type is invalid.                   */
#define  FS_ERR_ENTRY_OPEN                               715u   /* Operation not allowed on already open entry          */

#define  FS_ERR_STR_ENTRIES_SAME                                  "Paths specify same file system entry"
#define  FS_ERR_STR_ENTRIES_TYPE_DIFF                             "Paths do not both specify files OR dirs"
#define  FS_ERR_STR_ENTRIES_VOLS_DIFF                             "Paths specify file system entries on diff vols"
#define  FS_ERR_STR_ENTRY_EXISTS                                  "File system entry exists"
#define  FS_ERR_STR_ENTRY_INVALID                                 "File system entry invalid"
#define  FS_ERR_STR_ENTRY_NOT_DIR                                 "File system entry NOT a dir"
#define  FS_ERR_STR_ENTRY_NOT_EMPTY                               "File system entry NOT empty"
#define  FS_ERR_STR_ENTRY_NOT_FILE                                "File system entry NOT a file"
#define  FS_ERR_STR_ENTRY_NOT_FOUND                               "File system entry NOT found"
#define  FS_ERR_STR_ENTRY_PARENT_NOT_FOUND                        "Entry parent NOT found"
#define  FS_ERR_STR_ENTRY_PARENT_NOT_DIR                          "Entry parent NOT a dir"
#define  FS_ERR_STR_ENTRY_RD_ONLY                                 "File system entry marked read-only"
#define  FS_ERR_STR_ENTRY_ROOT_DIR                                "File system entry is a root dir"
#define  FS_ERR_STR_ENTRY_TYPE_INVALID                            "File system entry type is invalid"
#define  FS_ERR_STR_ENTRY_OPEN                                    "Operation not allowed on already open entry"

/*
*********************************************************************************************************
*                                          FILE ERROR CODES
*********************************************************************************************************
*/

#define  FS_ERR_FILE_ALREADY_OPEN                        800u   /* File already open.                                   */
#define  FS_ERR_FILE_BUF_ALREADY_ASSIGNED                801u   /* Buf already assigned.                                */
#define  FS_ERR_FILE_ERR                                 802u   /* Error indicator set on file.                         */
#define  FS_ERR_FILE_INVALID_ACCESS_MODE                 803u   /* Access mode is specified invalid.                    */
#define  FS_ERR_FILE_INVALID_ATTRIB                      804u   /* Attributes are specified invalid.                    */
#define  FS_ERR_FILE_INVALID_BUF_MODE                    805u   /* Buf mode is specified invalid or unknown.            */
#define  FS_ERR_FILE_INVALID_BUF_SIZE                    806u   /* Buf size is specified invalid.                       */
#define  FS_ERR_FILE_INVALID_DATE_TIME                   807u   /* Date/time is specified invalid.                      */
#define  FS_ERR_FILE_INVALID_DATE_TIME_TYPE              808u   /* Date/time type flag is specified invalid.            */
#define  FS_ERR_FILE_INVALID_NAME                        809u   /* Name is specified invalid.                           */
#define  FS_ERR_FILE_INVALID_ORIGIN                      810u   /* Origin is specified invalid or unknown.              */
#define  FS_ERR_FILE_INVALID_OFFSET                      811u   /* Offset is specified invalid.                         */
#define  FS_ERR_FILE_INVALID_FILES                       812u   /* Invalid file arguments.                              */
#define  FS_ERR_FILE_INVALID_OP                          813u   /* File operation invalid.                              */
#define  FS_ERR_FILE_INVALID_OP_SEQ                      814u   /* File operation sequence invalid.                     */
#define  FS_ERR_FILE_INVALID_POS                         815u   /* File position invalid.                               */
#define  FS_ERR_FILE_LOCKED                              816u   /* File locked.                                         */
#define  FS_ERR_FILE_NONE_AVAIL                          817u   /* No file available.                                   */
#define  FS_ERR_FILE_NOT_OPEN                            818u   /* File NOT open.                                       */
#define  FS_ERR_FILE_NOT_LOCKED                          819u   /* File NOT locked.                                     */
#define  FS_ERR_FILE_OVF                                 820u   /* File size overflowed max file size.                  */
#define  FS_ERR_FILE_OVF_OFFSET                          821u   /* File offset overflowed max file offset.              */


#define  FS_ERR_STR_FILE_ALREADY_OPEN                             "File already open"
#define  FS_ERR_STR_FILE_BUF_ALREADY_ASSIGNED                     "Buf already assigned"
#define  FS_ERR_STR_FILE_ERR                                      "Error indicator set on file"
#define  FS_ERR_STR_FILE_INVALID_ACCESS_MODE                      "Access mode is specified invalid"
#define  FS_ERR_STR_FILE_INVALID_ATTRIB                           "Attribs are specified invalid"
#define  FS_ERR_STR_FILE_INVALID_BUF_MODE                         "Buf mode is specified invalid or unknown"
#define  FS_ERR_STR_FILE_INVALID_BUF_SIZE                         "Buf size is specified invalid"
#define  FS_ERR_STR_FILE_INVALID_DATE_TIME                        "Date/time is specified invalid"
#define  FS_ERR_STR_FILE_INVALID_NAME                             "Name is specified invalid"
#define  FS_ERR_STR_FILE_INVALID_ORIGIN                           "Origin is specified invalid or unknown"
#define  FS_ERR_STR_FILE_INVALID_OFFSET                           "Offset is specified invalid"
#define  FS_ERR_STR_FILE_INVALID_FILES                            "Invalid file args"
#define  FS_ERR_STR_FILE_INVALID_OP                               "File op invalid"
#define  FS_ERR_STR_FILE_INVALID_OP_SEQ                           "File op seq invalid"
#define  FS_ERR_STR_FILE_INVALID_POS                              "File pos invalid"
#define  FS_ERR_STR_FILE_LOCKED                                   "File locked"
#define  FS_ERR_STR_FILE_NONE_AVAIL                               "No file available"
#define  FS_ERR_STR_FILE_NOT_USED                                 "File NOT used"
#define  FS_ERR_STR_FILE_NOT_OPEN                                 "File NOT open"
#define  FS_ERR_STR_FILE_NOT_LOCKED                               "File NOT locked"
#define  FS_ERR_STR_FILE_OVF                                      "File size ovf'd max file size"
#define  FS_ERR_STR_FILE_OVF_OFFSET                               "File offset ovf'd max file offset"

/*
*********************************************************************************************************
*                                          NAME ERROR CODES
*********************************************************************************************************
*/

#define  FS_ERR_NAME_BASE_TOO_LONG                       900u   /* Base name too long.                                  */
#define  FS_ERR_NAME_EMPTY                               901u   /* Name empty.                                          */
#define  FS_ERR_NAME_EXT_TOO_LONG                        902u   /* Extension too long.                                  */
#define  FS_ERR_NAME_INVALID                             903u   /* Invalid file name or path.                           */
#define  FS_ERR_NAME_MIXED_CASE                          904u   /* Name is mixed case.                                  */
#define  FS_ERR_NAME_NULL                                905u   /* Name ptr arg(s) passed NULL ptr(s).                  */
#define  FS_ERR_NAME_PATH_TOO_LONG                       906u   /* Entry path is too long.                              */
#define  FS_ERR_NAME_BUF_TOO_SHORT                       907u   /* Buffer for name is too short.                        */
#define  FS_ERR_NAME_TOO_LONG                            908u   /* Full name is too long.                               */

#define  FS_ERR_STR_NAME_BASE_TOO_LONG                            "Base name too long"
#define  FS_ERR_STR_NAME_EMPTY                                    "Name empty"
#define  FS_ERR_STR_NAME_EXT_TOO_LONG                             "Extension too long"
#define  FS_ERR_STR_NAME_INVALID                                  "Invalid file name or path"
#define  FS_ERR_STR_NAME_MIXED_CASE                               "Name is mixed case"
#define  FS_ERR_STR_NAME_NULL                                     "Name ptr arg(s) passed NULL ptr(s)"
#define  FS_ERR_STR_NAME_PATH_TOO_LONG                            "Path name too long"
#define  FS_ERR_STR_NAME_BUF_TOO_SHORT                            "Buf for name is too short"
#define  FS_ERR_STR_NAME_TOO_LONG                                 "Full name is too long"

/*
*********************************************************************************************************
*                                        PARTITION ERROR CODES
*********************************************************************************************************
*/

#define  FS_ERR_PARTITION_INVALID                       1001u   /* Partition invalid.                                   */
#define  FS_ERR_PARTITION_INVALID_NBR                   1002u   /* Partition nbr specified invalid.                     */
#define  FS_ERR_PARTITION_INVALID_SIG                   1003u   /* Partition sig invalid.                               */
#define  FS_ERR_PARTITION_INVALID_SIZE                  1004u   /* Partition size invalid.                              */
#define  FS_ERR_PARTITION_MAX                           1005u   /* Max nbr partitions have been created in MBR.         */
#define  FS_ERR_PARTITION_NOT_FINAL                     1006u   /* Prev partition is not final partition.               */
#define  FS_ERR_PARTITION_NOT_FOUND                     1007u   /* Partition NOT found.                                 */
#define  FS_ERR_PARTITION_ZERO                          1008u   /* Partition zero.                                      */

#define  FS_ERR_STR_PART_INVALID                                  "Partition invalid"
#define  FS_ERR_STR_PART_INVALID_NBR                              "Partition nbr specified invalid"
#define  FS_ERR_STR_PART_INVALID_SIG                              "Partition sig invalid"
#define  FS_ERR_STR_PART_INVALID_SIZE                             "Partition size invalid"
#define  FS_ERR_STR_PART_MAX                                      "Max nbr partitions have been created in MBR"
#define  FS_ERR_STR_PART_NOT_FINAL                                "Prev partition is not final partition"
#define  FS_ERR_STR_PARTITION_NOT_FOUND                           "Partition NOT found"
#define  FS_ERR_STR_PART_ZERO                                     "Partition zero"

/*
*********************************************************************************************************
*                                          POOLS ERROR CODE
*********************************************************************************************************
*/

#define  FS_ERR_POOL_EMPTY                              1100u   /* Pool is empty.                                       */
#define  FS_ERR_POOL_FULL                               1101u   /* Pool is full.                                        */
#define  FS_ERR_POOL_INVALID_BLK_ADDR                   1102u   /* Block not found in used pool pointers.               */
#define  FS_ERR_POOL_INVALID_BLK_IN_POOL                1103u   /* Block found in free pool pointers.                   */
#define  FS_ERR_POOL_INVALID_BLK_IX                     1104u   /* Block index invalid.                                 */
#define  FS_ERR_POOL_INVALID_BLK_NBR                    1105u   /* Number blocks specified invalid.                     */
#define  FS_ERR_POOL_INVALID_BLK_SIZE                   1106u   /* Block size specified invalid.                        */

#define  FS_ERR_STR_POOL_EMPTY                                    "Pool is empty"
#define  FS_ERR_STR_POOL_FULL                                     "Pool is full"
#define  FS_ERR_STR_POOL_INVALID_BLK_ADDR                         "Blk not found in used pool ptrs"
#define  FS_ERR_STR_POOL_INVALID_BLK_IN_POOL                      "Blk found in free pool ptrs"
#define  FS_ERR_STR_POOL_INVALID_BLK_IX                           "Blk ix invalid"
#define  FS_ERR_STR_POOL_INVALID_BLK_NBR                          "Nbr blks specified invalid"
#define  FS_ERR_STR_POOL_INVALID_BLK_SIZE                         "Blk size specified invalid"

/*
*********************************************************************************************************
*                                       FILE SYSTEM ERROR CODES
*********************************************************************************************************
*/

#define  FS_ERR_SYS_TYPE_NOT_SUPPORTED                  1301u   /* File sys type not supported.                         */
#define  FS_ERR_SYS_INVALID_SIG                         1309u   /* Sec has invalid OR illegal sig.                      */
#define  FS_ERR_SYS_DIR_ENTRY_PLACE                     1330u   /* Dir entry could not be placed.                       */
#define  FS_ERR_SYS_DIR_ENTRY_NOT_FOUND                 1331u   /* Dir entry not found.                                 */
#define  FS_ERR_SYS_DIR_ENTRY_NOT_FOUND_YET             1332u   /* Dir entry not found (yet).                           */
#define  FS_ERR_SYS_SEC_NOT_FOUND                       1333u   /* Sec not found.                                       */
#define  FS_ERR_SYS_CLUS_CHAIN_END                      1334u   /* Cluster chain ended.                                 */
#define  FS_ERR_SYS_CLUS_CHAIN_END_EARLY                1335u   /* Cluster chain ended before number clusters traversed.*/
#define  FS_ERR_SYS_CLUS_INVALID                        1336u   /* Cluster invalid.                                     */
#define  FS_ERR_SYS_CLUS_NOT_AVAIL                      1337u   /* Cluster not avail.                                   */
#define  FS_ERR_SYS_SFN_NOT_AVAIL                       1338u   /* SFN is not avail.                                    */
#define  FS_ERR_SYS_LFN_ORPHANED                        1339u   /* LFN entry orphaned.                                  */

#define  FS_ERR_STR_SYS_TYPE_NOT_SUPPORTED                        "File sys type not supported"
#define  FS_ERR_STR_SYS_INVALID_SIG                               "Sec has invalid OR illegal sig"
#define  FS_ERR_STR_SYS_DIR_ENTRY_PLACE                           "Dir entry could not be placed"
#define  FS_ERR_STR_SYS_DIR_ENTRY_NOT                             "Dir entry not found"
#define  FS_ERR_STR_SYS_DIR_ENTRY_NOT_YET                         "Dir entry not found (yet)"
#define  FS_ERR_STR_SYS_SEC_NOT_FOUND                             "Sec not found"
#define  FS_ERR_STR_SYS_CLUS_CHAIN_END                            "Clus chain ended"
#define  FS_ERR_STR_SYS_CLUS_CHAIN_END_EARLY                      "Clus chain ended before nbr clus's traversed"
#define  FS_ERR_STR_SYS_CLUS_INVALID                              "Clus invalid"
#define  FS_ERR_STR_SYS_CLUS_NOT_AVAIL                            "Clus not avail"
#define  FS_ERR_STR_SYS_SFN_NOT_AVAIL                             "SFN is not avail"
#define  FS_ERR_STR_SYS_LFN_ORPHANED                              "LFN entry orphaned"

/*
*********************************************************************************************************
*                                           VOLUME ERROR CODES
*********************************************************************************************************
*/

#define  FS_ERR_VOL_INVALID_NAME                        1400u   /* Invalid volume name.                                 */
#define  FS_ERR_VOL_INVALID_SIZE                        1401u   /* Invalid volume size.                                 */
#define  FS_ERR_VOL_INVALID_SEC_SIZE                    1403u   /* Invalid volume sector size.                          */
#define  FS_ERR_VOL_INVALID_CLUS_SIZE                   1404u   /* Invalid volume cluster size.                         */
#define  FS_ERR_VOL_INVALID_OP                          1405u   /* Volume operation invalid.                            */
#define  FS_ERR_VOL_INVALID_SEC_NBR                     1406u   /* Invalid volume sector number.                        */
#define  FS_ERR_VOL_INVALID_SYS                         1407u   /* Invalid file system on volume.                       */
#define  FS_ERR_VOL_NO_CACHE                            1408u   /* No cache assigned to volume.                         */

#define  FS_ERR_STR_VOL_INVALID_NAME                              "Invalid vol name"
#define  FS_ERR_STR_VOL_INVALID_SIZE                              "Invalid vol size"
#define  FS_ERR_STR_VOL_INVALID_SEC_SIZE                          "Invalid vol sec size"
#define  FS_ERR_STR_VOL_INVALID_CLUS_SIZE                         "Invalid vol clus size"
#define  FS_ERR_STR_VOL_INVALID_OP                                "Vol op invalid"
#define  FS_ERR_STR_VOL_INVALID_SEC_NBR                           "Invalid vol sec nbr"
#define  FS_ERR_STR_VOL_INVALID_SYS                               "Invalid file sys on vol"
#define  FS_ERR_STR_VOL_NO_CACHE                                  "No cache assigned to vol"

#define  FS_ERR_VOL_NONE_AVAIL                          1410u   /* No vol  avail.                                       */
#define  FS_ERR_VOL_NONE_EXIST                          1411u   /* No vols exist.                                       */
#define  FS_ERR_VOL_NOT_OPEN                            1413u   /* Vol NOT open.                                        */
#define  FS_ERR_VOL_NOT_MOUNTED                         1414u   /* Vol NOT mounted.                                     */
#define  FS_ERR_VOL_ALREADY_OPEN                        1415u   /* Vol already open.                                    */
#define  FS_ERR_VOL_FILES_OPEN                          1416u   /* Files open on vol.                                   */
#define  FS_ERR_VOL_DIRS_OPEN                           1417u   /* Dirs open on vol.                                    */

#define  FS_ERR_STR_VOL_NONE_AVAIL                                "No vol  avail"
#define  FS_ERR_STR_VOL_NONE_EXIST                                "No vols exist"
#define  FS_ERR_STR_VOL_NOT_USED                                  "Vol NOT used"
#define  FS_ERR_STR_VOL_NOT_OPEN                                  "Vol NOT open"
#define  FS_ERR_STR_VOL_NOT_MOUNTED                               "Vol NOT mounted"
#define  FS_ERR_STR_VOL_ALREADY_OPEN                              "Vol already open"
#define  FS_ERR_STR_VOL_FILES_OPEN                                "Files open on vol"
#define  FS_ERR_STR_VOL_DIRS_OPEN                                 "Dirs open on vol"

#define  FS_ERR_VOL_JOURNAL_ALREADY_OPEN                1420u   /* Journal already open.                                */
#define  FS_ERR_VOL_JOURNAL_CFG_CHNGD                   1421u   /* File system suite cfg changed since log created.     */
#define  FS_ERR_VOL_JOURNAL_FILE_INVALID                1422u   /* Journal file invalid.                                */
#define  FS_ERR_VOL_JOURNAL_FULL                        1423u   /* Journal full.                                        */
#define  FS_ERR_VOL_JOURNAL_LOG_INVALID_ARG             1424u   /* Invalid arg read from journal log.                   */
#define  FS_ERR_VOL_JOURNAL_LOG_INCOMPLETE              1425u   /* Log not completely entered in journal.               */
#define  FS_ERR_VOL_JOURNAL_LOG_NOT_PRESENT             1426u   /* Log not present in journal.                          */
#define  FS_ERR_VOL_JOURNAL_NOT_OPEN                    1427u   /* Journal not open.                                    */
#define  FS_ERR_VOL_JOURNAL_NOT_REPLAYING               1428u   /* Journal not being replayed.                          */
#define  FS_ERR_VOL_JOURNAL_NOT_STARTED                 1429u   /* Journaling not started.                              */
#define  FS_ERR_VOL_JOURNAL_NOT_STOPPED                 1430u   /* Journaling not stopped.                              */

#define  FS_ERR_STR_VOL_JOURNAL_ALREADY_OPEN                      "Journal already open"
#define  FS_ERR_STR_VOL_JOURNAL_CFG_CHNGD                         "File sys suite cfg chngd since log created"
#define  FS_ERR_STR_VOL_JOURNAL_FILE_INVALID                      "Journal file invalid."
#define  FS_ERR_STR_VOL_JOURNAL_FULL                              "Journal full."
#define  FS_ERR_STR_VOL_JOURNAL_LOG_INVALID_ARG                   "Invalid arg read from journal log."
#define  FS_ERR_STR_VOL_JOURNAL_LOG_INCOMPLETE                    "Log not completely entered in journal"
#define  FS_ERR_STR_VOL_JOURNAL_LOG_NOT_PRESENT                   "Log not present in journal"
#define  FS_ERR_STR_VOL_JOURNAL_NOT_OPEN                          "Journal not open"
#define  FS_ERR_STR_VOL_JOURNAL_NOT_REPLAYING                     "Journal not being replayed"
#define  FS_ERR_STR_VOL_JOURNAL_NOT_STARTED                       "Journaling not started"
#define  FS_ERR_STR_VOL_JOURNAL_NOT_STOPPED                       "Journaling not stopped"

#define  FS_ERR_VOL_LABEL_INVALID                       1440u   /* Volume label is invalid.                             */
#define  FS_ERR_VOL_LABEL_NOT_FOUND                     1441u   /* Volume label was not found.                          */
#define  FS_ERR_VOL_LABEL_TOO_LONG                      1442u   /* Volume label is too long.                            */

#define  FS_ERR_STR_VOL_LABEL_INVALID                             "Vol label is invalid"
#define  FS_ERR_STR_VOL_LABEL_NOT_FOUND                           "Vol label was not found"
#define  FS_ERR_STR_VOL_LABEL_TOO_LONG                            "Vol label is too long"

/*
*********************************************************************************************************
*                                    FILE SYSTEM-OS LAYER ERROR CODES
*********************************************************************************************************
*/

#define  FS_ERR_OS_LOCK                                 1501u
#define  FS_ERR_OS_INIT                                 1510u
#define  FS_ERR_OS_INIT_LOCK                            1511u
#define  FS_ERR_OS_INIT_LOCK_NAME                       1512u


/*
*********************************************************************************************************
*                                               MACRO'S
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                             DATA TYPES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                        ERROR CODES DATA TYPE
*********************************************************************************************************
*/

typedef  CPU_INT16U  FS_ERR;


/*
*********************************************************************************************************
*                                          GLOBAL VARIABLES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/

const  CPU_CHAR  *FSErr_GetStr(FS_ERR  err_code);


/*
*********************************************************************************************************
*                                        CONFIGURATION ERRORS
*********************************************************************************************************
*/
