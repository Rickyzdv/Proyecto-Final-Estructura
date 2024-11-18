#include "lista_pacientes.h"

lista_pacientes::lista_pacientes()
{
    cabecera = final = NULL;
}

lista_pacientes::~lista_pacientes()
{
}

void lista_pacientes::InsertarPaciente(Paciente nuevo)
{
    nodo = new elemento_lista_pacientes;
    nodo->datos = nuevo;
    nodo->siguiente = cabecera;
    cabecera = nodo;
    if (final == NULL)
    {
        final = nodo;
    }
}

void lista_pacientes::InsertarPacienteFinal(Paciente data)
{
    if (final == NULL)
    {
        InsertarPaciente(data);
        return;
    }
    nodo = new elemento_lista_pacientes;
    nodo->datos = data;
    nodo->siguiente = NULL;
    final->siguiente = nodo;
    final = nodo;
}

Paciente lista_pacientes::ExtraerInicio()
{
    Paciente aux;
    aux.enfermedad = "-1";
    aux.id_paciente = "-1";
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

Paciente lista_pacientes::ExtraerInter(string enfermedad)
{
    Paciente aux;
    aux.enfermedad = "-1";
    aux.id_paciente = "-1";
    aux.nombre = "-1";

    bool found = false;

    elemento_lista_pacientes* nodoAnterior = NULL;
    nodo = cabecera;

    while (nodo != NULL)
    {
        if (nodo->datos.enfermedad == enfermedad) {
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

Paciente lista_pacientes::ExtraerFinal()
{
    Paciente aux;
    aux.enfermedad = "-1";
    aux.id_paciente = "-1";
    aux.nombre = "-1";

    if (cabecera == NULL)
    {
        return aux;
    }
    if (cabecera == final)
    {
        aux = ExtraerInicio();
        return aux;
    }

    elemento_lista_pacientes* nodoAnterior = NULL;
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

void lista_pacientes::mostrar()
{
    if (cabecera == NULL)
    {
        cout << "Lista de espera VACIA" << endl;
    }
    nodo = cabecera;
    while (nodo != NULL)
    {
        cout << "\n\tID: " << nodo->datos.id_paciente;
        cout << "\n\tNombre: " << nodo->datos.nombre;
        cout << "\n\tEnfermedad: " << nodo->datos.enfermedad;
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
