class Node:
    def __init__(self, _id, nombre,carrera):
        self.id = _id
        self.nombre = nombre
        self.carrera = carrera
        self.Previous = None
        self.Next = None