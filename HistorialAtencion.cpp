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
    if (tope == NULL) {
        extraido.fecha = "";
        extraido.peso = 0.0;
        extraido.edad = 0;
        extraido.tratamiento = "";
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
    cout << "\nHistorial de Atenciones:" << endl;
    if (tope == NULL) {
        cout << "\n\tEl historial está vacío" << endl;
        return;
    }
    nodo = tope;
    while (nodo != NULL) {
        cout << "\tFecha: " << nodo->datos.fecha;
        cout << "\tPeso: " << nodo->datos.peso;
        cout << "\tEdad: " << nodo->datos.edad;
        cout << "\tTratamiento: " << nodo->datos.tratamiento << endl;
        nodo = nodo->anterior;
    }
}
