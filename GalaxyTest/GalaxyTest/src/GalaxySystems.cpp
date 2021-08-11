#include "GalaxySystems.h"

void GalaxySystems::CreateGalaxySector(const flecs::iter& iter, GalaxyComponents::SectorNumber* sn)
{
	for (auto it : iter)
	{
		for (int16_t x = -1; x < 1; x++)
		{
			for (int16_t y = -1; y < 1; y++)
			{
				for (int16_t z = -1; z < 1; z++)
				{
					auto e = iter.world().entity();
					e.set<GalaxyComponents::SectorGridCoord>({ x, y, z });
				}
			}
		}
	}
}
