import os

class Grafo:
    def __init__(self):
        pass

    def graficarArbol(self, raiz):
        acumuladores = ["digraph G{\nnode [shape=rectangle];\n", ""]

        if raiz != None:
            self.recorrerArbol(raiz,acumuladores)

        acumuladores[0] += acumuladores[1] + "\n}"

        f = open('grafoAVL.dot', 'w')
        try:
            f.write(acumuladores[0])
        finally:
            f.close()

        prog = "dot -Tpng  grafoAVL.dot -o grafoAVL.png"
        os.system(prog)


    def recorrerArbol(self, raiz,acum):

        if raiz:
            acum[1] += '"{}"[label="{}"];\n'.format(str(hash(raiz)),str(raiz.id)+"\n"+str(raiz.nombre)+"\n"+str(raiz.carrera))

            if raiz.Previous.raiz != None:
                acum[1] += '"{}" -> "{}";\n'.format(str(hash(raiz)),str(hash(raiz.Previous.raiz)))
            if raiz.Next.raiz != None:
                acum[1] += '"{}" -> "{}";\n'.format(str(hash(raiz)), str(hash(raiz.Next.raiz)))

            self.recorrerArbol(raiz.Previous.raiz, acum)
            self.recorrerArbol(raiz.Next.raiz, acum)