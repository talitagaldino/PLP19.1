#include <iostream>
#include "dialogos.hpp"
#include "carta.hpp"

using namespace std;

//prototipo de fucoes
bool menu(carta baralhoHerois[],carta baralhoViloes[]);
void visualizarBaralhos(carta baralhoHerois[],carta baralhoViloes[]);
void gameLoop(carta baralhoPlayer1[15], carta baralhoPlayer[15]);

int main()
{
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

void gameLoop(carta baralhoPlayer1[15], carta baralhoPlayer2[15]) {
    for (int i = 0; i < 15; i++){
        embaralhar(baralhoPlayer1, 15 - i);
        embaralhar(baralhoPlayer2, 15 - i);

        carta tublaDeCartasParaEscolherPlayer1[] =  {baralhoPlayer1[14 -i],baralhoPlayer1[13 -i],baralhoPlayer1[12 -i]};
        carta tublaDeCartasParaEscolherPlayer2[] =  {baralhoPlayer2[14 -i],baralhoPlayer2[13 -i],baralhoPlayer2[12 -i]};

        //dialogoEscolherCarta();
        //exibirCartasNaTela(baralhoViloes);
        
    }
    
    
}