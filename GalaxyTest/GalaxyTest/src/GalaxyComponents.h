#pragma once

#include <cstdint>

#include <iostream>

#include "flecs.h"

#include "GalaxyComponentConfig.h"

struct GalaxyComponents 
{
	GalaxyComponents(flecs::world& world)
	{
		world.module<GalaxyComponents>();

		world.component<Galaxy>();
		world.component<SectorGridCoord>();
		world.component<Sector>();
		world.component<SectorStage>();
		world.component<StarCoord>();
		world.component<StarSystem>();
		world.component<StarSystemStage>();
		world.component<Star>();
		world.component<Planet>();
	};
	struct Galaxy 
	{
		uint16_t size;
		//GalaxyType Galaxytype;
		uint16_t year;
        uint8_t stage;
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
		uint16_t sectorLevel;
	};

	struct SectorStage 
	{
		uint8_t stage;
	};

	struct StarCoord 
	{
		uint16_t Xcoord;
		uint16_t Ycoord;
		uint16_t Zcoord;
	};

	struct StarSystem
	{
		uint16_t size;
		uint16_t numPlants;
	};

	struct StarSystemStage 
	{
		uint8_t stage;
	};

	struct Star 
	{
		uint8_t size;
	};

	struct Planet 
	{
		uint8_t size;
	};

    struct SectorTagCore;
    struct SectorTagCoreDisk;
    struct SectorTagMidDisk;
    struct SectorTagOuterDisk;
    struct SectorTagEdgeDisk;
    struct SectorTagHalo;
    struct SectorTagCluster;
    struct SectorTagNebular;
};