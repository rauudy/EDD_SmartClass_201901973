#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include <sstream>
#include <fstream>
using namespace std;


void cargaEstudiantes();
void cargaTareas();
void manual();
void reportes();

int main(){
    int op;
    do{
        cout<<"\n\tMENU";
        cout<<"\n1. Cargar usuarios\n2. Cargar tareas";
        cout<<"\n3. Ingresar manual\n4. Reportes";
        cout<<"\n5. Salir";
        cout<<"\nOpcion: "; cin>>op;
        
        switch(op){
            case 1:
                cout<<"--- Carga de Usuarios ---"<<endl;
                cargaEstudiantes();
                break;
            case 2:
                cout<<"--- Carga de Tareas ---"<<endl;
                cargaTareas();
                break;
            case 3:
                cout<<"Manual";
                manual();
                break;
            case 4:
                cout<<"Reportes";
                reportes();
                break;
            case 5:
                break;
            default:
                cout<<"INGRESE UN VALOR LEGIBLE";
                break;
        }
    }while(op!=5);
    return 0;
}

void cargaEstudiantes(){
    string rutaEst;
    cout<<"Ingrese ruta del archivo: ";
    cin>>rutaEst;
    ifstream archivo(rutaEst);
    
    string linea;
    char delimitador = ',';
    getline(archivo, linea);
    while (getline(archivo, linea))
    {

        stringstream stream(linea);
        string carnet,dpi,nombre,carrera,pass,creditos,edad,correo;
        getline(stream, carnet, delimitador);
        getline(stream, dpi, delimitador);
        getline(stream, nombre, delimitador);
        getline(stream, carrera, delimitador);
        getline(stream, pass, delimitador);
        getline(stream, creditos, delimitador);
        getline(stream, edad, delimitador);
        getline(stream, correo, delimitador);
        
        cout << "*******************" << endl;
        cout << "carnet: " << carnet << endl;
        cout << "dpi: " << dpi << endl;
        cout << "nombre: " << nombre << endl;
        cout << "carrera: " << carrera << endl;
        cout << "pass: " << pass << endl;
        cout << "creditos: " << creditos << endl;
        cout << "edad: " << edad << endl;
        cout << "correo: " << correo << endl;

        

    }
}

void cargaTareas(){
    string rutaTa;
    cout<<"Ingrese ruta del archivo: ";
    cin>>rutaTa;
    ifstream archivo(rutaTa);
    
    string linea;
    char delimitador = ',';
    getline(archivo, linea);
    while (getline(archivo, linea))
    {

        stringstream stream(linea);
        string id,carnet,nombre,descripcion,materia,fecha,hora,estado;
        getline(stream, id, delimitador);
        getline(stream, carnet, delimitador);
        getline(stream, nombre, delimitador);
        getline(stream, descripcion, delimitador);
        getline(stream, materia, delimitador);
        getline(stream, fecha, delimitador);
        getline(stream, hora, delimitador);
        getline(stream, estado, delimitador);
        
        cout << "*******************" << endl;
        cout << "id: " << id << endl;
        cout << "carnet: " << carnet << endl;
        cout << "nombre: " << nombre << endl;
        cout << "descripcion: " << descripcion << endl;
        cout << "materia: " << materia << endl;
        cout << "fecha: " << fecha << endl;
        cout << "hora: " << hora << endl;
        cout << "estado: " << estado << endl;
    }
}

void manual(){
    int ot, ee,tt;
    do
    {
        cout<<"--- Manual ---"<<endl;
        cout<<"1. Usuarios"<<endl;
        cout<<"2. Tareas"<<endl;
        cout<<"3. Salir"<<endl;
        cin>>ot;
        switch (ot)
        {
        case 1:
            cout<<"--- Usuarios ---"<<endl;
            cout<<"1. Ingresar"<<endl;
            cout<<"2. Modificar"<<endl;
            cout<<"3. Eliminar"<<endl;
            cout<<"4. Salir"<<endl;
            cout<<"Opcion: ";
            cin>>ee;
            switch (ee)
            {
            case 1:
                cout<<"Ingresar usuario"<<endl;
                break;
            case 2:
                cout<<"Modificar usuario"<<endl;
                break;
            case 3:
                cout<<"Elimiar usuario"<<endl;
                break;
            default:
                cout<<"Ingrese un valor valido"<<endl;
                break;
            }
            break;
        case 2:
            cout<<"--- Tareas ---"<<endl;
            cout<<"1. Ingresar"<<endl;
            cout<<"2. Modificar"<<endl;
            cout<<"3. Eliminar"<<endl;
            cout<<"4. Salir"<<endl;
            cout<<"Opcion: ";
            cin>>tt;
            switch (tt)
            {
            case 1:
                cout<<"Ingresar tareas"<<endl;
                break;
            case 2:
                cout<<"Modificar tareas"<<endl;
                break;
            case 3:
                cout<<"Elimiar tareas"<<endl;
                break;
            default:
                cout<<"Ingrese un valor valido"<<endl;
                break;
            }
            break;
            break;
        case 3:

            break;
        default:
            break;
        }

    } while (ot!=3);
    
}

void reportes(){
    int pp;
    do
    {
        cout<<"--- Reportes ---"<<endl;
        cout<<"1. Lista usuarios"<<endl;
        cout<<"2. Linealizacion tareas"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>pp;
        switch (pp)
        {
        case 1:
            cout<<"-Lista Usuarios-"<<endl;
            break;
        case 2:
            cout<<"-Linealizacion tareas-"<<endl;
            break;
        case 3:
            break;
        default:
            cout<<"Ingresar valor valido";
            break;
        }
    } while (pp!=3);
}