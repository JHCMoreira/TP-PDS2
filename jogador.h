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
    std::string _estado; //vivo ou morto

  public:
    std::string getNome();
    void setNome(std::string nome);
    std::string getPapel();
    void setPapel(std::string papel);
    std::string getEstado();
    void setEstado(std::string estado);
};

#endif