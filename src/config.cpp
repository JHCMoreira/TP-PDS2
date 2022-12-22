#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "config.h"
#include "Jogador.h"
#include "Jogo.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

/**
 * @brief Construtor da classe config, definindo o número de papeis de quais papéis existem
 *
 */
Config::Config()
{
	numPapeis = 4;
	Papel = new string[numPapeis]{"LOBISOMEM", "VIDENTE", "MEDICO", "CAMPONES"};
	cout << "Criar sala Config::Config()" << endl;
}

/**
 * @brief Função para rodar o jogo inicialmente. Ela possúi o menu inicial onde o jogador pode escolher entre configurar o jogo,
 * iniciá-lo ou sair. O jogador apenas consegue iniciar o jogo quando o mesmo está configurado.
 */
void Config::run()
{
	system("cls");
	int inputInicial;			  // Input do jogador para selecionar a opção desejada.
	bool jogoConfigurado = false; // Acompanha se o jogo está ou não configurado.
	while (inputInicial != 3)
	{
		cout << "(1) Configuracoes do jogo | (2) Iniciar jogo | (3) Sair : ";
		cin >> inputInicial;

		while (cin.fail()) // Tratamento caso seja fornecido algum argumento inválido no input. Como por exemplo fornecer um caractére a um int.
		{
			cin.clear();				  // Limpa o buffer do input para restaurar o cin para um estádo uilizável
			cin.ignore(2147483647, '\n'); // Ignora o último input
			cout << "Por favor digite sua escolha novamente." << endl;
			cout << "(1) Configuracoes do jogo | (2) Iniciar jogo | (3) Sair :";
			cin >> inputInicial;
		}
		switch (inputInicial)
		{
		case 1:
			setJogo();
			jogoConfigurado = true; // Determina que o jogo está configurado

		case 2:
			if (jogoConfigurado) // Apenas permite que o jogo funcione quando estiver configurado
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

/**
 * @brief Configura o jogo, definindo os jogadores e seus papéis.
 *
 */
void Config::setJogo()
{
	setListaUsuarios();
	setListaPapeis();
}

/**
 * @brief Finaliza as configurações do jogo e inicia o mesmo.
 *
 */
void Config::iniciaJogo()
{
	setListaJogadores();
	mostraPapeisJogadores();

	Jogo jogo(listaJogadores, numJogadores);
	jogo.play();
}

/**
 * @brief Determina quais serão todos os jogadores organizando-os em uma lista.
 *
 */
void Config::setListaUsuarios()
{
	system("cls");
	cout << "Por favor digite o numero de jogadores (minimo 3): ";
	cin >> numJogadores; // Define a quantidade de jogadores

	while ((cin.fail()) || (numJogadores < 3)) // Tratamento caso seja fornecido algum input inválido ou se o número de jogadores fornecidos for menor do que 3.
	{
		cin.clear();				  // Limpa o buffer do input para restaurar o cin para um estádo uilizável
		cin.ignore(2147483647, '\n'); // Ignora o último input

		if (numJogadores <= 3)
			cout << "São necessários no mínimo 3 jogadores." << endl;
		else
			cout << "Por favor digite um valor valido." << endl;

		cout << "Por favor digite o numero de jogadores (minimo 3): ";
		cin >> numJogadores;
	}

	listaUsuarios = new Usuario[numJogadores]; // Cria a lista de jogadores

	for (int i = 0; i < numJogadores; i++) // Armazena os jogadores na lista
	{
		string nome;
		cout << "Digite o nome dos jogadores (um por vez): ";
		cin >> nome;
		listaUsuarios[i] = Config::addUsuario(nome);
	}
}

/**
 * @brief Determina quais serão os papéis de todos os jogadores organizando-os em uma lista.
 *
 */
void Config::setListaPapeis()
{
	system("cls");
	cout << "Numero total de jogadores: " << numJogadores << endl;
	listaPapeis = new string[numJogadores]; // Cria a lista de papeis para os jogadores

	int numTotalPapeis = 0;
	int numPapel;
	int listaPapeisIndex = 0;

	for (int i = 0; i < numPapeis; i++) // Pergunta ao usuário a quantidade de jogadores por papel no jogo
	{
		cout << "Numero de " << Papel[i] << ": ";
		cin >> numPapel;

		if (Papel[i] == "LOBISOMEM") // O Lobisomem é um caso especial pois é necessário que tenha ao menos 1 e menos do que a quantidade total de jogadores.
		{
			while ((cin.fail()) || (numPapel <= 0) || (numPapel >= numJogadores)) // Tratamento caso seja fornecido algum input inválido e limitando os valores de acordo com as especificações do lobisomem.
			{
				cin.clear();				  // Limpa o buffer do input para restaurar o cin para um estádo uilizável
				cin.ignore(2147483647, '\n'); // Ignora o último input
				cout << "A quantidade de lobisomens deve ser maior do que 1 e menor do que a quantidade total de jogadores." << endl;
				cout << "Numero de " << Papel[i] << ": ";
				cin >> numPapel;
			}
		}

		else
		{
			// Tratamento caso seja fornecido algum input invalido
			while ((cin.fail()) || (numPapel < 0))
			{
				cin.clear();				  // Limpa o buffer do input para restaurar o cin para um estádo uilizável
				cin.ignore(2147483647, '\n'); // Ignora o último input
				cout << "Por favor digite um valor valido." << endl;
				cout << "Numero de " << Papel[i] << ": ";
				cin >> numPapel;
			}
		}

		numTotalPapeis += numPapel;		   // Incrementa o valor digitado à variável numTotalPapeis para acompanhar quantos papeis foram preenchidos até o momento
		if (numTotalPapeis > numJogadores) // Filtra para que não seja possível que o valor escolhido como quantidade faça com que o numero de papeis seja maior do que o numero total de jogadores.
		{
			cout << "A quantidade de papeis fornecida eh maior do que a quantidade total de jogadores" << endl;
			numTotalPapeis -= numPapel;
			i--;
			continue;
		}

		if (((numJogadores - numTotalPapeis) > 0) && (i == numPapeis - 1)) // Filtra para que a quantidade final de papeis seja igual a quantidade total de jogadores
		{
			cout << "Eh necessario que a quantidade total fornecida de papeis seja igual ao numero de jogadores." << endl;
			numTotalPapeis -= numPapel;
			i--;
			continue;
		}

		for (int j = 0; j < numPapel; j++, listaPapeisIndex++) // Adiciona os papéis a uma lista.
		{
			listaPapeis[listaPapeisIndex] = Papel[i];
		}
	}
}

/**
 * @brief Organiza os papéis para cada jogador, aleatorizando qual jogador fica com cada papel a cada jogo.
 *
 */
void Config::setListaJogadores()
{
	// Embaralha a lista de papéis
	embaralhaArr(listaPapeis, numJogadores);
	// Cria o objeto jogador
	listaJogadores = new Jogador[numJogadores];
	for (int i = 0; i < numJogadores; i++)
	{
		Jogador jogador(listaUsuarios[i].nome, listaPapeis[i]);
		listaJogadores[i] = jogador;
	}
}

/**
 * @brief Como o nome indica, mostra o papel de cada jogador.
 *
 */
void Config::mostraPapeisJogadores()
{
	system("cls");
	for (int i = 0; i < numJogadores; i++)
	{
		listaJogadores[i].mostrarPapelJogador();
	}
}

/**
 * @brief Embaralha os papéis para que depois sejam sorteados entre os jogadores
 *
 * @param arr
 * @param size
 */
void Config::embaralhaArr(string *arr, int size)
{
	srand((unsigned int)time(NULL));
	string temp;
	int randIndex;
	for (int i = 0; i < size; i++)
	{
		randIndex = rand() % size;
		temp = listaPapeis[i];
		listaPapeis[i] = listaPapeis[randIndex];
		listaPapeis[randIndex] = temp;
	}
}

/**
 * @brief Adiciona um usuario ao jogo
 *
 * @param nome
 * @return Config::Usuario
 */
Config::Usuario Config::addUsuario(string nome)
{
	Usuario usuario;
	usuario.nome = nome;
	return usuario;
}
