#include <cmath>
#include <exception>

#include "jogador.h"

Jogador::Jogador(std::string nome, std::string papel) {
      _nome = nome;
      _papel = papel;
}

std::string Jogador::getNome()
{
			return _nome;
}

std::string Jogador::getPapel()
{
			return _papel;
}