
#Definicion
"""
class Persona:
    def __init__(self, nombre, edad):
        self.nombre = nombre
        self.edad = edad

    def saluda(self, otra_persona):
        print("Hola {}  me llamo {}".format(otra_persona.nombre,self.nombre))

#uso

david = Persona("DAVID",35)
erika = Persona("ERIKA",32)

david.saluda(erika) practicas 
"""

class saludarAlgatoNegro:

    def __init__(self,nombre):
        self.nombre = nombre
    def saludo(self,nombre):
        print("hola {} Gatico  ".format(self.nombre))
    def miau(self):
        print("Miaaaaaauuu")
    def alimentar(self,comida):
        self.comida = comida
        item = len(comida)
        if item > 0 :
            for i in range(len(comida)):
                print("toma tu {} lindo Gatito {}".format(comida[i],self.nombre))
        else:
            print("no seas triple hp dale comida al gatico negro")

    def ataque(self):
        #self.rasguno = rasguno

        rasguno = input(str("Quieres al gato?: "))
        if rasguno == "si":
            print("Ronrronear")
        else:
            print("Aruñar")

    def dormir(self):
        print("El gatito quiere dormir ")

Gato = saludarAlgatoNegro("Isabella")
lista = ['leche','macflurry','atun']
#lista = []
Gato.saludo(Gato)
Gato.miau()
Gato.alimentar(lista)
Gato.ataque()
Gato.dormir()