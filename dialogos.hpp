#include <iostream>

using namespace std;

void limparTela(){
    #ifdef __unix__
        system("clear");
    #endif
}

void exibirMenu(){
    string teste;
    cout << "+---+---------------------+" << endl;
    cout << "|   |       Menu          |" << endl;
    cout << "+---+---------------------+" << endl;
    cout << "| 1 | Jogar               |" << endl;
    cout << "| 2 | Visualizar baralhos |" << endl;
    cout << "| 3 | Regras              |" << endl;
    cout << "| 4 | Sair                |" << endl;
    cout << "+---+---------------------+" << endl;
}

void exibirTelaInicialMenu() {
    limparTela();
    cout << " _                    _                    _ _                 " << endl;
    cout << "| |                  (_)                  (_) |                " << endl;
    cout << "| |__   ___ _ __ ___  _ ___    ___  __   ___| | ___   ___  ___ " << endl;
    cout << "| '_ \\ / _ \\ '__/ _ \\| / __|  / _ \\ \\ \\ / / | |/ _ \\ / _ \\/ __|" << endl;
    cout << "| | | |  __/ | | (_) | \\__ \\ |  __/  \\ V /| | | (_) |  __/\\__ \\" << endl;
    cout << "|_| |_|\\___|_|  \\___/|_|___/  \\___|   \\_/ |_|_|\\___/ \\___||___/" << endl;
    cout << "===============================================================" << endl;
    exibirMenu();
}

void exibirBaralhoMenu() {
    limparTela();
    cout << "Deseja visualizar qual baralho:" << endl;
	cout << "\n1)Baralho de Herois\n2)Baralho de Viloes" << endl;
}

void dialogoJogar() {
    limparTela();
    cout << "+---+---------------------------------+" << endl;
    cout << "|   | Deseja jogar de heroi ou vilao? |" << endl;
    cout << "+---+---------------------------------+" << endl;
    cout << "| 1 | heroi                           |" << endl;
    cout << "| 2 | vilao                           |" << endl;
    cout << "+---+---------------------------------+" << endl;
}

void mostraRegras() {
    limparTela();
    cout <<"\nAs regras do jogo sao as seguintes:" << endl;
    cout <<"->O jogador e a máquina irão alternar turnos " << endl;
    cout <<"->O jogador puxa aleatoriamente 3 cartas das 15 do seu baralho" << endl;
    cout <<"->Escolhe 1 para colocar em combate" << endl;
    cout <<"->O mesmo serve para a máquina" << endl;
    cout <<"->As outras 2 nao escolhidas retornam ao deck" << endl;
    cout <<"->Em cada turno escolhe um atributo para a batalha" << endl;
    cout <<"->Marca 1 ponto quem tiver maior atributo" << endl;
    cout <<"->As duas cartas que batalharam são removidas do jogo" << endl;
    cout <<"->Quando acabarem as cartas quem tiver mais ponto vence o jogo." << endl;
    exibirMenu();
}