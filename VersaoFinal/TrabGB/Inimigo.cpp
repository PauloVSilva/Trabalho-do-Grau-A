#include "Inimigo.h"



Inimigo::Inimigo()
{
	//sprite = getSprite();
	x = 350;
	y = 10;
}


Inimigo::~Inimigo()
{
}


void Inimigo::Movimentar(int x, int y)
{
	
	//this->x = (this->x - x);
	//this->y = (this->y - y);

	if (this->x < x) {
		this->x += x;
	}
	else if (this->x > x)
		this->x -= x;		

	if (this->y < y)
		this->y += y;

	else if (this->y > y)
		this->y -= y;	
	

	/*
	setPosX(getPosX());
	setPosY(getPosY());
	
	xInicial = getPosX();
	yInicial = getPosY();
	
	vaiX = x;
	vaiY = y;
	*/	

	sprite.desenhar(this->x, this->y);
}
void Inimigo::atualizar()
{
	
	if (this->x < vaiX)
		this->x += inimVel;

	else if (this->x > vaiX)
		this->x -= inimVel;

	if (this->y < vaiY)
		this->y += inimVel;

	else if (this->y > vaiY)
		this->y -= inimVel;
		

	/*if (xInicial != x) {
		xInicial = x;
	}
	if (yInicial != y) {
		yInicial = y;
	}*/

	sprite.desenhar(this->x, this->y);
}


