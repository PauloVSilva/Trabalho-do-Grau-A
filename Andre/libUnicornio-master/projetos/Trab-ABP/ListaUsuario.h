#pragma once
#include "No.h"
#include "Usuario.h"
#include"libUnicornio.h"
template<class T>
class ListaUsuario
{
	ListaUsuario() {}
	~ListaUsuario() {}

	void adicionarUsuario(T* user);
	void removerUsuario();
	T* buscarUsuario(T * elemento);

private:
//	No<T>* inicioLista new No<T>;
	No<T>* listaAux;
	No<T>* percorreLista;
};

template<class T>
void ListaUsuario<T>::adicionarUsuario(T* user)
{
	listaAux new No<T>;
	percorreLista new No<T>;
	//se a primeira posicao da lista estiver vazia
	if (inicioLista->info == nullptr && inicioLista->proximo() == nullptr) {
		inicioLista->info = user;
	}
	else {
		//se nao percorrer a lista até encontrar o ultimo elemento
		listaAux = inicioLista;
		inicioLista->proximo = percorreLista;
		percorreLista->anterior = listaAux;
		while (percorreLista->proximo != nullptr)
		{
			listaAux = percorreLista;
			percorreLista = percorreLista->proximo;
			percorreLista->anterior = listaAux;
		}
		percorreLista->info = user();
	}
}

template<class T>
void ListaUsuario<T>::removerUsuario() {
	//remover sempre o ultimo da lista(sistema de fila)
	if (percorreLista->proximo == nullptr) {
		percorreLista->info = nullptr;
		delete percorreLista;
	}
	else if(inicioLista->proximo() == nullptr)
	{
		inicioLista->info = nullptr;
	}
	else {
		while (percorreLista->proximo != nullptr)
		{
			listaAux = percorreLista;
			percorreLista = percorreLista->proximo;
			percorreLista->anterior = listaAux;
		}
		percorreLista->info = nullptr;
		delete percorreLista;
	}
}

template<class T>
T* ListaUsuario<T>::buscarUsuario(T *elemento) {
	if (inicioLista->info == elemento) {
		return inicioLista->info;
	}
	else {
		while(percorreLista->proximo != nullptr) {

			if (percorreLista->info == elemento) {
				return percorreLista->info;
				break;
			}
			listaAux = percorreLista;
			percorreLista = percorreLista->proximo;
			percorreLista->anterior = listaAux;
		}
		if (percorreLista->proximo == nullptr && percorreLista->info != elemento) {
			gDebug.erro("Usuario nao encontrado!");
		}
	}
}
