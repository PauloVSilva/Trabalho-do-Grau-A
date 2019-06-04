#pragma once
#include<fstream>
#include"InputTexto.h"
#include"libUnicornio.h"
#include"Usuario.h"
#include"ListaUsuario.h"
class SistemaLogin
{
public:
	SistemaLogin();
	~SistemaLogin();

	bool inicializar();
	bool cadastrar(std::string user, std::string senha);

	bool iniciarCadastro();
private:
	std::fstream login;
	Texto texto;
	std::string sTokken;
	std::fstream arq;

	//Input de Texto
	InputTexto input;
	Texto tEscrita, teste;
	Cor verleho;
	bool bUsuario = false, bSenha1 = false, bSenha2 = false, inputInicio = false;
	std::string user = "", sn1 = "", sn2 = "";

	int t = 10;

	//controle de lista
	//ListaUsuario<Usuario> * listUser = new ListaUsuario<Usuario>;
	Usuario * userDude;
};

