#pragma once
#include "flecs.h"
#include "GalaxyComponents.h"

struct GalaxySystems
{
	GalaxySystems(flecs::world& world)
	{
		world.import<GalaxyComponents>();

		world.system<GalaxyComponents::SectorNumber>("CreateGalaxySector").iter(CreateGalaxySector);
	};

	static void CreateGalaxySector(const flecs::iter& iter, GalaxyComponents::SectorNumber* ss);
};