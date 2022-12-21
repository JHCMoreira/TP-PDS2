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
		struct User
		{
			std::string nome;
		};
		// Papeis : Lobisomem, Aldeão, Médico e Vidente
		const std::string *Papel;
		// Número de papeis
		int numPapeis;

		// Lista de usuários
		User *userList;
		// Lista de papeis
		std::string *jobCodeList;
		// Lista de jogadores
		Jogador *listaJogadores;

		User addUser(std::string nome);
		void suffleStringArr(std::string *arr, int size);
	public:
		Config();
		void setUserList();
		void setJobList();
		void setJogadorList();
		void showAllJogadorJobCode();

		void run();
		void setJogo();
		void gameStart();
};
#endif