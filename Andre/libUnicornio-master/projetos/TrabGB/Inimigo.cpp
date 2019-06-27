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
	
	//this->x = x/3;
	//this->y = (y/3);

	if (this->x < x) {	
		this->x = (x/2) ;		
	}
	/*else if (this->x > x)	
		this->x = (x/2) ;
		*/
		if (this->y < y) {			
		this->y = (y/2);
	
		}
	//else if (this->y > y)		
	//	this->y = (y/2);

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
	/*
	if (this->x < vaiX)
		this->x += inimVel;

	else if (this->x > vaiX)
		this->x -= inimVel;

	if (this->y < vaiY)
		this->y += inimVel;

	else if (this->y > vaiY)
		this->y -= inimVel;
		*/
	if (xInicial != x) {
		xInicial = x+1;
	}
	if (yInicial != y) {
		yInicial = y+1;
	}


	sprite.desenhar(xInicial, yInicial);
}


