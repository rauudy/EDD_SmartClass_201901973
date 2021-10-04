from ArbolAVL.NodeAvl import Node

class Avl:
    def __init__(self):
        self.raiz = None

        self.altura = -1
        self.equilibrio = 0

    def insertar(self,_id,nombre,carrera):
        nuevo = Node(_id,nombre,carrera)
        if self.raiz == None:
            self.raiz = nuevo
            self.raiz.Previous = Avl()
            self.raiz.Next = Avl()
        elif _id > self.raiz.id:
            self.raiz.Next.insertar(_id,nombre,carrera)
        elif _id < self.raiz.id:
            self.raiz.Previous.insertar(_id,nombre,carrera)
        else: #YA EXISTE
            print("el valor ya existe")
        self.balancear()

    def balancear(self):
        self.actualizarAlturas(recursivo= False)
        self.actualizarEquilibrio(False)
        while self.equilibrio < -1 or self.equilibrio > 1:
            if self.equilibrio > 1:
                if self.raiz.Previous.equilibrio < 0:
                    self.raiz.Previous.rotacionziquierda()
                    self.actualizarAlturas()
                    self.actualizarEquilibrio()
                self.rotacionDerecha()
                self.actualizarAlturas()
                self.actualizarEquilibrio()
            if self.equilibrio < -1:
                if self.raiz.Next.equilibrio > 0:
                    self.raiz.Next.rotacionDerecha()
                    self.actualizarAlturas()
                    self.actualizarEquilibrio()
                self.rotacionziquierda()
                self.actualizarAlturas()
                self.actualizarEquilibrio()


    def actualizarAlturas(self, recursivo =  True):
        if self.raiz == None:
            self.altura = -1
        else:
            if recursivo:
                if self.raiz.Previous != None:
                    self.raiz.Previous.actualizarAlturas()
                if self.raiz.Next != None:
                    self.raiz.Next.actualizarAlturas()
            self.altura = max(self.raiz.Previous.altura, self.raiz.Next.altura) + 1

    def actualizarEquilibrio(self, recursivo = True):
        if self.raiz == None:
            self.equilibrio = 0
        else:
            if recursivo:
                if self.raiz.Previous != None:
                    self.raiz.Previous.actualizarEquilibrio()
                if self.raiz.Next != None:
                    self.raiz.Next.actualizarEquilibrio()
            self.equilibrio = self.raiz.Previous.altura - self.raiz.Next.altura

    def rotacionDerecha(self):
        raiz = self.raiz
        self.raiz = raiz.Previous.raiz
        raiz.Previous.raiz = self.raiz.Next.raiz
        self.raiz.Next.raiz = raiz

    def rotacionziquierda(self):
        raiz = self.raiz
        self.raiz = raiz.Next.raiz
        raiz.Next.raiz = self.raiz.Previous.raiz
        self.raiz.Previous.raiz = raiz

    def enOrden(self):
        arr = []
        self.enOrden2(self.raiz,arr)
        return arr

    def enOrden2(self, raizActual,arr):
        if raizActual:
            self.enOrden2(raizActual.Previous.raiz , arr )
            # print(raizActual.id)
            arr.append(
                {
                    "id":raizActual.id,
                    "nombre":raizActual.nombre,
                    "carrera":raizActual.carrera
                }
            )
            self.enOrden2(raizActual.Next.raiz , arr )