#include<iostream>
#include"PersoBase.h"

using namespace std;

PersoBase::PersoBase(){
	x = 0;
	y = 0;
	v = 5;
	vel = 1;
}

PersoBase::~PersoBase(){
}

void PersoBase::setVida(int v){
	vida = v;
}

void PersoBase::setPos(int x, int y){
	this->x = x;
	this->y = y;
	xInicial = this->x;
	yInicial = this->y;
}

void PersoBase::setvivo(bool v){
	std::cout << "Voce tem " << this->v << "vidas" << std::endl;
	this->v = v;
}

void PersoBase::setSpriteSheet(std::string nome, std::string caminho, int numAnim, int numFreme){
	gRecursos.carregarSpriteSheet(nome, caminho, numAnim, numFreme);
	sprite.setSpriteSheet(nome);
}


void PersoBase::desenhar(int x, int y){
	sprite.desenhar(x, y);
}

void PersoBase::atualizar(){
	if (xInicial != x) {
		xInicial = x;
	}
	if (yInicial != y) {
		yInicial = y;
	}
	sprite.desenhar(xInicial, yInicial);
}

void PersoBase::especial(int e){
	if (e == 0) {
		
	}
	if (e == 1) {
		
	}
	if (e == 2) {

	}
}

void PersoBase::mover()
{
	if (gTeclado.segurando[TECLA_DIR] || gTeclado.segurando[TECLA_D]) {
		x += vel;
		sprite.setAnimacao(2);
		sprite.avancarAnimacao();
	}
	if (gTeclado.segurando[TECLA_ESQ] || gTeclado.segurando[TECLA_A]) {
		x-= vel;
		sprite.setAnimacao(1);
		sprite.avancarAnimacao();
	}
	if (gTeclado.segurando[TECLA_CIMA] || gTeclado.segurando[TECLA_W]) {
		y-= vel;
		sprite.setAnimacao(3);
		sprite.avancarAnimacao();
	}
	if (gTeclado.segurando[TECLA_BAIXO] || gTeclado.segurando[TECLA_S]) {
		y += vel;
		sprite.setAnimacao(0);
		sprite.avancarAnimacao();
	}
}