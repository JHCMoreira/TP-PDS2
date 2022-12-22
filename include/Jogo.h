#ifndef JOGO_H
#define JOGO_H
#include <string>
#include "Jogador.h"

class Jogo
{
private:
	//Declara lista de jogadores
	Jogador *listaJogadores;
	//Numero de jogadores
	int numJogadores;
	//Variável para determinar se o jogo chegou ou não ao fim
	bool gameOver;

	void Dia();
	void Noite();

	void mostraListaVotos();
	void mostraResultadoVotos(int deadJogadorKey);
	void removeJogadorMorto(int deadJogadorKey);
	void checaFimDeJogo();

public:
	Jogo();
	Jogo(Jogador *listaJogadores, int numJogadores);

	void play();
};
#endif
