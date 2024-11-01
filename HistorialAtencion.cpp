#include "HistorialAtencion.h"

HistorialAtencion::HistorialAtencion()
{
	tope = NULL;
}

void HistorialAtencion::InsertarAtencion(Atencion nuevo)
{
    nodo = new Atencion;
    *nodo = nuevo;
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
    extraido = *nodo;
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
    Atencion* nodo = tope;
    while (nodo != NULL) {
        cout << "\tFecha: " << nodo->fecha;
        cout << "\tPeso: " << nodo->peso;
        cout << "\tEdad: " << nodo->edad;
        cout << "\tTratamiento: " << nodo->tratamiento << endl;
        nodo = nodo->anterior;
    }
}
