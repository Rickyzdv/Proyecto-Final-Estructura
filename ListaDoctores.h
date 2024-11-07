#pragma once
#include <iostream>
#include <string>
#include"Paciente.h"
using namespace std;

struct Doctor : public Paciente
{
    string id_doctor;
    string nombreDoc;
    char especialidad; // La letra inicial de cada especialidad de doctor que pongamos
};

struct elemento_doctor
{
    Doctor datos;
    elemento_doctor* siguiente;
};

class ListaDoctores
{
public:
    ListaDoctores();
    void InsertarDoctorInicio(Doctor);
    Doctor ExtraerInicio();
    Doctor ExtraerInter(char);
    Doctor ExtraerFinal();
    Doctor ExtraerBuscado(char);

    int buscar(char);


    void MostrarDoctores();

private:
    elemento_doctor* cabecera, *final, *nodo,*buscado;
};
