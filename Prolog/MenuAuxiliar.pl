exibeLetreiro :-
    open('letreiro.txt', read, Str),
    read_file(Str,String),
    close(Str),
    nl,nl,
    exibeNaTela(String).
    
menuInicial :-
    nl,
    write('1) Jogar'),nl,
    write('2) Visualizar Baralhos'),nl,
    write('3) Regras'),nl,
    write('4) Sair'),nl,
    write('Escolha uma Opcão: ').


visualizaBaralho :-
    open('cartas.txt', read, Str),
    read_file(Str,String),
    close(Str),
    nl,nl,
    exibeNaTela(String),
    menu.

exibeRegras :-
    shell(clear),
    write('As regras do jogo são as seguintes:'),nl,
    write('->O jogador e a máquina irão alternar turnos'), nl,
    write('->O jogador puxa aleatoriamente 3 cartas das 15 do seu baralho'),nl,
    write('->Escolhe 1 para colocar em combate'),nl,
    write('->As outras 2 nao escolhidas retornam ao deck'),nl,
    write('->Em cada turno escolhe um atributo para a batalha'),nl,
    write('->Marca 1 ponto quem tiver maior atributo'),nl,
    write('->Cartas especiais concederá o dobro de pontos para o vencedor do turno.'),nl,
    write('->As duas cartas que batalharam são removidas do jogo'),nl,
    write('->Quando acabarem as cartas quem tiver mais ponto vence o jogo.'),nl,
    menu.

exibeNaTela([]).

exibeNaTela([H|T]):- 
    write(H),nl, 
    exibeNaTela(T).