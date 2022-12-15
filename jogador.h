#ifndef JOGADORES
#define JOGADORES

#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <exception>

class Jogador {
  private:
    std::string _nome;
    std::string _papel;

  public:
    Jogador(std::string nome, std::string papel) {
      _nome = nome;
      _papel = papel;
    }
    std::string getNome()
	{
			return _nome;
	}
    std::string getPapel()
	{
			return _papel;
	}
};

#endif