/*
 * Menu.cxx
 * 
 * Copyright 2019 MateusMangueira <mateusmangueira@mateusmangueira-All-Series>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <string>

using std::string;
using namespace std;

void menuInicio(){
	cout << "Bem vindo ao jogo Hérois x Vilões!" << '\n';

	cout << "Menu: \n1) Jogar\n2) Visualizar baralhos\n3) Regras\n4) Sair" << '\n';

}

bool ehPar(int i) {
	if(i%2==0) {
		return true;
	} else {
		return false;
	}
}

void jogar() {

}

void mostraRegras() {
	cout << "O jogador e a máquina irão alternar turnos \no jogador puxa aleatoriamente 3 cartas das 15 do seu baralho\nescolhe 1 para colocar em combate\no mesmo serve para a máquina\nas outras 2 nao escolhidas retornam\nEm cada turno escolha o atributo para a batalha\nMarca 1 ponto quem tiver maior atributo\nAs duas cartas que batalharam são removidas do jogo\nQuando acabarem as cartas quem tiver mais ponto vence.\n";
}



void visualizarBaralhos() {
//Definindo o structure Carta e seus atributos.
	struct Carta {
	int ID;
	string nome;
	int vitalidade;
	int inteligencia;
	int forcaBruta;
	int velocidade;
	int habilidade;
	bool especial;
	};

//Conjunto de Cartas Herois e SuperHerois.
	
	Carta homemAranha;
	//Atributos de Homem Aranha
	homemAranha.nome = "Homem Aranha";
	homemAranha.ID = 0;
	homemAranha.vitalidade = 18;
	homemAranha.velocidade = 23;
	homemAranha.inteligencia = 76;
	homemAranha.habilidade = 87;
	homemAranha.forcaBruta = 26;

	Carta homemDeFerro;
	//Atributos de Homem de Ferro
	homemDeFerro.especial = true;
	homemDeFerro.nome = "Homem de Ferro";
	homemDeFerro.ID = 1;
	homemDeFerro.vitalidade = 43;
	homemDeFerro.velocidade = 58;
	homemDeFerro.inteligencia = 10;
	homemDeFerro.habilidade = 25;
	homemDeFerro.forcaBruta = 76;

	Carta thor;
	//Atributos de Thor;
	thor.especial = true;
	thor.nome = "Thor";
	thor.ID = 2;
	thor.vitalidade = 88;
	thor.velocidade = 12;
	thor.inteligencia = 8;
	thor.habilidade = 64;
	thor.forcaBruta = 71;

	Carta capitaoAmerica;
	//Atributos Capitao America;
	capitaoAmerica.nome = "Capitao America";
	capitaoAmerica.ID = 3;
	capitaoAmerica.vitalidade = 47;
	capitaoAmerica.velocidade = 21;
	capitaoAmerica.inteligencia = 33;
	capitaoAmerica.habilidade = 49;
	capitaoAmerica.forcaBruta = 89;

	Carta viuvaNegra;
	//Atributos de Viuva Negra;
	viuvaNegra.nome = "Viuva Negra";
	viuvaNegra.ID = 4;
	viuvaNegra.vitalidade = 73;
	viuvaNegra.velocidade = 24;
	viuvaNegra.inteligencia = 44;
	viuvaNegra.habilidade = 81;
	viuvaNegra.forcaBruta = 26;

	Carta gaviaoArqueiro;
	//Atributos de Gaviao Arqueiro;
	gaviaoArqueiro.nome = "Gaviao Arqueiro";
	gaviaoArqueiro.ID = 5;
	gaviaoArqueiro.vitalidade = 32;
	gaviaoArqueiro.velocidade = 19;
	gaviaoArqueiro.inteligencia = 36;
	gaviaoArqueiro.habilidade = 57;
	gaviaoArqueiro.forcaBruta = 10;

	Carta maquinaDeCombate;
	//Atributos de Maquina de Combate;
	maquinaDeCombate.nome = "Maquina de Combate";
	maquinaDeCombate.ID = 6;
	maquinaDeCombate.vitalidade = 42;
	maquinaDeCombate.velocidade = 51;
	maquinaDeCombate.inteligencia = 30;
	maquinaDeCombate.habilidade = 20;
	maquinaDeCombate.forcaBruta = 68;

	Carta homemFormiga;
	//Atributos de Homem Formiga
	homemFormiga.nome = "Homem Formiga";
	homemFormiga.ID = 7;
	homemFormiga.vitalidade = 35;
	homemFormiga.velocidade = 40;
	homemFormiga.inteligencia = 16;
	homemFormiga.habilidade = 65;
	homemFormiga.forcaBruta = 20;

	Carta capitaMarvel;
	//Atributos da Capita Marvel;
	capitaMarvel.especial = true;
	capitaMarvel.nome = "Capita Marvel";
	capitaMarvel.ID = 8;
	capitaMarvel.vitalidade = 90;
	capitaMarvel.velocidade = 20;
	capitaMarvel.inteligencia = 3;
	capitaMarvel.habilidade = 62;
	capitaMarvel.forcaBruta = 35;

	Carta drEstranho;
	//Atributos de Dr. Estranho
	drEstranho.nome = "Dr. Estranho";
	drEstranho.ID = 9;
	drEstranho.vitalidade = 18;
	drEstranho.velocidade = 11;
	drEstranho.inteligencia = 95;
	drEstranho.habilidade = 75;
	drEstranho.forcaBruta = 5;

	Carta panteraNegra;
	//Atributo de Pantera Negra
	panteraNegra.nome = "Pantera Negra";
	panteraNegra.ID = 10;
	panteraNegra.vitalidade = 45;
	panteraNegra.velocidade = 65;
	panteraNegra.inteligencia = 25;
	panteraNegra.habilidade = 12;
	panteraNegra.forcaBruta = 72;

	Carta hulk;
	//Atributos de Hulk
	hulk.nome = "Hulk";
	hulk.ID = 11;
	hulk.vitalidade = 65;
	hulk.velocidade = 20;
	hulk.inteligencia = 3;
	hulk.habilidade = 14;
	hulk.forcaBruta = 80;

	Carta deadPool;
	//Atributos de Dead Pool
	deadPool.nome = "Dead Pool";
	deadPool.ID = 12;
	deadPool.vitalidade = 43;
	deadPool.velocidade = 16;
	deadPool.inteligencia = 4;
	deadPool.habilidade = 35;
	deadPool.forcaBruta = 20;

	Carta vespa;
	//Atributos de Vespa
	vespa.nome = "Vespa";
	vespa.ID = 13;
	vespa.vitalidade = 15;
	vespa.velocidade = 5;
	vespa.inteligencia = 45;
	vespa.habilidade = 68;
	vespa.forcaBruta = 10;

	Carta mulherMaravilha;
	//Atributos de Mulher Maravilha
	mulherMaravilha.nome = "Mulher Maravilha";
	mulherMaravilha.ID = 14;
	mulherMaravilha.vitalidade = 25;
	mulherMaravilha.velocidade = 18;
	mulherMaravilha.inteligencia = 30;
	mulherMaravilha.habilidade = 50;
	mulherMaravilha.forcaBruta = 45;


//Conjunto de Cartas Viloes e SuperViloes;
	Carta galactus;
	Carta thanos;
	Carta loki;
	Carta magneto;
	Carta apocalipse;
	Carta drDestino;
	Carta ultron;
	Carta mephisto;
	Carta kang;
	Carta reiDoCrime;
	Carta duendeVerde;
	Carta caveiraVermelha;
	Carta venom;
	Carta coringa;
	Carta charada;

	Carta herois[15];
	herois[0] = homemAranha;
	herois[1] = homemDeFerro;
	herois[2] = thor;
	herois[3] = capitaoAmerica;
	herois[4] = viuvaNegra;
	herois[5] = gaviaoArqueiro;
	herois[6] = maquinaDeCombate;
	herois[7] = homemFormiga;
	herois[8] = capitaMarvel;
	herois[9] = drEstranho;
	herois[10] = panteraNegra;
	herois[11] = hulk;
	herois[12] = deadPool;
	herois[13] = vespa;
	herois[14] = mulherMaravilha;

	cout << homemAranha.nome << endl;
	cout << homemAranha.forcaBruta << endl;
	cout << homemAranha.habilidade << endl;
}


int main(int argc, char **argv) {

	int turno;


	menuInicio();

	int opcao;
	cout << "Digite aqui sua opcao: ";
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
	
	
		
		
	


