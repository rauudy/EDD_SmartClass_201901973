from ArbolB.ArbolB import Arbol_B
from ArbolB.Grafo import Grafo
from Listas.Anios import anios
from Listas.Tareas import tarea
from Structures.List import List
from analyzers.Syntactic import parser
from analyzers.Syntactic import user_list, task_list
from Listas.DobleEnlazadaTarea import linked_list_de
from Listas.DE_Anios import linked_list_de_anios
from flask import Flask, jsonify, request,json

app = Flask(__name__)
arbolB=Arbol_B(5)
listAn=linked_list_de_anios()
g = Grafo()

listanios=[]

@app.route('/')
def index():
    return "Hola clase de lab EDD"

@app.route('/cargacursos', methods=['POST'])
def pensum():
    if request.method == 'POST':
        x = request.json
        cursos=list(x['Cursos'])
        for curso in cursos:
            print(curso['Codigo'])
            arbolB.insertar(int(curso['Codigo']))
        g.generarGrafo(arbolB.raiz)
        return jsonify({'status': "Goooooooood"})

    return jsonify({'status': "Todo bien"})

@app.route("/cargaestudiantes", methods=['POST'])
def estudiantes():
    global listanios, listAn
    if request.method == 'POST':
        x = request.json
        estudiantes=list(x['Estudiantes'])
        i=0
        student=[]
        carnet=[]
        añoss=[]
        semes=[]
        cursosB=list()
        for estudiante in estudiantes:
            student.append([estudiante['Carnet']])
            carnet.append(estudiante['Carnet'])
            

            for anio in estudiante['Años']:
                añoss.append(anio['Año'])

            for a in range(len(student)):
                for anio in estudiante['Años']:
                    if str(estudiante['Carnet']) == str(carnet[a]):
                        student[a].append([anio['Año']])
                        listanios.append([anio['Año']])

        for b in range(len(listanios)):
            listanios[b].append([])
        
        for estudiante in estudiantes:
            for anio in estudiante['Años']:
                for a in range(len(listanios)):
                    for cursos in anio['Semestres']:
                        if str(anio['Año']) == str(añoss[a]):
                            listanios[a][1].append(cursos['Semestre'])
                            print()
                            
                            



        print("Prueba")
        print(student[0])

        print("Prueba")
        print(listanios[0][1][0])
        
        for a in listanios:
            #print(a[0])
            listAn.insertarAnio(anios(a[0],a[1]))

        listAn.imprimirAnios()       

        return jsonify({'status:': 'todo bien bb'})

    return jsonify({'status': "Todo bien"})

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    f = open('Estudiantes.txt',"r", encoding="utf-8")
    mensaje = f.read()
    f.close()
    parser.parse(mensaje)

    #user_list.getList()
    #print(type(user_list.First))
    #print("------------------------")
    #task_list.getList()
    #print(type(task_list))
    

    #print("----------------------")
    user_list.prueba()
    task_list.tareasPrueba()
    


    # -----------------------

    app.run(debug=True,port=3000)
    

