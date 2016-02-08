#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "SDL_thread.h"
#include <string>

#undef main
#include "Renderer.h"
#include "Sprite.h"
#include "InputHandler.h"
#include "Player.h"

void Init();
void DrawGame();

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;


Sprite* backGroundImage;
InputHandler inputHandler = InputHandler();

// Player
SDL_Rect myRect{ 400, 400, 60, 65 };
Player player;

int main()
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;



	Mix_Music *music = NULL;
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1;
	music = Mix_LoadMUS(("Assets/background.wav"));
	Mix_PlayMusic(music, -1);


	//SDL
#pragma region SDL STUFF
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("SDL Template", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Create Renderer for the Window
			if (!Renderer::GetInstance()->Init(window, SCREEN_WIDTH, SCREEN_HEIGHT))
			{
				return 0;
			}

			bool quit = false;
			Init();


			SDL_Event e;
			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (inputHandler.CheckInput(SDLK_ESCAPE, e))
					{
						quit = true;
					}
				}//Key Input Update

				//*******************
				// Update Method
				//*******************
				DrawGame();

			}

			return 0;
		}
	}
}

void Init()
{

	backGroundImage = new Sprite();
	SDL_Rect Source = { 0, 0, 1240, 720 };
	SDL_Rect destination = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	backGroundImage->Init("Assets/menu.png", destination, Source);

	player.Init(myRect);

}

void DrawGame()
{
	Renderer::GetInstance()->ClearRenderer();

	backGroundImage->Draw();
	player.Draw();

	Renderer::GetInstance()->RenderScreen();
}