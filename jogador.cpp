#include <cmath>
#include <exception>

#include "jogador.h"

void Jogador::setNome(std::string nome)
{
      _nome = nome;
	return;
}

void Jogador::setPapel(std::string papel)
{
      _papel = papel;
	return;
}

void Jogador::setEstado(std::string estado)
{
      _estado = estado;
	return;
}

std::string Jogador::getNome()
{
			return _nome;
}

std::string Jogador::getPapel()
{
			return _papel;
}

std::string Jogador::getEstado()
{
			return _estado;
}