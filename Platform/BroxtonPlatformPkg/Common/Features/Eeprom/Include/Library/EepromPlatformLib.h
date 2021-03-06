/** @file
  Copyright (c) 2015 - 2018, Intel Corporation. All rights reserved.<BR>

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef _EEPROM_PLATFORM_LIB_
#define _EEPROM_PLATFORM_LIB_
////
//// Header files
////
#include <Uefi.h>

#include <EepromStruct.h>
#include <Library/EepromDataLib.h>
#include <Library/EepromLib.h>


////
//// defines
////
#define END_OF_GPIO_ARRAY   0xFFFFFFFF


////
//// Functions
////
/**
  Returns the $BrdInfo structure

  @param[out]  StructureIndex  Index of where to start looking for the next structure
  @param[out]  BoardInfo       Buffer containing the BOARD_INFO_TABLE structure
                               - Up to the caller to free the buffer

  @retval      EFI_SUCCESS     $BrdInfo structure found
  @retval      EFI_NOT_FOUND   $BrdInfo structure not found
**/
EFI_STATUS
EFIAPI
EepromGetBoardInfo (
  IN OUT   UINT32              *StructureIndex,
  OUT      BOARD_INFO_TABLE   **BoardInfo
  );

/**
  Returns the $HdCodec data

  @param[out]  StructureIndex  Index of where to start looking for the next structure
  @param[out]  Buffer          Buffer containing the $HdCodec data
  @param[out]  BufferSize      Size of the HdaData buffer

  @retval      EFI_SUCCESS     $HdCodec data found
  @retval      EFI_NOT_FOUND   $HdCodec data not found
  @retval      EFI_NOT_READY   $HdCodec data not ready yet
**/
EFI_STATUS
EFIAPI
EepromGetHdaCodec (
  IN OUT   UINT32   *StructureIndex,
  OUT      UINT8   **Buffer,
  OUT      UINT32   *BufferSize
  );

/**
  Returns the $Logo$ data

  @param[out]  StructureIndex  Index of where to start looking for the next structure
  @param[out]  Buffer          Buffer containing the $Logo$ data
                               - Up to the caller to free the buffer
  @param[out]  BufferSize      Size of the LogoData buffer

  @retval      EFI_SUCCESS     $Logo$ data found
  @retval      EFI_NOT_FOUND   $Logo$ data not found
  @retval      EFI_NOT_READY   $Logo$ data not ready yet
**/
EFI_STATUS
EFIAPI
EepromGetLogo (
  IN OUT   UINT32   *StructureIndex,
  OUT      UINT8   **Buffer,
  OUT      UINT32   *BufferSize
  );

/**
  Returns the $MemCnfg data

  @param[out]  StructureIndex  Index of where to start looking for the next structure
  @param[out]  SpdSlotFlag     Flags of which SPD this data is valid for
  @param[out]  Buffer          Buffer containing the $MemCnfg data
                               - Up to the caller to free the buffer
  @param[out]  BufferSize      Size of the MemoryData buffer

  @retval      EFI_SUCCESS     $MemCnfg data found
  @retval      EFI_NOT_FOUND   $MemCnfg data not found
  @retval      EFI_NOT_READY   $MemCnfg data not ready yet
**/
EFI_STATUS
EFIAPI
EepromGetMemoryData (
  IN OUT   UINT32   *StructureIndex,
  OUT      UINT16   *SpdSlotFlag,
  OUT      UINT8   **Buffer,
  OUT      UINT32   *BufferSize
  );

/**
  Returns the $Video$ data

  @param[out]  StructureIndex  Index of where to start looking for the next structure
  @param[out]  Buffer          Buffer containing the $Video$ data
                               - Up to the caller to free the buffer
  @param[out]  BufferSize      Size of the VideoData buffer

  @retval      EFI_SUCCESS     $Video$ data found
  @retval      EFI_NOT_FOUND   $Video$ data not found
  @retval      EFI_NOT_READY   $Video$ data not ready yet
**/
EFI_STATUS
EFIAPI
EepromGetVbt (
  IN OUT   UINT32   *StructureIndex,
  OUT      UINT8   **Buffer,
  OUT      UINT32   *BufferSize
  );

/**
  Checks whether the PadOffset is in the platform GPIO whitelist.

  @param[in]  PadOffset    The PAD offset to check against the platform whitelist

  @retval     TRUE         PAD offset is in the whitelist
  @retval     FALSE        PAD offset is not in the whitelist
**/
BOOLEAN
EFIAPI
EepromPadCheck (
  IN  UINT32    PadOffset
  );

/**
  Programs the ACPI SSDT data in $AcpiTbl

  @param[in]  VOID

  @retval     EFI_SUCCESS     $AcpiTbl data found
  @retval     EFI_NOT_FOUND   $AcpiTbl data not found
  @retval     EFI_NOT_READY   $AcpiTbl data not ready to be programmed
**/
EFI_STATUS
EFIAPI
EepromProgramAcpi (VOID);

/**
  Program GPIOs per binary and whitelist.

  @param[in]  VOID

  @retval     EFI_SUCCESS     GPIOs programmed successfully.
  @retval     EFI_NOT_FOUND   GPIO data not found.
**/
EFI_STATUS
EFIAPI
EepromProgramGpioPads (VOID);

/**
  Reset the system using the platform desired reset method.

  @param[in]  ResetType    The reset type to perform

  @retval     None
**/
VOID
EFIAPI
EepromResetSystem (
  IN EFI_RESET_TYPE   ResetType
  );

#endif // _EEPROM_PLATFORM_LIB_

