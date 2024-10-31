#include <iostream>
#include<string>
#include"HistorialAtencion.h"
#include"ListaDoctores.h"
#include"Paciente.h"

using namespace std;

int main()
{
	// Tenemos que agregar toda la parte de logística, las estructuras ya están creadas.

	// 1.- Hay que crear la terminal de manera visual, como se va a ver el menú y las opciones que va a tener

	// 2.- Debe haber las opciones de:
	/*Insertar paciente, abrir hospital (toda la parte automática de consultas y luego con un numero random iremos regresando a los 
	doctores a la lista ligada, salir dle programa*/

	// 3.- Insertar Paciente consiste en:
	//  Vamos a preguntar los datos (id,nombre,enfermedad,urgencia)
	//  Insertar Paciente en cola 

	//4.- Crear la lista prehecha de doctores

	//5.- Pasar paciente a consulta: 
	//	1.-Extraer paciente de la cola
	//	2.-Asignar paciente a un doctor de acuerdo a su enfermedad
	//	3.-Si no hay doctor disponible, pasar a lista de espera
	//  4.-Si hay doctor disponible, pasar a lista de consultas

	//6.- En consulta
	//	1.-Guardar info del paciente
	//	2.-Guardan info en pila
	//	3.-Guardar registro
	//	4.-Asignar medicina
	//	5.-Terminar consulta, y regresar un doctor al azar a la lista de disponibles

	//7.- Lista de espera
	//	1.-Al insertar otra consulta, se checa la lista de espera.
	//	2.-Si un paciente corresponde con un doctor, pasar a consulta y extraer de la lista.
	//	3.-Si no, regresar al paso de insertar a consulta desde la cola principal

	//PROBAR LA HERENCIA DE ESTRUCTURAS

	//OPCIONAL
	//ARCHIVOS, REPORTE EN TXT


	return 0;
}


