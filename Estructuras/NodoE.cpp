#ifndef NODO_H
#define NODO_H

#include <stdlib.h>
#include "Estudiante.cpp"

template <typename Estudiante>
class Nodo
{
private:
    /* data */
public:
    T valor;
    int id;
    Nodo * siguiente; 
    Nodo * anterior;
    Nodo(Estudiante _valor, int _id);
    ~Nodo();
};


template <typename Estudiante>
Nodo<Estudiante>::Nodo(Estudiante _valor,int _id)
{
    this->valor = _valor;
    this->siguiente = NULL;
    this->anterior = NULL;
    this->id = _id;
}

template <typename Estudiante>
Nodo<Estudiante>::~Nodo()
{
}

#endif // NODO_H