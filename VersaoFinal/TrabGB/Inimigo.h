#pragma once
#include "PersoBase.h"
class Inimigo :
	public PersoBase
{
public:
	Inimigo();
	~Inimigo();

	void Movimentar(int x, int y);
	void atualizar()override;
	void setSpriteInim() { sprite = getSprite(); }
	//void setPos(int iX, int iY) { x = iX; y = iY; }

private:
	int dano;
	bool vivo;
	int x, y, xInicial, yInicial, inimVel = 1;
	int vaiX = 0, vaiY = 0;
	Sprite sprite;
};

