#include <iostream>
#include<string>
#include"HistorialAtencion.h"
#include"ListaDoctores.h"
#include"Paciente.h"
#include"Consulta.h"
#include"lista_pacientes.h"
#include<cstdlib>
#include<ctime>

using namespace std;

//Funciones que nos van a ayudar con el flujo del programa
string asignarEnfermedad(char);


int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));

	//Variables normales que ayudan en las funciones
	bool band = true, submenu = true, found = false;
	int cont = 0, opc, opc2;
	int numerorandom;

	//Estructuras que usamos en las clases y que usamos para interactuar con los usuarios, llenar las variables de datos e insertarlas y moverlas por los distintos métodos
	Paciente dato_paciente, return_paciente;
	Doctor dato_doctor, return_doctor;
	datos_consulta dato_de_consulta, return_consulta;
	Atencion dato_atencion;

	//Instancias de las clases creadas, para usar sus métodos y así
	Consulta objeto_consulta;
	ListaDoctores objeto_doctores;
	ColaPacientes objeto_pacientes;
	lista_pacientes lista_espera;
	HistorialAtencion historial_citas;

	//Creación de 5 Doctores para el uso del programa, con especialidades distintas.
	dato_doctor.id_doctor = "1";
	dato_doctor.nombreDoc = "Santiago Torres";
	dato_doctor.especialidad = 'C';// Cardiología  Enfermedades que pueden tratar: (Hipertensión, Arritmias, Pericarditis, Enfermedad Coronaria)

	objeto_doctores.InsertarDoctorInicio(dato_doctor);

	dato_doctor.id_doctor = "2";
	dato_doctor.nombreDoc = "Antonio Mendoza";
	dato_doctor.especialidad = 'E';// Endocinología Enfermedades que pueden tratar: (Diabetes, Obesidad, Hipotiroidismo, Hipertiroidismo)

	objeto_doctores.InsertarDoctorInicio(dato_doctor);

	dato_doctor.id_doctor = "3";
	dato_doctor.nombreDoc = "Sofía Perez";
	dato_doctor.especialidad = 'N'; // Neumología Enfermedades que pueden tratar: (Asma, Bronquitis crónica, Neumonía, Apena de sueño)

	objeto_doctores.InsertarDoctorInicio(dato_doctor);

	dato_doctor.id_doctor = "4";
	dato_doctor.nombreDoc = "Fernando Zuñiga";
	dato_doctor.especialidad = 'A'; // Reumatología Enfermedades que pueden tratar: (Artritis, Lupus, Osteoporósis, Gota,)

	objeto_doctores.InsertarDoctorInicio(dato_doctor);
	dato_doctor.id_doctor = "5";
	dato_doctor.nombreDoc = "Mariana García";
	dato_doctor.especialidad = 'G'; //Gastroenterología Enfermedades que pueden tratar: (Gastritis, SII, reflujo gastroesofágico, Úlceras pépticas)

	objeto_doctores.InsertarDoctorInicio(dato_doctor);

	while (band)
	{
		cout << "\n1. Creación del paciente";
		cout << "\n2. Pasar paciente a consulta";
		cout << "\n3. Finalizar consulta aleatoria";
		cout << "\n4. Mostrar Consultas en Proceso";
		cout << "\n5. Mostrar Lista de Espera";
		cout << "\n6. Mostrar Historial de Consultas";
		cout << "\n7. Ver Doctores Disponibles";
		cout << "\n8. Mostrar cola de pacientes";
		cout << "\n9. Salir\n";
		cout << "\nDigite la opción deseada: ";
		cin >> opc;
		switch (opc)
		{
		case 1:
			cout << "\n\tIngrese el nombre del paciente: ";
			cin.ignore();
			getline(cin, dato_paciente.nombre);

			cout << "\n\tIngrese el ID del paciente: ";
			getline(cin, dato_paciente.id_paciente);

			cout << "\n\t¿Para qué departamento busca atención?";
			cout << "\n\t\t1. Cardiología";
			cout << "\n\t\t2. Endocrinología";
			cout << "\n\t\t3. Neumología";
			cout << "\n\t\t4. Reumatología";
			cout << "\n\t\t5. Gastroenterología";
			cout << "\n\tDigite su opción deseada: ";

			submenu = true;
			while (submenu)
			{
				cin >> opc2;
				switch (opc2)
				{
				case 1:
					dato_paciente.enfermedad = asignarEnfermedad('C');  
					submenu = false;
					break;
				case 2:
					dato_paciente.enfermedad = asignarEnfermedad('E'); 
					submenu = false;
					break;
				case 3:
					dato_paciente.enfermedad = asignarEnfermedad('N'); 
					submenu = false;
					break;
				case 4:
					dato_paciente.enfermedad = asignarEnfermedad('A');  
					submenu = false;
					break;
				case 5:
					dato_paciente.enfermedad = asignarEnfermedad('G');  
					submenu = false;
					break;
				default:
					cout << "\n\t\tDigite una opción válida." << endl;
					break;
				}
			}
			objeto_pacientes.InsertarPaciente(dato_paciente);
			break;
		case 2:
			return_paciente = objeto_pacientes.ExtraerPaciente();
			if (return_paciente.nombre == "-1") 
			{	
				cout << "\n\tNo hay pacientes disponibles para consulta." << endl;
				break;
			}
			
			cout << "\nDatos del paciente:";
			cout << "\n\tID: " << return_paciente.id_paciente;
			cout << "\n\tNombre: " << return_paciente.nombre;
			cout << "\n\tEnfermedad: " << return_paciente.enfermedad << endl;

			if (return_paciente.enfermedad == "Hipertensión" || return_paciente.enfermedad == "Arritmias" ||
				return_paciente.enfermedad == "Pericarditis" || return_paciente.enfermedad == "Enfermedad Coronaria") 
			{

				return_doctor = objeto_doctores.ExtraerBuscado('C');  // Cardiología
				if (return_doctor.especialidad == 'C') 
				{
					cout << "\n\tSe encontró un doctor de Cardiología, empezando consulta..." << endl;
				}
				else 
				{
					cout << "\n\tNo hay doctores disponibles de Cardiología, insertando paciente a lista de espera." << endl;
					lista_espera.InsertarPaciente(return_paciente);
				}

			}
			else if (return_paciente.enfermedad == "Diabetes" || return_paciente.enfermedad == "Obesidad" ||
				return_paciente.enfermedad == "Hipotiroidismo" || return_paciente.enfermedad == "Hipertiroidismo") 
			{

				return_doctor = objeto_doctores.ExtraerBuscado('E');  // Endocrinología
				if (return_doctor.especialidad == 'E') 
				{
					cout << "\n\tSe encontró un doctor de Endocrinología, empezando consulta..." << endl;
				}
				else 
				{
					cout << "\n\tNo hay doctores disponibles de Endocrinología, insertando paciente a lista de espera." << endl;
					lista_espera.InsertarPaciente(dato_paciente);
				}

			}
			else if (return_paciente.enfermedad == "Asma" || return_paciente.enfermedad == "Bronquitis crónica" ||
				return_paciente.enfermedad == "Neumonía" || return_paciente.enfermedad == "Apnea del sueño") 
			{

				return_doctor = objeto_doctores.ExtraerBuscado('N');  // Neumología
				if (return_doctor.especialidad == 'N') {
					cout << "\n\tSe encontró un doctor de Neumología, empezando consulta..." << endl;
				}
				else {
					cout << "\n\tNo hay doctores disponibles de Neumología, insertando paciente a lista de espera." << endl;
					lista_espera.InsertarPaciente(return_paciente);
				}

			}
			else if (return_paciente.enfermedad == "Artritis" || return_paciente.enfermedad == "Lupus" ||
				return_paciente.enfermedad == "Osteoporosis" || return_paciente.enfermedad == "Gota") 
			{

				return_doctor = objeto_doctores.ExtraerBuscado('A');  // Reumatología
				if (return_doctor.especialidad == 'A') {
					cout << "\n\tSe encontró un doctor de Reumatología, empezando consulta..." << endl;
				}
				else {
					cout << "\n\tNo hay doctores disponibles de Reumatología, insertando paciente a lista de espera." << endl;
					lista_espera.InsertarPaciente(return_paciente);
				}

			}
			else if (return_paciente.enfermedad == "Gastritis" || return_paciente.enfermedad == "Síndrome de Intestino Irritable" ||
				return_paciente.enfermedad == "Reflujo Gastroesofágico" || return_paciente.enfermedad == "Úlceras Pépticas") 
			{

				return_doctor = objeto_doctores.ExtraerBuscado('G');  // Gastroenterología
				if (return_doctor.especialidad == 'G') 
				{
					cout << "\n\tSe encontró un doctor de Gastroenterología, empezando consulta..." << endl;
				}
				else 
				{
					cout << "\n\tNo hay doctores disponibles de Gastroenterología, insertando paciente a lista de espera." << endl;
					lista_espera.InsertarPaciente(return_paciente);
				}
			}
			else 
			{
				cout << "\n\tLa enfermedad del paciente no corresponde a ningún departamento conocido." << endl;
				lista_espera.InsertarPaciente(return_paciente);
				break;
			}

			cout << "\nDoctor asignado:";
			cout << "\n\tID: " << return_doctor.id_doctor;
			cout << "\n\tNombre: " << return_doctor.nombreDoc;
			cout << "\n\tEspecialidad: " << return_doctor.especialidad << endl;

			//Los pasamos a consulta
			dato_de_consulta.datos_doctor = return_doctor;
			dato_de_consulta.datos_paciente = return_paciente;
			objeto_consulta.insertar(dato_de_consulta);

			//Datos registrados de la consulta para pasar a la pila
			dato_atencion.nomPac = return_paciente.nombre;
			dato_atencion.enfermedadPac = return_paciente.enfermedad;
			dato_atencion.nomDoc = return_doctor.nombreDoc;
			dato_atencion.especialidadDoc = return_doctor.especialidad;
			historial_citas.InsertarAtencion(dato_atencion);
			break;
		case 3:
			numerorandom = 1 + rand() % (10 - 1);
			dato_de_consulta = objeto_consulta.extraer_random(numerorandom);
			cout << "\nSe terminó la consulta del paciente: " << dato_de_consulta.datos_paciente.nombre << "\nCon el doctor: " << dato_de_consulta.datos_doctor.nombreDoc << endl;
			return_doctor = dato_de_consulta.datos_doctor;
			objeto_doctores.InsertarDoctorInicio(return_doctor);
			break;
		case 4:
			objeto_consulta.mostrar();
			break;
		case 5:
			lista_espera.mostrar();
			break;
		case 6:
			historial_citas.MostrarHistorial();
			break;
		case 7:
			objeto_doctores.MostrarDoctores();
			break;
		case 8:
			objeto_pacientes.MostrarPacientes();
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

string asignarEnfermedad(char especialidad)
{
	string enfermedad;
	int numaleatorio = rand() % 4;

	switch (especialidad) {
	case 'C':  // Cardiología
		switch (numaleatorio) {
		case 0:
			enfermedad = "Hipertensión";
			break;
		case 1:
			enfermedad = "Arritmias";
			break;
		case 2:
			enfermedad = "Pericarditis";
			break;
		case 3:
			enfermedad = "Enfermedad Coronaria";
			break;
		}
		break;

	case 'E':  // Endocrinología
		switch (numaleatorio) {
		case 0:
			enfermedad = "Diabetes";
			break;
		case 1:
			enfermedad = "Obesidad";
			break;
		case 2:
			enfermedad = "Hipotiroidismo";
			break;
		case 3:
			enfermedad = "Hipertiroidismo";
			break;
		}
		break;

	case 'N':  // Neumología
		switch (numaleatorio) {
		case 0:
			enfermedad = "Asma";
			break;
		case 1:
			enfermedad = "Bronquitis crónica";
			break;
		case 2:
			enfermedad = "Neumonía";
			break;
		case 3:
			enfermedad = "Apnea del sueño";
			break;
		}
		break;

	case 'A':  // Reumatología
		switch (numaleatorio) {
		case 0:
			enfermedad = "Artritis";
			break;
		case 1:
			enfermedad = "Lupus";
			break;
		case 2:
			enfermedad = "Osteoporosis";
			break;
		case 3:
			enfermedad = "Gota";
			break;
		}
		break;

	case 'G':  // Gastroenterología
		switch (numaleatorio) {
		case 0:
			enfermedad = "Gastritis";
			break;
		case 1:
			enfermedad = "Síndrome de Intestino Irritable";
			break;
		case 2:
			enfermedad = "Reflujo Gastroesofágico";
			break;
		case 3:
			enfermedad = "Úlceras Pépticas";
			break;
		}
		break;

	default:
		cout << "fsdkfblsdbafif" << endl;
		break;
	}
	return enfermedad;
}


