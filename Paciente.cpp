#include "Paciente.h"

ColaPacientes::ColaPacientes()
{
	principio = final = NULL;
}

void ColaPacientes::InsertarPaciente(Paciente nuevo)
{
    nodo = new elemento;

    nodo->datos.id_paciente = nuevo.id_paciente;
    nodo->datos.nombre = nuevo.nombre;
    nodo->datos.enfermedad = nuevo.enfermedad;
    nodo->siguiente = NULL;
    if (principio == NULL) 
    {
        principio = nodo;
    }
    else 
    {
        final->siguiente = nodo;
    }
    final = nodo;
}

elemento ColaPacientes::ConsultarSiguiente()
{
    elemento consulta;
    if (principio == NULL) {
        consulta.datos.id_paciente = "";
        consulta.datos.nombre = "";
        consulta.datos.enfermedad = "";
        return consulta;
    }
	return *principio;
}

Paciente ColaPacientes::ExtraerPaciente()
{
    Paciente extraido;
    if (principio == NULL) {
        extraido.id_paciente = "-1";
        extraido.nombre = "-1";
        extraido.enfermedad = "-1";
        return extraido;
    }
    nodo = principio;
    extraido = nodo->datos;
    principio = nodo->siguiente;
    if (principio == NULL) 
    {
        final = NULL;
    }

    delete nodo;

    return extraido;
}

void ColaPacientes::MostrarPacientes()
{
    cout << "\nCOLA DE PACIENTES EN ESPERA:" << endl;
    if (principio == NULL) {
        cout << "\n\tNo hay pacientes en espera." << endl;
        return;
    }
    nodo = principio;
    while (nodo != NULL) {
        cout << "\n\tID: " << nodo->datos.id_paciente;
        cout << "\n\tNombre: " << nodo->datos.nombre;
        cout << "\n\tEnfermedad: " << nodo->datos.enfermedad;
        if (nodo == principio) cout << "\t<- primero";
        if (nodo == final) cout << "\t<- último";
        cout << endl;
        nodo = nodo->siguiente;
    }
}

