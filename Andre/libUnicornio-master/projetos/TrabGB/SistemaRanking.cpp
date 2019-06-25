#include "SistemaRanking.h"



//SistemaRanking::SistemaRanking()
//{
//}
//
//
//SistemaRanking::~SistemaRanking()
//{
//}

bool SistemaRanking::inicializar()
{
	arq.open("../assets/ranking.txt", std::ios::in);

	if (arq.is_open()) {

		while (!arq.eof()) {
			arq >> sTokken;
			nome = sTokken;

			if (sTokken == nome) {
				arq >> sTokken;
				if (sTokken == " Pontos: ") {
					arq >> iTokken;

					if (iTokken > pontos) {
						pontos = iTokken;
					}
					usuario.nome = nome;
					usuario.pontos = pontos;
					filaUsuario.push(usuario);
				}
			}
		}
	
		arq.close();
		return true;
	}
	else {
		gDebug.erro("arquivo Ranking nao abriu!");
		return false;
	}

}

bool SistemaRanking::salvar(Usuario &u)
{
	usuario = u;
	arq.open("../assets/ranking.txt", std::ios::app | std::ios::out);

	if (arq.is_open()) {
		test = " Pontos: ";
		arq << usuario.nome << test << usuario.pontos;

		arq.close();
		return true;
	}
	else {
		gDebug.erro("arquivo Ranking nao abriu para salvar!");
		return false;
	}
}

void SistemaRanking::prepararRanking()
{
	branco.set(255, 255, 255, 255);
	txtRanking.setFonte("arial");
	txtRanking.setCor(branco);

	if (!filaUsuario.empty()) {
		txtRanking.setString(filaUsuario.front().nome + " Pontos: " + std::to_string(filaUsuario.front().pontos));
		filaUsuario.pop();
	}
}
