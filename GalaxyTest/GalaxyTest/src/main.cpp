#include <iostream>
#include "flecs.h"
#include "flecs_os_api_stdcpp.h"
#include "GalaxyComponents.h"
#include "GalaxySystems.h"

int main() 
{
	flecs::world world;

	stdcpp_set_os_api();

	int32_t threadcount = 12;

	world.set_threads(threadcount);

	world.import<GalaxySystems>();

	world.entity("Galaxy").set<GalaxyComponents::Galaxy>({1000, 0, 1 });

	while (world.progress()) {};

	return 0;
}