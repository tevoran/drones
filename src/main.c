#include "drones.h"

#include <stdio.h>

#include <SDL2/SDL.h>

#include "general/general.h"
#include "gfx/gfx.h"
#include "maths/maths.h"
#include "gfx/ui/ui.h"
#include "net/net.h"


void main()
{
	game_init();



	//main loop
	int quit=0;
	int i=0;
	while(quit==0)
	{
		/*handling input via SDL2*/
		{
			SDL_Event event;

			SDL_PollEvent(&event);
			switch(event.type)
			{
				case SDL_QUIT:
					quit=1;
					break;
			}
		}

		gfx_new_frame();
		i++;
		printf("i: %i\n", i);
	}
}