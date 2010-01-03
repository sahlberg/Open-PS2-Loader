/*
# _____     ___ ____     ___ ____
#  ____|   |    ____|   |        | |____|
# |     ___|   |____ ___|    ____| |    \    PS2DEV Open Source Project.
#-----------------------------------------------------------------------
# Copyright (c) 2003 Marcus R. Brown <mrbrown@0xd6.org>
# Licenced under Academic Free License version 2.0
# Review ps2sdk README & LICENSE files for further details.
#
# $Id: atad.h 629 2004-10-11 00:45:00Z mrbrown $
# ATA Device Driver definitions and imports.
*/

#ifndef IOP_ATAD_H
#define IOP_ATAD_H

#include "types.h"
#include "irx.h"

/* These are used with the dir parameter of ata_device_dma_transfer().  */
#define ATA_DIR_READ	0
#define ATA_DIR_WRITE	1

typedef struct _ata_devinfo {
	int	exists;		/* Was successfully probed.  */
	int	has_packet;	/* Supports the PACKET command set.  */
	u32	total_sectors;	/* Total number of user sectors.  */
	u32	security_status;/* Word 0x100 of the identify info.  */
} ata_devinfo_t;

#define atad_IMPORTS_start DECLARE_IMPORT_TABLE(atad, 1, 2)
#define atad_IMPORTS_end END_IMPORT_TABLE

ata_devinfo_t * ata_get_devinfo(int device);
#define I_ata_get_devinfo DECLARE_IMPORT(4, ata_get_devinfo)

int ata_reset_devices(void);
#define I_ata_reset_devices DECLARE_IMPORT(5, ata_reset_devices)

int ata_io_start(void *buf, u32 blkcount, u16 feature, u16 nsector, u16 sector,
		u16 lcyl, u16 hcyl, u16 select, u16 command);
#define I_ata_io_start DECLARE_IMPORT(6, ata_io_start)
int ata_io_finish(void);
#define I_ata_io_finish DECLARE_IMPORT(7, ata_io_finish)

int ata_get_error(void);
#define I_ata_get_error DECLARE_IMPORT(8, ata_get_error)

int ata_device_dma_transfer(int device, void *buf, u32 lba, u32 nsectors, int dir);
#define I_ata_device_dma_transfer DECLARE_IMPORT(9, ata_device_dma_transfer)

int ata_device_sec_set_password(int device, void *password);
#define I_ata_device_sec_set_password DECLARE_IMPORT(10, ata_device_sec_set_password)
int ata_device_sec_unlock(int device, void *password);
#define I_ata_device_sec_unlock DECLARE_IMPORT(11, ata_device_sec_unlock)
int ata_device_sec_erase(int device, void *password);
#define I_ata_device_sec_erase DECLARE_IMPORT(12, ata_device_sec_erase)
int ata_device_idle(int device, int period);
#define I_ata_device_idle DECLARE_IMPORT(13, ata_device_idle)
int ata_device_sce_security_init(int device, void *data);
#define I_ata_device_sce_security_init DECLARE_IMPORT(14, ata_device_sce_security_init)
int ata_device_smart_get_status(int device);
#define I_ata_device_smart_get_status DECLARE_IMPORT(15, ata_device_smart_get_status)
int ata_device_smart_save_attr(int device);
#define I_ata_device_smart_save_attr DECLARE_IMPORT(16, ata_device_smart_save_attr)
int ata_device_flush_cache(int device);
#define I_ata_device_flush_cache DECLARE_IMPORT(17, ata_device_flush_cache)
int ata_device_is_sce(int device);
#define I_ata_device_is_sce DECLARE_IMPORT(18, ata_device_is_sce)
int ata_device_is_48bit(int device);
#define I_ata_device_is_48bit DECLARE_IMPORT(19, ata_device_is_48bit)

#endif /* IOP_ATAD_H */
