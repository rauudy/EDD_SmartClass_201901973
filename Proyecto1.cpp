#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include <sstream>
#include <fstream>
using namespace std;


void cargaEstudiantes();
void cargaTareas();

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
                break;
            case 4:
                cout<<"Reportes";
                break;
            case 5:
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
