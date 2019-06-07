#include "Jogo.h"
#include"PersoBase.h"

//Jogo::Jogo()
//{
//}
//
//Jogo::~Jogo()
//{
//}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false);
	//telaAtual = tInicial;
	pilhamenu.push(tInicial);
	sysLogin.inicializar();

	if(!sysLogin.inicializar()){
		gDebug.erro("Funcao login inicializar nao abriu!");
	}

	gDebug.ativar();

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

	//inicializar sistema login
	arqLogin.open("../assets/login.dat", std::ios::binary | std::ios::in);
	if (arqLogin.is_open()) {

	}
	else {
		gDebug.erro("Carregador de login nao abriu!");
	}
	
	//carregar fonte
	gRecursos.carregarFonte("Fonte1","../assets/Fonts/Bearskin.otf", 32);
	gRecursos.carregarFonte("Fonte2", "../assets/Fonts/OldExcalibur.otf", 28);

	//carregar fundos
	gRecursos.carregarSpriteSheet("fundoMenu", "../assets/fundos/Menu.png");
	fundoMenu.setSpriteSheet("fundoMenu");

	gRecursos.carregarSpriteSheet("fundoJogar", "../assets/fundos/Jogo.png");
	fundoJogar.setSpriteSheet("fundoJogar");

	//carregar botoes
	gRecursos.carregarSpriteSheet("botaoJogar", "../assets/Button/botaoJogar.png", 3, 1);
	bJogar.setSpriteSheet("botaoJogar");
	bJogar.setPos((gJanela.getLargura() / 2) - 176, (gJanela.getAltura() / 2) + 42);

	gRecursos.carregarSpriteSheet("botaoCreditos", "../assets/Button/botaoCreditos.png", 3, 1);
	bCreditos.setSpriteSheet("botaoCreditos");
	bCreditos.setPos((gJanela.getLargura() / 2) - 176, (gJanela.getAltura() / 2) + 162);

	gRecursos.carregarSpriteSheet("botaoInstrucoes", "../assets/Button/botaoInstrucoes.png", 3, 1);
	bInstrucoes.setSpriteSheet("botaoInstrucoes");
	bInstrucoes.setPos((gJanela.getLargura() / 2) - 176, (gJanela.getAltura() / 2) + 102);

	gRecursos.carregarSpriteSheet("botaoSair", "../assets/Button/botaoSair.png", 3);
	bSair.setSpriteSheet("botaoSair");
	bSair.setPos((gJanela.getLargura() / 2) - 176, (gJanela.getAltura() / 2) + 222);

	gRecursos.carregarSpriteSheet("botaoLogar","../assets/Button/botaoLogar.png", 3);
	bLogar.setSpriteSheet("botaoLogar");
	bLogar.setPos(gJanela.getLargura() / 2 , gJanela.getAltura() / 2);

	gRecursos.carregarSpriteSheet("botaoCadastrar", "../assets/Button/botaoCadastrar.png", 3);
	bCdastrar.setSpriteSheet("botaoCadastrar");
	bCdastrar.setPos(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) + 60);

	gRecursos.carregarSpriteSheet("botaoSair2", "../assets/Button/botaoSair2.png", 3);
	bSair2.setSpriteSheet("botaoSair2");
	bSair2.setPos(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) + 120);

	gRecursos.carregarSpriteSheet("botaoVoltar", "../assets/Button/botaoVoltar.png", 3);
	bVoltar.setSpriteSheet("botaoVoltar");
	bVoltar.setPos(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) + 250);

	//carregar sprite extra

	gRecursos.carregarSpriteSheet("Ghost", "../assets/spriteSheets/Ghost.png", 4, 3);
	gRecursos.carregarSpriteSheet("Sword", "../assets/spriteSheets/Sword.png", 2, 4);

	// carregar musicas
	//gRecursos.carregarMusica("Epic", "../assets/music/Epic.mp3");
	
	//setando cor para texto
	Branco.set(255,255,255,255);

	//carregar Personagens

	base[0] = new Knight;
	base[1] = new Mage;
	base[2] = new Rouge;

	base[0]->setSpriteSheet("Knight", "../assets/spriteSheets/Knight.png", 4, 4);
	
	base[0]->setPos((gJanela.getLargura() / 2) - 25, gJanela.getAltura() / 2);
	base[0]->desenhar((gJanela.getLargura() / 2) + 100, gJanela.getAltura() / 2);

	base[1]->setSpriteSheet("Mage", "../assets/spriteSheets/Mage.png", 4, 4);

	base[1]->setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	base[1]->desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	base[2]->setSpriteSheet("Rouge", "../assets/spriteSheets/Rouge.png", 4, 4);

	base[2]->setPos((gJanela.getLargura() / 2) + 25, gJanela.getAltura() / 2);
	base[2]->desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	per = 0;
}

void Jogo::finalizar()
{
	//	O resto da finalização vem aqui (provavelmente, em ordem inversa a inicialização)!
	//	...
	gRecursos.descarregarTodasMusicas();
	gRecursos.descarregarTudo();
	uniFinalizar();
}

void Jogo::testarColisao()
{
	//colisao com as boradas verticais da tela
	if (base[per]->getColisaoY() <= 10) {
		base[per]->setPos(base[per]->getColisaoX(),10);
	}
	if (base[per]->getColisaoY() >= gJanela.getAltura() -10) {
		base[per]->setPos(base[per]->getColisaoX(), gJanela.getAltura() -10);
	}
	//colisao com as bordas horizontais da tela
	if (base[per]->getColisaoX() >= gJanela.getLargura() - 120) {
		base[per]->setPos(gJanela.getLargura() - 120, base[per]->getColisaoY());
	}
	if (base[per]->getColisaoX() <= 120) {
		base[per]->setPos(120, base[per]->getColisaoY());
	}

	//nao ta funcionando
	/*if (uniTestarColisaoSpriteComSprite(base[0]->getSprite(), base[0]->getColisaoX(), base[0]->getColisaoY(), 0,
		base[1]->getSprite(), base[1]->getColisaoX(), base[1]->getColisaoY(), 0)) {
		base[0]->setPos(base[0]->getColisaoX(), base[0]->getColisaoY());
		base[1]->setPos(base[1]->getColisaoX(), base[1]->getColisaoY());
	}*/
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair && getSair())
	{
		uniIniciarFrame();

		gDebug.atualizar();
		gDebug.desenhar();
		//	Seu código vem aqui!
		//	...
		//tela vai ser executadas de cada vez 
		
		switch (pilhamenu.top())
		{
		case tInicial: telaInicial();
			break;
		case tMenu: telaMenu();
			break;
		case tJogo: telaJogo();
			break;
		case tFinal: telaFinal();
			break;
		case tCadastrar: telaCadastrar();
			break;
		case tLogin: telaLogin();
			break;
		case tInstrucoes: telaInstrocoes();
			break;
		case tCreditos: telaCreditos();
			break;
		}
		
		

		uniTerminarFrame();
	}
}

void Jogo::telaMenu()
{
	fundoMenu.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	bJogar.atualizar();
	bJogar.desenhar();

	bInstrucoes.atualizar();
	bInstrucoes.desenhar();

	bCreditos.atualizar();
	bCreditos.desenhar();

	bSair.atualizar();
	bSair.desenhar();

	if (bJogar.estaClicado()) {
		//telaAtual = tJogo;
		pilhamenu.push(tJogo);
	}
	if (bSair.estaClicado()) {
		saida = false;
		
	}
	if (bInstrucoes.estaClicado()) {
		pilhamenu.push(tInstrucoes);
	}
	if (bCreditos.estaClicado()) {
		pilhamenu.push(tCreditos);
	}
}

void Jogo::telaInstrocoes()
{
	fundoJogar.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	bVoltar.atualizar();
	bVoltar.desenhar();

	txtCreditos.setCor(Branco);
	txtCreditos.setFonte("Fonte2");
	txtCreditos.setString("Intrucoes:\n"
		"Mover para cima - SETA PARA CIMA ou W\n"
		"Mover para baixo - SETA PARA BAIXO ou S\n"
		"Mover para esquerda - SETA PARA ESQUERDA ou A\N"
		"Mover para direita - SETA PARA DIREITA ou D\n"
		"Especial - tecla ESPACO\n"
		"TROCA DE PERSONAGEM:\n"
		"Guerreiro - TECLA 1\n"
		"Mago - TECLA 2\n"
		"Ladino  - TECLA 3\n");

	txtCreditos.desenhar(gJanela.getLargura() / 2, 200);

	if (bVoltar.estaClicado()) {
		pilhamenu.pop();
	}
}

void Jogo::telaCreditos()
{
	fundoJogar.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	bVoltar.atualizar();
	bVoltar.desenhar();

	
	

	if (bVoltar.estaClicado()) {
		pilhamenu.pop();
	}
}

void Jogo::telaJogo()
{
	fundoJogar.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	/*if (!musica.estaCarregado())
		musica.carregar("Epic", true);*/

	base[0]->atualizar();
	base[1]->atualizar();
	base[2]->atualizar();

	base[per]->mover();

	testarColisao();

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
	//gRecursos.
	//indicador de personagem
	if (per == 0)
		gGraficos.desenharTexto("Controlando Guerreiro",80, 30, 255, 0, 0, 255);

	if (per == 1)
		gGraficos.desenharTexto("Controlando Mago", 80, 30, 255, 0, 0, 255);

	if (per == 2)
		gGraficos.desenharTexto("Controlando Ladino", 80, 30, 255, 0, 0, 255);
}

void Jogo::telaFinal()
{
}

void Jogo::telaLogin()
{
	sysLogin.iniciarLogin();
	if (sysLogin.getLoginAprovado() == true) {
		//telaAtual = tMenu;
		pilhamenu.push(tMenu);
	}
}

void Jogo::telaCadastrar()
{
	sysLogin.iniciarCadastro();
	if (sysLogin.iniciarCadastro() == true) {
		//telaAtual = tMenu;
		pilhamenu.push(tMenu);
	}
}

void Jogo::telaInicial()
{
	bLogar.atualizar();
	bLogar.desenhar();

	bCdastrar.atualizar();
	bCdastrar.desenhar();

	bSair2.atualizar();
	bSair2.desenhar();

	if (bLogar.estaClicado()) {
		//telaAtual = tLogin;
		pilhamenu.push(tLogin);
	}

	if (bCdastrar.estaClicado()) {
		//telaAtual = tCadastrar;
		pilhamenu.push(tCadastrar);
	}

	if (bSair2.estaClicado()) {
		saida = false;
	}
}
