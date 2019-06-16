constroiCarta(Nome,Vitalidade,Inteligencia,Forca,Velocidade,Habilidade,EhEspecial,carta(Nome,Vitalidade,Inteligencia,Forca,Velocidade,Habilidade,EhEspecial)).

getNome(carta(Nome,_,_,_,_,_,_),Nome).
getVitalidade(carta(_,Vitalidade,_,_,_,_,_),Vitalidade).
getInteligencia(carta(_,_,Inteligencia,_,_,_,_),Inteligencia).
getForca(carta(_,_,_,Forca,_,_,_),Forca).
getVelocidade(carta(_,_,_,_,Velocidade,_,_),Velocidade).
getHabilidade(carta(_,_,_,_,_,Habilidade,_),Habilidade).
getEspecial(carta(_,_,_,_,_,_,EhEspecial),EhEspecial).

descricaoCarta(Carta) :-
    write('') ,nl,
    getNome(Carta,Nome_),
    getVitalidade(Carta,Vitalidade_),
    getInteligencia(Carta,Inteligencia_),
    getForca(Carta,Forca_),
    getVelocidade(Carta,Velocidade_),
    getHabilidade(Carta,Habilidade_),
    Especial = ehEspecial(Carta),
    string_concat('Nome: ', Nome_, Nome),
    string_concat('Vitalidade: ', Vitalidade_, Vitalidade),
    string_concat('Inteligencia: ', Inteligencia_, Inteligencia),
    string_concat('Forca: ', Forca_, Forca),
    string_concat('Velocidade: ', Velocidade_, Velocidade),
    string_concat('Habilidade: ', Habilidade_ , Habilidade),
    
    write(Nome),nl,
    write(Vitalidade),nl,
    write(Inteligencia),nl,
    write(Forca),nl,
    write(Velocidade),nl,
    write(Habilidade),nl,
    Especial -> write('CARTA ESPECIAL') ; write('').

ehEspecial(carta(_,_,_,_,_,_,1)).

ehEspecial(Carta,Is) :-
    getEspecial(Carta) -> Is = 1; Is = 0.

string_equals(StringA,StringB,Equal) :-
    string_to_atom(StringA, Atom),
    string_to_atom(StringB, Atom2),
    ((Atom == Atom2) -> Equal = 1; Equal = 0).


criaAcumulador(Cont,Ac_Vitalidade,Ac_Inteligencia,Ac_Forca,Ac_Velocidade,Ac_Habilidade, acumuladorAtributo(Cont,Ac_Vitalidade,Ac_Inteligencia,Ac_Forca,Ac_Velocidade,Ac_Habilidade)).

getAcumuladorCont(acumuladorAtributo(Cont,_,_,_,_,_),Cont).
getAcumuladorVit(acumuladorAtributo(_,Ac_Vitalidade,_,_,_,_),Ac_Vitalidade).
getAcumuladorInt(acumuladorAtributo(_,_,Ac_Inteligencia,_,_,_),Ac_Inteligencia).
getAcumuladorFor(acumuladorAtributo(_,_,_,Ac_Forca,_,_),Ac_Forca).
getAcumuladorVel(acumuladorAtributo(_,_,_,_,Ac_Velocidade,_),Ac_Velocidade).
getAcumuladorHab(acumuladorAtributo(_,_,_,_,_,Ac_Habilidade),Ac_Habilidade).

atualizaAcumulador(Acumulador,Carta,Acumulador2) :-
  getAcumuladorCont(Acumulador,Cont),
  getAcumuladorVit(Acumulador,Vit),
  getAcumuladorInt(Acumulador,Int),
  getAcumuladorFor(Acumulador,For),
  getAcumuladorVel(Acumulador,Vel),
  getAcumuladorHab(Acumulador,Hab),

  getVitalidade(Carta,Vit_S),
  number_string(Vit_,Vit_S),
  getInteligencia(Carta,Int_S),
  number_string(Int_,Int_S),
  getForca(Carta,For_S),
  number_string(For_,For_S),
  getVelocidade(Carta,Vel_S),
  number_string(Vel_,Vel_S),
  getHabilidade(Carta,Hab_S),
  number_string(Hab_,Hab_S),

  Con is Cont + 1,
  Vitalidade is Vit + Vit_,
  Inteligencia is Int + Int_,
  Forca is For + For_,
  Velocidade is Vel + Vel_,
  Habilidade is Hab + Hab_,

  Acumulador2 = acumuladorAtributo(Con,Vitalidade,Inteligencia,Forca,Velocidade,Habilidade).


mediaVit(Acumulador,Media) :-
   getAcumuladorVit(Acumulador,Vit),
   getAcumuladorCont(Acumulador,Cont),
   Media is Vit / Cont.

mediaInt(Acumulador,Media) :-
    getAcumuladorInt(Acumulador,Int),
    getAcumuladorCont(Acumulador,Cont),
    Media is Int / Cont.

mediaFor(Acumulador,Media) :-
    getAcumuladorFor(Acumulador,For),
    getAcumuladorCont(Acumulador,Cont),
    Media is For / Cont.

mediaVel(Acumulador,Media) :-
    getAcumuladorVel(Acumulador,Vel),
    getAcumuladorCont(Acumulador,Cont),
    Media is Vel / Cont.

mediaHab(Acumulador,Media) :-
    getAcumuladorHab(Acumulador,Hab),
    getAcumuladorCont(Acumulador,Cont),
    Media is Hab / Cont.

desempata(StringA,StringB,Comparator) :-
    (StringA @< StringB) -> Comparator = 1 ; Comparator = -1.

comparaCarta(Carta1,Carta2,Atributo,Comparador) :-
    string_equals(Atributo,'VITALIDADE',Vitalidade_eq),
    string_equals(Atributo,'INTELIGENCIA',Inteligencia_eq),
    string_equals(Atributo,'FORCA',Forca_eq),
    string_equals(Atributo,'VELOCIDADE',Velocidade_eq),
    string_equals(Atributo,'HABILIDADE',Habilidade_eq),

    getVitalidade(Carta1,Vitalidade_1),
    number_string(Vitalidade1,Vitalidade_1),
    getVitalidade(Carta2,Vitalidade_2),
    number_string(Vitalidade2,Vitalidade_2),

    getInteligencia(Carta1,Inteligencia_1),
    number_string(Inteligencia1,Inteligencia_1),
    getInteligencia(Carta2,Inteligencia_2),
    number_string(Inteligencia2,Inteligencia_2),

    getForca(Carta1,Forca_1),
    number_string(Forca1,Forca_1),
    getForca(Carta2,Forca_2),
    number_string(Forca2,Forca_2),

    getVelocidade(Carta1,Velocidade_1),
    number_string(Velocidade1,Velocidade_1),
    getVelocidade(Carta2,Velocidade_2),
    number_string(Velocidade2,Velocidade_2),

    getHabilidade(Carta1,Habilidade_1),
    number_string(Habilidade1,Habilidade_1),
    getHabilidade(Carta2,Habilidade_2),
    number_string(Habilidade2,Habilidade_2),

    getEspecial(Carta1,Especial1),
    getEspecial(Carta2,Especial2),
    desempata(Especial1,Especial2,Desempate),

    (Vitalidade_eq == 1 -> comparaCartaAuxiliar(Vitalidade1,Vitalidade2,Desempate,Comparador);
     Inteligencia_eq == 1 -> comparaCartaAuxiliar(Inteligencia1,Inteligencia2,Desempate,Comparador);
     Forca_eq == 1 -> comparaCartaAuxiliar(Forca1,Forca2,Desempate,Comparador);
     Velocidade_eq == 1 -> comparaCartaAuxiliar(Velocidade1,Velocidade2,Desempate,Comparador);
     Habilidade_eq == 1 -> comparaCartaAuxiliar(Habilidade1,Habilidade2,Desempate,Comparador)).
    
comparaCartaAuxiliar(Atributo1,Atributo2,Desempata,Comparador) :-
    Subtracao is Atributo1 - Atributo2,
   (Subtracao \= 0 -> Comparador is Subtracao ; Comparador is Desempata).









