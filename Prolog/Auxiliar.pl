:- include('Carta.pl').
//METODO PARA INICIALIZAR AS CARTAS DE HEROIS USANDO O ARQUIVO TXT//
iniciaCartaHerois(Carta) :-
   
//METODO PARA INICIALIZAR AS CARTAS DE VILOES USANDO O ARQUIVO TXT//
iniciaCartaViloes(Carta) :-
    
//FUNCAO QUE MAPEIA O LOCAL DE UMA LISTA PARA UM OBJETO, JA TA PRONTA.//
map(Index,FunctionName,[H|T],[NH|NT]):-
   Function=..[FunctionName,Index,H,NH],
   call(Function),
   map(Index,FunctionName,T,NT).
map(_,_,[],[]).

//FUNCAO PARA LER ARQUIVOS, JA TA PRONTA.//
read_file(Stream,[]) :-
    at_end_of_stream(Stream).

read_file(Stream,[X|L]) :-
    \+ at_end_of_stream(Stream),
    read_line_to_string(Stream, String),
    atomic_list_concat(X,' ', String),
    read_file(Stream,L), !.

//FUNCAO PARA MAPEAR OS ATRIBUTOS DAS CARTAS PARA UMA LISTA, USA A FUNCAO MAP ANTERIOR. FALTA IMPLEMENTAR//
mapeiaCartas :-
