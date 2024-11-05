#include <iostream>
#include<string>
#include"HistorialAtencion.h"
#include"ListaDoctores.h"
#include"Paciente.h"
#include"Consulta.h"
#include"lista_pacientes.h"

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



	bool band = true;
	bool submenu = true;
	bool found = false;
	int cont = 0;
	int opc;
	int opc2;

	Paciente dato_paciente;
	Doctor dato_doctor;
	datos_consulta dato_de_consulta;

	Paciente return_paciente;
	Doctor return_doctor;
	datos_consulta return_consulta;

	Consulta objeto_consulta;
	ListaDoctores objeto_doctores;
	ColaPacientes objeto_pacientes;
	lista_pacientes lista_espera;

	dato_doctor.id_doctor = "Id prueba";
	dato_doctor.nombre = "Nombre Prueba";
	dato_doctor.especialidad = 'o';

	objeto_doctores.InsertarDoctorInicio(dato_doctor);

	dato_doctor.id_doctor = "Id prueba2";
	dato_doctor.nombre = "Nombre Prueba";
	dato_doctor.especialidad = 'e';

	objeto_doctores.InsertarDoctorInicio(dato_doctor);

	dato_doctor.id_doctor = "Id prueba3";
	dato_doctor.nombre = "Nombre Prueba";
	dato_doctor.especialidad = 't';

	objeto_doctores.InsertarDoctorInicio(dato_doctor);

	while (band)
	{
		submenu = true;
		found = false;
		cout << "\n1.Insertar Paciente  \n2.Empezar consulta  \n3.Terminar Consulta  \n4.Mostrar doctores  \n5.Mostrar lista de espera  \n6.Mostrar consultas  \n7.Terminar" << endl;
		cout << "\nDigite la opcion deseada: ";
		cin >> opc;
		switch (opc)
		{
		case 1:
			cout << "\n\tIngrese el nombre del paciente: ";
			cin.ignore();
			getline(cin, dato_paciente.nombre);

			cout << "\n\tIngrese el id del paciente: ";
			getline(cin, dato_paciente.id_paciente);

			cout << "\n\tQue enfermedad sufre el paciente:\n\t1.Cancer\n\t2.Diabetes\n\tDigite su opcion deseada: ";
			while(submenu)
			{
				cin >> opc2;
				switch (opc2)
				{
				case 1:
					dato_paciente.enfermedad = "Cancer";
					submenu = false;
					break;
				case 2:
					dato_paciente.enfermedad = "Diabetes";
					submenu = false;
					break;
				default:
					cout << "Digite una opcion valida." << endl;
					break;
				}
			}
			objeto_pacientes.InsertarPaciente(dato_paciente);
			break;
		case 2:
			return_paciente = objeto_pacientes.ExtraerPaciente();
			if (return_paciente.nombre == "-1")
			{
				cout << "No hay pacientes disponibles para consulta." << endl;
				break;
			}
			if (return_paciente.enfermedad == "Cancer")
			{
				return_doctor = objeto_doctores.ExtraerBuscado('o');
				if (return_doctor.especialidad == 'o')
				{
					cout << "Se encontro un doctor, empezando consulta" << endl;
					dato_de_consulta.datos_doctor = return_doctor;
					dato_de_consulta.datos_paciente = return_paciente;
					objeto_consulta.insertar(dato_de_consulta);
				}
				else
				{
					cout << "No hay doctores disponibles, insertando paciente a lista de espera." << endl;
					lista_espera.InsertarPaciente(return_paciente);
				}
			}
			if (return_paciente.enfermedad == "Diabetes")
			{
				return_doctor = objeto_doctores.ExtraerBuscado('e');
				if (return_doctor.especialidad == 'e')
				{
					cout << "Se encontro un doctor, empezando consulta" << endl;
					dato_de_consulta.datos_doctor = return_doctor;
					dato_de_consulta.datos_paciente = return_paciente;
					objeto_consulta.insertar(dato_de_consulta);
					break;
				}
				else
				{
					cout << "No hay doctores disponibles, insertando paciente a lista de espera." << endl;
					lista_espera.InsertarPaciente(return_paciente);
				}
			}
			break;
		case 3:
			return_paciente = objeto_pacientes.ExtraerPaciente();
			break;
		case 4:
			objeto_doctores.MostrarDoctores();
			break;
		case 5:
			lista_espera.mostrar();
			break;
		case 6:
			objeto_consulta.mostrar();
			break;

		case 7:
			band = false;
			break;
	
		default:
			break;
		}
	}




	return 0;
}


