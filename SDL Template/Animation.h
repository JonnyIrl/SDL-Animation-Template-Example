/**************************************************************************************
|  Animation Class made by Jonathan                                                   |
|  Create an animation object representing the animation you want. i.e IdleAnimation  |
|  Call that objects Init method passing in the total number of frames,               |
|  the playback speed, the width of 1 single frame, the height of 1 single frame      |
**************************************************************************************/

#pragma once
#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL.h>
#include "Renderer.h"
#include "Sprite.h"

class Animation
{
public:
	Animation();
	void Init(int frames, int speed, int frameWidth, int frameHeight);
	SDL_Rect Animate();
private:
	SDL_Rect m_SpriteClips[11];
	int m_animationSpeed;
	int m_width, m_height, m_totalAnimationframes, m_currentFrame;
};

#endif
