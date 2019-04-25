#pragma once
#include"CarregadorAssets.h"
#include "libUnicornio.h"
#include"PersoBase.h"
#include"Knight.h"
#include"Mage.h"
#include"Rouge.h"

enum Tela {tMenu,tJogo,tFinal};

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();

	PersoBase * base[3];

private:
	CarregadorAssets *carregadorAssets;
	Tela telaAtual;
	Sprite fundoMenu, fundoJogar, fundoFinal;
	Sprite Player;
	std::ifstream arquivo;
	Texto font1;
	Musica musica;

	//criar botoes
	BotaoSprite bJogar, bSair;

	//metodos de telas
	void telaMenu();
	void telaJogo();
	void telaFinal();

	int per;
};

