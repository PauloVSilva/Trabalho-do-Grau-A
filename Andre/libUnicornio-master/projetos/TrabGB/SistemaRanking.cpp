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
	arq.open("../assets/ranking.txt", std::ios::trunc | std::ios::out);

	if (arq.is_open()) {

		arq.close();
		return true;
	}
	else {
		gDebug.erro("arquivo Ranking nao abriu!");
		return false;
	}

}
