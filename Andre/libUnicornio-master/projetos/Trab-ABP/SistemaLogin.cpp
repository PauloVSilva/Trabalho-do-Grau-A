#include "SistemaLogin.h"



SistemaLogin::SistemaLogin()
{
	
}


SistemaLogin::~SistemaLogin()
{
}

bool SistemaLogin::inicializar() {
	return false;
}

bool SistemaLogin::cadastrar(std::string user, std::string senha) {
	arq.open("../assets/login.dat", std::ios::binary | std::ios::out | std::ios::app);

	if (arq.is_open()) {
			//salvar usuario
			arq.write(reinterpret_cast<const char*>(&u), sizeof(u));
			arq.write(reinterpret_cast<const char*>(&user),sizeof(user));

			//savar senha
			arq.write(reinterpret_cast<const char*>(&s), sizeof(s));
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
			teste = input.getTextoTxt();
			input.finalizar();

			if (user != "") {
				bUsuario = true;
				inputInicio = false;
			}
			else {
				input.inicializar();
			}
		}
	}
	else if (bSenha1 == false) {
		//configurar texto
		tEscrita.setString("Iforme a sua senha:");
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
			}
			else {
				input.inicializar();
			}
		}
	}
	else if (bSenha2 == false) {
		//configurar texto
		tEscrita.setString("Confirme a senha a sua senha:");
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
	if (bSenha1 == true && bSenha2 == true) {
		if (sn1 != "" && sn2 != "") {
		if (sn1 == sn2) {
			tEscrita.setString("Senha salva:");
			tEscrita.desenhar(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) - 40);

			cadastrar(user, sn1);
			return true;
		}
		else {
			tEscrita.setString("Senha incorreta:");
			tEscrita.desenhar(gJanela.getLargura() / 2, (gJanela.getAltura() / 2) - 40);
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
