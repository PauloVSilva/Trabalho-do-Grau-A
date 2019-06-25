#include "Knight.h"



Knight::Knight()
{
	cor.set(255, 0, 0, 255);
	font1.setFonte("Fonte1");
	font1.adicionarString("Argh!");
	font1.setCor(cor);
}


Knight::~Knight()
{
}

void Knight::especial(int e)
{
	if (e == 0) {
		font1.desenhar(getPosX(), (getPosY() - 30));
	}
}

