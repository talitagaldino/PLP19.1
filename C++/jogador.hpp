int entradaPlayer1(carta tuplaDeCartasParaEscolherPlayer1[3], int cartasRestantes, int pontosPlayer1, int pontosPlayer2) {
    int resposta = -1;
    if(cartasRestantes == 1){
		exibirCartasNaTela(tuplaDeCartasParaEscolherPlayer1, 1);
        cout << "\033[1;32mEsta é sua ultima carta, digite 1 para continuar: \033[m";
        cin >> resposta;//apenas para pausar axecucao
        resposta = 0;
    } else if(cartasRestantes == 2) {
        exibirCartasNaTela(tuplaDeCartasParaEscolherPlayer1, 2);
        DialogoEntradaPlayer1(false,false,pontosPlayer1,pontosPlayer2);
        cin >> resposta;
        if(resposta == 9) {
            exibirRegrasInGame();
        }
        while (resposta < 0 || resposta > 1){
            limparTela();
            exibirCartasNaTela(tuplaDeCartasParaEscolherPlayer1, 2);
            DialogoEntradaPlayer1(false,true,pontosPlayer1,pontosPlayer2);
            cin >> resposta;
            if(resposta == 9) {
                exibirRegrasInGame();
            }
        }
    } else {
        exibirCartasNaTela(tuplaDeCartasParaEscolherPlayer1, 3);
        DialogoEntradaPlayer1(true, false, pontosPlayer1,pontosPlayer2);
        cin >> resposta;
        if(resposta == 9) {
            exibirRegrasInGame();
        }
        while (resposta < 0 || resposta > 2){
            limparTela();
            exibirCartasNaTela(tuplaDeCartasParaEscolherPlayer1, 3);
            DialogoEntradaPlayer1(true,true,pontosPlayer1,pontosPlayer2);
            cin >> resposta;
            if(resposta == 9) {
                exibirRegrasInGame();
            }
        }
    }
    return resposta;
}

int entradaPlayer2(int cartasRestantes) {
    srand (time(NULL));
    int resposta;
    if(cartasRestantes > 3) {
        resposta = rand() % (3);
    } else {
        resposta = rand() % (cartasRestantes);
    }
    return resposta;
}

int entradaAtributoPlayer1(bool atributorEmpatados[]){
    int resposta;
    limparTela();
    cout << "Escolha um atributo:" << endl;
    cout << "0)Vit 1)Int 2)For 3)Vel 4)Hab: ";
    cin >> resposta;
    while ((resposta < 0 || resposta > 4) || atributorEmpatados[resposta] == true){
        limparTela();
        cout << "\033[1;31mResposta invalida ou atributo ja foi usado, tente novamente!\033[m" << endl;
        cout << "Escolha um atributo:" << endl;
        cout << "0)Vit 1)Int 2)For 3)Vel 4)Hab: ";
        cin >> resposta;
    }
    return resposta;
}

int entradaAtributoPlayer2(bool atributorEmpatados[], carta cartaJogador){
    int valoresAtributos[] = {-1,-1,-1,-1,-1};
    if (!atributorEmpatados[0]){
        valoresAtributos[0] = cartaJogador.vitalidade;
    }
    if (!atributorEmpatados[1]){
        valoresAtributos[1] = cartaJogador.inteligencia;
    }
    if (!atributorEmpatados[2]){
        valoresAtributos[2] = cartaJogador.forcaBruta;
    }
    if (!atributorEmpatados[3]){
        valoresAtributos[3] = cartaJogador.velocidade;
    }
    if (!atributorEmpatados[4]){
        valoresAtributos[4] = cartaJogador.habilidade;
    }

    int indiceMaiorAtributo = 0;
    for (int i = 1; i < 5; i++){
        if(valoresAtributos[i] > valoresAtributos[indiceMaiorAtributo]) {
            indiceMaiorAtributo = i;
        }
    }
    return indiceMaiorAtributo;
}
