#pragma once
#include"libUnicornio.h"

class PersoBase
{
public:
	PersoBase();
	~PersoBase();


	//Deixei tudo publico para depois definirmos o que vamos proteger 
	void setVida(int vida);
	virtual void setPos(int x, int y);
	void setvivo(bool v);
	virtual void setSpriteSheet(std::string nome, std::string caminho, int numAnim, int numFreme);
	void resetarVelocidade() { vel = 1; }
	virtual void setVel(int i) { vel = i; }

	virtual void desenhar(int x, int y);
	virtual void atualizar();

	virtual void especial(int e);

	void mover();

protected:
	int getPosX() { return xInicial; }
	int getPosY() { return yInicial; }

private:
	Sprite sprite;
	int vida;       //Define a vida
	bool v;		   //status de vida
	int x, y, xInicial, yInicial;   //posição no mapa
	int vel;   //velocidade do personagem


};

