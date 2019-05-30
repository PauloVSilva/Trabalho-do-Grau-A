#pragma once
#include"CarregadorAssets.h"
#include"SistemaLogin.h"
#include "libUnicornio.h"
#include"PersoBase.h"
#include"Knight.h"
#include"Mage.h"
#include"Rouge.h"

enum Tela {tMenu,tJogo,tFinal,tLogin,tCadastrar,tInicial};

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();

	bool getSair() { return saida; }

	PersoBase * base[3];

private:
	CarregadorAssets *carregadorAssets;
	Tela telaAtual;
	Sprite fundoMenu, fundoJogar, fundoFinal;
	Sprite Player;
	std::ifstream arquivo;
	Texto font1;
	Musica musica;

	//sistema login
	SistemaLogin sysLogin;
	std::fstream arqLogin;
	EventosInputTexto usuario;
	std::string senha1, senha2, login;
	Texto tUsuario, tSenha;
	Cor vermelho;

	//criar botoes
	BotaoSprite bJogar, bSair, bCreditos, bInstrucoes, bLogar, bCdastrar, bSair2;

	//metodos de telas
	void telaMenu();
	void telaJogo();
	void telaFinal();
	void telaLogin();
	void telaCadastrar();
	void telaInicial();

	int per;
	bool saida;
};

