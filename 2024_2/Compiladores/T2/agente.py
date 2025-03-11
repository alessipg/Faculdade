from maspy import *

class ag1(Agent):
    def __init__(self, agt_name):
        super().__init__(agt_name)
        self.add(Belief("estaChovendo"))
        self.add(Belief("naotenhoGuardaChuva"))
        self.add(Belief("tenhoProva"))
        self.add(Goal("comprarGuardaChuva"))

    @pl(gain,Goal("comprarGuardaChuva"), Belief("estaChovendo"))
    def comprarGuardaChuva_(self, src):
        self.print("sair para comprar guardachuva")
        self.print("procurar loja")
        self.print("comprar guardachuva")
        self.add(Goal("estudar"))

    @pl(gain,Goal("estudar"), Belief("tenhoProva"))
    def estudar_(self, src):
        self.print("estudar sozinho")

class ag2(Agent):
    def __init__(self, agt_name):
        super().__init__(agt_name)
        self.add(Belief("estaChovendo"))
        self.add(Belief("tenhoGuardaChuva"))
        self.add(Belief("tenhoProva"))

    @pl(gain,Belief("tenhoGuardaChuva"), Belief("estaChovendo"))
    def tenhoGuardaChuva_(self, src):
        self.print("preparar materiais de estudo")
        self.add(Goal("estudarNaBiblioteca"))

    @pl(gain,Goal("estudarNaBiblioteca"), Belief("tenhoProva"))
    def estudarNaBiblioteca_(self, src):
        self.print("escolher caminho")
        self.print("usar guardachuva")
        self.print("ir para biblioteca")
        self.print("estudar!")

class ag3(Agent):
    def __init__(self, agt_name):
        super().__init__(agt_name)
        self.add(Belief("estaFrio"))
        self.add(Belief("tenhoCasaco"))
        self.add(Belief("precisoFazerCompras"))
        self.add(Goal("irAoMercado"))

    @pl(gain,Goal("irAoMercado"), Belief("precisoFazerCompras"))
    def irAoMercado_(self, src):
        self.print("colocar casaco")
        self.print("sair para o mercado")
        self.print("comprar mantimentos")

class ag4(Agent):
    def __init__(self, agt_name):
        super().__init__(agt_name)
        self.add(Belief("tenhoTrabalho"))
        self.add(Belief("gostoDeCafe"))
        self.add(Belief("cafeteriaAberta"))
        self.add(Goal("tomarCafe"))

    @pl(gain,Goal("tomarCafe"), Belief("cafeteriaAberta"))
    def tomarCafe_(self, src):
        self.print("pegar carteira")
        self.print("ir para cafeteria")
        self.print("comprar cafe")
        self.print("relaxar antes do trabalho")

class ag5(Agent):
    def __init__(self, agt_name):
        super().__init__(agt_name)
        self.add(Belief("tenhoSono"))
        self.add(Belief("precisoEstudar"))
        self.add(Belief("tenhoCafe"))
        self.add(Goal("acordar"))

    @pl(gain,Goal("acordar"), Belief("tenhoSono"))
    def acordar_(self, src):
        self.print("beber cafe")
        self.print("lavar rosto")
        self.print("estudar")

ag1("bob")
ag2("alice")
ag3("carlos")
ag4("diana")
ag5("eduardo")
Admin().start_system()
