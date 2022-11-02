#ifndef IMAGE_H_
#define IMAGE_H_

#include <stdint.h>

typedef struct {
    const uint16_t *data;
    uint16_t width;
    uint16_t height;
    uint8_t dataSize;
} tImage;

#endif
