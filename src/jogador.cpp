#include <iostream>
#include <string>
#include <conio.h>
#include "jogador.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

/**
 * @brief Construtor vazio para jogador
 *
 */
Jogador::Jogador() {}

/**
 * @brief Construtor para um novo jogador fornecendo seu nome e papel.
 *
 * @param nome
 * @param Papel
 */
Jogador::Jogador(string nome, string Papel)
{
	this->nome = nome;
	this->Papel = Papel;
}

/**
 * @brief Mostra o nome do jogador e o papel destinado a ele.
 *
 */
void Jogador::mostrarPapelJogador()
{
	cout << "Jogador: " << nome << endl;
	cout << "Pressione qualquer tecla para revelar seu papel." << endl;
	getch();
	cout << "Seu papel eh: " << Papel << endl;
	cout << "Pressione qualquer tecla para continuar" << endl;
	getch();
	system("cls");
}

/**
 * @brief Função utilizada em todas as rodadas como sistema de escolha e votação. Durante o dia é utilizada para a votação geral.
 *        Durante a noite é utilizada para que os jogadores realizem as ações relacionadas a seu papel.
 *
 * @return int
 */
int Jogador::votar()
{
	int key;
	cin >> key;
	while ((cin.fail()) || (key <= 0)) // Filtra inputs invalidos para votação
	{
		cin.clear();				  // Limpa o buffer do input para restaurar o cin para um estádo uilizável
		cin.ignore(2147483647, '\n'); // Ignora o último input
		cout << "Input invalido. Vote entre as opcoes apresentadas na lista, escrevendo o numero ao lado do nome do jogador escolhido." << endl;
		cout << "Realize sua escolha novamente. ";
		cin >> key;
	}
	return key;
}

/**
 * @brief Getter para o nome do jogador
 *
 * @return string
 */
string Jogador::getNome()
{
	return nome;
}

/**
 * @brief Getter para o papel do jogador
 *
 * @return string
 */
string Jogador::getPapel()
{
	return Papel;
}
