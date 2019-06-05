
//METODO PARA COLOCAR OS ATRIBUTOS NA CARTA//
constroiCarta(Nome,Vitalidade,Inteligencia,Forca,Velocidade,Habilidade,Especial,carta(Nome,Vitalidade,Inteligencia,Forca,Velocidade,Habilidade,Especial)).

//METODOS PARA ACESSAR AOS ATRIBUTOS DA CARTA//
//METODO QUE ACESSA O NOME DA CARTA, TA PRONTO.//
//PRECISA APENAS IMPLEMENTAR PARA ACESSAR OS OUTROS ATRIBUTOS.//
getNome(carta(Nome,_,_,_,_,_,_),Nome).

getVitalidade
getInteligencia
getForca
getVelocidade
getHabilidade
getEspecial

//PARA SABER SE A CARTA EH ESPECIAL OU NAO//
ehEspecial(carta(_,_,_,_,_,_,True))

//TO STRING DA CARTA, REPRESENTACAO EM STRING DA CLASSE CARTA//
//PRECISA IMPLEMENTAR//
descricaoCarta(Carta) :-
   
//PARA SABER SE DUAS STRINGS SAO IGUAIS, JA TA PRONTO//
stringIgual(StringA,StringB,Equal) :-
    string_to_atom(StringA, Atom),
    string_to_atom(StringB, Atom2),
    ((Atom == Atom2) -> Equal = 1; Equal = 0).


//PARA COMPARAR OS ATRIBUTOS DAS CARTAS, PRECISA IMPLEMENTAR.//
comparaCarta(Carta1,Carta2,Atributo,Comparador) :-

//PRECISA USAR UM METODO AUXILIAR PARA IMPLEMENTAR O COMPARA CARTA ANTERIOR//    
comparaCartaAuxiliar(Atributo1,Atributo2,Desempata,Comparador) :-
    









