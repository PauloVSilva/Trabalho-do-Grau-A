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
	arq.open("../assets/ranking.txt", std::ios::in);//abre o arquivo para leitura

	if (arq.is_open()) {//verifica se o arquivo abriu
		usuario2 = new Usuario;

		while (!arq.eof()) {//while so termina quando o arquivo chegar no fim
			arq >> sTokken;//le o arquivo
			nome = sTokken;//passa para nome

			if (sTokken == nome) {
				arq >> sTokken;//le novamente o arquivo
				if (sTokken == " Pontos: ") {//compara com a imformacao esperada
					arq >> iTokken;//le o arquivo dessa vez com um Tokken para interiro

					if (iTokken > pontos) {//verifica se tokken e maior que pontos se sim
						pontos = iTokken;//substitui o valor original de pontos
					}
					usuario2->nome = nome; //atribui nome para um obj da classe usuario
					usuario2->pontos = pontos;//atribui pontos para um obj da classe usuario
					filaUsuario.push(*usuario2);//adiciona esse usuario na fila
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
	arq.open("../assets/ranking.txt", std::ios::out | std::ios::app);

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
	//definir conf. do texto
	//branco.set(255, 255, 255, 255);	

	txtRanking.setCor(branco);
	txtRanking.setFonte("arial");
	txtRanking.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);//nao esta desenhando
	

	if (!filaUsuario.empty()) {//se a fila de usuario nao estiver vazia
		txtRanking.setString(filaUsuario.front().nome + " Pontos: " + std::to_string(filaUsuario.front().pontos));//desenhar score de primeiro da fila(provavelmente tem erro aqui)
		filaUsuario.pop();//remove o primeiro da fila
	}

	
}
