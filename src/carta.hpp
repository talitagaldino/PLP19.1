#include <iostream>

using namespace std;

struct carta{
	string nome;
    int ID;
	int vitalidade;
	int inteligencia;
	int forcaBruta;
	int velocidade;
	int habilidade;
	bool especial = false;
};

carta criarCarta(string nome,int ID,int vitalidade,int inteligencia, int forcaBruta, int velocidade, int habilidade,bool especial = false) {
    carta novaCarta;
    novaCarta.nome = nome;
    novaCarta.ID = ID;
	novaCarta.vitalidade = vitalidade;
	novaCarta.inteligencia = inteligencia;
	novaCarta.forcaBruta = forcaBruta;
	novaCarta.velocidade = velocidade;
	novaCarta.habilidade = habilidade;
    if (especial) {
	    novaCarta.especial = false;
    }
    return novaCarta;
}

void iniciarBaralhoHerois(carta baralhoHerois[15]) {
    baralhoHerois[0] = criarCarta("Homem Aranha", 0, 31, 71, 45, 38, 82, false);
    baralhoHerois[1] = criarCarta("Homem de Ferro", 1, 48, 71, 54, 52, 49, true);
    baralhoHerois[2] = criarCarta("Thor", 2, 71, 18, 83, 38, 68, true);
    baralhoHerois[3] = criarCarta("Capitao America", 3, 48, 38, 89, 21, 45, false);
    baralhoHerois[4] = criarCarta("Viuva Negra", 4, 58, 41, 78, 27, 42, false);
    baralhoHerois[5] = criarCarta("Wolverine", 5, 61, 25, 83, 28, 19, false);
    baralhoHerois[6] = criarCarta("Maquina de Combate", 6, 62, 32, 61, 55, 65, false);
    baralhoHerois[7] = criarCarta("Homem Formiga", 7, 35, 48, 37, 40, 68, false);
    baralhoHerois[8] = criarCarta("Capita Marvel", 8, 87, 28, 44, 48, 62, true);
    baralhoHerois[9] = criarCarta("Dr. Estranho", 9, 18, 86, 12, 33, 81, false);
    baralhoHerois[10] = criarCarta("Pantera Negra", 10, 42, 40, 74, 65, 21, false);
    baralhoHerois[11] = criarCarta("Hulk", 11, 78, 3, 90, 20, 14, false);
    baralhoHerois[12] = criarCarta("Ciclope", 12, 29, 42, 39, 24, 73, false);
    baralhoHerois[13] = criarCarta("Mulher Invisivel", 13, 72, 38, 21, 34, 65, false);
    baralhoHerois[14] = criarCarta("Mulher Maravilha", 14, 58, 30, 76, 51, 48, false);
}

void iniciarBaralhoVilao(carta baralhoViloes[15]) {
baralhoViloes[0] = criarCarta("Galactus", 0, 83, 75, 23, 61, 82, true);
baralhoViloes[1] = criarCarta("Thanos", 1, 71, 74, 49, 39, 86, true);
baralhoViloes[2] = criarCarta("Loki", 2, 58, 68, 41, 53, 57, false);
baralhoViloes[3] = criarCarta("Magneto", 3, 26, 61, 39, 54, 77, false);
baralhoViloes[4] = criarCarta("Apocalipse", 4, 71, 64, 86, 51, 39, true);
baralhoViloes[5] = criarCarta("Doutor Destino", 5, 65, 74, 41, 43, 80, false);
baralhoViloes[6] = criarCarta("Ultron", 6, 87, 46, 63, 35, 71, false);
baralhoViloes[7] = criarCarta("Doutor Octopus", 7, 34, 62, 55, 36, 21, false);
baralhoViloes[8] = criarCarta("Kang", 8, 46, 48, 41, 78, 71, false);
baralhoViloes[9] = criarCarta("Rei do Crime", 9, 23, 46, 66, 21, 12, false);
baralhoViloes[10] = criarCarta("Duende Verde", 10, 47, 58, 32, 55, 41, false);
baralhoViloes[11] = criarCarta("Caveira Vermelha", 11, 31, 58, 66, 34, 11, false);
baralhoViloes[12] = criarCarta("Venom", 12, 72, 37, 55, 28, 19, false);
baralhoViloes[13] = criarCarta("Coringa", 13, 31, 78, 24, 20, 37, false);
baralhoViloes[14] = criarCarta("Mistica", 14, 51, 57, 38, 27, 61, false);
}

void embaralhar(carta baralho[], int limite) {
    srand (time(NULL));
    for (int i = 0; i < limite; i++){
        int novaPosicao =  rand() % (limite);
        carta aux  = baralho[i];
        baralho[i] = baralho[novaPosicao];
        baralho[novaPosicao] = aux;
    }
    
}

void exibirCartasNaTela(carta baralho[],int tamanho) {
    limparTela();
    for (int i = 0; i < tamanho ; i++){
        if (baralho[i].especial){
				cout << "\nSUPER-HEROI";
			}
			cout << endl << baralho[i].nome << endl;
			cout << "Vitalidade: " << baralho[i].vitalidade << endl;
			cout << "Inteligencia: " << baralho[i].inteligencia << endl;
			cout << "Forca Bruta: " << baralho[i].forcaBruta << endl;
			cout << "Velocidade: " << baralho[i].velocidade << endl;
			cout << "Habilidade: " << baralho[i].habilidade << endl;
    }
    
}

int getValorAtributo(carta cartaJodagor, int atributo){
    int resposta;
    switch (atributo){
        case 0:
            resposta = cartaJodagor.vitalidade;
            break;

        case 1:
            resposta = cartaJodagor.inteligencia;
            break;
        
        case 2:
            resposta = cartaJodagor.forcaBruta;
            break;
        
        case 3:
            resposta = cartaJodagor.velocidade;
            break;
        case 4:
            resposta = cartaJodagor.habilidade;
            break;

        default:
            resposta = 0;
            break;
    }
    return resposta;
}