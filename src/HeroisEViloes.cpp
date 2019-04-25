#include <iostream>
#include "dialogos.hpp"
#include "carta.hpp"

using namespace std;

//prototipo de fucoes
bool menu(carta baralhoHerois[],carta baralhoViloes[]);
void visualizarBaralhos(carta baralhoHerois[],carta baralhoViloes[]);
void gameLoop(carta baralhoPlayer1[15], carta baralhoPlayer[15]);

int main() {
    carta baralhoHerois[15];
    carta baralhoViloes[15];

    iniciarBaralhoHerois(baralhoHerois);
    iniciarBaralhoVilao(baralhoViloes);

    bool iniciarJogo = true;

    while (iniciarJogo) {
        iniciarJogo = menu(baralhoHerois,baralhoViloes);
        if (iniciarJogo){
            int preferenciaDeBaralho;
            dialogoJogar();
            do {
                do {
                cout << "/nDigite aqui sua opcao: ";
                cin >> preferenciaDeBaralho;
                switch (preferenciaDeBaralho) {
                case 1:
                    gameLoop(baralhoHerois, baralhoViloes);
                    break;
                case 2:
                    gameLoop(baralhoViloes, baralhoHerois);
                    break;
                
                default:
                dialogoJogar();
                cout << "/nOpcao invalida! tente novamente!";
                    break;
                }

                } while (preferenciaDeBaralho != 1 && preferenciaDeBaralho != 2);
                iniciarJogo = menu(baralhoHerois,baralhoViloes);
            } while (iniciarJogo);
        }
    }
    return 0;
}

bool menu(carta baralhoHerois[],carta baralhoViloes[]) {
    exibirTelaInicialMenu();
    bool resposta = false;
    int entradaUsuario;
    do{
        cout << "Digite aqui sua opcao: ";
        cin >> entradaUsuario;
        switch (entradaUsuario){
            case 1:
                resposta = true;
                break;
            case 2:
                visualizarBaralhos(baralhoHerois, baralhoViloes);
                break;
            case 3:
                mostraRegras();
                break;
            case 4:
                break;
            default:
                cout << "Opcao invalida!";
                break;
        }
    } while (entradaUsuario != 1 && entradaUsuario != 4);
    
    return resposta;
}

void visualizarBaralhos(carta baralhoHerois[],carta baralhoViloes[]) {
    exibirBaralhoMenu();
    cout << "\nDigite sua opcao: ";
    int entradaUsuario;
    cin >> entradaUsuario;
    do{
        switch (entradaUsuario)
        {
        case 1:
            exibirCartasNaTela(baralhoHerois,15);
            break;
            
        case 2:
            exibirCartasNaTela(baralhoViloes,15);
            break;
        
        default:
            exibirBaralhoMenu();
            cout << "\nEntrada invalida! Tente novamente\nDigite sua opcao: ";
            cin >> entradaUsuario;
            break;
        }
    } while (entradaUsuario != 1 && entradaUsuario != 2);
    exibirMenu();
}

void gameLoop(carta baralhoPlayer1[], carta baralhoPlayer2[]) {
    int pontosPlayer1 = 0;
    int pontosPlayer2 = 0;
    int sizeBaralhos = sizeof(baralhoPlayer1);
    for (int i = 0; i < sizeBaralhos; i++){
        embaralhar(baralhoPlayer1, sizeBaralhos - i);
        embaralhar(baralhoPlayer2, sizeBaralhos - i);

        carta tublaDeCartasParaEscolherPlayer1[] = 
        {baralhoPlayer1[sizeBaralhos -1 -i],baralhoPlayer1[sizeBaralhos -2 -i],baralhoPlayer1[sizeBaralhos -3 -i]};
        carta tublaDeCartasParaEscolherPlayer2[] = 
        {baralhoPlayer2[sizeBaralhos -1 -i],baralhoPlayer2[sizeBaralhos -2 -i],baralhoPlayer2[sizeBaralhos -3 -i]};

        //dialogoEscolherCarta();
        int escolharPlayer1 = entradaPlayer1();
        int escolharPlayer2 = entradaPlayer2();
        
        bool atributorEmpatados[] = {false,false,false,false,false};
        int contadorEmpate = 5;
        do {
            //dialogo atributo()
            int atributoPlayer1 = entradaAtributoPlayer1();
            int atributoPlayer2 = entradaAtributoPlayer2();

            int valorAtributoPlayer1 = getValorAtributo(tublaDeCartasParaEscolherPlayer1[escolharPlayer1], atributoPlayer1);
            int valorAtributoPlayer2 = getValorAtributo(tublaDeCartasParaEscolherPlayer2[escolharPlayer2], atributoPlayer2);

            if(valorAtributoPlayer1 != valorAtributoPlayer2){
                if (valorAtributoPlayer1 > valorAtributoPlayer2) {
                    pontosPlayer1 ++;
                } else {
                    pontosPlayer1 --;
                }
            }
            contadorEmpate --;
            if(contadorEmpate <= 0){
                break;
            }
        } while (valorAtributoPlayer1 == valorAtributoPlayer2);  
    }
    if (pontosPlayer1 > pontosPlayer1) {
        //dialogo win
    } else if (pontosPlayer1 < pontosPlayer1) {
        //dialogo win
    } else {
        //dialogin win
    }
}