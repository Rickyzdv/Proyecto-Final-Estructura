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
	aux.datos_doctor.id_doctor = aux.datos_doctor.nombreDoc = aux.datos_doctor.especialidad = '-1';
	aux.datos_paciente.enfermedad = aux.datos_paciente.id_paciente = aux.datos_paciente.nombre = "-1";

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
	aux.datos_doctor.id_doctor = aux.datos_doctor.nombreDoc = aux.datos_doctor.especialidad = '-1';
	aux.datos_paciente.enfermedad = aux.datos_paciente.id_paciente = aux.datos_paciente.nombre = "-1";

	if (cabecera == NULL)
	{
		return aux;
	}

	bool found = false;

	if (cabecera == final)
	{
		aux = nodo->datos;
		final = buscado = cabecera = NULL;
		return aux;
	}

	nodo = cabecera;
	elemento_consulta* NodoAnterior;
	NodoAnterior = NULL;

	do
	{
		if (nodo->datos.datos_doctor.id_doctor == data)
		{
			found = true;
			break;
		}
		NodoAnterior = nodo;
		nodo = nodo->siguiente;

	} while (nodo != cabecera);

	if (found == false)
	{
		return aux;
	}
	if (nodo == final)
	{
		aux = extraer_final();
		return aux;
	}

	if (nodo == cabecera)
	{
		aux = extraer_inicio();
		return aux;
	}


	aux = nodo->datos;
	NodoAnterior->siguiente = nodo->siguiente;

	if (nodo == buscado)
	{
		buscado = cabecera;
	}

	delete nodo;

	return aux;
}

datos_consulta Consulta::extraer_final()
{
	datos_consulta aux;
	aux.datos_doctor.id_doctor = aux.datos_doctor.nombreDoc = aux.datos_doctor.especialidad = '-1';
	aux.datos_paciente.enfermedad = aux.datos_paciente.id_paciente = aux.datos_paciente.nombre = "-1";

	if (cabecera == NULL)
	{
		return aux;
	}

	nodo = final;

	if (cabecera == final)
	{
		aux = nodo->datos;
		final = buscado = cabecera = NULL;
		return aux;
	}

	elemento_consulta* NodoAnterior = NULL;

	do
	{
		NodoAnterior = nodo;
		nodo = nodo->siguiente;

	} while (nodo!=final);

	
	aux = nodo->datos;
	NodoAnterior->siguiente = cabecera;  
	final = NodoAnterior;           

	if (nodo == buscado)
	{
		buscado = cabecera;
	}

	delete nodo;  
	return aux;
}

datos_consulta Consulta::extraer_random(int num)
{
	datos_consulta aux;
	aux.datos_doctor.id_doctor = aux.datos_doctor.nombreDoc = aux.datos_doctor.especialidad = '-1';
	aux.datos_paciente.enfermedad = aux.datos_paciente.id_paciente = aux.datos_paciente.nombre = "-1";

	if (cabecera == NULL)
	{
		return aux;
	}

	nodo = cabecera;
	int contador = 0;

	do 
	{
		nodo = nodo->siguiente;
		contador++;
	} while (nodo != cabecera);


	nodo = cabecera;

	for (int i = 0; i < contador; i++)
	{

		buscado = nodo;
		cout << nodo->datos.datos_doctor.id_doctor << endl;
		nodo = nodo->siguiente;
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
		cout << "\n\tNombre doctor: " << nodo->datos.datos_doctor.nombreDoc;
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