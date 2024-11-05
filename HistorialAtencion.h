#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Atencion {
    string fecha;
    float peso;
    int edad;
    string tratamiento;
    string nomDoc;
    char especialidadDoc;
};

struct elemento_atencion 
{
    Atencion datos;
    elemento_atencion* anterior;
};

class HistorialAtencion {
public:
    HistorialAtencion();
    void InsertarAtencion(Atencion);
    Atencion ExtraerAtencion();
    void MostrarHistorial();

private:
    elemento_atencion* tope, *nodo;
};

