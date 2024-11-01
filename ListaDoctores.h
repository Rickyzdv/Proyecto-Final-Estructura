#pragma once
#include <iostream>
#include <string>
#include"Paciente.h"
using namespace std;

struct Doctor : public Paciente
{
    string id;
    string nombre;
    char especialidad; // La letra inicial de cada especialidad de doctor que pongamos
    Doctor* siguiente;
};

class ListaDoctores: public Paciente
{
public:
    ListaDoctores();
    void InsertarDoctorInicio(Doctor);
    Doctor* ExtraerInicio();
    Doctor* ExtraerInter(string id);
    Doctor* ExtraerFinal();
    void MostrarDoctores();

private:
protected:
    Doctor* cabecera, *final, *nodo;
};
