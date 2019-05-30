#pragma once
#include "PersoBase.h"
class Mage :
	public PersoBase
{
public:
	Mage();
	~Mage();

	void SoltarFantasma();
	void seguir();

	 void especial(int e) override;
	 void animar(int e);

private:
	Sprite special;
	int fanX, fanY;
};

