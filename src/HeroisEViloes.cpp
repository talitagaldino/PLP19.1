#include <iostream>
#include "dialogos.hpp"
#include "carta.hpp"
#include "jogador.hpp"

using namespace std;

//prototipo de fucoes
bool menu(carta baralhoHerois[],carta baralhoViloes[]);
void visualizarBaralhos(carta baralhoHerois[],carta baralhoViloes[]);
void gameLoop(carta baralhoPlayer1[], carta baralhoPlayer[], int sizeBaralhos);

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
                cout << "\nDigite aqui sua opcao: ";
                cin >> preferenciaDeBaralho;
                switch (preferenciaDeBaralho) {
                case 1:
                    gameLoop(baralhoHerois, baralhoViloes, 15);
                    break;
                case 2:
                    gameLoop(baralhoViloes, baralhoHerois, 15);
                    break;
                
                default:
                dialogoJogar();
                cout << "\nOpcao invalida! tente novamente!";
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
                exibirMenu();
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

void gameLoop(carta baralhoPlayer1[], carta baralhoPlayer2[], int sizeBaralhos) {
    int pontosPlayer1 = 0;
    int pontosPlayer2 = 0;
    bool vezPlayer1 = true;
    for (int i = 0; i < sizeBaralhos; i++){
        embaralhar(baralhoPlayer1, sizeBaralhos - i);
        embaralhar(baralhoPlayer2, sizeBaralhos - i);

        carta tuplaDeCartasParaEscolherPlayer1[3];
        carta tuplaDeCartasParaEscolherPlayer2[3];
        tuplaDeCartasParaEscolherPlayer1[0] = baralhoPlayer1[sizeBaralhos -1 -i];
        tuplaDeCartasParaEscolherPlayer2[0] = baralhoPlayer2[sizeBaralhos -1 -i];
        if ((15 -i) > 1){
            tuplaDeCartasParaEscolherPlayer1[1] = baralhoPlayer1[sizeBaralhos -2 -i];
            tuplaDeCartasParaEscolherPlayer2[1] = baralhoPlayer2[sizeBaralhos -2 -i];
        }
        if ((15 -i) > 2) {
            tuplaDeCartasParaEscolherPlayer1[2] = baralhoPlayer1[sizeBaralhos -3 -i];
            tuplaDeCartasParaEscolherPlayer2[2] = baralhoPlayer2[sizeBaralhos -3 -i];
        }

        int escolharPlayer1 = entradaPlayer1(tuplaDeCartasParaEscolherPlayer1,(15 -i),pontosPlayer1,pontosPlayer2);
        int escolharPlayer2 = entradaPlayer2(15 -i);
        
        bool atributorEmpatados[] = {false,false,false,false,false};
        int contadorEmpate = 5;
        int valorAtributoPlayer1 = 0;
        int valorAtributoPlayer2 = 0;
        do {
            if (vezPlayer1){
                int atributoPlayer1 = entradaAtributoPlayer1(atributorEmpatados);
                atributorEmpatados[atributoPlayer1] = true;
                valorAtributoPlayer1 = getValorAtributo(tuplaDeCartasParaEscolherPlayer1[escolharPlayer1], atributoPlayer1);
                valorAtributoPlayer2 = getValorAtributo(tuplaDeCartasParaEscolherPlayer2[escolharPlayer2], atributoPlayer1);
            } else {
                int atributoPlayer2 = entradaAtributoPlayer2(atributorEmpatados, tuplaDeCartasParaEscolherPlayer2[escolharPlayer2]);
                atributorEmpatados[atributoPlayer2] = true;
                valorAtributoPlayer1 = getValorAtributo(tuplaDeCartasParaEscolherPlayer1[escolharPlayer1], atributoPlayer2);
                valorAtributoPlayer2 = getValorAtributo(tuplaDeCartasParaEscolherPlayer2[escolharPlayer2], atributoPlayer2);
            }

            if(valorAtributoPlayer1 != valorAtributoPlayer2){
                if (valorAtributoPlayer1 > valorAtributoPlayer2) {
                    pontosPlayer1 ++;
                } else {
                    pontosPlayer2 ++;
                }
            }
            contadorEmpate --;
            if(contadorEmpate <= 0){
                break;
            }
        } while (valorAtributoPlayer1 == valorAtributoPlayer2);
        baralhoPlayer1[(15 -i) - (1 + escolharPlayer1)] = baralhoPlayer1[(15 -i -1)];
        baralhoPlayer2[(15 -i) - (1 + escolharPlayer1)] = baralhoPlayer2[(15 -i -1)];
    }
    if (pontosPlayer1 > pontosPlayer2) {
        limparTela();
        cout << "Jogador 1 venceu, digite 1 para voltar ao menu.";
        string pausarExeculcao;
        cin >> pausarExeculcao;
    } else if (pontosPlayer2 > pontosPlayer1) {
        limparTela();
        cout << "Jogador 2(Maquina) venceu, digite 1 para voltar ao menu.";
        string pausarExeculcao;
        cin >> pausarExeculcao;
    } else {
        limparTela();
        cout << "Deu empate, digite 1 para voltar ao menu.";
        string pausarExeculcao;
        cin >> pausarExeculcao;
    }
}