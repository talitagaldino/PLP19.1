

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <random>

using namespace std;

//Definindo o structure Carta e seus atributos.
struct Carta
{
	int ID;
	string nome;
	int vitalidade;
	int inteligencia;
	int forcaBruta;
	int velocidade;
	int habilidade;
	bool especial = false;
};

Carta herois[15];
Carta viloes[15];

void menuInicio()
{
	cout << "Bem vindo ao jogo Hérois x Vilões!";
	cout << "Menu: \n1) Jogar\n2) Visualizar baralhos\n3) Regras\n4) Sair" << '\n';
}

void mostraRegras()
{
	cout << "\nAs regras do jogo sao as seguintes: \nO jogador e a máquina irão alternar turnos \nO jogador puxa aleatoriamente 3 cartas das 15 do seu baralho\nEscolhe 1 para colocar em combate\nO mesmo serve para a máquina\nAs outras 2 nao escolhidas retornam ao deck\nEm cada turno escolhe um atributo para a batalha\nMarca 1 ponto quem tiver maior atributo\nAs duas cartas que batalharam são removidas do jogo\nQuando acabarem as cartas quem tiver mais ponto vence o jogo.\n";
}

void iniciaBaralhos()
{
	//Conjunto de Cartas Herois e SuperHerois.

	Carta homemAranha;
	//Atributos de Homem Aranha
	homemAranha.nome = "Homem Aranha";
	homemAranha.ID = 0;
	homemAranha.vitalidade = 31;
	homemAranha.velocidade = 38;
	homemAranha.inteligencia = 71;
	homemAranha.habilidade = 82;
	homemAranha.forcaBruta = 45;

	Carta homemDeFerro;
	//Atributos de Homem de Ferro
	homemDeFerro.especial = true;
	homemDeFerro.nome = "Homem de Ferro";
	homemDeFerro.ID = 1;
	homemDeFerro.vitalidade = 48;
	homemDeFerro.velocidade = 52;
	homemDeFerro.inteligencia = 71;
	homemDeFerro.habilidade = 49;
	homemDeFerro.forcaBruta = 54;

	Carta thor;
	//Atributos de Thor;
	thor.especial = true;
	thor.nome = "Thor";
	thor.ID = 2;
	thor.vitalidade = 71;
	thor.velocidade = 38;
	thor.inteligencia = 18;
	thor.habilidade = 68;
	thor.forcaBruta = 83;

	Carta capitaoAmerica;
	//Atributos Capitao America;
	capitaoAmerica.nome = "Capitao America";
	capitaoAmerica.ID = 3;
	capitaoAmerica.vitalidade = 48;
	capitaoAmerica.velocidade = 21;
	capitaoAmerica.inteligencia = 38;
	capitaoAmerica.habilidade = 45;
	capitaoAmerica.forcaBruta = 89;

	Carta viuvaNegra;
	//Atributos de Viuva Negra;
	viuvaNegra.nome = "Viuva Negra";
	viuvaNegra.ID = 4;
	viuvaNegra.vitalidade = 58;
	viuvaNegra.velocidade = 27;
	viuvaNegra.inteligencia = 41;
	viuvaNegra.habilidade = 42;
	viuvaNegra.forcaBruta = 78;

	Carta wolverine;
	//Atributos do Wolverine;
	wolverine.nome = "Wolverine";
	wolverine.ID = 5;
	wolverine.vitalidade = 61;
	wolverine.velocidade = 28;
	wolverine.inteligencia = 25;
	wolverine.habilidade = 19;
	wolverine.forcaBruta = 83;

	Carta maquinaDeCombate;
	//Atributos de Maquina de Combate;
	maquinaDeCombate.nome = "Maquina de Combate";
	maquinaDeCombate.ID = 6;
	maquinaDeCombate.vitalidade = 62;
	maquinaDeCombate.velocidade = 55;
	maquinaDeCombate.inteligencia = 32;
	maquinaDeCombate.habilidade = 65;
	maquinaDeCombate.forcaBruta = 61;

	Carta homemFormiga;
	//Atributos de Homem Formiga
	homemFormiga.nome = "Homem Formiga";
	homemFormiga.ID = 7;
	homemFormiga.vitalidade = 35;
	homemFormiga.velocidade = 40;
	homemFormiga.inteligencia = 48;
	homemFormiga.habilidade = 68;
	homemFormiga.forcaBruta = 37;

	Carta capitaMarvel;
	//Atributos da Capita Marvel;
	capitaMarvel.especial = true;
	capitaMarvel.nome = "Capita Marvel";
	capitaMarvel.ID = 8;
	capitaMarvel.vitalidade = 87;
	capitaMarvel.velocidade = 48;
	capitaMarvel.inteligencia = 28;
	capitaMarvel.habilidade = 62;
	capitaMarvel.forcaBruta = 44;

	Carta drEstranho;
	//Atributos de Dr. Estranho
	drEstranho.nome = "Dr. Estranho";
	drEstranho.ID = 9;
	drEstranho.vitalidade = 18;
	drEstranho.velocidade = 33;
	drEstranho.inteligencia = 86;
	drEstranho.habilidade = 81;
	drEstranho.forcaBruta = 12;

	Carta panteraNegra;
	//Atributo de Pantera Negra
	panteraNegra.nome = "Pantera Negra";
	panteraNegra.ID = 10;
	panteraNegra.vitalidade = 42;
	panteraNegra.velocidade = 65;
	panteraNegra.inteligencia = 40;
	panteraNegra.habilidade = 21;
	panteraNegra.forcaBruta = 74;

	Carta hulk;
	//Atributos de Hulk
	hulk.nome = "Hulk";
	hulk.ID = 11;
	hulk.vitalidade = 78;
	hulk.velocidade = 20;
	hulk.inteligencia = 3;
	hulk.habilidade = 14;
	hulk.forcaBruta = 90;

	Carta ciclope;
	//Atributos de Ciclope
	ciclope.nome = "Ciclope";
	ciclope.ID = 12;
	ciclope.vitalidade = 29;
	ciclope.velocidade = 24;
	ciclope.inteligencia = 42;
	ciclope.habilidade = 73;
	ciclope.forcaBruta = 39;

	Carta mulherInvisivel;
	//Atributos de Mulher Invisivel
	mulherInvisivel.nome = "Mulher Invisivel";
	mulherInvisivel.ID = 13;
	mulherInvisivel.vitalidade = 72;
	mulherInvisivel.velocidade = 34;
	mulherInvisivel.inteligencia = 38;
	mulherInvisivel.habilidade = 65;
	mulherInvisivel.forcaBruta = 21;

	Carta mulherMaravilha;
	//Atributos de Mulher Maravilha
	mulherMaravilha.nome = "Mulher Maravilha";
	mulherMaravilha.ID = 14;
	mulherMaravilha.vitalidade = 58;
	mulherMaravilha.velocidade = 51;
	mulherMaravilha.inteligencia = 30;
	mulherMaravilha.habilidade = 48;
	mulherMaravilha.forcaBruta = 76;

	//Conjunto de Cartas Viloes e SuperViloes;
	Carta galactus;
	//Atributos do Galactus
	galactus.nome = "Galactus";
	galactus.ID = 0;
	galactus.vitalidade = 83;
	galactus.velocidade = 61;
	galactus.inteligencia = 75;
	galactus.habilidade = 82;
	galactus.forcaBruta = 23;
	galactus.especial = true;

	Carta thanos; //EH SUPER VILAO, TEM Q DEFINIR ATRIBUTO especial = true;
	// Atributos do Thanos
	thanos.nome = "Thanos";
	thanos.ID = 1;
	thanos.vitalidade = 71;
	thanos.velocidade = 39;
	thanos.inteligencia = 74;
	thanos.habilidade = 86;
	thanos.forcaBruta = 49;
	thanos.especial = true;

	Carta loki;
	// Atributos do Loki
	loki.nome = "Loki";
	loki.ID = 2;
	loki.vitalidade = 58;
	loki.velocidade = 53;
	loki.inteligencia = 68;
	loki.habilidade = 57;
	loki.forcaBruta = 41;

	Carta magneto;
	// Atributos do Magneto
	magneto.nome = "Magneto";
	magneto.ID = 3;
	magneto.vitalidade = 26;
	magneto.velocidade = 54;
	magneto.inteligencia = 61;
	magneto.habilidade = 77;
	magneto.forcaBruta = 39;

	Carta apocalipse;
	// Atributos do Apocalipse
	apocalipse.nome = "Apocalipse";
	apocalipse.ID = 4;
	apocalipse.vitalidade = 71;
	apocalipse.velocidade = 51;
	apocalipse.inteligencia = 64;
	apocalipse.habilidade = 39;
	apocalipse.forcaBruta = 86;
	apocalipse.especial = true;

	Carta drDestino;
	// Atributos do Dr. Destino
	drDestino.nome = "Doutor Destino";
	drDestino.ID = 5;
	drDestino.vitalidade = 65;
	drDestino.velocidade = 43;
	drDestino.inteligencia = 74;
	drDestino.habilidade = 80;
	drDestino.forcaBruta = 41;

	Carta ultron;
	// Atributos do Ultron
	ultron.nome = "Ultron";
	ultron.ID = 6;
	ultron.vitalidade = 87;
	ultron.velocidade = 35;
	ultron.inteligencia = 46;
	ultron.habilidade = 71;
	ultron.forcaBruta = 63;

	Carta drOctopus;
	// Atributos do Dr Octopus
	drOctopus.nome = "Doutor Octopus";
	drOctopus.ID = 7;
	drOctopus.vitalidade = 34;
	drOctopus.velocidade = 36;
	drOctopus.inteligencia = 62;
	drOctopus.habilidade = 21;
	drOctopus.forcaBruta = 55;

	Carta kang;
	// Atributos do Kang
	kang.nome = "Kang";
	kang.ID = 8;
	kang.vitalidade = 46;
	kang.velocidade = 78;
	kang.inteligencia = 48;
	kang.habilidade = 71;
	kang.forcaBruta = 41;

	Carta reiDoCrime;
	// Atributos do Rei do Crime
	reiDoCrime.nome = "Rei do Crime";
	reiDoCrime.ID = 9;
	reiDoCrime.vitalidade = 23;
	reiDoCrime.velocidade = 21;
	reiDoCrime.inteligencia = 46;
	reiDoCrime.habilidade = 12;
	reiDoCrime.forcaBruta = 66;

	Carta duendeVerde;
	// Atributos do Doende Verde
	duendeVerde.nome = "Duende Verde";
	duendeVerde.ID = 10;
	duendeVerde.vitalidade = 47;
	duendeVerde.velocidade = 55;
	duendeVerde.inteligencia = 58;
	duendeVerde.habilidade = 41;
	duendeVerde.forcaBruta = 32;

	Carta caveiraVermelha;
	// Atributos do Caveira Vermelha;
	caveiraVermelha.nome = "Caveira Vermelha";
	caveiraVermelha.ID = 11;
	caveiraVermelha.vitalidade = 31;
	caveiraVermelha.velocidade = 34;
	caveiraVermelha.inteligencia = 58;
	caveiraVermelha.habilidade = 11;
	caveiraVermelha.forcaBruta = 66;

	Carta venom;
	// Atributos do Venom
	venom.nome = "Venom";
	venom.ID = 12;
	venom.vitalidade = 72;
	venom.velocidade = 28;
	venom.inteligencia = 37;
	venom.habilidade = 19;
	venom.forcaBruta = 55;

	Carta coringa;
	// Atributos do Coringa
	coringa.nome = "Coringa";
	coringa.ID = 13;
	coringa.vitalidade = 31;
	coringa.velocidade = 20;
	coringa.inteligencia = 78;
	coringa.habilidade = 37;
	coringa.forcaBruta = 24;

	Carta mistica;
	// Atributos da Mística
	mistica.nome = "Mistica";
	mistica.ID = 14;
	mistica.vitalidade = 51;
	mistica.velocidade = 27;
	mistica.inteligencia = 57;
	mistica.habilidade = 61;
	mistica.forcaBruta = 38;

	//Array de Cartas de Herois.
	herois[0] = homemAranha;
	herois[1] = homemDeFerro;
	herois[2] = thor;
	herois[3] = capitaoAmerica;
	herois[4] = viuvaNegra;
	herois[5] = wolverine;
	herois[6] = maquinaDeCombate;
	herois[7] = homemFormiga;
	herois[8] = capitaMarvel;
	herois[9] = drEstranho;
	herois[10] = panteraNegra;
	herois[11] = hulk;
	herois[12] = ciclope;
	herois[13] = mulherInvisivel;
	herois[14] = mulherMaravilha;

	viloes[0] = galactus;
	viloes[1] = thanos;
	viloes[2] = loki;
	viloes[3] = magneto;
	viloes[4] = apocalipse;
	viloes[5] = drDestino;
	viloes[6] = ultron;
	viloes[7] = drOctopus;
	viloes[8] = kang;
	viloes[9] = reiDoCrime;
	viloes[10] = duendeVerde;
	viloes[11] = caveiraVermelha;
	viloes[12] = venom;
	viloes[13] = coringa;
	viloes[14] = mistica;
}

void visualizarBaralhos()
{
	int opcao;
	cout << "\nDeseja visualizar qual baralho:\n";
	cout << "\n1)Baralho de Herois\n2)Baralho de Viloes\n";
	cout << "\nDigite sua opcao: ";
	cin >> opcao;
	switch (opcao)
	{
	case 1:
		cout << "\nHEROIS";
		for (int i = 0; i < 15; i++)
		{
			if (herois[i].especial)
			{
				cout << "\nSUPER-HEROI";
			}
			cout << endl << herois[i].nome << endl;
			cout << herois[i].vitalidade << endl;
			cout << herois[i].inteligencia << endl;
			cout << herois[i].forcaBruta << endl;
			cout << herois[i].velocidade << endl;
			cout << herois[i].habilidade << endl;
		}
		break;
	case 2:
		cout << "\nVILOES\n";
		for (int i = 0; i < 15; i++)
		{
			if (viloes[i].especial)
			{
				cout << "\nSUPER-VILAO";
			}
			cout << endl << viloes[i].nome << endl;
			cout << viloes[i].vitalidade << endl;
			cout << viloes[i].inteligencia << endl;
			cout << viloes[i].forcaBruta << endl;
			cout << viloes[i].velocidade << endl;
			cout << viloes[i].habilidade << endl;
		}
	
	
	default:
		cout << "Opcao invalida.";
		break;
	}	
}

bool ehPar(int i)
{
	if (i % 2 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//metodo para embaralhar o deck,testar!
void embaralhaDeck(Carta deck[])
{
	for (int i = 0; i < 15; i++)
	{
		int random = rand() % 15;

		Carta temp = deck[i];
		deck[i] = deck[random];
		deck[random] = temp;
	}
}

void escolherBaralho()
{
	int opcao;
	cout << "\nDigite qual baralho que jogar: \n1- Herois\n2- Viloes\n";
	cin >> opcao;

	if (opcao == 1)
	{
		embaralhaDeck(herois);
	}
	else
	{
		embaralhaDeck(viloes);
	}
}
void jogar()
{
	escolherBaralho();
	//...continuar algoritmo de jogar.
}

int main(int argc, char **argv)
{
	iniciaBaralhos();
	menuInicio();

	int opcao;
	cout << "\nDigite aqui sua opcao: ";
	cin >> opcao;
	switch (opcao)
	{
	case 1:
		jogar();
		break;
	case 2:
		visualizarBaralhos();
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

	return 0;
}
