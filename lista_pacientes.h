#pragma once
#include"Paciente.h"

struct elemento_lista_pacientes: public Paciente
{
	Paciente datos;
	elemento_lista_pacientes* siguiente;
};

class lista_pacientes
{
public:
	lista_pacientes();
	~lista_pacientes();
	void InsertarPaciente(Paciente);
	Paciente ExtraerInicio();
	Paciente ExtraerInter(string);
	Paciente ExtraerFinal();
	void mostrar();

private:
	elemento_lista_pacientes* nodo, * cabecera, * final;
};

