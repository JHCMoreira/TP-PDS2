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
    Jogador(std::string nome, std::string papel);
    std::string getNome();
    std::string getPapel();
};

#endif