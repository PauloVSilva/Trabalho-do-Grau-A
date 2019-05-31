#pragma once
#include<fstream>
#include"InputTexto.h"
#include"libUnicornio.h"
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
	std::string u = "usuario", s = "senbha";
	std::fstream arq;

	//Input de Texto
	InputTexto input;
	Texto tEscrita, teste;
	Cor verleho;
	bool bUsuario = false, bSenha1 = false, bSenha2 = false, inputInicio = false;
	std::string user = "", sn1 = "", sn2 = "";

	int t = 10;
};

