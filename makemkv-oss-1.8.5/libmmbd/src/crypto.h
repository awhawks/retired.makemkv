/*
    libMMBD - MakeMKV BD decryption API library

    Copyright (C) 2007-2013 GuinpinSoft inc <libmmbd@makemkv.com>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

*/
#ifndef MMBD_CRYPTO_H_
#define MMBD_CRYPTO_H_

#include <stdint.h>

typedef void (*aes_cbc_d_proc_t)(const uint8_t* key,const uint8_t* iv,uint8_t* data,unsigned int size);

aes_cbc_d_proc_t mmbd_init_aes_cbcd();

#endif // MMBD_CRYPTO_H_
