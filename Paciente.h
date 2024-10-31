#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Paciente
{
	string id;
	string nombre; 
	string enfermedad;
	Paciente* siguiente;
};

class ColaPacientes
{
public:
	ColaPacientes();
	void InsertarPaciente(Paciente nuevo);
	Paciente ConsultarSiguiente();
	Paciente ExtraerPaciente();
	void MostrarPacientes();

private:
	Paciente* principio , * final, * nodo;
};


