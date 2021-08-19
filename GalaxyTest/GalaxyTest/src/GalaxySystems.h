#pragma once
#include "flecs.h"
#include "GalaxyComponents.h"
#include <Random>

struct GalaxySystems
{
	GalaxySystems(flecs::world& world)
	{
		world.import<GalaxyComponents>();

		world.module<GalaxySystems>();

		world.system<GalaxyComponents::SectorNumber>("CreateGalaxySector").iter(CreateGalaxySector);

		world.system<GalaxyComponents::SectorGridCoord, GalaxyComponents::Sector, GalaxyComponents::SectorStage>("CreateSectorStars").iter(CreateSectorStars);

		world.system<GalaxyComponents::Sector, GalaxyComponents::SectorStage>("CreateStarsFromSectorCount").iter(CreateStarsFromSectorCount);

		world.system<GalaxyComponents::StarSystem, GalaxyComponents::StarSystemStage>("CreatePlanetsFromStarSystem").iter(CreatePlanetsFromStarSystem);
	};

public:

	static void CreateGalaxySector(const flecs::iter& iter, GalaxyComponents::SectorNumber* ss);
	static void CreateSectorStars(const flecs::iter& iter, GalaxyComponents::SectorGridCoord* sgc, GalaxyComponents::Sector* s, GalaxyComponents::SectorStage* ss);
	static void CreateStarsFromSectorCount(const flecs::iter& iter, GalaxyComponents::Sector* s, GalaxyComponents::SectorStage* ss);
	static void CreatePlanetsFromStarSystem(const flecs::iter& iter, GalaxyComponents::StarSystem* ssy, GalaxyComponents::StarSystemStage* sss);

private:

	static inline int CreatingSeed();
	static inline int CreatingRandom32BitIntNumbers(int seed, int min, int max);
	static inline float CreatingRandom32BitFloatNumbers(int seed, float min, float max);
};