:- initialization main.
:- use_module(library(pio)).
:- include('Auxiliar.pl').
:- include('MenuAuxiliar.pl').

main :-
    exibeLetreiro,
    menu.

menu :-
    menuInicial,
    inputOpcao(Opcao),
    selecionaOpcao(Opcao).

inputOpcao(Opcao) :-
  read(Option),
  (validaOpcao(Option) -> Opcao = Option ; inputOpcao(Opcao)).

validaOpcao(1).
validaOpcao(2).
validaOpcao(3).
validaOpcao(4).

selecionaOpcao(1) :- iniciaJogo.

selecionaOpcao(2) :- visualizaBaralho.

selecionaOpcao(3) :- exibeRegras.
selecionaOpcao(4) :- halt(0).

iniciaJogo :-
    write('Comeca o jogo aqui!').

