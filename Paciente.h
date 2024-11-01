#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Paciente
{
	string id_paciente;
	string nombre;
	string enfermedad;
};

struct elemento
{
	Paciente datos;
	elemento* siguiente;
};

class ColaPacientes
{
public:
	ColaPacientes();
	void InsertarPaciente(Paciente nuevo);
	elemento ConsultarSiguiente();
	Paciente ExtraerPaciente();
	void MostrarPacientes();

private:
	elemento* principio , * final, * nodo;
};


