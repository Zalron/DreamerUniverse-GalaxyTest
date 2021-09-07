#pragma once

#include <cstdint>

#include <iostream>

#include "flecs.h"

struct GalaxyComponentsConfig
{
    GalaxyComponentsConfig(flecs::world& world)
    {
        world.module<GalaxyComponentsConfig>();

        world.component<SectorConfig>();
    };

    struct SectorConfig
    {
        uint32_t SectorNumStarsMin;
        uint32_t SectorNumStarsMax;

        int16_t SectorCoordRangeMinX;
        int16_t SectorCoordRangeMaxX;
        int16_t SectorCoordRangeMinY;
        int16_t SectorCoordRangeMaxY;
        int16_t SectorCoordRangeMinZ;
        int16_t SectorCoordRangeMaxZ;
    };

    static constexpr SectorConfig CoreSector = {5500,6000, 0, 95 , -60, 60 ,0, 95};
    static constexpr SectorConfig CoreDiskSector = {5000,5500,96, 200, -20, 20, 96, 200 };
    static constexpr SectorConfig MidDiskSector = {4500, 5000, 201, 800, -20, 20, 201, 800};
    static constexpr SectorConfig OuterDiskSector = {4000, 4500, 801, 900, -15, 15, 801, 900};
    static constexpr SectorConfig EdgeDiskSector = {3000, 4000, 900, 1000, -10, 10, 900, 1000};
    static constexpr SectorConfig OpenClusterSector = {};
    static constexpr SectorConfig HaloSector = {100, 200, 1000, };
    static constexpr SectorConfig GlobularClusterSector = {};
    static constexpr SectorConfig NebularSector = {};
};
struct SectorTagCore;
struct SectorTagCoreDisk;
struct SectorTagMidDisk;
struct SectorTagOuterDisk;
struct SectorTagEdgeDisk;
struct SectorTagHalo;
struct SectorTagGlobularCluster;
struct SectorTagOpenCluster;
struct SectorTagNebula;

