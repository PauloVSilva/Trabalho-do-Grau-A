#pragma once
#include<fstream>
#include"libUnicornio.h"
class SistemaLogin
{
public:
	SistemaLogin();
	~SistemaLogin();

	bool inicializar();
	bool cadastrar(std::fstream &arq, std::string user, std::string senha);

private:
	std::fstream login;
	Texto texto;
	std::string u = "usuario", s = "senbha";

	int t = 10;
};

