#ifndef PLAYER_H
#define PLAYER_H

#include <iostream> 
#include "SDL.h"
#include <SDL_image.h>
#include "Renderer.h"
#include "Sprite.h"
#include "InputHandler.h"
#include "Animation.h"

class Player
{
public:
	Player();
	bool Update();
	void Draw();
	SDL_Rect getRectangle();
	void Init(SDL_Rect pRect);

private:
	SDL_Rect initPos;
	SDL_Rect myRect;
	SDL_Rect source;
	int spriteOffset;
	Animation idleAnimation;
	Sprite playerAnimate;
};

#endif
