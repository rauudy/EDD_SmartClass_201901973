import os

def nodoGrafTarea(nombre,apellido,numero):
    return "[label=\"" + "Nombre: " + nombre + "\n  Apellido: " +  apellido + "\n  Numero:"+ numero + "\" , shape=box,style=filled, fillcolor =skyblue]\n"


def crearGraphis():
    file = open("graphiz1.dot", "w")
    file.write("digraph Tarea1{\n")
    file.write("edge[dir="'both'"]\n")

    file.write("AgendaM[label="'Agenda'" , shape=box,style=filled, fillcolor =skyblue]\n")
    k = []
    for aa in nodosGraficTarea:
        le = random.choice(string.ascii_letters)
        file.write( le +str(aa))
        k.append(le)



    file.write("AgendaM->") 
    contador= 0
    for m in k:
        if contador != len(k)-1:
            file.write(str(m) + "->")
        else:
            file.write(str(m))
        contador += 1


    file.write("\n")
    
       
    file.write("}")
    file.close()
    os.system("dot -Tpng graphiz1.dot -o graphiz1.png")
    os.startfile("graphiz1.png")
