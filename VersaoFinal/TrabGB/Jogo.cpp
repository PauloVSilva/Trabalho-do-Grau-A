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

	if (sysRanking.inicializar()) {

	}
	else {
		gDebug.erro("Sistema de ranking nao inicionu!");
	}
	
	//carregar fonte
	gRecursos.carregarFonte("Fonte1","../assets/Fonts/Bearskin.otf", 32);
	gRecursos.carregarFonte("Fonte2", "../assets/Fonts/OldExcalibur.otf", 28);
	gRecursos.carregarFonte("OldEng", "../assets/Fonts/OldEng.TTF", 24);
	gRecursos.carregarFonte("arial", "../assets/Fonts/arial.ttf", 20);

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

	gRecursos.carregarSpriteSheet("botaoRanking", "../assets/Button/botaoRanking.png", 3);
	bRanking.setSpriteSheet("botaoRanking");
	bRanking.setPos((gJanela.getLargura() / 2) + 176, (gJanela.getAltura() / 2) + 222);

	//carregar sprite extra

	gRecursos.carregarSpriteSheet("Ghost", "../assets/spriteSheets/Ghost.png", 4, 3);
	gRecursos.carregarSpriteSheet("Sword", "../assets/spriteSheets/Sword.png", 2, 4);

	// carregar musicas
	gRecursos.carregarMusica("Epic", "../assets/music/Epic.mp3");
	gRecursos.carregarMusica("musicaJogo", "../assets/music/MusicaJogo.mp3");
	
	//gMusica.tocar("musicaJogo", True);
	//gMusica.tocar("Epic", True);

	//setando cor para texto
	Branco.set(255,255,255,255);

	//carregar Personagens

	base[0] = new Knight;
	base[1] = new Mage;
	base[2] = new Rouge;

	 inimigoo = new Inimigo;

	base[0]->setSpriteSheet("Knight", "../assets/spriteSheets/Knight.png", 4, 4);
	
	base[0]->setPos((gJanela.getLargura() / 2) - 25, gJanela.getAltura() / 2);
	base[0]->desenhar((gJanela.getLargura() / 2) + 100, gJanela.getAltura() / 2);

	base[1]->setSpriteSheet("Mage", "../assets/spriteSheets/Mage.png", 4, 4);

	base[1]->setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	base[1]->desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	base[2]->setSpriteSheet("Rouge", "../assets/spriteSheets/Rouge.png", 4, 4);

	base[2]->setPos((gJanela.getLargura() / 2) + 25, gJanela.getAltura() / 2);
	base[2]->desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	//carregar inimigo
	inimigoo->setSpriteSheet("Inimigo", "../assets/spriteSheets/BlueKnight.png", 4, 4);

	inimigoo->setPos(gJanela.getLargura()/2, gJanela.getAltura() / 2);
	inimigoo->desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	inimigoo->setSpriteInim();

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
	while(/*!gTeclado.soltou[TECLA_ESC] &&*/ !gEventos.sair && getSair())
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
		case tPause: telaPause();
			break;
		case tRanking: telaRanking();
			break;
		}
		
		

		uniTerminarFrame();
	}
}

void Jogo::telaMenu()
{
	fundoMenu.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	if(!gMusica.estaTocando())
		gMusica.tocar("musicaJogo", true);

	bJogar.atualizar();
	bJogar.desenhar();

	bInstrucoes.atualizar();
	bInstrucoes.desenhar();

	bCreditos.atualizar();
	bCreditos.desenhar();

	bSair.atualizar();
	bSair.desenhar();

	bRanking.atualizar();
	bRanking.desenhar();

	if (bJogar.estaClicado() && confirma != true) {
		//telaAtual = tJogo;
		pilhamenu.push(tJogo);
		gMusica.parar();
	}
	if (bSair.estaClicado()) {
		//sysRanking.salvar(sysLogin.getUsuario());
		confirma = true;
		
	}
	if (bInstrucoes.estaClicado() && confirma != true) {
		pilhamenu.push(tInstrucoes);
	}
	if (bCreditos.estaClicado() && confirma != true) {
		pilhamenu.push(tCreditos);
	}
	if (bRanking.estaClicado() && confirma != true) {
		pilhamenu.push(tRanking);
	}

	/*if (gTeclado.segurando[TECLA_ESC]) {
		confirma = true;
	}*/

	if (confirma == true) {
		txtSair.setFonte("arial");
		txtSair.setCor(Branco);
		txtSair.setString("Tem certeza que deseja sair ? \nENTER para sair\nESPACO para voltar");
		txtSair.desenhar(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) - 100);

		if (gTeclado.pressionou[TECLA_ESPACO]) {
			confirma = false;
		}
		if (gTeclado.pressionou[TECLA_ENTER]) {
			sysRanking.salvar(sysLogin.getUsuario());
			saida = false;
		}
	}
}

void Jogo::telaInstrocoes()
{
	fundoJogar.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	bVoltar.atualizar();
	bVoltar.desenhar();

	txtCreditos.setCor(Branco);
	txtCreditos.setFonte("arial");
	txtCreditos.setString("Intrucoes:\n"
		"Mover p/ cima..........SETA PARA CIMA ou W\n"
		"Mover p/ baixo........SETA PARA BAIXO ou S\n"
		"Mover p/ esquerda..SETA PARA ESQUERDA ou A\n"
		"Mover p/ direita....SETA PARA DIREITA ou D\n"
		"Especial......................tecla ESPACO\n\n"
		"TROCA DE PERSONAGEM:\n"
		"Guerreiro..........................TECLA 1\n"
		"Mago...............................TECLA 2\n"
		"Ladino.............................TECLA 3\n");

	txtCreditos.desenhar(gJanela.getLargura() / 2, 200);

	if (bVoltar.estaClicado() || gTeclado.pressionou[TECLA_ESC]) {
		pilhamenu.pop();
	}
}

void Jogo::telaCreditos()
{
	fundoJogar.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	
	txtCreditos.setCor(Branco);
	txtCreditos.setFonte("arial");
	txtCreditos.setString("Créditos: \n"
		"\nsprites:"
		"\nKnight...............assetsProf.Raphael"
		"\nMage.................assetsProf.Raphael"
		"\nRouge................assetsProf.Raphael"
		"\nGhost.....................googleImagens"
		"\nInimigo...........................Paulo"

		"\nbotoes:"
		"\nbotoes do menu principal..........Paulo"
		"\nbotoes do menu de login...........Andre"

		"\nfundo:"
		"\nFundoJogo.........................Paulo"
		"\nFundoMenu.........................Paulo"

		"\nprogramacao:"
		"\npreparacao do projeto.............Bruno"
		"\nmontagem da base do projeto.......Bruno"
		"\nanimacao..........................Andre"
		"\nmovimentacao......................Andre"
		"\nespeciais.........................Andre"
		"\ntroca de personagem...............Andre"
		"\ncolisoes..........................Andre"
		"\nmenus e suas funcionalidades......Andre"
		"\nsistema de usuario, login e senha.Andre"
		"\nprogrmacao inimigo................Bruno"
		"\ncorrecao de bugs..................Bruno"

		"\nmusicas:"
		"\nepic....................site : bensound"
		"\nmusica jogo....................internet"

		"\nfontes:"
		"\nBearskin.otf.......site : 1001freefonts"
		"\nOldExcalibur.......site : 1001freefonts"
		"\narial..................Fonte do windows"

		"\nsoftware:"
		"\nMicrosoft Visual Studio 2017 / 2019"
		"\nBiblioteca LibUnicornio");
	
	txtCreditos.desenhar(gJanela.getLargura() / 2, y);
	

	if (y > -451) {
		y--;
		txtCreditos.desenhar(gJanela.getLargura() / 2, y);
	}
	else {
		y = 1050;
	}

	/*if (gTeclado.segurando[TECLA_BAIXO]) {
		y--;
		txtCreditos.desenhar(gJanela.getLargura() / 2, y);
	}
	if (gTeclado.segurando[TECLA_CIMA]) {
		y++;
		txtCreditos.desenhar(gJanela.getLargura() / 2, y);
	}*/

	bVoltar.atualizar();
	bVoltar.desenhar();

	if (bVoltar.estaClicado() || gTeclado.pressionou[TECLA_ESC]) {
		pilhamenu.pop();
	}
}

void Jogo::telaJogo()
{
	fundoJogar.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
    if(!gMusica.estaTocando())
		gMusica.tocar("Epic", true);

	int xInim, yInim;
	
	

			

	base[0]->atualizar();
	base[1]->atualizar();
	base[2]->atualizar();
	//base[3]->atualizar();

	base[per]->mover();

	xInim = base[per]->getX();
	yInim = base[per]->getY();
	inimigoo->atualizar();

	inimigoo->Movimentar(xInim, yInim);
	

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
	
	//indicador de personagem
	if (per == 0)
		gGraficos.desenharTexto("Controlando Guerreiro",80, 30, 255, 0, 0, 255);

	if (per == 1)
		gGraficos.desenharTexto("Controlando Mago", 80, 30, 255, 0, 0, 255);

	if (per == 2)
		gGraficos.desenharTexto("Controlando Ladino", 80, 30, 255, 0, 0, 255);

	if (gTeclado.pressionou[TECLA_ESC])
	{
		pilhamenu.push(tPause);
	}
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

void Jogo::telaPause()
{
	fundoJogar.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	bSair.atualizar();
	bSair.desenhar();

	txtCreditos.setCor(Branco);
	txtCreditos.setFonte("arial");
	txtCreditos.setString("Pause Menu!\nPrecione ESC para voltar continuar\nClique em sair para voltar ao menu");
	txtCreditos.desenhar(gJanela.getLargura()/ 2, (gJanela.getAltura() / 2) - 100);

	if (gTeclado.pressionou[TECLA_ESC])
	{
		pilhamenu.pop();
	}
	if (bSair.estaClicado()) {
		pilhamenu.pop();
		pilhamenu.pop();
	}
	gMusica.parar();
}

void Jogo::telaRanking()
{
	gMusica.parar();
	fundoJogar.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	/*
	txtCreditos.setCor(Branco);
	txtCreditos.setFonte("arial");
	txtCreditos.setString("Exibindo o ranking");
	txtCreditos.desenhar(gJanela.getLargura() / 2, 200);
	*/
	sysRanking.prepararRanking();//nao esta funcionando

	bVoltar.atualizar();
	bVoltar.desenhar();

	if (bVoltar.estaClicado() || gTeclado.pressionou[TECLA_ESC]) {
		pilhamenu.pop();
	}

	
}
