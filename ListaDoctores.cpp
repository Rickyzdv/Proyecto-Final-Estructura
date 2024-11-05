#include "ListaDoctores.h"

ListaDoctores::ListaDoctores()
{
    cabecera = final = buscado=  NULL;
}

void ListaDoctores::InsertarDoctorInicio(Doctor nuevo)
{
    nodo = new elemento_doctor;
    nodo->datos = nuevo;
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

Doctor ListaDoctores::ExtraerInicio()
{
    Doctor aux;
    aux.enfermedad = " ";
    aux.especialidad = '-1';
    aux.id_doctor = " ";
    aux.nombre = " ";


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
        buscado = NULL;
    }

    delete nodo;

    return aux;
}

Doctor ListaDoctores::ExtraerInter(char especialidad)
{
    Doctor aux;
    aux.enfermedad = " ";
    aux.especialidad = '-1';
    aux.id_doctor = " ";
    aux.nombre = " ";

    if (cabecera == NULL)
    {
        return aux;
    }

    bool found = false;

    if (cabecera == final)
    {
        aux = ExtraerInicio();
        return aux;
    }

    nodo = cabecera;
    elemento_doctor* NodoAnterior;
    NodoAnterior = NULL;

    do
    {
        if (nodo->datos.especialidad == especialidad)
        {
            found = true;
            break;
        }
        NodoAnterior = nodo;
        nodo = nodo->siguiente;

    } while (nodo != final);

    if (found == false)
    {
        return aux;
    }
    if (nodo == final)
    {
        aux = ExtraerFinal();
        return aux;
    }

    if (nodo == cabecera)
    {
        aux = ExtraerInicio();
        return aux;
    }

    aux = nodo->datos;
    NodoAnterior->siguiente = nodo->siguiente;

    if (nodo == buscado)
    {
        buscado = NULL;
    }

    delete nodo;


    return aux;
}

Doctor ListaDoctores::ExtraerFinal()
{
    Doctor aux;
    aux.enfermedad = " ";
    aux.especialidad = '-1';
    aux.id_doctor = " ";
    aux.nombre = " ";

    if (cabecera == NULL)
    {
        return aux;
    }

    if (cabecera == final)
    {
        aux = ExtraerInicio();
        return aux;
    }


    nodo = cabecera;
    elemento_doctor* NodoAnterior;
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
Doctor ListaDoctores::ExtraerBuscado(char especialidad)
{
    Doctor aux;
    aux.enfermedad = " ";
    aux.especialidad = '-1';
    aux.id_doctor = " ";
    aux.nombre = " ";

    int code;

    code=buscar(especialidad);
    if (code == -3 || code==-4)
    {
        return aux;
    }
    if (buscado == cabecera)
    {
        aux=ExtraerInicio();
        return aux;
    }
    if (buscado == final)
    {
        aux=ExtraerFinal();
        return aux;
    }
    else 
    {
        aux=ExtraerInter(especialidad);
        return aux;
    }
}
int ListaDoctores::buscar(char especialidad)
{
    if (cabecera == NULL)
    {
        return -3;
    }
    if (buscado == NULL)
    {
        buscado = cabecera;
    }
    bool found = false;
    nodo = buscado;
    do
    {
        if (nodo->datos.especialidad == especialidad)
        {
            found = true;
            break;
        }
        nodo = nodo->siguiente;
    } while (nodo != buscado);

    if (found == false)
    {
        return -4;
    }

    buscado = nodo;

    return 0;
}
void ListaDoctores::MostrarDoctores()
{
    cout << "\nLista de Doctores Disponibles:" << endl;
    if (cabecera == NULL) 
    {
        cout << "\n\tNo hay doctores disponibles." << endl;
        return;
    }
    nodo = cabecera;
    do
    {
        cout << "\tID: " << nodo->datos.id_doctor;
        cout << "\tNombre: " << nodo->datos.nombre;
        cout << "\tEspecialidad: " << nodo->datos.especialidad;
        if (nodo == cabecera)
        {
            cout << "\t<- primero";
        }
        if (nodo == final)
        {
            cout << "\t<- último";
        }
        cout << endl;
        cout << endl;
        nodo = nodo->siguiente;
    } while (nodo != cabecera);
}