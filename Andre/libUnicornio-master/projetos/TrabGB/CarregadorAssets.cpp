#include "CarregadorAssets.h"



CarregadorAssets::CarregadorAssets()
{
}


CarregadorAssets::~CarregadorAssets()
{
}

bool CarregadorAssets::carregarRecursos(std::ifstream &carregador)
{
	if(carregador.is_open()) {

		//while (!carregador.eof()) {
			arqEntrada >> *sTokken;
			if (*sTokken == "fundo") {
				tipo = *sTokken;

				arqEntrada >> *sTokken;
				nome = *sTokken;

				arqEntrada >> *sTokken;
				caminho = *sTokken;

				gRecursos.carregarSpriteSheet(nome, caminho);
			//}
		}
	carregador.close();
	return true;
}
	else {
		gDebug.erro("nao foi possivel abrir o arquivo!");
		return false;
	}
}
