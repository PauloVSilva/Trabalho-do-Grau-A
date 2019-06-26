#pragma once
#include"libUnicornio.h"
#include"Usuario.h"
#include<fstream>
#include<queue>
class SistemaRanking

{
public:
	SistemaRanking() {}
	~SistemaRanking() {}

	bool inicializar();
	bool salvar(Usuario &u);
	void prepararRanking();

private:
	std::fstream arq;
	Usuario usuario, *usuario2;
	std::string test;

	//leitura
	std::string sTokken, nome;
	int iTokken, pontos = 0;
	std::queue<Usuario> filaUsuario;

	//ranking
	Texto txtRanking;
	Cor branco;
};

