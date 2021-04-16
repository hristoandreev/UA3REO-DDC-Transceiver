#ifndef BANDS_H
#define BANDS_H

#include "stm32h7xx_hal.h"
#include <stdio.h>
#include <stdbool.h>

#define BANDS_COUNT 35 // number of bands in the collection

#define BANDID_2200m 0
#define BANDID_160m 3
#define BANDID_80m 6
#define BANDID_60m 10
#define BANDID_40m 12
#define BANDID_30m 15
#define BANDID_20m 18
#define BANDID_17m 21
#define BANDID_15m 23
#define BANDID_12m 25
#define BANDID_CB 27
#define BANDID_10m 28
#define BANDID_6m 29
#define BANDID_FM 30
#define BANDID_2m 32
#define BANDID_Marine 33
#define BANDID_70cm 34

typedef struct // description of the region in the band
{
	const uint32_t startFreq;
	const uint32_t endFreq;
	const uint_fast8_t mode;
} REGION_MAP;

typedef struct // description of the region in the band
{
	const char *name;
	const uint32_t rxFreq;
	const uint32_t txFreq;
} CHANNEL_MAP;

typedef struct // description of the band
{
	const char *name;
	bool selectable;
	const uint32_t startFreq;
	const uint32_t endFreq;
	const REGION_MAP *regions;
	const uint_fast8_t regionsCount;
	const bool channels_clar;
	const CHANNEL_MAP *channels;
	const uint_fast8_t channelsCount;
} BAND_MAP;

// Public variables
extern BAND_MAP BANDS[BANDS_COUNT];

// Public methods
extern uint_fast8_t getModeFromFreq(uint32_t freq);			// mod from frequency
extern int8_t getBandFromFreq(uint32_t freq, bool nearest); // band number from frequency
#endif
