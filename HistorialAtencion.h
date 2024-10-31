#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Atencion {
    string fecha;
    float peso;
    int edad;
    string tratamiento;
    Atencion* anterior;
};

class HistorialAtencion {
public:
    HistorialAtencion();
    void InsertarAtencion(string fecha, float peso, int edad, string tratamiento);
    Atencion ExtraerAtencion();
    void MostrarHistorial();

private:
    Atencion* tope, *nodo;
};

