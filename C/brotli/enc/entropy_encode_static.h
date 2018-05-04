/* Copyright 2015 Google Inc. All Rights Reserved.

   Distributed under MIT license.
   See file LICENSE for detail or copy at https://opensource.org/licenses/MIT
*/

/* Static entropy codes used for faster meta-block encoding. */

#ifndef BROTLI_ENC_ENTROPY_ENCODE_STATIC_H_
#define BROTLI_ENC_ENTROPY_ENCODE_STATIC_H_

#include "../common/constants.h"
#include "../port.h"
#include "../types.h"
#include "./write_bits.h"

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

static const uint8_t kCodeLengthDepth[18] = {
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 0, 4, 4,
};

static const uint8_t kStaticCommandCodeDepth[BROTLI_NUM_COMMAND_SYMBOLS] = {
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
   9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,
  11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
  11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
  11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
  11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
  11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
  11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
  11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
  11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
  11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
  11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
  11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
  11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
  11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
  11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
  11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
  11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
};

static const uint8_t kStaticDistanceCodeDepth[64] = {
  6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
  6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
  6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
  6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
};

static const uint32_t kCodeLengthBits[18] = {
  0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 15, 31, 0, 11, 7,
};

static BROTLI_INLINE void StoreStaticCodeLengthCode(
    size_t* storage_ix, uint8_t* storage) {
  BrotliWriteBits(
      40, BROTLI_MAKE_UINT64_T(0x0000ffU, 0x55555554U), storage_ix, storage);
}

static const uint64_t kZeroRepsBits[BROTLI_NUM_COMMAND_SYMBOLS] = {
  0x00000000, 0x00000000, 0x00000000, 0x00000007, 0x00000017, 0x00000027,
  0x00000037, 0x00000047, 0x00000057, 0x00000067, 0x00000077, 0x00000770,
  0x00000b87, 0x00001387, 0x00001b87, 0x00002387, 0x00002b87, 0x00003387,
  0x00003b87, 0x00000397, 0x00000b97, 0x00001397, 0x00001b97, 0x00002397,
  0x00002b97, 0x00003397, 0x00003b97, 0x000003a7, 0x00000ba7, 0x000013a7,
  0x00001ba7, 0x000023a7, 0x00002ba7, 0x000033a7, 0x00003ba7, 0x000003b7,
  0x00000bb7, 0x000013b7, 0x00001bb7, 0x000023b7, 0x00002bb7, 0x000033b7,
  0x00003bb7, 0x000003c7, 0x00000bc7, 0x000013c7, 0x00001bc7, 0x000023c7,
  0x00002bc7, 0x000033c7, 0x00003bc7, 0x000003d7, 0x00000bd7, 0x000013d7,
  0x00001bd7, 0x000023d7, 0x00002bd7, 0x000033d7, 0x00003bd7, 0x000003e7,
  0x00000be7, 0x000013e7, 0x00001be7, 0x000023e7, 0x00002be7, 0x000033e7,
  0x00003be7, 0x000003f7, 0x00000bf7, 0x000013f7, 0x00001bf7, 0x000023f7,
  0x00002bf7, 0x000033f7, 0x00003bf7, 0x0001c387, 0x0005c387, 0x0009c387,
  0x000dc387, 0x0011c387, 0x0015c387, 0x0019c387, 0x001dc387, 0x0001cb87,
  0x0005cb87, 0x0009cb87, 0x000dcb87, 0x0011cb87, 0x0015cb87, 0x0019cb87,
  0x001dcb87, 0x0001d387, 0x0005d387, 0x0009d387, 0x000dd387, 0x0011d387,
  0x0015d387, 0x0019d387, 0x001dd387, 0x0001db87, 0x0005db87, 0x0009db87,
  0x000ddb87, 0x0011db87, 0x0015db87, 0x0019db87, 0x001ddb87, 0x0001e387,
  0x0005e387, 0x0009e387, 0x000de387, 0x0011e387, 0x0015e387, 0x0019e387,
  0x001de387, 0x0001eb87, 0x0005eb87, 0x0009eb87, 0x000deb87, 0x0011eb87,
  0x0015eb87, 0x0019eb87, 0x001deb87, 0x0001f387, 0x0005f387, 0x0009f387,
  0x000df387, 0x0011f387, 0x0015f387, 0x0019f387, 0x001df387, 0x0001fb87,
  0x0005fb87, 0x0009fb87, 0x000dfb87, 0x0011fb87, 0x0015fb87, 0x0019fb87,
  0x001dfb87, 0x0001c397, 0x0005c397, 0x0009c397, 0x000dc397, 0x0011c397,
  0x0015c397, 0x0019c397, 0x001dc397, 0x0001cb97, 0x0005cb97, 0x0009cb97,
  0x000dcb97, 0x0011cb97, 0x0015cb97, 0x0019cb97, 0x001dcb97, 0x0001d397,
  0x0005d397, 0x0009d397, 0x000dd397, 0x0011d397, 0x0015d397, 0x0019d397,
  0x001dd397, 0x0001db97, 0x0005db97, 0x0009db97, 0x000ddb97, 0x0011db97,
  0x0015db97, 0x0019db97, 0x001ddb97, 0x0001e397, 0x0005e397, 0x0009e397,
  0x000de397, 0x0011e397, 0x0015e397, 0x0019e397, 0x001de397, 0x0001eb97,
  0x0005eb97, 0x0009eb97, 0x000deb97, 0x0011eb97, 0x0015eb97, 0x0019eb97,
  0x001deb97, 0x0001f397, 0x0005f397, 0x0009f397, 0x000df397, 0x0011f397,
  0x0015f397, 0x0019f397, 0x001df397, 0x0001fb97, 0x0005fb97, 0x0009fb97,
  0x000dfb97, 0x0011fb97, 0x0015fb97, 0x0019fb97, 0x001dfb97, 0x0001c3a7,
  0x0005c3a7, 0x0009c3a7, 0x000dc3a7, 0x0011c3a7, 0x0015c3a7, 0x0019c3a7,
  0x001dc3a7, 0x0001cba7, 0x0005cba7, 0x0009cba7, 0x000dcba7, 0x0011cba7,
  0x0015cba7, 0x0019cba7, 0x001dcba7, 0x0001d3a7, 0x0005d3a7, 0x0009d3a7,
  0x000dd3a7, 0x0011d3a7, 0x0015d3a7, 0x0019d3a7, 0x001dd3a7, 0x0001dba7,
  0x0005dba7, 0x0009dba7, 0x000ddba7, 0x0011dba7, 0x0015dba7, 0x0019dba7,
  0x001ddba7, 0x0001e3a7, 0x0005e3a7, 0x0009e3a7, 0x000de3a7, 0x0011e3a7,
  0x0015e3a7, 0x0019e3a7, 0x001de3a7, 0x0001eba7, 0x0005eba7, 0x0009eba7,
  0x000deba7, 0x0011eba7, 0x0015eba7, 0x0019eba7, 0x001deba7, 0x0001f3a7,
  0x0005f3a7, 0x0009f3a7, 0x000df3a7, 0x0011f3a7, 0x0015f3a7, 0x0019f3a7,
  0x001df3a7, 0x0001fba7, 0x0005fba7, 0x0009fba7, 0x000dfba7, 0x0011fba7,
  0x0015fba7, 0x0019fba7, 0x001dfba7, 0x0001c3b7, 0x0005c3b7, 0x0009c3b7,
  0x000dc3b7, 0x0011c3b7, 0x0015c3b7, 0x0019c3b7, 0x001dc3b7, 0x0001cbb7,
  0x0005cbb7, 0x0009cbb7, 0x000dcbb7, 0x0011cbb7, 0x0015cbb7, 0x0019cbb7,
  0x001dcbb7, 0x0001d3b7, 0x0005d3b7, 0x0009d3b7, 0x000dd3b7, 0x0011d3b7,
  0x0015d3b7, 0x0019d3b7, 0x001dd3b7, 0x0001dbb7, 0x0005dbb7, 0x0009dbb7,
  0x000ddbb7, 0x0011dbb7, 0x0015dbb7, 0x0019dbb7, 0x001ddbb7, 0x0001e3b7,
  0x0005e3b7, 0x0009e3b7, 0x000de3b7, 0x0011e3b7, 0x0015e3b7, 0x0019e3b7,
  0x001de3b7, 0x0001ebb7, 0x0005ebb7, 0x0009ebb7, 0x000debb7, 0x0011ebb7,
  0x0015ebb7, 0x0019ebb7, 0x001debb7, 0x0001f3b7, 0x0005f3b7, 0x0009f3b7,
  0x000df3b7, 0x0011f3b7, 0x0015f3b7, 0x0019f3b7, 0x001df3b7, 0x0001fbb7,
  0x0005fbb7, 0x0009fbb7, 0x000dfbb7, 0x0011fbb7, 0x0015fbb7, 0x0019fbb7,
  0x001dfbb7, 0x0001c3c7, 0x0005c3c7, 0x0009c3c7, 0x000dc3c7, 0x0011c3c7,
  0x0015c3c7, 0x0019c3c7, 0x001dc3c7, 0x0001cbc7, 0x0005cbc7, 0x0009cbc7,
  0x000dcbc7, 0x0011cbc7, 0x0015cbc7, 0x0019cbc7, 0x001dcbc7, 0x0001d3c7,
  0x0005d3c7, 0x0009d3c7, 0x000dd3c7, 0x0011d3c7, 0x0015d3c7, 0x0019d3c7,
  0x001dd3c7, 0x0001dbc7, 0x0005dbc7, 0x0009dbc7, 0x000ddbc7, 0x0011dbc7,
  0x0015dbc7, 0x0019dbc7, 0x001ddbc7, 0x0001e3c7, 0x0005e3c7, 0x0009e3c7,
  0x000de3c7, 0x0011e3c7, 0x0015e3c7, 0x0019e3c7, 0x001de3c7, 0x0001ebc7,
  0x0005ebc7, 0x0009ebc7, 0x000debc7, 0x0011ebc7, 0x0015ebc7, 0x0019ebc7,
  0x001debc7, 0x0001f3c7, 0x0005f3c7, 0x0009f3c7, 0x000df3c7, 0x0011f3c7,
  0x0015f3c7, 0x0019f3c7, 0x001df3c7, 0x0001fbc7, 0x0005fbc7, 0x0009fbc7,
  0x000dfbc7, 0x0011fbc7, 0x0015fbc7, 0x0019fbc7, 0x001dfbc7, 0x0001c3d7,
  0x0005c3d7, 0x0009c3d7, 0x000dc3d7, 0x0011c3d7, 0x0015c3d7, 0x0019c3d7,
  0x001dc3d7, 0x0001cbd7, 0x0005cbd7, 0x0009cbd7, 0x000dcbd7, 0x0011cbd7,
  0x0015cbd7, 0x0019cbd7, 0x001dcbd7, 0x0001d3d7, 0x0005d3d7, 0x0009d3d7,
  0x000dd3d7, 0x0011d3d7, 0x0015d3d7, 0x0019d3d7, 0x001dd3d7, 0x0001dbd7,
  0x0005dbd7, 0x0009dbd7, 0x000ddbd7, 0x0011dbd7, 0x0015dbd7, 0x0019dbd7,
  0x001ddbd7, 0x0001e3d7, 0x0005e3d7, 0x0009e3d7, 0x000de3d7, 0x0011e3d7,
  0x0015e3d7, 0x0019e3d7, 0x001de3d7, 0x0001ebd7, 0x0005ebd7, 0x0009ebd7,
  0x000debd7, 0x0011ebd7, 0x0015ebd7, 0x0019ebd7, 0x001debd7, 0x0001f3d7,
  0x0005f3d7, 0x0009f3d7, 0x000df3d7, 0x0011f3d7, 0x0015f3d7, 0x0019f3d7,
  0x001df3d7, 0x0001fbd7, 0x0005fbd7, 0x0009fbd7, 0x000dfbd7, 0x0011fbd7,
  0x0015fbd7, 0x0019fbd7, 0x001dfbd7, 0x0001c3e7, 0x0005c3e7, 0x0009c3e7,
  0x000dc3e7, 0x0011c3e7, 0x0015c3e7, 0x0019c3e7, 0x001dc3e7, 0x0001cbe7,
  0x0005cbe7, 0x0009cbe7, 0x000dcbe7, 0x0011cbe7, 0x0015cbe7, 0x0019cbe7,
  0x001dcbe7, 0x0001d3e7, 0x0005d3e7, 0x0009d3e7, 0x000dd3e7, 0x0011d3e7,
  0x0015d3e7, 0x0019d3e7, 0x001dd3e7, 0x0001dbe7, 0x0005dbe7, 0x0009dbe7,
  0x000ddbe7, 0x0011dbe7, 0x0015dbe7, 0x0019dbe7, 0x001ddbe7, 0x0001e3e7,
  0x0005e3e7, 0x0009e3e7, 0x000de3e7, 0x0011e3e7, 0x0015e3e7, 0x0019e3e7,
  0x001de3e7, 0x0001ebe7, 0x0005ebe7, 0x0009ebe7, 0x000debe7, 0x0011ebe7,
  0x0015ebe7, 0x0019ebe7, 0x001debe7, 0x0001f3e7, 0x0005f3e7, 0x0009f3e7,
  0x000df3e7, 0x0011f3e7, 0x0015f3e7, 0x0019f3e7, 0x001df3e7, 0x0001fbe7,
  0x0005fbe7, 0x0009fbe7, 0x000dfbe7, 0x0011fbe7, 0x0015fbe7, 0x0019fbe7,
  0x001dfbe7, 0x0001c3f7, 0x0005c3f7, 0x0009c3f7, 0x000dc3f7, 0x0011c3f7,
  0x0015c3f7, 0x0019c3f7, 0x001dc3f7, 0x0001cbf7, 0x0005cbf7, 0x0009cbf7,
  0x000dcbf7, 0x0011cbf7, 0x0015cbf7, 0x0019cbf7, 0x001dcbf7, 0x0001d3f7,
  0x0005d3f7, 0x0009d3f7, 0x000dd3f7, 0x0011d3f7, 0x0015d3f7, 0x0019d3f7,
  0x001dd3f7, 0x0001dbf7, 0x0005dbf7, 0x0009dbf7, 0x000ddbf7, 0x0011dbf7,
  0x0015dbf7, 0x0019dbf7, 0x001ddbf7, 0x0001e3f7, 0x0005e3f7, 0x0009e3f7,
  0x000de3f7, 0x0011e3f7, 0x0015e3f7, 0x0019e3f7, 0x001de3f7, 0x0001ebf7,
  0x0005ebf7, 0x0009ebf7, 0x000debf7, 0x0011ebf7, 0x0015ebf7, 0x0019ebf7,
  0x001debf7, 0x0001f3f7, 0x0005f3f7, 0x0009f3f7, 0x000df3f7, 0x0011f3f7,
  0x0015f3f7, 0x0019f3f7, 0x001df3f7, 0x0001fbf7, 0x0005fbf7, 0x0009fbf7,
  0x000dfbf7, 0x0011fbf7, 0x0015fbf7, 0x0019fbf7, 0x001dfbf7, 0x00e1c387,
  0x02e1c387, 0x04e1c387, 0x06e1c387, 0x08e1c387, 0x0ae1c387, 0x0ce1c387,
  0x0ee1c387, 0x00e5c387, 0x02e5c387, 0x04e5c387, 0x06e5c387, 0x08e5c387,
  0x0ae5c387, 0x0ce5c387, 0x0ee5c387, 0x00e9c387, 0x02e9c387, 0x04e9c387,
  0x06e9c387, 0x08e9c387, 0x0ae9c387, 0x0ce9c387, 0x0ee9c387, 0x00edc387,
  0x02edc387, 0x04edc387, 0x06edc387, 0x08edc387, 0x0aedc387, 0x0cedc387,
  0x0eedc387, 0x00f1c387, 0x02f1c387, 0x04f1c387, 0x06f1c387, 0x08f1c387,
  0x0af1c387, 0x0cf1c387, 0x0ef1c387, 0x00f5c387, 0x02f5c387, 0x04f5c387,
  0x06f5c387, 0x08f5c387, 0x0af5c387, 0x0cf5c387, 0x0ef5c387, 0x00f9c387,
  0x02f9c387, 0x04f9c387, 0x06f9c387, 0x08f9c387, 0x0af9c387, 0x0cf9c387,
  0x0ef9c387, 0x00fdc387, 0x02fdc387, 0x04fdc387, 0x06fdc387, 0x08fdc387,
  0x0afdc387, 0x0cfdc387, 0x0efdc387, 0x00e1cb87, 0x02e1cb87, 0x04e1cb87,
  0x06e1cb87, 0x08e1cb87, 0x0ae1cb87, 0x0ce1cb87, 0x0ee1cb87, 0x00e5cb87,
  0x02e5cb87, 0x04e5cb87, 0x06e5cb87, 0x08e5cb87, 0x0ae5cb87, 0x0ce5cb87,
  0x0ee5cb87, 0x00e9cb87, 0x02e9cb87, 0x04e9cb87, 0x06e9cb87, 0x08e9cb87,
  0x0ae9cb87, 0x0ce9cb87, 0x0ee9cb87, 0x00edcb87, 0x02edcb87, 0x04edcb87,
  0x06edcb87, 0x08edcb87, 0x0aedcb87, 0x0cedcb87, 0x0eedcb87, 0x00f1cb87,
  0x02f1cb87, 0x04f1cb87, 0x06f1cb87, 0x08f1cb87, 0x0af1cb87, 0x0cf1cb87,
  0x0ef1cb87, 0x00f5cb87, 0x02f5cb87, 0x04f5cb87, 0x06f5cb87, 0x08f5cb87,
  0x0af5cb87, 0x0cf5cb87, 0x0ef5cb87, 0x00f9cb87, 0x02f9cb87, 0x04f9cb87,
  0x06f9cb87, 0x08f9cb87,
};

static const uint32_t kZeroRepsDepth[BROTLI_NUM_COMMAND_SYMBOLS] = {
   0,  4,  8,  7,  7,  7,  7,  7,  7,  7,  7, 11, 14, 14, 14, 14,
  14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
  14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
  14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
  14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
  21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 28, 28, 28, 28, 28,
  28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
  28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
  28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
  28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
  28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
  28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
  28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
};

static const uint64_t kNonZeroRepsBits[BROTLI_NUM_COMMAND_SYMBOLS] = {
  0x0000000b, 0x0000001b, 0x0000002b, 0x0000003b, 0x000002cb, 0x000006cb,
  0x00000acb, 0x00000ecb, 0x000002db, 0x000006db, 0x00000adb, 0x00000edb,
  0x000002eb, 0x000006eb, 0x00000aeb, 0x00000eeb, 0x000002fb, 0x000006fb,
  0x00000afb, 0x00000efb, 0x0000b2cb, 0x0001b2cb, 0x0002b2cb, 0x0003b2cb,
  0x0000b6cb, 0x0001b6cb, 0x0002b6cb, 0x0003b6cb, 0x0000bacb, 0x0001bacb,
  0x0002bacb, 0x0003bacb, 0x0000becb, 0x0001becb, 0x0002becb, 0x0003becb,
  0x0000b2db, 0x0001b2db, 0x0002b2db, 0x0003b2db, 0x0000b6db, 0x0001b6db,
  0x0002b6db, 0x0003b6db, 0x0000badb, 0x0001badb, 0x0002badb, 0x0003badb,
  0x0000bedb, 0x0001bedb, 0x0002bedb, 0x0003bedb, 0x0000b2eb, 0x0001b2eb,
  0x0002b2eb, 0x0003b2eb, 0x0000b6eb, 0x0001b6eb, 0x0002b6eb, 0x0003b6eb,
  0x0000baeb, 0x0001baeb, 0x0002baeb, 0x0003baeb, 0x0000beeb, 0x0001beeb,
  0x0002beeb, 0x0003beeb, 0x0000b2fb, 0x0001b2fb, 0x0002b2fb, 0x0003b2fb,
  0x0000b6fb, 0x0001b6fb, 0x0002b6fb, 0x0003b6fb, 0x0000bafb, 0x0001bafb,
  0x0002bafb, 0x0003bafb, 0x0000befb, 0x0001befb, 0x0002befb, 0x0003befb,
  0x002cb2cb, 0x006cb2cb, 0x00acb2cb, 0x00ecb2cb, 0x002db2cb, 0x006db2cb,
  0x00adb2cb, 0x00edb2cb, 0x002eb2cb, 0x006eb2cb, 0x00aeb2cb, 0x00eeb2cb,
  0x002fb2cb, 0x006fb2cb, 0x00afb2cb, 0x00efb2cb, 0x002cb6cb, 0x006cb6cb,
  0x00acb6cb, 0x00ecb6cb, 0x002db6cb, 0x006db6cb, 0x00adb6cb, 0x00edb6cb,
  0x002eb6cb, 0x006eb6cb, 0x00aeb6cb, 0x00eeb6cb, 0x002fb6cb, 0x006fb6cb,
  0x00afb6cb, 0x00efb6cb, 0x002cbacb, 0x006cbacb, 0x00acbacb, 0x00ecbacb,
  0x002dbacb, 0x006dbacb, 0x00adbacb, 0x00edbacb, 0x002ebacb, 0x006ebacb,
  0x00aebacb, 0x00eebacb, 0x002fbacb, 0x006fbacb, 0x00afbacb, 0x00efbacb,
  0x002cbecb, 0x006cbecb, 0x00acbecb, 0x00ecbecb, 0x002dbecb, 0x006dbecb,
  0x00adbecb, 0x00edbecb, 0x002ebecb, 0x006ebecb, 0x00aebecb, 0x00eebecb,
  0x002fbecb, 0x006fbecb, 0x00afbecb, 0x00efbecb, 0x002cb2db, 0x006cb2db,
  0x00acb2db, 0x00ecb2db, 0x002db2db, 0x006db2db, 0x00adb2db, 0x00edb2db,
  0x002eb2db, 0x006eb2db, 0x00aeb2db, 0x00eeb2db, 0x002fb2db, 0x006fb2db,
  0x00afb2db, 0x00efb2db, 0x002cb6db, 0x006cb6db, 0x00acb6db, 0x00ecb6db,
  0x002db6db, 0x006db6db, 0x00adb6db, 0x00edb6db, 0x002eb6db, 0x006eb6db,
  0x00aeb6db, 0x00eeb6db, 0x002fb6db, 0x006fb6db, 0x00afb6db, 0x00efb6db,
  0x002cbadb, 0x006cbadb, 0x00acbadb, 0x00ecbadb, 0x002dbadb, 0x006dbadb,
  0x00adbadb, 0x00edbadb, 0x002ebadb, 0x006ebadb, 0x00aebadb, 0x00eebadb,
  0x002fbadb, 0x006fbadb, 0x00afbadb, 0x00efbadb, 0x002cbedb, 0x006cbedb,
  0x00acbedb, 0x00ecbedb, 0x002dbedb, 0x006dbedb, 0x00adbedb, 0x00edbedb,
  0x002ebedb, 0x006ebedb, 0x00aebedb, 0x00eebedb, 0x002fbedb, 0x006fbedb,
  0x00afbedb, 0x00efbedb, 0x002cb2eb, 0x006cb2eb, 0x00acb2eb, 0x00ecb2eb,
  0x002db2eb, 0x006db2eb, 0x00adb2eb, 0x00edb2eb, 0x002eb2eb, 0x006eb2eb,
  0x00aeb2eb, 0x00eeb2eb, 0x002fb2eb, 0x006fb2eb, 0x00afb2eb, 0x00efb2eb,
  0x002cb6eb, 0x006cb6eb, 0x00acb6eb, 0x00ecb6eb, 0x002db6eb, 0x006db6eb,
  0x00adb6eb, 0x00edb6eb, 0x002eb6eb, 0x006eb6eb, 0x00aeb6eb, 0x00eeb6eb,
  0x002fb6eb, 0x006fb6eb, 0x00afb6eb, 0x00efb6eb, 0x002cbaeb, 0x006cbaeb,
  0x00acbaeb, 0x00ecbaeb, 0x002dbaeb, 0x006dbaeb, 0x00adbaeb, 0x00edbaeb,
  0x002ebaeb, 0x006ebaeb, 0x00aebaeb, 0x00eebaeb, 0x002fbaeb, 0x006fbaeb,
  0x00afbaeb, 0x00efbaeb, 0x002cbeeb, 0x006cbeeb, 0x00acbeeb, 0x00ecbeeb,
  0x002dbeeb, 0x006dbeeb, 0x00adbeeb, 0x00edbeeb, 0x002ebeeb, 0x006ebeeb,
  0x00aebeeb, 0x00eebeeb, 0x002fbeeb, 0x006fbeeb, 0x00afbeeb, 0x00efbeeb,
  0x002cb2fb, 0x006cb2fb, 0x00acb2fb, 0x00ecb2fb, 0x002db2fb, 0x006db2fb,
  0x00adb2fb, 0x00edb2fb, 0x002eb2fb, 0x006eb2fb, 0x00aeb2fb, 0x00eeb2fb,
  0x002fb2fb, 0x006fb2fb, 0x00afb2fb, 0x00efb2fb, 0x002cb6fb, 0x006cb6fb,
  0x00acb6fb, 0x00ecb6fb, 0x002db6fb, 0x006db6fb, 0x00adb6fb, 0x00edb6fb,
  0x002eb6fb, 0x006eb6fb, 0x00aeb6fb, 0x00eeb6fb, 0x002fb6fb, 0x006fb6fb,
  0x00afb6fb, 0x00efb6fb, 0x002cbafb, 0x006cbafb, 0x00acbafb, 0x00ecbafb,
  0x002dbafb, 0x006dbafb, 0x00adbafb, 0x00edbafb, 0x002ebafb, 0x006ebafb,
  0x00aebafb, 0x00eebafb, 0x002fbafb, 0x006fbafb, 0x00afbafb, 0x00efbafb,
  0x002cbefb, 0x006cbefb, 0x00acbefb, 0x00ecbefb, 0x002dbefb, 0x006dbefb,
  0x00adbefb, 0x00edbefb, 0x002ebefb, 0x006ebefb, 0x00aebefb, 0x00eebefb,
  0x002fbefb, 0x006fbefb, 0x00afbefb, 0x00efbefb, 0x0b2cb2cb, 0x1b2cb2cb,
  0x2b2cb2cb, 0x3b2cb2cb, 0x0b6cb2cb, 0x1b6cb2cb, 0x2b6cb2cb, 0x3b6cb2cb,
  0x0bacb2cb, 0x1bacb2cb, 0x2bacb2cb, 0x3bacb2cb, 0x0becb2cb, 0x1becb2cb,
  0x2becb2cb, 0x3becb2cb, 0x0b2db2cb, 0x1b2db2cb, 0x2b2db2cb, 0x3b2db2cb,
  0x0b6db2cb, 0x1b6db2cb, 0x2b6db2cb, 0x3b6db2cb, 0x0badb2cb, 0x1badb2cb,
  0x2badb2cb, 0x3badb2cb, 0x0bedb2cb, 0x1bedb2cb, 0x2bedb2cb, 0x3bedb2cb,
  0x0b2eb2cb, 0x1b2eb2cb, 0x2b2eb2cb, 0x3b2eb2cb, 0x0b6eb2cb, 0x1b6eb2cb,
  0x2b6eb2cb, 0x3b6eb2cb, 0x0baeb2cb, 0x1baeb2cb, 0x2baeb2cb, 0x3baeb2cb,
  0x0beeb2cb, 0x1beeb2cb, 0x2beeb2cb, 0x3beeb2cb, 0x0b2fb2cb, 0x1b2fb2cb,
  0x2b2fb2cb, 0x3b2fb2cb, 0x0b6fb2cb, 0x1b6fb2cb, 0x2b6fb2cb, 0x3b6fb2cb,
  0x0bafb2cb, 0x1bafb2cb, 0x2bafb2cb, 0x3bafb2cb, 0x0befb2cb, 0x1befb2cb,
  0x2befb2cb, 0x3befb2cb, 0x0b2cb6cb, 0x1b2cb6cb, 0x2b2cb6cb, 0x3b2cb6cb,
  0x0b6cb6cb, 0x1b6cb6cb, 0x2b6cb6cb, 0x3b6cb6cb, 0x0bacb6cb, 0x1bacb6cb,
  0x2bacb6cb, 0x3bacb6cb, 0x0becb6cb, 0x1becb6cb, 0x2becb6cb, 0x3becb6cb,
  0x0b2db6cb, 0x1b2db6cb, 0x2b2db6cb, 0x3b2db6cb, 0x0b6db6cb, 0x1b6db6cb,
  0x2b6db6cb, 0x3b6db6cb, 0x0badb6cb, 0x1badb6cb, 0x2badb6cb, 0x3badb6cb,
  0x0bedb6cb, 0x1bedb6cb, 0x2bedb6cb, 0x3bedb6cb, 0x0b2eb6cb, 0x1b2eb6cb,
  0x2b2eb6cb, 0x3b2eb6cb, 0x0b6eb6cb, 0x1b6eb6cb, 0x2b6eb6cb, 0x3b6eb6cb,
  0x0baeb6cb, 0x1baeb6cb, 0x2baeb6cb, 0x3baeb6cb, 0x0beeb6cb, 0x1beeb6cb,
  0x2beeb6cb, 0x3beeb6cb, 0x0b2fb6cb, 0x1b2fb6cb, 0x2b2fb6cb, 0x3b2fb6cb,
  0x0b6fb6cb, 0x1b6fb6cb, 0x2b6fb6cb, 0x3b6fb6cb, 0x0bafb6cb, 0x1bafb6cb,
  0x2bafb6cb, 0x3bafb6cb, 0x0befb6cb, 0x1befb6cb, 0x2befb6cb, 0x3befb6cb,
  0x0b2cbacb, 0x1b2cbacb, 0x2b2cbacb, 0x3b2cbacb, 0x0b6cbacb, 0x1b6cbacb,
  0x2b6cbacb, 0x3b6cbacb, 0x0bacbacb, 0x1bacbacb, 0x2bacbacb, 0x3bacbacb,
  0x0becbacb, 0x1becbacb, 0x2becbacb, 0x3becbacb, 0x0b2dbacb, 0x1b2dbacb,
  0x2b2dbacb, 0x3b2dbacb, 0x0b6dbacb, 0x1b6dbacb, 0x2b6dbacb, 0x3b6dbacb,
  0x0badbacb, 0x1badbacb, 0x2badbacb, 0x3badbacb, 0x0bedbacb, 0x1bedbacb,
  0x2bedbacb, 0x3bedbacb, 0x0b2ebacb, 0x1b2ebacb, 0x2b2ebacb, 0x3b2ebacb,
  0x0b6ebacb, 0x1b6ebacb, 0x2b6ebacb, 0x3b6ebacb, 0x0baebacb, 0x1baebacb,
  0x2baebacb, 0x3baebacb, 0x0beebacb, 0x1beebacb, 0x2beebacb, 0x3beebacb,
  0x0b2fbacb, 0x1b2fbacb, 0x2b2fbacb, 0x3b2fbacb, 0x0b6fbacb, 0x1b6fbacb,
  0x2b6fbacb, 0x3b6fbacb, 0x0bafbacb, 0x1bafbacb, 0x2bafbacb, 0x3bafbacb,
  0x0befbacb, 0x1befbacb, 0x2befbacb, 0x3befbacb, 0x0b2cbecb, 0x1b2cbecb,
  0x2b2cbecb, 0x3b2cbecb, 0x0b6cbecb, 0x1b6cbecb, 0x2b6cbecb, 0x3b6cbecb,
  0x0bacbecb, 0x1bacbecb, 0x2bacbecb, 0x3bacbecb, 0x0becbecb, 0x1becbecb,
  0x2becbecb, 0x3becbecb, 0x0b2dbecb, 0x1b2dbecb, 0x2b2dbecb, 0x3b2dbecb,
  0x0b6dbecb, 0x1b6dbecb, 0x2b6dbecb, 0x3b6dbecb, 0x0badbecb, 0x1badbecb,
  0x2badbecb, 0x3badbecb, 0x0bedbecb, 0x1bedbecb, 0x2bedbecb, 0x3bedbecb,
  0x0b2ebecb, 0x1b2ebecb, 0x2b2ebecb, 0x3b2ebecb, 0x0b6ebecb, 0x1b6ebecb,
  0x2b6ebecb, 0x3b6ebecb, 0x0baebecb, 0x1baebecb, 0x2baebecb, 0x3baebecb,
  0x0beebecb, 0x1beebecb, 0x2beebecb, 0x3beebecb, 0x0b2fbecb, 0x1b2fbecb,
  0x2b2fbecb, 0x3b2fbecb, 0x0b6fbecb, 0x1b6fbecb, 0x2b6fbecb, 0x3b6fbecb,
  0x0bafbecb, 0x1bafbecb, 0x2bafbecb, 0x3bafbecb, 0x0befbecb, 0x1befbecb,
  0x2befbecb, 0x3befbecb, 0x0b2cb2db, 0x1b2cb2db, 0x2b2cb2db, 0x3b2cb2db,
  0x0b6cb2db, 0x1b6cb2db, 0x2b6cb2db, 0x3b6cb2db, 0x0bacb2db, 0x1bacb2db,
  0x2bacb2db, 0x3bacb2db, 0x0becb2db, 0x1becb2db, 0x2becb2db, 0x3becb2db,
  0x0b2db2db, 0x1b2db2db, 0x2b2db2db, 0x3b2db2db, 0x0b6db2db, 0x1b6db2db,
  0x2b6db2db, 0x3b6db2db, 0x0badb2db, 0x1badb2db, 0x2badb2db, 0x3badb2db,
  0x0bedb2db, 0x1bedb2db, 0x2bedb2db, 0x3bedb2db, 0x0b2eb2db, 0x1b2eb2db,
  0x2b2eb2db, 0x3b2eb2db, 0x0b6eb2db, 0x1b6eb2db, 0x2b6eb2db, 0x3b6eb2db,
  0x0baeb2db, 0x1baeb2db, 0x2baeb2db, 0x3baeb2db, 0x0beeb2db, 0x1beeb2db,
  0x2beeb2db, 0x3beeb2db, 0x0b2fb2db, 0x1b2fb2db, 0x2b2fb2db, 0x3b2fb2db,
  0x0b6fb2db, 0x1b6fb2db, 0x2b6fb2db, 0x3b6fb2db, 0x0bafb2db, 0x1bafb2db,
  0x2bafb2db, 0x3bafb2db, 0x0befb2db, 0x1befb2db, 0x2befb2db, 0x3befb2db,
  0x0b2cb6db, 0x1b2cb6db, 0x2b2cb6db, 0x3b2cb6db, 0x0b6cb6db, 0x1b6cb6db,
  0x2b6cb6db, 0x3b6cb6db, 0x0bacb6db, 0x1bacb6db, 0x2bacb6db, 0x3bacb6db,
  0x0becb6db, 0x1becb6db, 0x2becb6db, 0x3becb6db, 0x0b2db6db, 0x1b2db6db,
  0x2b2db6db, 0x3b2db6db, 0x0b6db6db, 0x1b6db6db, 0x2b6db6db, 0x3b6db6db,
  0x0badb6db, 0x1badb6db, 0x2badb6db, 0x3badb6db, 0x0bedb6db, 0x1bedb6db,
  0x2bedb6db, 0x3bedb6db, 0x0b2eb6db, 0x1b2eb6db, 0x2b2eb6db, 0x3b2eb6db,
  0x0b6eb6db, 0x1b6eb6db, 0x2b6eb6db, 0x3b6eb6db, 0x0baeb6db, 0x1baeb6db,
  0x2baeb6db, 0x3baeb6db,
};

static const uint32_t kNonZeroRepsDepth[BROTLI_NUM_COMMAND_SYMBOLS] = {
   6,  6,  6,  6, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
  12, 12, 12, 12, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
  18, 18, 18, 18, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
  24, 24, 24, 24, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
  30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
  30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
  30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
  30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
  30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
  30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
  30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
  30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
  30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
  30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
  30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
  30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
  30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
  30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
  30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
  30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
  30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
  30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
  30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
  30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
  30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
  30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
};

static const uint16_t kStaticCommandCodeBits[BROTLI_NUM_COMMAND_SYMBOLS] = {
    0,  256,  128,  384,   64,  320,  192,  448,
   32,  288,  160,  416,   96,  352,  224,  480,
   16,  272,  144,  400,   80,  336,  208,  464,
   48,  304,  176,  432,  112,  368,  240,  496,
    8,  264,  136,  392,   72,  328,  200,  456,
   40,  296,  168,  424,  104,  360,  232,  488,
   24,  280,  152,  408,   88,  344,  216,  472,
   56,  312,  184,  440,  120,  376,  248,  504,
    4,  260,  132,  388,   68,  324,  196,  452,
   36,  292,  164,  420,  100,  356,  228,  484,
   20,  276,  148,  404,   84,  340,  212,  468,
   52,  308,  180,  436,  116,  372,  244,  500,
   12,  268,  140,  396,   76,  332,  204,  460,
   44,  300,  172,  428,  108,  364,  236,  492,
   28,  284,  156,  412,   92,  348,  220,  476,
   60,  316,  188,  444,  124,  380,  252,  508,
    2,  258,  130,  386,   66,  322,  194,  450,
   34,  290,  162,  418,   98,  354,  226,  482,
   18,  274,  146,  402,   82,  338,  210,  466,
   50,  306,  178,  434,  114,  370,  242,  498,
   10,  266,  138,  394,   74,  330,  202,  458,
   42,  298,  170,  426,  106,  362,  234,  490,
   26,  282,  154,  410,   90,  346,  218,  474,
   58,  314,  186,  442,  122,  378,  250,  506,
    6,  262,  134,  390,   70,  326,  198,  454,
   38,  294,  166,  422,  102,  358,  230,  486,
   22,  278,  150,  406,   86,  342,  214,  470,
   54,  310,  182,  438,  118,  374,  246,  502,
   14,  270,  142,  398,   78,  334,  206,  462,
   46,  302,  174,  430,  110,  366,  238,  494,
   30,  286,  158,  414,   94,  350,  222,  478,
   62,  318,  190,  446,  126,  382,  254,  510,
    1,  257,  129,  385,   65,  321,  193,  449,
   33,  289,  161,  417,   97,  353,  225,  481,
   17,  273,  145,  401,   81,  337,  209,  465,
   49,  305,  177,  433,  113,  369,  241,  497,
    9,  265,  137,  393,   73,  329,  201,  457,
   41,  297,  169,  425,  105,  361,  233,  489,
   25,  281,  153,  409,   89,  345,  217,  473,
   57,  313,  185,  441,  121,  377,  249,  505,
    5,  261,  133,  389,   69,  325,  197,  453,
   37,  293,  165,  421,  101,  357,  229,  485,
   21,  277,  149,  405,   85,  341,  213,  469,
   53,  309,  181,  437,  117,  373,  245,  501,
   13,  269,  141,  397,   77,  333,  205,  461,
   45,  301,  173,  429,  109,  365,  237,  493,
   29,  285,  157,  413,   93,  349,  221,  477,
   61,  317,  189,  445,  125,  381,  253,  509,
    3,  259,  131,  387,   67,  323,  195,  451,
   35,  291,  163,  419,   99,  355,  227,  483,
   19,  275,  147,  403,   83,  339,  211,  467,
   51,  307,  179,  435,  115,  371,  243,  499,
   11,  267,  139,  395,   75,  331,  203,  459,
   43,  299,  171,  427,  107,  363,  235,  491,
   27,  283,  155,  411,   91,  347,  219,  475,
   59,  315,  187,  443,  123,  379,  251,  507,
    7, 1031,  519, 1543,  263, 1287,  775, 1799,
  135, 1159,  647, 1671,  391, 1415,  903, 1927,
   71, 1095,  583, 1607,  327, 1351,  839, 1863,
  199, 1223,  711, 1735,  455, 1479,  967, 1991,
   39, 1063,  551, 1575,  295, 1319,  807, 1831,
  167, 1191,  679, 1703,  423, 1447,  935, 1959,
  103, 1127,  615, 1639,  359, 1383,  871, 1895,
  231, 1255,  743, 1767,  487, 1511,  999, 2023,
   23, 1047,  535, 1559,  279, 1303,  791, 1815,
  151, 1175,  663, 1687,  407, 1431,  919, 1943,
   87, 1111,  599, 1623,  343, 1367,  855, 1879,
  215, 1239,  727, 1751,  471, 1495,  983, 2007,
   55, 1079,  567, 1591,  311, 1335,  823, 1847,
  183, 1207,  695, 1719,  439, 1463,  951, 1975,
  119, 1143,  631, 1655,  375, 1399,  887, 1911,
  247, 1271,  759, 1783,  503, 1527, 1015, 2039,
   15, 1039,  527, 1551,  271, 1295,  783, 1807,
  143, 1167,  655, 1679,  399, 1423,  911, 1935,
   79, 1103,  591, 1615,  335, 1359,  847, 1871,
  207, 1231,  719, 1743,  463, 1487,  975, 1999,
   47, 1071,  559, 1583,  303, 1327,  815, 1839,
  175, 1199,  687, 1711,  431, 1455,  943, 1967,
  111, 1135,  623, 1647,  367, 1391,  879, 1903,
  239, 1263,  751, 1775,  495, 1519, 1007, 2031,
   31, 1055,  543, 1567,  287, 1311,  799, 1823,
  159, 1183,  671, 1695,  415, 1439,  927, 1951,
   95, 1119,  607, 1631,  351, 1375,  863, 1887,
  223, 1247,  735, 1759,  479, 1503,  991, 2015,
   63, 1087,  575, 1599,  319, 1343,  831, 1855,
  191, 1215,  703, 1727,  447, 1471,  959, 1983,
  127, 1151,  639, 1663,  383, 1407,  895, 1919,
  255, 1279,  767, 1791,  511, 1535, 1023, 2047,
};

static BROTLI_INLINE void StoreStaticCommandHuffmanTree(
    size_t* storage_ix, uint8_t* storage) {
  BrotliWriteBits(
      56, BROTLI_MAKE_UINT64_T(0x926244U, 0x16307003U), storage_ix, storage);
  BrotliWriteBits(3, 0x00000000U, storage_ix, storage);
}

static const uint16_t kStaticDistanceCodeBits[64] = {
   0, 32, 16, 48,  8, 40, 24, 56,  4, 36, 20, 52, 12, 44, 28, 60,
   2, 34, 18, 50, 10, 42, 26, 58,  6, 38, 22, 54, 14, 46, 30, 62,
   1, 33, 17, 49,  9, 41, 25, 57,  5, 37, 21, 53, 13, 45, 29, 61,
   3, 35, 19, 51, 11, 43, 27, 59,  7, 39, 23, 55, 15, 47, 31, 63,
};

static BROTLI_INLINE void StoreStaticDistanceHuffmanTree(
    size_t* storage_ix, uint8_t* storage) {
  BrotliWriteBits(28, 0x0369dc03U, storage_ix, storage);
}

#if defined(__cplusplus) || defined(c_plusplus)
}  /* extern "C" */
#endif

#endif  /* BROTLI_ENC_ENTROPY_ENCODE_STATIC_H_ */
