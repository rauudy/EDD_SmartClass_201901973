//Estudiantes

#include<iostream>
using namespace std;

class Estudiante{
	private:
		string carnet;
		string dpi;
		string nombre;
		string carrera;
		string pass;
		string creditos;
		string edad;
		string correo;
	public:
		Estudiante(string,string,string,string,string,string,string,string);
};

Estudiante::Estudiante(string _carnet,string _dpi,string _nombre,string _carrera,string _pass,string _creditos,string _edad,string _correo){
	carnet = _carnet;
	dpi = _dpi;
	nombre = _nombre;
	carrera = _carrera;
	pass = _pass;
	creditos = _creditos;
	edad = _edad;
	correo = _correo;
}
