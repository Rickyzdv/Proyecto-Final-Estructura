#pragma once
#include<string>
#include<iostream>
#pragma once
#include<string>
#include<iostream>
#include"ListaDoctores.h"

using namespace std;

struct datos_consulta
{
	Paciente datos_paciente;
	Doctor datos_doctor;
};

struct elemento_consulta
{
	datos_consulta datos;
	elemento_consulta* siguiente;
};

class Consulta
{
public:
	Consulta();
	~Consulta();

	void insertar(datos_consulta);
	datos_consulta extraer_inicio();
	datos_consulta extraer_medio(string);
	datos_consulta extraer_final();

	datos_consulta extraer_random(int);

	void mostrar();


private:
	elemento_consulta* nodo, * cabecera, * final, * buscado;

};


