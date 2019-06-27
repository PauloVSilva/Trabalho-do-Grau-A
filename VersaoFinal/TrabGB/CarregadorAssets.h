#pragma once
#include<fstream>
#include"libUnicornio.h"
#include<string>
class CarregadorAssets
{
public:
	CarregadorAssets();
	~CarregadorAssets();

	bool carregarRecursos(std::ifstream &carregador);

private:
	std::ifstream arqEntrada;

	std::string caminho, nome, tipo, *sTokken;
	int nFrame, nAnim, *iTokken;
};

