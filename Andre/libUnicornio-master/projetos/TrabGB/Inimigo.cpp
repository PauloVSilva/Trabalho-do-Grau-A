#include "Inimigo.h"



Inimigo::Inimigo()
{
	//sprite = getSprite();
}


Inimigo::~Inimigo()
{
}

//base[per]->getPosiçãoX
void Inimigo::Movimentar(int x, int y)
{
	/*this->x = x;
	this->y = y;*/

	/*setPosX(getPosX());
	setPosY(getPosY());*/

	xInicial = getPosX();
	yInicial = getPosY();

	vaiX = x;
	vaiY = y;



	if (this->x < x)
		this->x += inimVel;

	else if (this->x > x)
		this->x -= inimVel;

	if (this->y < y)
		this->y += inimVel;

	else if (this->y > y)
		this->y -= inimVel;

	sprite.desenhar(this->x, this->y);
}
void Inimigo::atualizar()
{
	/*if (this->x < vaiX)
		this->x += inimVel;

	else if (this->x > vaiX)
		this->x -= inimVel;

	if (this->y < vaiY)
		this->y += inimVel;

	else if (this->y > vaiY)
		this->y -= inimVel;*/

	if (xInicial != x) {
		xInicial = x;
	}
	if (yInicial != y) {
		yInicial = y;
	}
	sprite.desenhar(xInicial, yInicial);
}


