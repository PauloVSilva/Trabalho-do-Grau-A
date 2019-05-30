#include "SistemaLogin.h"



SistemaLogin::SistemaLogin()
{
}


SistemaLogin::~SistemaLogin()
{
}

bool SistemaLogin::inicializar() {
	login.open("../assets/login.dat",std::ios::binary | std::ios::out);

	if (login.is_open()) {

		while (!login.eof()) {
			login.write(reinterpret_cast<const char*>(&t), sizeof(int));
			break;
		}

		login.close();
		return true;
	}
	else {
		gDebug.erro("Arquivo Login nao abriu!");
		return false;
	}
}

bool SistemaLogin::cadastrar(std::fstream &arq, std::string user, std::string senha) {
	arq.open("../assets/login.dat", std::ios::binary | std::ios::out);

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
