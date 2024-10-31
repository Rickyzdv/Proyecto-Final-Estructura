#pragma once
#include <iostream>
#include <string>
#include"Paciente.h"
using namespace std;

struct Doctor : public Paciente
{
    string id;
    string nombre;
    Doctor* siguiente;
};

class ListaDoctores: public Paciente
{
public:
    ListaDoctores();
    void InsertarDoctorInicio(string id, string nombre);
    Doctor* ExtraerInicio();
    Doctor* ExtraerInter(string id);
    Doctor* ExtraerFinal();
    void MostrarDoctores();

private:
protected:
    Doctor* cabecera, *final, *nodo;
};
