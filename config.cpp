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
	int inputInicial;
	bool jogoConfigurado = false;
	while(inputInicial != 3)
	{
		cout << "(1) Configuracoes do jogo | (2) Iniciar jogo | (3) Sair : ";
		cin >> inputInicial;
		while (cin.fail())
    	{
			cin.clear(); // clear input buffer to restore cin to a usable state
			cin.ignore(INT_MAX, '\n'); // ignore last input
			cout << "Por favor digite sua escolha novamente."  << endl;
			cout << "(1) Configuracoes do jogo | (2) Iniciar jogo | (3) Sair :";
			cin >> inputInicial;
    	}
		switch(inputInicial)
		{
			case 1:
				setJogo();
				jogoConfigurado = true;

			case 2:
				if(jogoConfigurado)
				{
					iniciaJogo();
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
	setListaUsuarios();
	setListaPapeis();
}

void Config::iniciaJogo()
{
	setListaJogadores();
	mostraPapeisJogadores();

	Jogo jogo(listaJogadores, numJogadores);
	jogo.play();
}

void Config::setListaUsuarios()
{
	system("cls");
	// Define a quantidade de jogadores
	cout << "Por favor digite o numero de jogadores: ";
	cin >> numJogadores;

	while ((cin.fail()) || (numJogadores <= 0))
    {
		cin.clear(); // clear input buffer to restore cin to a usable state
		cin.ignore(INT_MAX, '\n'); // ignore last input
		cout << "Por favor digite um valor valido."  << endl;
		cout << "Por favor digite o numero de jogadores: ";
		cin >> numJogadores;
    }

	listaUsuarios = new Usuario[numJogadores];

	for(int i=0; i<numJogadores; i++)
	{
		string nome;
		cout << "Digite o nome dos jogadores (um por vez): ";
		cin >> nome;
		listaUsuarios[i] = Config::addUsuario(nome);
	}
}

void Config::setListaPapeis()
{
	system("cls");
	cout << "Numero total de jogadores: " << numJogadores << endl;
	listaPapeis = new string[numJogadores];

	int numTotalPapeis = 0;
	int numPapel;
	int listaPapeisIndex = 0;
	for(int i=0; i<numPapeis; i++)
	{
		cout << "Numero de " << Papel[i] <<": ";
		cin >> numPapel;
		if(Papel[i] == "LOBISOMEM")
		{
			while ((cin.fail()) || (numPapel <= 0) || (numPapel >= numJogadores))
			{
				cin.clear(); // clear input buffer to restore cin to a usable state
				cin.ignore(INT_MAX, '\n'); // ignore last input
				cout << "A quantidade de lobisomens deve ser maior do que 1 e menor do que a quantidade total de jogadores."  << endl;
				cout << "Numero de " << Papel[i] <<": ";
				cin >> numPapel;
			}
		}

		else
		{
			while ((cin.fail()) || (numPapel < 0))
			{
				cin.clear(); // clear input buffer to restore cin to a usable state
				cin.ignore(INT_MAX, '\n'); // ignore last input
				cout << "Por favor digite um valor valido."  << endl;
				cout << "Numero de " << Papel[i] <<": ";
				cin >> numPapel;
			}
		}

		numTotalPapeis += numPapel;
		if(numTotalPapeis > numJogadores)
		{
			cout << "A quantidade de papeis fornecida eh maior do que a quantidade total de jogadores" << endl;
			numTotalPapeis -= numPapel;
			i--;
			continue;
		}

		if(((numJogadores - numTotalPapeis) > 0) && (i == numPapeis-1))
		{
			cout << "Eh necessario que a quantidade total fornecida de papeis seja igual ao numero de jogadores." << endl;
			numTotalPapeis -= numPapel;
			i--;
			continue;
		}

		for(int j=0; j<numPapel; j++,listaPapeisIndex++)
		{
			listaPapeis[listaPapeisIndex] = Papel[i];
		}
	}
}
void Config::setListaJogadores()
{
	// Embaralha a lista de papéis
	embaralhaArr(listaPapeis, numJogadores);
	// Cria o objeto jogador
	listaJogadores = new Jogador[numJogadores];
	for(int i=0; i<numJogadores; i++)
	{
		Jogador jogador(listaUsuarios[i].nome, listaPapeis[i]);
		listaJogadores[i] = jogador;
	}
}
void Config::mostraPapeisJogadores()
{
	system("cls");
	for(int i=0; i<numJogadores; i++)
	{
		listaJogadores[i].mostrarPapelJogador();
	}
}
void Config::embaralhaArr(string *arr, int size)
{
	srand((unsigned int)time(NULL));
	string temp;
	int randIndex;
	for(int i=0; i<size; i++)
	{
		randIndex = rand() % size;
		temp = listaPapeis[i];
		listaPapeis[i] = listaPapeis[randIndex];
		listaPapeis[randIndex] = temp;

	}
}
Config::Usuario Config::addUsuario(string nome)
{
	Usuario usuario;
	usuario.nome = nome;
	return usuario;
}
