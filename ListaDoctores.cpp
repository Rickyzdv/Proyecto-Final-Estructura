#include "ListaDoctores.h"

ListaDoctores::ListaDoctores()
{
    cabecera = final = NULL;
}

void ListaDoctores::InsertarDoctorInicio(Doctor nuevo)
{
    nodo = new Doctor;
    *nodo = nuevo;
    cabecera = nodo;
    if (final == NULL) 
    {
        final = nodo;
    }
}

Doctor* ListaDoctores::ExtraerInicio()
{
    if (cabecera == NULL) 
    {
        return NULL;
    }
    Doctor* extraido = cabecera;
    cabecera = cabecera->siguiente;
    if (cabecera == NULL) 
    {
        final = NULL;
    }
    return extraido;
}

Doctor* ListaDoctores::ExtraerInter(string id)
{
    if (cabecera == NULL) 
    {
        return NULL;
    }

    Doctor* nodoAnterior = NULL;
    nodo = cabecera;

    while (nodo != NULL) 
    {
        if (nodo->id == id) {
            if (nodo == cabecera) 
            {
                return ExtraerInicio();
            }
            if (nodo == final) 
            {
                return ExtraerFinal();
            }

            nodoAnterior->siguiente = nodo->siguiente;
            return nodo;
        }
        nodoAnterior = nodo;
        nodo = nodo->siguiente;
    }
    return NULL;
}

Doctor* ListaDoctores::ExtraerFinal()
{
    if (cabecera == NULL) 
    {
        return NULL;
    }
    if (cabecera == final)
    {
        return ExtraerInicio();
    }

    Doctor* nodoAnterior = NULL;
    nodo = cabecera;

    while (nodo->siguiente != final) 
    {
        nodoAnterior = nodo;
        nodo = nodo->siguiente;
    }

    nodoAnterior->siguiente = NULL;
    Doctor* extraido = final;
    final = nodoAnterior;
    return extraido;
}
void ListaDoctores::MostrarDoctores()
{
    cout << "\nLista de Doctores Disponibles:" << endl;
    if (cabecera == NULL) 
    {
        cout << "\n\tNo hay doctores disponibles." << endl;
        return;
    }
    nodo = cabecera;
    while (nodo != NULL) 
    {
        cout << "\tID: " << nodo->id;
        cout << "\tNombre: " << nodo->nombre << endl;
        nodo = nodo->siguiente;
    }
}