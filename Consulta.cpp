#include "Consulta.h"

Consulta::Consulta()
{
	cabecera = final = NULL;
}

Consulta::~Consulta()
{
}

void Consulta::insertar(datos_consulta data)
{
	nodo = new elemento_consulta;
	nodo->datos = data;
	nodo->siguiente = cabecera;
	if (cabecera == NULL)
	{
		final = nodo;
	}
	cabecera = nodo;
}

datos_consulta Consulta::extraer_inicio()
{
	datos_consulta aux;
	aux.datos_doctor.id_doctor=aux.datos_doctor.nombre=aux.datos_doctor.especialidad = ' ';
	aux.datos_paciente.enfermedad = aux.datos_paciente.id_paciente = aux.datos_paciente.nombre = " ";

	if (cabecera == NULL)
	{
		return aux;
	}
	nodo = cabecera;
	aux = nodo->datos;
	cabecera = nodo->siguiente;

	delete nodo;

	return aux;
}

datos_consulta Consulta::extraer_medio(string data)
{
	datos_consulta aux;
	aux.datos_doctor.id_doctor = aux.datos_doctor.nombre = aux.datos_doctor.especialidad = ' ';
	aux.datos_paciente.enfermedad = aux.datos_paciente.id_paciente = aux.datos_paciente.nombre = " ";

	bool found = false;

	if (cabecera == NULL)
	{
		return aux;
	}

	elemento_consulta* nodoAnterior=NULL;
	nodo = cabecera;

	while (nodo!=NULL)
	{
		if (nodo->datos.datos_doctor.id_doctor == data) 
		{
			found = true;
			break;
		}
		nodoAnterior = nodo;
		nodo = nodo->siguiente;
	}

	if (found == false)
	{
		return aux;
	}

	if (nodo == cabecera)
	{
		aux=extraer_inicio();
		return aux;
	}
	
	if (nodo == final)
	{
		aux = extraer_final();
		return aux;
	}

	aux = nodo->datos;
	nodoAnterior->siguiente = nodo->siguiente;

	delete nodo;

	return aux;
}

datos_consulta Consulta::extraer_final()
{
	datos_consulta aux;
	aux.datos_doctor.id_doctor = aux.datos_doctor.nombre = aux.datos_doctor.especialidad = ' ';
	aux.datos_paciente.enfermedad = aux.datos_paciente.id_paciente = aux.datos_paciente.nombre = " ";

	if (cabecera == NULL)
	{
		return aux;
	}
	if (cabecera == final)
	{
		aux = extraer_inicio();
		return aux;
	}
	elemento_consulta* nodoAnterior = NULL;
	nodo = cabecera;
	while (nodo->siguiente!=NULL)
	{
		nodoAnterior = nodo;
		nodo = nodo->siguiente;
	}

	nodoAnterior->siguiente = NULL;
	aux = nodo->datos;
	final = nodoAnterior;

	delete nodo;

	return aux;
}

void Consulta::mostrar()
{
	if (cabecera == NULL)
	{
		cout << "Lista VACIA" << endl;
		return;
	}
	nodo = cabecera;
	while (nodo!=NULL)
	{
		cout << nodo->datos.datos_doctor.id_doctor;
		cout << nodo->datos.datos_paciente.id_paciente;
		if (nodo == cabecera)
		{
			cout << "\t<-cabecera";
		}
		if (nodo == final)
		{
			cout << "\t<-final";
		}
		cout << endl;
		cout << endl;
		nodo = nodo->siguiente;
	}
	

}

