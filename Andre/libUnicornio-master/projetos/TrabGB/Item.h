#pragma once
#include<string>
#include"libUnicornio.h"

enum Tipo{arma, armadura, item, consumivel};

class Item
{
public:
	Item();
	~Item();

	void defineTipo(Tipo t);
	void carregarSpriteSheet(std::string n,std::string caminho, int anim, int freme);
	void desenhar(int x, int y) { sprite.desenhar(x, y); }

	int id;
	std::string nome;
	int peso;

private:
	Sprite sprite;
	int tipo;
};

