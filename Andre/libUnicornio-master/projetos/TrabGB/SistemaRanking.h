#pragma once
#include"libUnicornio.h"
#include<fstream>
class SistemaRanking

{
public:
	SistemaRanking() {}
	~SistemaRanking() {}

	bool inicializar();

private:
	std::fstream arq;
};

