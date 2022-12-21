#ifndef CONFIG_H
#define CONFIG_H
#include <string>
#include "jogador.h"

class Config
{	
	private:
		// Número de jogadores
		int numJogadores;
		// Declara o usuario/jogador
		struct Usuario
		{
			std::string nome;
		};
		// Papeis : Lobisomem, Aldeão, Médico e Vidente
		const std::string *Papel;
		// Número de papeis
		int numPapeis;

		// Lista de usuários
		Usuario *listaUsuarios;
		// Lista de papeis
		std::string *listaPapeis;
		// Lista de jogadores
		Jogador *listaJogadores;

		Usuario addUsuario(std::string nome);
		void embaralhaArr(std::string *arr, int size);
	public:
		Config();
		void setListaUsuarios();
		void setListaPapeis();
		void setListaJogadores();
		void mostraPapeisJogadores();

		void run();
		void setJogo();
		void iniciaJogo();
};
#endif