#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Doctor {
    string id;
    string nombre;
    Doctor* siguiente;
};

class ListaDoctores {
public:
    ListaDoctores();
    void InsertarDoctorInicio(string id, string nombre);
    Doctor* ExtraerInicio();
    Doctor* ExtraerInter(string id);
    Doctor* ExtraerFinal();
    void MostrarDoctores();

private:
    Doctor* cabecera, *final, *nodo;
};
