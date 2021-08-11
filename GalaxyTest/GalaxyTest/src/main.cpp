#include <iostream>
#include "flecs.h"
#include "GalaxyComponents.h"

int main() 
{
	flecs::world world;

	auto e = world.entity("Item").set<GalaxyComponents::SectorNumber>({ 27 });

	while (world.progress()) {};

	return 0;
}