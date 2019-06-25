#pragma once
#include "PersoBase.h"
class Knight :
	public PersoBase
{
public:
	Knight();
	~Knight();

	void especial(int e) override;


private:
	Texto font1;
	Cor cor;
};

