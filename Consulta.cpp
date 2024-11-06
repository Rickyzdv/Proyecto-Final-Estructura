#include "Consulta.h"

Consulta::Consulta()
{
	cabecera = final = buscado = NULL;
}

Consulta::~Consulta()
{
}

void Consulta::insertar(datos_consulta data)
{
	nodo = new elemento_consulta;
	nodo->datos = data;
	if (cabecera == NULL)
	{
		cabecera = buscado = final = nodo;
		nodo->siguiente = cabecera;
	}
	else
	{
		nodo->siguiente = cabecera;
		cabecera = nodo;
		final->siguiente = nodo;
	}
}

datos_consulta Consulta::extraer_inicio()
{
	datos_consulta aux;
	aux.datos_doctor.id_doctor = aux.datos_doctor.nombre = aux.datos_doctor.especialidad = '-1';
	aux.datos_paciente.enfermedad = aux.datos_paciente.id_paciente = aux.datos_paciente.nombre = " ";

	if (cabecera == NULL)
	{
		return aux;
	}

	nodo = cabecera;
	aux = nodo->datos;

	if (cabecera == final)
	{
		cabecera = nodo = buscado = NULL;
		return aux;
	}

	final->siguiente = nodo->siguiente;
	cabecera = nodo->siguiente;

	if (nodo == buscado)
	{
		buscado = cabecera;
	}

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

	elemento_consulta* nodoAnterior = NULL;
	nodo = cabecera;

	while (nodo != NULL)
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
		aux = extraer_inicio();
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
	aux.datos_doctor.id_doctor = aux.datos_doctor.nombre = aux.datos_doctor.especialidad = '-1';
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


	nodo = cabecera;
	elemento_consulta* NodoAnterior;
	NodoAnterior = NULL;

	do
	{
		NodoAnterior = nodo;
		nodo = nodo->siguiente;

	} while (nodo != final);

	aux = nodo->datos;
	NodoAnterior->siguiente = cabecera;
	final = NodoAnterior;

	if (nodo == buscado)
	{
		buscado = NULL;
	}

	delete nodo;

	return aux;
}

datos_consulta Consulta::extraer_random(int num)
{
	datos_consulta aux;
	aux.datos_doctor.id_doctor = aux.datos_doctor.nombre = aux.datos_doctor.especialidad = '-1';
	aux.datos_paciente.enfermedad = aux.datos_paciente.id_paciente = aux.datos_paciente.nombre = " ";

	if (cabecera == NULL)
	{
		return aux;
	}

	nodo = cabecera;

	for (int i = 0; i < num; i++)
	{
		buscado = nodo;
		cout << buscado->datos.datos_paciente.id_paciente << endl;
		nodo = nodo->siguiente;
	}

	if (buscado == cabecera)
	{
		aux = extraer_inicio();
		return aux;
	}
	if (buscado == final)
	{
		aux = extraer_final();
		return aux;
	}
	aux = extraer_medio(buscado->datos.datos_doctor.id_doctor);
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
	do
	{
		cout << "\n\tId doctor: " << nodo->datos.datos_doctor.id_doctor;
		cout << "\n\tNombre doctor: " << nodo->datos.datos_doctor.nombre;
		cout << "\n\tId paciente: " << nodo->datos.datos_paciente.id_paciente;
		cout << "\n\tNombre paciente: " << nodo->datos.datos_paciente.nombre;

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
	} while (nodo != cabecera);


}