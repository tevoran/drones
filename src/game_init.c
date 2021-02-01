#include "drones.h"

#include <stdio.h>

#include <SDL2/SDL.h>

#include "general/general.h"
#include "gfx/gfx.h"
#include "maths/maths.h"
#include "gfx/ui/ui.h"
#include "net/net.h"

int game_init()
{
	engine_init("drones", "data/config.conf");

	struct vec3f cam_location={0,0,0};
	gfx_create_camera(cam_location, 0.5*PI);

	//loading font
	gfx_ui_set_font("data/ConsoleFont.bmp", 256);

	//skybox
	//light blue sky
	gfx_create_skybox(
		"data/sky.bmp",
		"data/sky.bmp",
		"data/sky.bmp",
		"data/sky.bmp",
		"data/sky.bmp",
		"data/sky.bmp");


	//crosshair
	struct ui_window *crosshair=gfx_ui_create_window(4,4,engine_config_state().resolution_x/2-2,engine_config_state().resolution_y/2-2);
}