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
    write('->O jogador e a máquina irão batalhar em turnos.'), nl,
    write('->O player joga com o baralho de HÉROIS e a máquina com o de VILÕES.'),nl,
    write('->O jogador puxa aleatoriamente 1 cartas das 16 do seu baralho'),nl,
    write('->Em cada turno, o jogador escolhe um atributo para a batalha'),nl,
    write('->Atributo da máquina será escolhido aleatoriamente tendendo para o maior.'),nl,    
    write('->Ganha a carta do oponente quem tiver maior atributo'),nl,
    write('->Cartas especiais concederá a vitória instantânea do turno.'),nl,
    write('->O jogo acaba quando algum dos jogadores ficarem sem carta. O vencendor será quem tiver cartas no baralho.'),nl,
    menu.

exibeNaTela([]).

exibeNaTela([H|T]):- 
    write(H),nl, 
    exibeNaTela(T).