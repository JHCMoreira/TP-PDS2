#ifndef JOGADOR_H
#define JOGADOR_H
#include <string>

class Jogador
{
private:
	std::string Papel;
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
