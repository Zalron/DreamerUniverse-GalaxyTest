#include "GalaxySystems.h"

void GalaxySystems::CreateGalaxySector(const flecs::iter& iter, GalaxyComponents::SectorNumber* sn)
{
	for (auto it : iter)
	{
		if (sn->SectorNumber == 1) 
		{
			for (int16_t x = -1; x <= 1; x++)
			{
				for (int16_t y = -1; y <= 1; y++)
				{
					for (int16_t z = -1; z <= 1; z++)
					{
						auto e = iter.world().entity();
						e.set<GalaxyComponents::SectorGridCoord>({ x, y, z });
						e.set<GalaxyComponents::Sector>({0,0});
						e.set<GalaxyComponents::SectorStage>({1});
						//std::cout << " This entity generated with the coordinates of " << x << " " << y << " " << z << std::endl;
					}
				}
			}
			sn->SectorNumber = 2;
		}
		if (sn->SectorNumber == 2)
		{
			iter.entity(it).destruct();
		}
	}
}

void GalaxySystems::CreateSectorStars(const flecs::iter& iter, GalaxyComponents::SectorGridCoord* sgc, GalaxyComponents::Sector* s, GalaxyComponents::SectorStage* ss)
{
	for (auto it : iter)
	{
		if (ss->stage == 1) 
		{
			s->numStars = CreatingRandom32BitIntNumbers(CreatingSeed(), 3000, 5000 );
			//std::cout << " This entity with sectorcoords of " << sgc->Xcoord << " " << sgc->Ycoord << " " << sgc->Zcoord << " generated this amount of stars of " << s->numStars << std::endl;
			ss->stage = 2;
		}
	}
}

void GalaxySystems::CreateStarsFromSectorCount(const flecs::iter& iter, GalaxyComponents::Sector* s, GalaxyComponents::SectorStage* ss)
{
	for (auto it : iter) 
	{
		if (ss->stage == 2) 
		{
			for (int16_t x = 0; x <= s->numStars; x++)
			{
				auto e = iter.world().entity().child_of(it);
				uint16_t xCoord = CreatingRandom32BitIntNumbers(CreatingSeed(), 0, 1000);
				uint16_t yCoord = CreatingRandom32BitIntNumbers(CreatingSeed(), 0, 1000);
				uint16_t zCoord = CreatingRandom32BitIntNumbers(CreatingSeed(), 0, 1000);
				e.set<GalaxyComponents::StarCoord>({xCoord, yCoord, zCoord});
				//std::cout << " This entity with starcoords of " << xCoord << " " << yCoord << " " << zCoord << " is generated this amount of stars of " << std::endl;

				uint16_t starSize = CreatingRandom32BitIntNumbers(CreatingSeed(), 1, 10);
				uint16_t numPlanet = CreatingRandom32BitIntNumbers(CreatingSeed(), 0, 10);
				e.set<GalaxyComponents::StarSystem>({ starSize, numPlanet });
				e.set<GalaxyComponents::StarSystemStage>({ 1 });
				//std::cout << " This entity with starsize and numPlants of " << starSize << " " << numPlanet << std::endl;
			}
			ss->stage = 3;
		}
	}
}

void GalaxySystems::CreatePlanetsFromStarSystem(const flecs::iter& iter, GalaxyComponents::StarSystem* ssy, GalaxyComponents::StarSystemStage* sss)
{
	for (auto it : iter)
	{
		if (sss->stage == 1) 
		{
			auto e = iter.world().entity().child_of(it);
			uint8_t StarSize = CreatingRandom32BitIntNumbers(CreatingSeed(), 1, 10);
			e.set<GalaxyComponents::Star>({ StarSize });
			for (int16_t i = 0; i < ssy->numPlants; i++)
			{
				auto e = iter.world().entity().child_of(it);
				uint8_t planetSize = CreatingRandom32BitIntNumbers(CreatingSeed(), 1, 10);
				e.set<GalaxyComponents::Planet>({ planetSize });
				//std::cout << " This entity with planet generated the planetsize of " << planetSize << std::endl;
			}
			sss->stage = 2;
		}
	}
}

inline int GalaxySystems::CreatingSeed()
{
	std::random_device rand32;
	std::mt19937 gen(rand32());
	std::uniform_int_distribution<> randomNumber32(0, INT32_MAX);
	int randomNumber = randomNumber32(gen);
	return randomNumber;
}

inline int GalaxySystems::CreatingRandom32BitIntNumbers(int seed, int min, int max)
{
	std::mt19937 gen(seed);
	std::uniform_int_distribution<int> randomNumber32(min, max);
	int randomNumber = randomNumber32(gen);
	return randomNumber;
}

inline float GalaxySystems::CreatingRandom32BitFloatNumbers(int seed, float min, float max)
{
	std::mt19937 gen(seed);
	std::uniform_real_distribution<float> randomNumber32(min, max);
	float randomNumber = randomNumber32(gen);
	return randomNumber;
}
