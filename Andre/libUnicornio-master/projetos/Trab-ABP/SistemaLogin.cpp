#include "SistemaLogin.h"



SistemaLogin::SistemaLogin()
{
	
}


SistemaLogin::~SistemaLogin()
{
}

bool SistemaLogin::inicializar() {
	arq.open("../assets/login.dat", std::ios::binary | std::ios::in);
	if (arq.is_open()) {
		if (arq.eof()) {
			gDebug.erro("arquivo vazio");
		}
		else {
			while (!arq.eof())
			{
				uUsuario = new Usuario;
				//ler Usuario
				arq.read(reinterpret_cast<char*>(&sTokken), sizeof(sTokken));
				uUsuario->nome = sTokken;

				//ler senha
				arq.read(reinterpret_cast<char*>(&sTokken), sizeof(sTokken));
				uUsuario->senha = sTokken;

				/*listUser*/
				listaUsuario.push_back(*uUsuario);

			}
		}
		arq.close();
		return true;
	}
	else {
		return false;
	}
}

bool SistemaLogin::cadastrar(std::string user, std::string senha) {
	arq.open("../assets/login.dat", std::ios::binary | std::ios::out | std::ios::app);

	if (arq.is_open()) {
			//salvar usuario
			arq.write(reinterpret_cast<const char*>(&user),sizeof(user));

			//savar senha
			arq.write(reinterpret_cast<const char*>(&senha), sizeof(user));

			return true;
		arq.close();
	}
	else {
		gDebug.erro("Erro ao abrir o arquivo login para cadastro");
		return false;
	}
}

bool SistemaLogin::iniciarCadastro()
{
	cadastroUsuario = new Usuario;

	tEscrita.setFonte("Fonte1");
	verleho.set(255, 0, 0, 255);
	tEscrita.setCor(verleho);

	if (inputInicio == false) {
		input.inicializar();
		inputInicio = true;
	}

	if (bUsuario == false) {//Salvar Usuario
		//configurar texto
		tEscrita.setString("Iforme o seu nome de Usuario:");
		tEscrita.desenhar(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) - 40);
		//inicializar Input
		input.atualizar();
		input.desenhar();

		if (gTeclado.pressionou[TECLA_ENTER] || gTeclado.pressionou[TECLA_ENTER2]) {
			user = input.getTexto();
			//teste = input.getTextoTxt();
			input.finalizar();

			if (user != "") {
				//verificar lista de usuarios
				fimLista = listaUsuario.back();
				while (listaUsuario.front().nome != fimLista.nome)
				{
					if (listaUsuario.front().nome == user) {
						usuarioRepetido = true;
						gDebug.erro("Usuario ja existente!");
						break;
					}
					else {
						aux = listaUsuario.front();
						listaUsuario.pop_front();
						listaUsuario.push_back(aux);
					}
				}
				//
				if (usuarioRepetido == false) {
					bUsuario = true;
					inputInicio = false;

					cadastroUsuario->nome = user;
				}
			}
			else {
				input.inicializar();
			}
		}
	}
	else if (bSenha1 == false) {
		//configurar texto
		tEscrita.setString("Informe a sua senha:");//informar a senha
		tEscrita.desenhar(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) - 40);

		//inicializar Input
		input.atualizar();
		input.desenhar();

		if (gTeclado.pressionou[TECLA_ENTER] || gTeclado.pressionou[TECLA_ENTER2]) {
			sn1 = input.getTexto();
			input.finalizar();

			if (sn1 != "") {
				bSenha1 = true;
				inputInicio = false;
				bSenha2 = false;
			}
			else {
				input.inicializar();
			}
		}
	}
	else if (bSenha2 == false) {
		//configurar texto
		tEscrita.setString("Confirme a senha a sua senha:");//confirmar senha
		tEscrita.desenhar(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) - 40);

		//inicializar Input
		input.atualizar();
		input.desenhar();

		if (gTeclado.pressionou[TECLA_ENTER] || gTeclado.pressionou[TECLA_ENTER2]) {
			sn2 = input.getTexto();
			input.finalizar();

			if (sn2 != "") {
				bSenha2 = true;
				inputInicio = false;
			}
			else {
				input.inicializar();
			}
		}
	}
	if (bSenha1 == true && bSenha2 == true) {//verifica se as senhas foram prenchidas
		if (sn1 != "" && sn2 != "") {//verrifica se as senhas nao estao vazias
		if (sn1 == sn2) {//verifica se as senhas sao iguais
			tEscrita.setString("Senha salva:");
			tEscrita.desenhar(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) - 40);

			cadastroUsuario->senha = sn1;

			listaUsuario.push_back(*cadastroUsuario);

			logando = *cadastroUsuario;

			cadastrar(user, sn1);
			return true;
		}
		else {
			tEscrita.setString("Senha incorreta: precione ENTER para redigitala");
			tEscrita.desenhar(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) - 40);
			gDebug.erro("Senha incorreta");

			if (gTeclado.pressionou[TECLA_ENTER]) {//reiniciar cadastro
				bSenha1 = false;
			}

			return false;
		}
	}
		else {
			tEscrita.setString("Erro: variaveis de senha vazias!");
			tEscrita.desenhar(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) - 40);
			return false;
		}
	}
}

void SistemaLogin::finalizar()
{
	listaUsuario.clear();
	delete uUsuario;
	delete cadastroUsuario;
}

bool SistemaLogin::iniciarLogin()
{
	tEscrita.setFonte("Fonte1");
	verleho.set(255, 0, 0, 255);
	tEscrita.setCor(verleho);

	if (lUser == false) {//verificar usuario
		tEscrita.setString("Informe seu nome de usuario:");
		tEscrita.desenhar(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) - 40);

		if (inputInicio == false) {
			input.inicializar();
			inputInicio = true;
		}

		input.atualizar();
		input.desenhar();

		if(input.getTexto() != "")
			if (gTeclado.pressionou[TECLA_ENTER]) {
				if (listaUsuario.front().nome == input.getTexto()) {
				lExiste = true;
				}
				while (fimLista.nome != listaUsuario.front().nome) {
					if (listaUsuario.front().nome == input.getTexto()) {
						lExiste = true;
						break;
					}
					aux = listaUsuario.front();
					listaUsuario.pop_front();
					listaUsuario.push_back(aux);
				}
				lUser = true;
			}
		if (lUser == true) {
			if (lExiste == false) {
				gDebug.erro("Usuario nao existe!");
				inputInicio = false;
				lUser = false;
			}
			else {
				logando = listaUsuario.front();
				lUser = true;
				lSenha = false;
				input.finalizar();
				inputInicio = false;
			}
		}	
	}

	if (lSenha == false) {//verificar senha
		tEscrita.setString("Informe sua senha:");
		tEscrita.desenhar(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) - 40);
		
		if (inputInicio == false) {//ativar input
			input.inicializar();
			inputInicio = true;
		}
		input.atualizar();
		input.desenhar();

		if (gTeclado.pressionou[TECLA_ENTER] && input.getTexto() != "") {
			if (logando.senha == input.getTexto()) {
				lSenha = true;
				input.finalizar();
				return true;
			}
			else {
				gDebug.erro("Senha incorreta!");
				//return false;
			}
		}
	}
}