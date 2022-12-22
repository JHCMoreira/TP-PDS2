#ifndef JOGO_H
#define JOGO_H
#include <string>
#include "Jogador.h"

class Jogo
{
private:
	Jogador *listaJogadores;
	int numJogadores;
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
