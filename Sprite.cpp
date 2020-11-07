#include "Sprite.h"
#include <string>



Sprite::Sprite()
{

}

Sprite::Sprite(const char* path, bool useTransparency)
{
	setTex(path, useTransparency);
}

//Load Image
void Sprite::setTex(const char* path, bool useTransparency)
{
	Texture = TextureManager::LoadBMPTexture(path,&destRect, useTransparency);	
}

void Sprite::init()
{
	//Define Position
	position = &entity->getComponent<Coordinate>();

	//sprte position n screen
	srcRect.x = srcRect.y = 0;	
	destRect.x = destRect.y = 0;

}


void Sprite::update()
{
	destRect.x = position->Get_X();
	destRect.y = position->Get_Y();
}

///Draw on screen
void Sprite::draw()
{
	TextureManager::Draw(Texture, destRect);
}

void Sprite::rotation()
{	

}
