#include "Mage.h"



Mage::Mage()
{
	special.setSpriteSheet("Ghost");
	fanX = getPosX();
	fanY = getPosY();

	fanY += 1;
}


Mage::~Mage()
{
}

void Mage::SoltarFantasma()
{
 special.desenhar(fanX, fanY);
}

void Mage::seguir()
{
	if (fanX != getPosX()) {
		fanX = getPosX();
	}
	if (fanY != getPosY()) {
		fanY = getPosY();
	}

	special.desenhar(fanX, fanY);
}

void Mage::especial(int e)
{
	SoltarFantasma();
	seguir();
	animar(e);
}

void Mage::animar(int e)
{
	if (e == 1) {
		if (gTeclado.segurando[TECLA_DIR] || gTeclado.segurando[TECLA_D]) {
			special.setAnimacao(2);
			special.avancarAnimacao();
		}
		if (gTeclado.segurando[TECLA_ESQ] || gTeclado.segurando[TECLA_A]) {
			special.setAnimacao(1);
			special.avancarAnimacao();
		}
		if (gTeclado.segurando[TECLA_CIMA] || gTeclado.segurando[TECLA_W]) {
			special.setAnimacao(3);
			special.avancarAnimacao();
		}
		if (gTeclado.segurando[TECLA_BAIXO] || gTeclado.segurando[TECLA_S]) {
			special.setAnimacao(0);
			special.avancarAnimacao();
		}
	}
}
