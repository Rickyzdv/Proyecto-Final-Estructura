# Clinic Management System (C++) 🏥

Console application that simulates the flow of patients in a clinic: registering patients and doctors, assigning consultations by specialty and keeping a history of the care provided.

Team final project for the Data Structures course at Universidad Panamericana (2024). Every data structure is implemented **from scratch with pointers**, without using the STL containers.

## Data structures

| Structure | Class | Used for |
|---|---|---|
| Linked list | `lista_pacientes` | Registered patients |
| Linked list | `ListaDoctores` | Doctors and their specialty, with search and extraction by specialty |
| Queue (linked) | `Consulta` | Consultations, with extraction from the start, the middle, the end or a random position |
| Stack (linked) | `HistorialAtencion` | Care history: patient, condition, treatment and attending doctor |

## Project structure

```
Source.cpp                 # Main menu and program flow
Paciente.h / .cpp          # Patient data
lista_pacientes.h / .cpp   # Patient linked list
ListaDoctores.h / .cpp     # Doctor linked list
Consulta.h / .cpp          # Consultation queue
HistorialAtencion.h / .cpp # Care history stack
```

## Running locally

With Visual Studio, open `Proyecto FInal Estructura.sln`.

With g++:

```bash
g++ -std=c++17 *.cpp -o clinic
./clinic
```

## Team

Developed with classmates as a team project.
