:- include('Carta.pl').

iniciaCarta(Carta) :-
    open('arquivo.txt', read, Str),
    read_file(Str,Cartas),
    random(1,30,Index_Trunfo),
    map(Index_Trunfo,mapeiaCartas,Cartas,Carta),
    close(Str).

iniciaPilha([H|T],Pilha1,Pilha2) :-
    reverse([H|T], Lista_Invertida),
    takeLista([H|T],Lista1),
    takeLista(Lista_Invertida,Lista2),
    stack(Lista1,Pilha1),
    stack(Lista2,Pilha2).
   
takeLista([H|T],[[NH|NT]]) :-
    takeListaAux(0,[H|T],[NH|NT]).

takeListaAux(16,_,_).
takeListaAux(Index,[H|T],[NH|NT]) :-
    Index_1 is Index + 1,
    NH = H,
    takeListaAux(Index_1,T,NT).

map(Index,FunctionName,[H|T],[NH|NT]):-
   Function=..[FunctionName,Index,H,NH],
   call(Function),
   map(Index,FunctionName,T,NT).
map(_,_,[],[]).

read_file(Stream,[]) :-
    at_end_of_stream(Stream).

read_file(Stream,[X|L]) :-
    \+ at_end_of_stream(Stream),
    read_line_to_string(Stream, String),
    atomic_list_concat(X,' ', String),
    read_file(Stream,L), !.

mapeiaCartas(PosicaoSuper,ListaString,Carta) :-
        nth0(0, ListaString, String),
        split_string(String, ',', ' ,', List),
        nth0(0, List, Nome),
        nth0(1, List, Vitalidade),
        nth0(2, List, Inteligencia),
        nth0(3, List, Forca),
        nth0(4, List, Velocidade),
        nth0(5, List, Habilidade),
        nth0(6, List, Super),
        number_string(IndexNumber,Super),
        ehSuper(IndexNumber,PosicaoSuper,Especial),
        constroiCarta(Nome,Vitalidade,Inteligencia,Forca,Velocidade,Habilidade,Especial,Carta).

ehSuper(Index,IndexCarta,Super):- 
    (Index == IndexCarta -> Super = 1 ; Super = 0).

imprimeLinha(0):-!. 
imprimeLinha(X):- 
    integer(X), 
    Y is X - 1, 
    nl, 
    imprimeLinha(Y).