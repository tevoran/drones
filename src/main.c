#include <stdio.h>

#include <SDL2/SDL.h>

#include "general/general.h"
#include "gfx/gfx.h"
#include "maths/maths.h"
#include "gfx/ui/ui.h"
#include "net/net.h"


void main()
{
	printf("CHECK: %i\n", engine_init("drones", "data/config.conf"));

	struct vec3f player_location={0,0,0};
	gfx_create_camera(player_location, 0.5*PI);

	struct vec3f drone_location={0,0,5};
	struct model *drone=gfx_load_model("data/models/drone/drone.obj", drone_location);
	gfx_model_load_texture("data/models/drone/drone.bmp", drone);

	gfx_ui_set_font("data/ConsoleFont.bmp", 256);


	gfx_create_skybox(
		"data/sky.bmp",
		"data/sky.bmp",
		"data/sky.bmp",
		"data/sky.bmp",
		"data/sky.bmp",
		"data/sky.bmp");

	struct ui_window *crosshair=gfx_ui_create_window(4,4,engine_config_state().resolution_x/2-2,engine_config_state().resolution_y/2-2);

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