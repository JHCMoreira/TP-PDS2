#include <iostream>
#include <string>
#include <conio.h>
#include "Jogo.h"
#include "Jogador.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

/**
 * @brief Construtor vazio para jogo
 * 
 */
Jogo::Jogo() {}


/**
 * @brief Construtor para o jogo a partir da lista e numero de jogadores
 * 
 */
Jogo::Jogo(Jogador *listaJogadores, int numJogadores)
{
	this->listaJogadores = listaJogadores;
	this->numJogadores = numJogadores;
}

/**
 * @brief Função que agrupa os eventos que acontecem durante o dia no jogo, ou seja a votação geral.
 * 
 */
void Jogo::Dia()
{
	cout << "Discussao da manha" << endl;
	cout << "Aperte qualquer tecla para entrar na votacao" << endl;
	getch();
	system("cls");

	int votedCnt[numJogadores] = {0,};

	for (int i = 0; i < numJogadores; i++) //Realiza a votação indo um jogador por vez
	{
		cout << "Voto de " << listaJogadores[i].getNome() << endl;
		mostraListaVotos();
		bool isVoteNum = false;
		int voteNum;
		do
		{
			cout << "Escreva o numero do jogador que deseja votar para ser eliminado.";
			voteNum = listaJogadores[i].votar() - 1;

			if ((voteNum < numJogadores) && (voteNum >= 0) && (voteNum != i)) //Apenas valida o voto se ele está dentre as opções da lista e se é diferente de si mesmo.
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
	int maxVotedCnt = 0;

	for (int i = 0; i < numJogadores; i++) //Contabiliza os votos
	{
		maxVotedCnt = votedCnt[i] > maxVotedCnt ? votedCnt[i] : maxVotedCnt;
	}

	int maxVotedJogadorKey = -1;
	for (int i = 0; i < numJogadores; i++) // Encontra o jogador com a maior quantidade de votos, em caso de empate ninguém é eliminado
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

/**
 * @brief Função que agrupa os eventos que acontecem durante a noite no jogo, ou seja a ação de cada jogador de acordo com seu papel.
 * 
 */
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

	for (int i = 0; i < numJogadores; i++)	//Organiza as rodadas de cada jogador
	{
		system("cls");
		cout << listaJogadores[i].getNome() << " pressione qualquer tecla" << endl;
		getch();
		string jobCode = listaJogadores[i].getPapel();
		cout << "Voce eh: " << jobCode << endl;
		mostraListaVotos();

		if (jobCode == "LOBISOMEM")	//Se o jogador for o lobisomem ele terá que escolher alguém para atacar
		{
			cout << "Escolha um jogador para atacar" << endl;
			killJogadorKey = listaJogadores[i].votar() - 1;

			while ((killJogadorKey == i) || (killJogadorKey + 1 > numJogadores)) //Filtra os inputs para que não seja inserido nenhum input invalido e não permite que o lobisomem se escolha.
			{
				cin.clear();				  // Limpa o buffer do input para restaurar o cin para um estádo uilizável
				cin.ignore(2147483647, '\n'); // Ignora o último input

				if (killJogadorKey == i)
					cout << "Voce nao pode atacar a si mesmo(a)." << endl;
				else if (killJogadorKey + 1 > numJogadores)
					cout << "Escolha invalida. Voce precisa escolher entre as opcoes da lista." << endl;

				cout << "Escolha um jogador para matar" << endl;
				killJogadorKey = listaJogadores[i].votar() - 1;
			}
		}

		else if (jobCode == "VIDENTE") //Se o jogador for vidente ele deverá escolher outro jogador e descobrirá seu papel. Se for qualquer papel além do lobisomem será apresentado como "HUMANO".
		{
			cout << "Escolha um jogador para ser investigado." << endl;
			checkJobJogadorKey = listaJogadores[i].votar() - 1;

			while ((checkJobJogadorKey == i) || (checkJobJogadorKey + 1 > numJogadores)) //Filtra os inputs para que não seja inserido nenhum input invalido e não permite que o vidente se escolha.
			{
				cin.clear();				  // Limpa o buffer do input para restaurar o cin para um estádo uilizável
				cin.ignore(2147483647, '\n'); // Ignora o último input
				cout << "Escolha invalida. Voce deve escolher entre os jogadores na lista exceto a si mesmo." << endl;
				cout << "Escolha um jogador para ser investigado." << endl;
				checkJobJogadorKey = listaJogadores[i].votar() - 1;
			}

			//A partir daqui descobre qual o papel do jogador escolhido, indicando se é o lobisomem ou apenas humano.
			cout << "Jogador: " << listaJogadores[checkJobJogadorKey].getNome() << endl;
			string jobCode = listaJogadores[checkJobJogadorKey].getPapel();
			if (jobCode != "LOBISOMEM")
			{
				jobCode = "HUMANO";
			}
			cout << "Papel: " << jobCode << endl;
		}

		else if (jobCode == "MEDICO") //Se o jogador for o médico ele terá que escolher alguém para proteger do lobisomem, podendo escolher a si mesmo.
		{
			cout << "Escolha um jogador para ser protegido." << endl;
			saveJogadorKey = listaJogadores[i].votar() - 1;
			while (saveJogadorKey + 1 > numJogadores) //Filtra inputs inválidos.
			{
				cin.clear();				  // Limpa o buffer do input para restaurar o cin para um estádo uilizável
				cin.ignore(2147483647, '\n'); // Ignora o último input
				cout << "Escolha invalida. Voce deve escolher entre os jogadores na lista." << endl;
				cout << "Escolha um jogador para ser protegido." << endl;
				saveJogadorKey = listaJogadores[i].votar() - 1;
			}
		}

		else if (jobCode == "CAMPONES") //Se o jogador for um camponês ele não poderá fazer nada. Ainda assim possui uma escolha em sua rodada para evitar suspeitas dos outros jogadores.
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
	if (killJogadorKey == saveJogadorKey) //Analisa se o jogador protegido pelo médico foi o mesmo atacado pelo lobisomem, se sim ele não morre.
	{
		deadJogadorKey = -1;
	}
	else	//Caso contrário o jogador é eliminado.
	{
		deadJogadorKey = killJogadorKey;
	}
	mostraResultadoVotos(deadJogadorKey);
}

/**
 * @brief Mostra a lista contendo as opções de escolha em todas as rodadas.
 * 
 */
void Jogo::mostraListaVotos()
{
	string jogadorName;
	for (int i = 0; i < numJogadores; i++)
	{
		cout << i + 1 << ". " << listaJogadores[i].getNome() << endl;
	}
}

/**
 * @brief Mostra se algum jogador foi eliminado tanto na votação do dia quanto no período da noite por conta do lobisomem.
 * 
 * @param deadJogadorKey 
 */
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

/**
 * @brief Elimina o jogador morto do jogo.
 * 
 * @param deadJogadorKey 
 */
void Jogo::removeJogadorMorto(int deadJogadorKey)
{
	int newJogadorCnt = numJogadores - 1;
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

/**
 * @brief Detecta se o jogo chegou ao fim.
 * 		  Os critérios para isso são: 
 * 			- Todos os lobisomens estão mortos. Garantindo vitória dos humanos.
 * 			- Apenas um ou nenhum humano restante. Garantindo vitória dos lobisomens.
 */
void Jogo::checaFimDeJogo()
{
	int numLobisomens = 0;
	int numHumanos = 0;

	for (int i = 0; i < numJogadores; i++) //Varre a lista de jogadores e seus papéis para contabilizar a quantidade de humanos e lobisomens.
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

	if (numLobisomens == 0) //Todos lobisomens estão mortos
	{
		cout << "Todos os lobisomens estao mortos." << endl;
		cout << "Vitoria dos inocentes!" << endl;
		gameOver = false;
	}

	else if (numHumanos <= 1) //Um ou zero humanos vivos.
	{
		if (numHumanos == 1)
			cout << "Apenas um humano vivo." << endl;
		else if (numHumanos == 0)
			cout << "Todos os humanos morreram." << endl;

		cout << "Vitoria dos lobisomens!" << endl;
		gameOver = false;
	}

	if (!gameOver) //Indica o fim do jogo
	{
		cout << "Sair do jogo." << endl;
	}

	cout << "Pressione qualquer tecla para continuar." << endl;
	getch();
}

/**
 * @brief Função que dá início ao jogo.
 * 
 */
void Jogo::play()
{
	cout << "Iniciando o jogo.....";

	gameOver = true;

	while (gameOver) //Cordena os turnos da noite e do dia.
	{
		Dia();
		if (!gameOver)
		{
			break;
		}
		Noite();
	}
}
