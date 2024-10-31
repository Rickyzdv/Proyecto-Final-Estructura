#include "Paciente.h"

ColaPacientes::ColaPacientes()
{
	principio = final = NULL;
}

void ColaPacientes::InsertarPaciente(Paciente nuevo)
{
    nodo->id = nuevo.id;
    nodo->nombre = nuevo.nombre;
    nodo->enfermedad = nuevo.enfermedad;
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

Paciente ColaPacientes::ConsultarSiguiente()
{
    Paciente consulta;
    if (principio == NULL) {
        consulta.id = "";
        consulta.nombre = "";
        consulta.enfermedad = "";
        return consulta;
    }
	return *principio;
}

Paciente ColaPacientes::ExtraerPaciente()
{
    Paciente extraido;
    if (principio == NULL) {
        extraido.id = "";
        extraido.nombre = "";
        extraido.enfermedad = "";
        return extraido;
    }
    nodo = principio;
    extraido = *nodo;
    principio = nodo->siguiente;
    if (principio == NULL) {
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
    Paciente* nodo = principio;
    while (nodo != NULL) {
        cout << "\tID: " << nodo->id;
        cout << "\tNombre: " << nodo->nombre;
        cout << "\tEnfermedad: " << nodo->enfermedad;
        if (nodo == principio) cout << "\t<- primero";
        if (nodo == final) cout << "\t<- último";
        cout << endl;
        nodo = nodo->siguiente;
    }
}

