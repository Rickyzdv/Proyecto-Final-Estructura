#include "ListaDoctores.h"

ListaDoctores::ListaDoctores()
{
    cabecera = final = NULL;
}

void ListaDoctores::InsertarDoctorInicio(Doctor nuevo)
{
    nodo = new elemento_doctor;
    nodo->datos = nuevo;
    nodo->siguiente = cabecera;
    cabecera = nodo;
    if (final == NULL) 
    {
        final = nodo;
    }
}

Doctor ListaDoctores::ExtraerInicio()
{
    Doctor aux;
    aux.enfermedad = " ";
    aux.especialidad = '-1';
    aux.id_doctor = " ";
    aux.nombre = " ";


    if (cabecera == NULL) 
    {
        return aux;
    }
    nodo = cabecera;
    aux = nodo->datos;
    cabecera = nodo->siguiente;

    delete nodo;

    return aux;
}

Doctor ListaDoctores::ExtraerInter(string id)
{
    Doctor aux;
    aux.enfermedad = " ";
    aux.especialidad = '-1';
    aux.id_doctor = " ";
    aux.nombre = " ";

    bool found = false;

    elemento_doctor *nodoAnterior = NULL;
    nodo = cabecera;

    while (nodo != NULL) 
    {
        if (nodo->datos.id_doctor == id) {
            found = true;
            break;
        }
        nodoAnterior = nodo;
        nodo = nodo->siguiente;
    }
    
    if (found == false)
    {
        return aux;
    }

    if (nodo == cabecera)
    {
        aux = ExtraerInicio();
        return aux;
    }

    if (nodo == final)
    {
        aux = ExtraerFinal();
        return aux;
    }

    aux = nodo->datos;
    nodoAnterior->siguiente = nodo->siguiente;

    delete nodo;
    return aux;
}

Doctor ListaDoctores::ExtraerFinal()
{
    Doctor aux;
    aux.enfermedad = " ";
    aux.especialidad = '-1';
    aux.id_doctor = " ";
    aux.nombre = " ";

    if (cabecera == NULL) 
    {
        return aux;
    }
    if (cabecera == final)
    {
        aux = ExtraerInicio();
        return aux;
    }

    elemento_doctor* nodoAnterior = NULL;
    nodo = cabecera;

    while (nodo != final) 
    {
        nodoAnterior = nodo;
        nodo = nodo->siguiente;
    }

    nodoAnterior->siguiente = NULL;
    aux = nodo->datos;
    final = nodoAnterior;
    return aux;
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
        cout << "\tID: " << nodo->datos.id_doctor;
        cout << "\tNombre: " << nodo->datos.nombre;
        if (nodo == cabecera)
        {
            cout << "\t<- primero";
        }
        if (nodo == final)
        {
            cout << "\t<- último";
        }
        cout << endl;
        cout << endl;
        nodo = nodo->siguiente;
    }
}