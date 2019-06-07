#pragma once
#include<fstream>
#include"InputTexto.h"
#include"libUnicornio.h"
#include<list>
#include"Usuario.h"
class SistemaLogin
{
public:
	SistemaLogin() {};
	~SistemaLogin() {};

	bool inicializar();
	bool cadastrar(std::string user, std::string senha);
	void finalizar();


	bool iniciarCadastro();
	bool iniciarLogin();

	bool percorrerUsuario(std::string &alvo, list<Usuario> &fLista);

	bool getLoginAprovado() { return logouEssaMerda; }
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

	//Input login
	bool lUser = false, lSenha = true, lExiste = false;
	Usuario logando;
	std::string test1, test2;
	bool logouEssaMerda = false;

	int t = 10;

	//controle de lista
	list<Usuario> listaUsuario;
	Usuario* uUsuario, fimLista, aux, *cadastroUsuario;
	bool usuarioRepetido = false;
};

