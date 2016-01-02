/*  =========================================================================
    zarmour - armoured text encoding and decoding

    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of CZMQ, the high-level C binding for 0MQ:
    http://czmq.zeromq.org.

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

#ifndef __ZARMOUR_H_INCLUDED__
#define __ZARMOUR_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

//  @warning THE FOLLOWING @INTERFACE BLOCK IS AUTO-GENERATED BY ZPROJECT!
//  @warning Please edit the model at "api/zarmour.xml" to make changes.
//  @interface
// Enumeration defining different encoding modes
typedef enum {
    ZARMOUR_MODE_BASE64_STD = 0,                            //  Standard base 64
    ZARMOUR_MODE_BASE64_URL = 1,                            //  URL and filename friendly base 64
    ZARMOUR_MODE_BASE32_STD = 2,                            //  Standard base 32
    ZARMOUR_MODE_BASE32_HEX = 3,                            //  Extended hex base 32
    ZARMOUR_MODE_BASE16 = 4,                                //  Standard base 16
    ZARMOUR_MODE_Z85 = 5                                    //  Z85 from ZeroMQ RFC 32
} zarmour_mode_t;

//  Create a new zarmour.
CZMQ_EXPORT zarmour_t *
    zarmour_new (void);

//  Destroy the zarmour.
CZMQ_EXPORT void
    zarmour_destroy (zarmour_t **self_p);

//  Encode a stream of bytes into an armoured string. Returns the armoured
//  string, or NULL if there was insufficient memory available to allocate
//  a new string.                                                         
//  The caller is responsible for destroying the return value when finished with it.
CZMQ_EXPORT char *
    zarmour_encode (zarmour_t *self, const byte *data, size_t size);

//  Decode an armoured string into a string of bytes.          
//  The decoded output is null-terminated, so it may be treated
//  as a string, if that's what it was prior to encoding.      
//  The caller is responsible for destroying the return value when finished with it.
CZMQ_EXPORT byte *
    zarmour_decode (zarmour_t *self, const char *data, size_t *decode_size);

//  Get the mode property.
CZMQ_EXPORT zarmour_mode_t
    zarmour_mode (zarmour_t *self);

//  Get printable string for mode.
CZMQ_EXPORT const char *
    zarmour_mode_str (zarmour_t *self);

//  Set the mode property.
CZMQ_EXPORT void
    zarmour_set_mode (zarmour_t *self, zarmour_mode_t mode);

//  Return true if padding is turned on.
CZMQ_EXPORT bool
    zarmour_pad (zarmour_t *self);

//  Turn padding on or off. Default is on.
CZMQ_EXPORT void
    zarmour_set_pad (zarmour_t *self, bool pad);

//  Get the padding character.
CZMQ_EXPORT char
    zarmour_pad_char (zarmour_t *self);

//  Set the padding character.
CZMQ_EXPORT void
    zarmour_set_pad_char (zarmour_t *self, char pad_char);

//  Return if splitting output into lines is turned on. Default is off.
CZMQ_EXPORT bool
    zarmour_line_breaks (zarmour_t *self);

//  Turn splitting output into lines on or off.
CZMQ_EXPORT void
    zarmour_set_line_breaks (zarmour_t *self, bool line_breaks);

//  Get the line length used for splitting lines.
CZMQ_EXPORT size_t
    zarmour_line_length (zarmour_t *self);

//  Set the line length used for splitting lines.
CZMQ_EXPORT void
    zarmour_set_line_length (zarmour_t *self, size_t line_length);

//  Print properties of object
CZMQ_EXPORT void
    zarmour_print (zarmour_t *self);

//  Self test of this class.
CZMQ_EXPORT void
    zarmour_test (bool verbose);
//  @end

#ifdef __cplusplus
}
#endif

#endif
