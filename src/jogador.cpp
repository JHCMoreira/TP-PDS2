#include <iostream>
#include <string>
#include <conio.h>
#include "jogador.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Jogador::Jogador() {}

Jogador::Jogador(string nome, string Papel)
{
	this->nome = nome;
	this->Papel = Papel;
}

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

int Jogador::votar()
{
	int key;
	cin >> key;
	while ((cin.fail()) || (key <= 0))
	{
		cin.clear();			   // clear input buffer to restore cin to a usable state
		cin.ignore(2147483647, '\n'); // ignore last input
		cout << "Input invalido. Vote entre as opcoes apresentadas na lista, escrevendo o numero ao lado do nome do jogador escolhido." << endl;
		cout << "Realize sua escolha novamente. ";
		cin >> key;
	}
	return key;
}

string Jogador::getNome()
{
	return nome;
}
string Jogador::getPapel()
{
	return Papel;
}
