#pragma once

template<class T>
class No
{
public:
	No() { proximo = nullptr; anterior = nullptr; info = nullptr; }
	~No() {}

	T* info;
	T* proximo;
	T* anterior;
};
