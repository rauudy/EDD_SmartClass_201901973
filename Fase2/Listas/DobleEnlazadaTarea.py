#from Listas.NodoTareas import node_de

class node_de:
    def __init__(self, tarea=None, next=None, previous=None):
        self.tarea = tarea
        self.next = next
        self.previous = previous

class node_de_anios:
    def __init__(self, anio=None, next=None, previous=None):
        self.anio = anio
        self.next = next
        self.previous = previous

class linked_list_de:
    def __init__ (self, head=None):
        self.head = head
        self.last = head
        self.size = 0

    def insertarTarea(self,Tarea):
        if self.size == 0:
            self.head = node_de(Tarea)
            self.last = self.head
        else:
            new_node = node_de(Tarea, next=self.head)
            self.head.previous = new_node
            self.head = new_node
        self.size += 1
    
    def insertarAnio(self,anio):
        if self.size == 0:
            self.head = node_de_anios(anio)
            self.last = self.head
        else:
            new_node = node_de_anios(anio, next=self.head)
            self.head.previous = new_node
            self.head = new_node
        self.size += 1

    def imprimirTarea(self):
        if self.head is None:
            return
        node = self.head
        print(node.tarea.nombre, end = " => ")
        while node.next:
            node = node.next
            print(node.tarea.nombre, end = " => ")
    
    def imprimirAnios(self):
        if self.head is None:
            return
        node = self.head
        print(node.anio.anio, end = " => ")
        while node.next:
            node = node.next
            print(node.anio.anio, end = " => ")
    
    def grafoTareas(self):
        file = open("graphiz1.dot", "w")
        file.write("digraph Tarea1{\n")
        file.write("edge[dir="'both'"]\n")
        if self.head is None:
            return
        node = self.head
