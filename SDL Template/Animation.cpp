#include "Animation.h"

Animation::Animation()
{

}

void Animation::Init(int frames, int animationSpeed, int frameWidth, int frameHeight)
{

	m_SpriteClips[frames];
	m_width = frameWidth;
	m_height = frameHeight;
	m_totalAnimationframes = frames;
	m_animationSpeed = animationSpeed;

	m_currentFrame = 0;

	for (int i = 0; i < m_totalAnimationframes; i++)
	{
		m_SpriteClips[i].x = (i * m_width);
		m_SpriteClips[i].y = 0;
		m_SpriteClips[i].w = m_width;
		m_SpriteClips[i].h = m_height;
	}

	int test = 0;
}

SDL_Rect Animation::Animate()
{
	//Render current frame
	SDL_Rect currentClip = m_SpriteClips[m_currentFrame / m_animationSpeed];
	++m_currentFrame;

	//Reset the frames back to 0
	if (m_currentFrame / m_animationSpeed > m_totalAnimationframes - 1)
	{
		m_currentFrame = 0;
	}

	return currentClip;
}