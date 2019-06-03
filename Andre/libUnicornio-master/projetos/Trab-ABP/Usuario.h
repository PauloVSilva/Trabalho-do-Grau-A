#pragma once
#include<string>
class Usuario
{
public:
	Usuario() { senha = ""; usuario = ""; }
	~Usuario() {}

	std::string senha, usuario;
};

