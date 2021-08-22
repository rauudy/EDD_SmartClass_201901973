//Tareas
#include<iostream>
using namespace std;

class Tareas
{
private:
    string id;
    string carnet;
    string nombre;
    string descripcion;
    string materia;
    string fecha;
    string hora;
    string estado;

public:
    Tareas(string,string,string,string,string,string,string,string);
};

Tareas::Tareas(string _id,string _carnet,string _nombre,string _descripcion,string _materia,string _fecha,string _hora,string _estado)
{
    id = _id;
    carnet = _carnet;
    nombre = _nombre;
    descripcion = _descripcion;
    materia = _materia;
    fecha = _fecha;
    hora = _hora;
    estado = _estado;
}

