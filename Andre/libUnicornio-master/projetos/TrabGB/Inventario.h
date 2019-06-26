#pragma once
#include<list>
#include"Item.h"
class Inventario
{
public:
	Inventario();
	~Inventario();

	void inserirItem(int id,Tipo t, string nome, int peso);
private:
	Item *item;
	list<Item> inventario;
};

/*para desenhar usar logica de matriz, semelhante ao trabalho do Grau A de algoritimos 1*/
/*provavelmente deve ser incluido no perso baase*/