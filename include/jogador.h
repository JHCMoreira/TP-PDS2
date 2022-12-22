#ifndef JOGADOR_H
#define JOGADOR_H
#include <string>

class Jogador
{
private:
	// Define papel do jogador
	std::string Papel;
	//Define o nome do jogador
	std::string nome;

public:
	Jogador();
	Jogador(std::string nome, std::string Papel);

	void mostrarPapelJogador();

	int votar();
	std::string getNome();
	std::string getPapel();
};
#endif
