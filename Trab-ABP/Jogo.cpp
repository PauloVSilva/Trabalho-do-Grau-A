#include "Jogo.h"
#include"PersoBase.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false);
	telaAtual = tMenu;
	//	O resto da inicialização vem aqui!
	//	...

	//carregador de assets
	/*arquivo.open("../carregadorRecursos.txt", ios::in);

	carregadorAssets = new CarregadorAssets;
	if (!arquivo) {
		gDebug.erro("Nao foi possivel abrir o arquivo!");
	}
	else {
		if (!carregadorAssets->carregarRecursos(arquivo)) {
			gDebug.erro("Falha no carregamento de recursos!");
		}
		arquivo.close();
	}*/
	
	//carregar fonte
	gRecursos.carregarFonte("Fonte1","../assets/Fonts/Bearskin.otf", 32);

	//carregar fundos
	gRecursos.carregarSpriteSheet("fundoMenu", "../assets/fundos/Menu.png");
	fundoMenu.setSpriteSheet("fundoMenu");

	gRecursos.carregarSpriteSheet("fundoJogar", "../assets/fundos/fundoJogo.png");
	fundoJogar.setSpriteSheet("fundoJogar");

	//carregar sprite extra

	gRecursos.carregarSpriteSheet("Ghost", "../assets/spriteSheets/Ghost.png", 4, 3);
	gRecursos.carregarSpriteSheet("Sword", "../assets/spriteSheets/Sword.png", 2, 4);

	// carregar musicas
	//gRecursos.carregarMusica("Epic", "../assets/music/Epic.mp3");
	

	//carregar Personagens

	base[0] = new Knight;
	base[1] = new Mage;
	base[2] = new Rouge;

	base[0]->setSpriteSheet("Knight", "../assets/spriteSheets/Knight.png", 4, 4);
	
	base[0]->setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	base[0]->desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	base[1]->setSpriteSheet("Mage", "../assets/spriteSheets/Mage.png", 4, 4);

	base[1]->setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	base[1]->desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	base[2]->setSpriteSheet("Rouge", "../assets/spriteSheets/Rouge.png", 4, 4);

	base[2]->setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	base[2]->desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	per = 0;
}

void Jogo::finalizar()
{
	//	O resto da finalização vem aqui (provavelmente, em ordem inversa a inicialização)!
	//	...
	gRecursos.descarregarTudo();
	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		//	Seu código vem aqui!
		//	...
		//tela vai ser executadas de cada vez 
		switch (telaAtual)
		{
		case tMenu: telaMenu();
			break;
		case tJogo: telaJogo();
			break;
		case tFinal: telaFinal();
			break;

		}
		
		

		uniTerminarFrame();
	}
}

void Jogo::telaMenu()
{
	fundoMenu.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	if (gTeclado.pressionou[TECLA_ENTER]) {
		telaAtual = tJogo;
	}
}

void Jogo::telaJogo()
{
	fundoJogar.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	/*if (!musica.estaCarregado())
		musica.carregar("Epic");*/

	base[0]->atualizar();
	base[1]->atualizar();
	base[2]->atualizar();

	base[per]->mover();

	//trocar personagem
	if (gTeclado.pressionou[TECLA_1]) {
		per = 0;
	}
	if (gTeclado.pressionou[TECLA_2]) {
		per = 1;
	}
	if (gTeclado.pressionou[TECLA_3]) {
		per = 2;
	}

	//especial
	if (gTeclado.segurando[TECLA_ESPACO]) {
		base[per]->especial(per);
	}
	if (!gTeclado.segurando[TECLA_ESPACO]) {
		base[per]->resetarVelocidade();
	}
}

void Jogo::telaFinal()
{
}
