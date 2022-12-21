#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "config.h"
#include "Jogador.h"
#include "Jogo.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

Config::Config()
{
	numPapeis = 4;
	Papel =new string[numPapeis]{"LOBISOMEM","VIDENTE","MEDICO","CAMPONES"};
	cout << "Criar sala Config::Config()"<<endl;
}
void Config::run()
{
	system("cls");
	int inputKey;
	bool isSetJogo = false;
	while(inputKey != 3)
	{
		cout << "1)Configuracoes do jogo, 2)Iniciar jogo, 3)Sair :";
		cin >> inputKey;
		switch(inputKey)
		{
			case 1:
				setJogo();
				isSetJogo = true;
			case 2:
				if(isSetJogo)
				{
					gameStart();
				}
				else
				{
					cout << "Configure o jogo antes de inicia-lo." << endl;
				}
				break;
			case 3:
				break;
			default:
				cout << "Por favor digite sua escolha novamente." << endl;
				break;
		}
	}
}
void Config::setJogo()
{
	setUserList();
	setJobList();
}
void Config::gameStart()
{
	setJogadorList();
	showAllJogadorJobCode();

	Jogo game(listaJogadores, numJogadores);
	game.play();
}
void Config::setUserList()
{
	system("cls");
	// Define a quantidade de jogadores
	cout << "Por favor digite o numero de jogadores: ";
	cin >> numJogadores;
	userList = new User[numJogadores];

	for(int i=0; i<numJogadores; i++)
	{
		string nome;
		cout << "Digite o nome dos jogadores (um por vez): ";
		cin >> nome;
		userList[i] = Config::addUser(nome);
	}
}
void Config::setJobList()
{
	system("cls");
	cout << "Numero total de jogadores: " << numJogadores << endl;
	jobCodeList = new string[numJogadores];

	int totalJobCnt = 0;
	int jobCnt;
	int jobCodeListIndex = 0;
	for(int i=0; i<numPapeis; i++)
	{
		cout << "Numero de " << Papel[i] <<": ";
		cin >> jobCnt;
		totalJobCnt += jobCnt;
		if(totalJobCnt > numJogadores)
		{
			cout << "Valor invalido." << endl;
			totalJobCnt -= jobCnt;
			i--;
			continue;
		}

		for(int j=0; j<jobCnt; j++,jobCodeListIndex++)
		{
			jobCodeList[jobCodeListIndex] = Papel[i];
		}
	}
}
void Config::setJogadorList()
{
	// Embaralha a lista de papéis
	suffleStringArr(jobCodeList, numJogadores);
	// Cria o objeto jogador
	listaJogadores = new Jogador[numJogadores];
	for(int i=0; i<numJogadores; i++)
	{
		Jogador jogador(userList[i].nome, jobCodeList[i]);
		listaJogadores[i] = jogador;
	}
}
void Config::showAllJogadorJobCode()
{
	system("cls");
	for(int i=0; i<numJogadores; i++)
	{
		listaJogadores[i].mostrarPapelJogador();
	}
}
void Config::suffleStringArr(string *arr, int size)
{
	srand((unsigned int)time(NULL));
	string temp;
	int randIndex;
	for(int i=0; i<size; i++)
	{
		randIndex = rand() % size;
		temp = jobCodeList[i];
		jobCodeList[i] = jobCodeList[randIndex];
		jobCodeList[randIndex] = temp;

	}
}
Config::User Config::addUser(string nome)
{
	User user;
	user.nome = nome;
	return user;
}
