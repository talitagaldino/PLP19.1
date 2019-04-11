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

void menuInicio(){
	std::cout << "Bem vindo ao jogo Hérois x Vilões!" << '\n';

	std::cout << "Menu: \n1) Jogar\n2) Visualizar baralhos\n3) Regras\n4) Sair" << '\n';

}

void jogar() {
	//logica do jogo...
}

void visualizarBaralhos() {
	std::cout << "falta implementar\n";

}

void mostraRegras() {
	std::cout << "implementacao...\n";
}

int main(int argc, char **argv) {

	menuInicio();

	int opcao;
	std::cout << "Digite aqui sua opcao: ";
	std::cin >> opcao;
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
		std::cout << "Opcao invalida!" << '\n';
		break;
	}

	return 0;

}
	
	
		
		
	


