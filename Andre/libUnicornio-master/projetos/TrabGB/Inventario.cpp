#include "Inventario.h"



Inventario::Inventario()
{
}


Inventario::~Inventario()
{
}

void Inventario::inserirItem(int id, Tipo t, string nome, int peso)
{
	item = new Item;

	item->id = id;
	item->nome = nome;
	item->defineTipo(t);
	item->peso;

	inventario.push_back(*item);
}
