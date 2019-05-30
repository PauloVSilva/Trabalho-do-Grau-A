#include "Rouge.h"



Rouge::Rouge()
{
}


Rouge::~Rouge()
{
}

void Rouge::especial(int e)
{
	if (e == 2) {
		setVel(4);
	}
	else
	{
		setVel(1);
	}
	
}
