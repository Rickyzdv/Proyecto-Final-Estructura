#include <iostream>
#include<string>
#include"HistorialAtencion.h"
#include"ListaDoctores.h"
#include"Paciente.h"
#include"Consulta.h"

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
	int opc;

	Paciente dato_paciente;
	Doctor dato_doctor;
	datos_consulta dato_de_consulta;

	Paciente return_paciente;
	Doctor return_doctor;
	datos_consulta return_consulta;

	Consulta objeto_consulta;
	ListaDoctores objeto_doctores;
	ColaPacientes objeto_pacientes;

	while (band)
	{
		cout << "1.Insertar Paciente  2.Insertar doctor  3.Extraer Paciente  4.Extraer Doctor  5.Mostrar  6.Insertar consulta  7.Extraer Consulta  8.Mostrar consulta  9.Terminar" << endl;
		cout << "Digite la opcion deseada: ";
		cin >> opc;
		switch (opc)
		{
		case 1:

			dato_paciente.enfermedad = "Enfermedad Prueba";
			dato_paciente.id_paciente = "Id prueba";
			dato_paciente.nombre = "Nombre Prueba";

			objeto_pacientes.InsertarPaciente(dato_paciente);


			dato_paciente.enfermedad = "Enfermedad Prueba";
			dato_paciente.id_paciente = "Id prueba2";
			dato_paciente.nombre = "Nombre Prueba";

			objeto_pacientes.InsertarPaciente(dato_paciente);


			dato_paciente.enfermedad = "Enfermedad Prueba";
			dato_paciente.id_paciente = "Id prueba3";
			dato_paciente.nombre = "Nombre Prueba";

			objeto_pacientes.InsertarPaciente(dato_paciente);
			break;
		case 2:
			dato_doctor.id_doctor= "Id prueba";
			dato_doctor.nombre= "Nombre Prueba";
			dato_doctor.especialidad = '1';

			objeto_doctores.InsertarDoctorInicio(dato_doctor);

			dato_doctor.id_doctor = "Id prueba2";
			dato_doctor.nombre = "Nombre Prueba";
			dato_doctor.especialidad = '1';

			objeto_doctores.InsertarDoctorInicio(dato_doctor);

			dato_doctor.id_doctor = "Id prueba3";
			dato_doctor.nombre = "Nombre Prueba";
			dato_doctor.especialidad = '1';

			objeto_doctores.InsertarDoctorInicio(dato_doctor);
			break;
		case 3:
			return_paciente = objeto_pacientes.ExtraerPaciente();
			break;
		case 4:
			return_doctor = objeto_doctores.ExtraerFinal();
			break;
		case 5:
			objeto_pacientes.MostrarPacientes();
			cout << "\n\n" << endl;
			objeto_doctores.MostrarDoctores();
			break;
		case 6:
			dato_paciente.enfermedad = "Enfermedad Prueba";
			dato_paciente.id_paciente = "Id prueba1";
			dato_paciente.nombre = "Nombre Prueba1";

			dato_doctor.id_doctor = "Id prueba11";
			dato_doctor.nombre = "Nombre Prueba11";
			dato_doctor.especialidad = '1';

			dato_de_consulta.datos_doctor = dato_doctor;
			dato_de_consulta.datos_paciente = dato_paciente;

			objeto_consulta.insertar(dato_de_consulta);

			dato_paciente.enfermedad = "Enfermedad Prueba";
			dato_paciente.id_paciente = "Id prueba2";
			dato_paciente.nombre = "Nombre Prueba2";

			dato_doctor.id_doctor = "Id prueba22";
			dato_doctor.nombre = "Nombre Prueba22";
			dato_doctor.especialidad = '1';

			dato_de_consulta.datos_doctor = dato_doctor;
			dato_de_consulta.datos_paciente = dato_paciente;

			objeto_consulta.insertar(dato_de_consulta);

			dato_paciente.enfermedad = "Enfermedad Prueba";
			dato_paciente.id_paciente = "Id prueba3";
			dato_paciente.nombre = "Nombre Prueba3";

			dato_doctor.id_doctor = "Id prueba33";
			dato_doctor.nombre = "Nombre Prueba33";
			dato_doctor.especialidad = '1';

			dato_de_consulta.datos_doctor = dato_doctor;
			dato_de_consulta.datos_paciente = dato_paciente;

			objeto_consulta.insertar(dato_de_consulta);
			break;

		case 7:
			return_consulta = objeto_consulta.extraer_medio("Id prueba11");
			break;
	
		case 8:
			cout << "\n\n" << endl;
			objeto_consulta.mostrar();
			break;
			
		case 9:
			band = false;
			break;

		default:
			break;
		}
	}




	return 0;
}


