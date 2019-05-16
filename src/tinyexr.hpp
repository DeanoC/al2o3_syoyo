#pragma once
#ifndef AL2O3_SYOYO_TINYEXR_HPP
#define AL2O3_SYOYO_TINYEXR_HPP

#include "al2o3_platform/platform.h"
#include "al2o3_syoyo/tiny_exr.hpp"

namespace tinyexr {

static const int kEXRVersionSize = 8;

int ParseEXRVersionFromMemory(EXRVersion *version,
                              const unsigned char *memory, size_t size);
int ParseEXRHeaderFromMemory(EXRHeader *exr_header,
                             const EXRVersion *version,
                             const unsigned char *memory, size_t size);
int ParseEXRMultipartHeaderFromMemory(EXRHeader ***exr_headers,
                                      int *num_headers,
                                      const EXRVersion *exr_version,
                                      const unsigned char *memory, size_t size);

int LoadEXRImageFromMemory(EXRImage *exr_image, const EXRHeader *exr_header,
                           const unsigned char *memory, const size_t size);

int LoadEXRMultipartImageFromMemory(EXRImage *exr_images, const EXRHeader **exr_headers, unsigned int num_parts,
                                    const unsigned char *memory, const size_t size);

size_t SaveEXRImageToMemory(const EXRImage *exr_image, const EXRHeader *exr_header, unsigned char **memory_out);

}

#endif //WYRD_SYOYO_TINYEXR_HPP
