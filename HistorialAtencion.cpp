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

Atencion HistorialAtencion::ExtraerAtencion()
{
    Atencion extraido;
    if (tope == NULL) 
    {
        extraido.fecha = "";
        extraido.peso = 0.0;
        extraido.edad = 0;
        extraido.tratamiento = "";
        extraido.nomDoc = "";
        return extraido;
    }
    nodo = tope;
    extraido = nodo->datos;
    tope = nodo->anterior;
    delete nodo;
    return extraido;
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
        cout << "\n\tFecha: " << nodo->datos.fecha;
        cout << "\n\tPeso: " << nodo->datos.peso;
        cout << "\n\tEdad: " << nodo->datos.edad;
        cout << "\n\tTratamiento: " << nodo->datos.tratamiento << endl;
        nodo = nodo->anterior;
    }
}
