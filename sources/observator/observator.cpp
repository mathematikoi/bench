#include "observator/observator.hpp"
#include <unistd.h>

int observator_initialize() {
	if (!bench.observator.perspectives.size()) {
		std::cout << "there are no loaded perspectives!";
		return EXIT_FAILURE;
	}
	SDL_Window *window;
	SDL_Renderer *renderer;

	int grid_cell_size = 36;
	int grid_width = 29;
	int grid_height = 23;

	// + 1 so that the last grid lines fit in the screen.
	int window_width = (grid_width * grid_cell_size) + 1;
	int window_height = (grid_height * grid_cell_size) + 1;

	// Place the grid cursor in the middle of the screen.
	SDL_Rect grid_cursor = {
		.x = (grid_width - 1) / 2 * grid_cell_size,
		.y = (grid_height - 1) / 2 * grid_cell_size,
		.w = grid_cell_size,
		.h = grid_cell_size,
	};

	// The cursor ghost is a cursor that always shows in the cell below the
	// mouse cursor.
	SDL_Rect grid_cursor_ghost = {grid_cursor.x, grid_cursor.y, grid_cell_size,
		grid_cell_size};

	SDL_Color grid_background = {233, 233, 233, 255};
	SDL_Color grid_line_color = {200, 200, 200, 255};
	SDL_Color grid_cursor_ghost_color = {200, 200, 200, 255};
	SDL_Color grid_cursor_color = {160, 160, 160, 255};

	SDL_Surface* screenSurface = NULL;

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return EXIT_FAILURE;
	}

	if (SDL_CreateWindowAndRenderer(window_width, window_height, 0, &window,
				&renderer) < 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
				"Create window and renderer: %s", SDL_GetError());
		return EXIT_FAILURE;
	}

	SDL_SetWindowTitle(window, "SDL Grid");

	SDL_bool mouse_active = SDL_FALSE;
	SDL_bool mouse_hover = SDL_FALSE;


	SDL_Event e;
	bool quit = false;

	while (!quit) {
		while( SDL_PollEvent( &e ) != 0 )
		{
			switch (e.type) {
				case SDL_KEYUP:
					break;

				case SDL_QUIT:
					quit = true;
					break;

				default:
					break;
			}
		}

		// Draw grid background.
		SDL_SetRenderDrawColor(renderer, grid_background.r, grid_background.g,
				grid_background.b, grid_background.a);
		SDL_RenderClear(renderer);

		// Draw grid lines.
		SDL_SetRenderDrawColor(renderer, grid_line_color.r, grid_line_color.g,
				grid_line_color.b, grid_line_color.a);

		for (int x = 0; x < 1 + grid_width * grid_cell_size;
				x += grid_cell_size) {
			SDL_RenderDrawLine(renderer, x, 0, x, window_height);
		}

		for (int y = 0; y < 1 + grid_height * grid_cell_size;
				y += grid_cell_size) {
			SDL_RenderDrawLine(renderer, 0, y, window_width, y);
		}

		// Draw grid ghost cursor.
		if (mouse_active && mouse_hover) {
			SDL_SetRenderDrawColor(renderer, grid_cursor_ghost_color.r,
					grid_cursor_ghost_color.g,
					grid_cursor_ghost_color.b,
					grid_cursor_ghost_color.a);
			SDL_RenderFillRect(renderer, &grid_cursor_ghost);
		}

		// Draw grid cursor.
		SDL_SetRenderDrawColor(renderer, grid_cursor_color.r,
				grid_cursor_color.g, grid_cursor_color.b,
				grid_cursor_color.a);
		SDL_RenderFillRect(renderer, &grid_cursor);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

}

int observator_destroy() {

}
