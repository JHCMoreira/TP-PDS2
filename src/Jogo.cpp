#include <iostream>
#include <string>
#include <conio.h>
#include "Jogo.h"
#include "Jogador.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Jogo::Jogo() {}

Jogo::Jogo(Jogador *listaJogadores, int numJogadores)
{
	this->listaJogadores = listaJogadores;
	this->numJogadores = numJogadores;
}

void Jogo::Dia()
{
	cout << "Discussao da manha" << endl;
	cout << "Aperte qualquer tecla para entrar na votacao" << endl;
	getch();
	system("cls");

	int votedCnt[numJogadores] = {
		0,
	};
	for (int i = 0; i < numJogadores; i++)
	{
		cout << "Voto de " << listaJogadores[i].getNome() << endl;
		mostraListaVotos();
		bool isVoteNum = false;
		int voteNum;
		do
		{
			cout << "Escreva o numero do jogador que deseja votar para ser eliminado.";
			voteNum = listaJogadores[i].votar() - 1;

			if ((voteNum < numJogadores) && (voteNum >= 0) && (voteNum != i))
			{
				isVoteNum = true;
			}
			else
			{
				if (voteNum == i)
					cout << "Voce nao pode votar em si." << endl;
				else
					cout << "Escolha invalida (fora das opcoes da lista)." << endl;
			}

		} while (!isVoteNum);
		votedCnt[voteNum]++;
		system("cls");
	}
	// Encontra o valor maximo de votos
	int maxVotedCnt = 0;
	for (int i = 0; i < numJogadores; i++)
	{
		maxVotedCnt = votedCnt[i] > maxVotedCnt ? votedCnt[i] : maxVotedCnt;
	}
	// Encontra o jogador com a maior quantidade de votos, em caso de empate ninguém é eliminado
	int maxVotedJogadorKey = -1;
	for (int i = 0; i < numJogadores; i++)
	{
		if (votedCnt[i] == maxVotedCnt)
		{
			if (maxVotedJogadorKey == -1)
			{
				maxVotedJogadorKey = i;
			}
			else
			{
				maxVotedJogadorKey = -1;
				break;
			}
		}
	}
	mostraResultadoVotos(maxVotedJogadorKey);
}
void Jogo::Noite()
{
	system("cls");
	cout << "A noite chegou" << endl
		 << endl;
	cout << "Lobisomens escolhem um jogador para ser atacado" << endl
		 << endl;
	cout << "Videntes podem descobrir se alguem eh um lobisomem." << endl
		 << endl;
	cout << "O medico escolhe um jogador para proteger" << endl
		 << endl;
	cout << "Camponeses voltem a dormir" << endl
		 << endl;
	cout << "Pressione qualquer tecla para seguir em frente" << endl;
	getch();

	int killJogadorKey = -2;
	int saveJogadorKey = -3;
	int checkJobJogadorKey;

	for (int i = 0; i < numJogadores; i++)
	{
		system("cls");
		cout << listaJogadores[i].getNome() << " pressione qualquer tecla" << endl;
		getch();
		string jobCode = listaJogadores[i].getPapel();
		cout << "Voce eh: " << jobCode << endl;
		mostraListaVotos();

		if (jobCode == "LOBISOMEM")
		{
			cout << "Escolha um jogador para matar" << endl;
			killJogadorKey = listaJogadores[i].votar() - 1;
			while ((killJogadorKey == i) || (killJogadorKey + 1 > numJogadores))
			{
				cin.clear();			   // clear input buffer to restore cin to a usable state
				cin.ignore(2147483647, '\n'); // ignore last input

				if (killJogadorKey == i)
					cout << "Voce nao pode atacar a si mesmo(a)." << endl;
				else if (killJogadorKey + 1 > numJogadores)
					cout << "Escolha invalida. Voce precisa escolher entre as opcoes da lista." << endl;

				cout << "Escolha um jogador para matar" << endl;
				killJogadorKey = listaJogadores[i].votar() - 1;
			}
		}

		else if (jobCode == "VIDENTE")
		{
			cout << "Escolha um jogador para ser investigado." << endl;
			checkJobJogadorKey = listaJogadores[i].votar() - 1;
			while ((checkJobJogadorKey == i) || (checkJobJogadorKey + 1 > numJogadores))
			{
				cin.clear();			   // clear input buffer to restore cin to a usable state
				cin.ignore(2147483647, '\n'); // ignore last input
				cout << "Escolha invalida. Voce deve escolher entre os jogadores na lista exceto a si mesmo." << endl;
				cout << "Escolha um jogador para ser investigado." << endl;
				checkJobJogadorKey = listaJogadores[i].votar() - 1;
			}
			cout << "Jogador: " << listaJogadores[checkJobJogadorKey].getNome() << endl;
			string jobCode = listaJogadores[checkJobJogadorKey].getPapel();
			if (jobCode != "LOBISOMEM")
			{
				jobCode = "HUMANO";
			}
			cout << "Papel: " << jobCode << endl;
		}

		else if (jobCode == "MEDICO")
		{
			cout << "Escolha um jogador para ser protegido." << endl;
			saveJogadorKey = listaJogadores[i].votar() - 1;
			while (saveJogadorKey + 1 > numJogadores)
			{
				cin.clear();			   // clear input buffer to restore cin to a usable state
				cin.ignore(2147483647, '\n'); // ignore last input
				cout << "Escolha invalida. Voce deve escolher entre os jogadores na lista." << endl;
				cout << "Escolha um jogador para ser protegido." << endl;
				saveJogadorKey = listaJogadores[i].votar() - 1;
			}
		}

		else if (jobCode == "CAMPONES")
		{
			cout << "Vote em alguem para nao levantar suspeitas de seu papel." << endl;
			listaJogadores[i].votar();
			cout << "Seu voto nao possui poder algum." << endl;
			cout << "Volte a dormir" << endl;
		}

		else
		{
			cout << "[ERROR] Papel";
		}
		cout << "Apos confirmar pressione qualquer tecla" << endl;
		getch();
	}
	system("cls");
	cout << "Fim da noite. O dia amanhece." << endl;
	int deadJogadorKey;
	if (killJogadorKey == saveJogadorKey)
	{
		deadJogadorKey = -1;
	}
	else
	{
		deadJogadorKey = killJogadorKey;
	}
	mostraResultadoVotos(deadJogadorKey);
}
void Jogo::mostraListaVotos()
{
	string jogadorName;
	for (int i = 0; i < numJogadores; i++)
	{
		cout << i + 1 << ". " << listaJogadores[i].getNome() << endl;
	}
}
void Jogo::mostraResultadoVotos(int deadJogadorKey)
{
	if (deadJogadorKey == -1)
	{
		cout << "Nenhum jogador foi eliminado" << endl;
		cout << "Pressione qualquer tecla para continuar." << endl;
		getch();
	}
	else
	{
		cout << "O jogador " << listaJogadores[deadJogadorKey].getNome() << " foi eliminado." << endl;
		removeJogadorMorto(deadJogadorKey);
	}
}
void Jogo::removeJogadorMorto(int deadJogadorKey)
{
	int newJogadorCnt = numJogadores - 1;
	// Jogador removedJogadorList[newJogadorCnt];
	Jogador *removedJogadorList;
	removedJogadorList = new Jogador[newJogadorCnt];
	for (int i = 0, j = 0; i < numJogadores; i++)
	{
		if (deadJogadorKey != i)
		{
			removedJogadorList[j++] = listaJogadores[i];
		}
	}
	this->numJogadores = newJogadorCnt;
	this->listaJogadores = removedJogadorList;

	checaFimDeJogo();
}
void Jogo::checaFimDeJogo()
{
	int numLobisomens = 0;
	int numHumanos = 0;

	for (int i = 0; i < numJogadores; i++)
	{
		if (listaJogadores[i].getPapel() == "LOBISOMEM")
		{
			numLobisomens++;
		}
		else
		{
			numHumanos++;
		}
	}

	if (numLobisomens == 0)
	{
		cout << "Todos os lobisomens estao mortos." << endl;
		cout << "Vitoria dos inocentes!" << endl;
		gameOver = false;
	}

	else if (numHumanos <= 1)
	{
		if (numHumanos == 1)
			cout << "Apenas um humano vivo." << endl;
		else if (numHumanos == 0)
			cout << "Todos os humanos morreram." << endl;

		cout << "Vitoria dos lobisomens!" << endl;
		gameOver = false;
	}

	if (!gameOver)
	{
		cout << "Sair do jogo." << endl;
	}

	cout << "Pressione qualquer tecla para continuar." << endl;
	getch();
}

void Jogo::play()
{
	cout << "Iniciando o jogo.....";

	gameOver = true;
	while (gameOver)
	{
		Dia();
		if (!gameOver)
		{
			break;
		}
		Noite();
	}
}
