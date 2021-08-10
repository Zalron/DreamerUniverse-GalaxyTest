#pragma once

#include <cstdint>

struct Galaxy 
{
	int16_t size;
	//GalaxyType Galaxytype;
	int16_t year;
};


struct SectorGridCoord
{
	int16_t Xcoord;
	int16_t Ycoord;
	int16_t Zcoord;
};

struct Sector 
{
	uint32_t numStars;
	//sectortype sectortype;
	uint16_t sectorLevel;
};