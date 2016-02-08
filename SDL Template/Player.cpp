#include "Player.h"

// Constructor
Player::Player()
{

}


void Player::Init(SDL_Rect pRect)
{
	initPos = pRect;
	myRect = pRect;
	source = { pRect.x, pRect.y, 60, 65 };
	playerAnimate.Init("Assets/playerLeft.png", pRect, source);
	idleAnimation.Init(11, 3, 60, 65);
}


bool Player::Update()
{
	return true;
}

void Player::Draw()
{
	playerAnimate.SetSourceRect(idleAnimation.Animate());
	playerAnimate.Draw();
}

SDL_Rect Player::getRectangle()
{
	return myRect;
}
