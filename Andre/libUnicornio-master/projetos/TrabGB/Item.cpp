#include "Item.h"



Item::Item()
{
}


Item::~Item()
{
}

void Item::defineTipo(Tipo t)
{
	switch (t)
	{
	case arma: tipo = 1;
		break;
	case armadura: tipo = 2;
		break;
	case item: tipo = 3;
		break;
	case consumivel: tipo = 4;
		break;
	default:
		break;
	}
}
void Item::carregarSpriteSheet(std::string n, std::string caminho, int anim, int freme)
{
	gRecursos.carregarSpriteSheet(n, caminho, anim, freme);
}