#pragma once

#include <cstdint>

#include "flecs.h"

struct GalaxyComponents 
{
	GalaxyComponents(flecs::world& world)
	{
		world.module<GalaxyComponents>();

		world.component<Galaxy>();
		world.component<SectorGridCoord>();
		world.component<Sector>();
		world.component<SectorStage>();
		world.component<SectorNumber>();
	};
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

	struct SectorStage 
	{
		uint8_t stage;
	};

	struct SectorNumber 
	{
		uint8_t SectorNumber;
	};
};