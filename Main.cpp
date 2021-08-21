#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<fstream>
#include<vector>

using namespace std;

void lectura(char ruta[50]);

int main(){
	int op;
	char ruta[50];
	string txt;
	do{
		cout<<"\n\tMENU";
		cout<<"\n1. Cargar usuarios\n2. Cargar tareas";
		cout<<"\n3. Ingresar manual\n4. Reportes";
		cout<<"\n5. Salir";
		cout<<"\nOpcion: "; cin>>op;
		
		switch(op){
			case 1:
				cout<<"Usuarios"<<endl;
				cout<<"Ingrese ruta del archivo: ";cin>>ruta;
				lectura(ruta);
				//txt=lectura(ruta);
				//cout<<txt<<endl;
				getch();
				break;
			case 2:
				cout<<"Tareas";
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

void lectura(char ruta[50]){
	ifstream archivo;
	string texto;
	//string estudiantes[30];
	vector<string> alumnos;
	int i=0;
	
	archivo.open(ruta,ios::in); //Abrimos el archivo en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	while(!archivo.eof()){ //mientras no sea el final del archivo
		getline(archivo,texto);
		cout<<texto<<endl;
		alumnos.push_back(texto);
		//return texto;
	}
	cout<<"Estudiantes guardados";
	getch();
	
	for(int i=0;i<=30;i++){
		cout<<alumnos[i];
	}
	
	
	
	archivo.close(); //Cerramos el archivo
	
	//return texto;
	
}
