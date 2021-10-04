from Structures.NodeS import NodeS
from ArbolAVL.Avl import  Avl
from ArbolAVL.Grafo import Grafo
from Listas.DobleEnlazadaTarea import linked_list_de
from Listas.Tareas import tarea
from Listas.Anios import anios
import random




class List:
    def __init__(self):
        self.First = None
        self.Last = None
        self.arbol=Avl()
        self.grafo=Grafo()
        self.listadoble=linked_list_de()

    def getSize(self):
        aux = self.First
        counter = 0
        while aux is not None:
            counter += 1
            aux = aux.Next()

        return counter

    def isEmpty(self):
        return self.First is None

    def getList(self):
        aux = self.First
        while aux is not None:
            print(aux.Carnet + " - " + aux.Nombre + "-" + aux.DPI + "-" + aux.Descripcion + "-" + aux.Correo)
            aux = aux.Next

    def insertValue(self, carnet, dpi, nombre, carrera, password, creditos, edad, correo, descripcion, materia, fecha, hora, estado):
        #cont=0
        new_node = NodeS(carnet, dpi, nombre, carrera, password, creditos, edad, correo, descripcion, materia, fecha, hora, estado)
        self.arbol.insertar(int(carnet),str(nombre),str(carrera))
        self.listadoble.insertarTarea(tarea(carnet,nombre,descripcion,materia,fecha,hora,estado))
        #self.listadoble.insertarAnio(anios())
        #cont+=1

        if self.isEmpty():
            self.Last = new_node
            self.First = self.Last
            
        else:
            self.Last.Next = new_node
            new_node.Previous = self.Last
            self.Last = new_node

    def prueba(self):
        self.grafo.graficarArbol(self.arbol.raiz)
    
    def tareasPrueba(self):
        self.listareas.imprimirTarea()

