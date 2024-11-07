#include "HistorialAtencion.h"

HistorialAtencion::HistorialAtencion()
{
	tope = NULL;
}

void HistorialAtencion::InsertarAtencion(Atencion nuevo)
{
    nodo = new elemento_atencion;
    nodo->datos = nuevo;
    nodo->anterior = tope;
    tope = nodo;
}

void HistorialAtencion::MostrarHistorial()
{
    cout << "\n\tHistorial de Atenciones:" << endl;
    if (tope == NULL) 
    {
        cout << "\n\tEl historial está vacío" << endl;
        return;
    }
    nodo = tope;
    while (nodo != NULL) 
    {
        cout << "\n\tNombre del Paciente: " << nodo->datos.nomPac;
        cout << "\n\tEnfermedad que presentó: " << nodo->datos.enfermedadPac;
        cout << "\n\tDoctor que lo atendió: " << nodo->datos.nomDoc; 
        cout << "\n\tEspecialidad del doctor: " << nodo->datos.especialidadDoc << endl;
        nodo = nodo->anterior;
    }
}
