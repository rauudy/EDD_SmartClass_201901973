from Listas.DobleEnlazada import node_de_anios


class curso:
    def __init__(self,codigo,nombre,creditos,prerequisitos,obligatorio):
        self.codigo = codigo
        self.nombre = nombre
        self.creditos = creditos
        self.prerequisitos = prerequisitos
        self.obligatorio = obligatorio