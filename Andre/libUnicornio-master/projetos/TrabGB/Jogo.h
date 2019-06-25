#pragma once
#include"CarregadorAssets.h"
#include"SistemaLogin.h"
#include"SistemaRanking.h"
#include "libUnicornio.h"
#include"PersoBase.h"
#include"Knight.h"
#include"Mage.h"
#include"Rouge.h"
#include"Inimigo.h"
#include<stack>

enum Tela {tMenu,tJogo,tFinal,tLogin,tCadastrar,tInicial,tInstrucoes,tCreditos, tPause, tRanking};

class Jogo
{
public:
	Jogo(){ }
	~Jogo(){ }

	void inicializar();
	void finalizar();

	void executar();

	bool getSair() { return saida; }

	PersoBase * base[4];
	Inimigo * inimigoo;

	//metodo de colisao
	void testarColisao();

private:
	//controlador de jogo/cena
	CarregadorAssets *carregadorAssets;
	Tela telaAtual;
	Sprite fundoMenu, fundoJogar, fundoFinal;
	Sprite Player;
	std::ifstream arquivo;
	Texto font1;
	Musica musica;
	stack<Tela> pilhamenu;

	//sistema login
	SistemaLogin sysLogin;
	std::fstream arqLogin;

	//sistema ranking
	SistemaRanking sysRanking;

	//criar botoes
	BotaoSprite bJogar, bSair, bCreditos, bInstrucoes, bLogar, bCdastrar, bSair2, bVoltar, bRanking;

	//metodos de telas
	void telaMenu();
	void telaJogo();
	void telaFinal();
	void telaLogin();
	void telaCadastrar();
	void telaInicial();
	void telaInstrocoes();
	void telaCreditos();
	void telaPause();
	void telaRanking();

	//texto creditos
	Texto txtCreditos;
	Cor Branco;

	int per;
	bool saida, pause = false;
};

