#include <exception>
#include <iostream>
#include <ostream>
#include <string>

#include "jogador.h"
#include "rodadas.h"

int main() {
//Foi decidido que o jogo apresentará um número fixo de jogadores, diminuindo assim as variáveis a serem trabalhadas. Atualmente esse número é de - 6 - jogadores. //!Atualizar caso for alterado
//O raciocínio abaixo está completamente sujeito a mudanças. Isso é apenas umas base para se ter uma ideia de como as coisas serão definidas, porém aqui tudo foi definido de forma mais "bruta", sem uso até mesmo de estruturas de repetição. 
const char* papel[6] = { "Inocente", "Inocente", "Assassino", "Inocente","Inocente","Inocente"}; //Esse array armazena os papeis disponíveis, foi feito dessa forma pois diminui a complexidade do código, mantendo o mesmo funcionamento caso fosse utilizada uma classe para os papéis.
std::string nome;
int Pos_Aleatoria;
bool AssassinoSorteado;

std::cout << "Digite o nome do primeiro jogador: ";
std::cin >> nome;
Pos_Aleatoria = rand() % 5;
if(Pos_Aleatoria == 2)
{
    AssassinoSorteado = true;
}
else{

    AssassinoSorteado = false;
}
Jogador jogador1 = Jogador("nome",papel[Pos_Aleatoria]);

std::cout << "Digite o nome do segundo jogador: ";
std::cin >> nome;
if(AssassinoSorteado == true)
{
    Pos_Aleatoria = 0; //Para ser inocente
}
else
{
    Pos_Aleatoria = rand() % 5;
        if(Pos_Aleatoria == 2)
        {
            AssassinoSorteado = true;
        }
}
Jogador jogador2 = Jogador("nome",papel[Pos_Aleatoria]);

std::cout << "Digite o nome do terceiro jogador: ";
std::cin >> nome;
if(AssassinoSorteado == true)
{
    Pos_Aleatoria = 0; //Para ser inocente
}
else
{
    Pos_Aleatoria = rand() % 5;
        if(Pos_Aleatoria == 2)
        {
            AssassinoSorteado = true;
        }
}
Jogador jogador3 = Jogador("nome",papel[Pos_Aleatoria]);

std::cout << "Digite o nome do quarto jogador: ";
std::cin >> nome;
if(AssassinoSorteado == true)
{
    Pos_Aleatoria = 0; //Para ser inocente
}
else
{
    Pos_Aleatoria = rand() % 5;
        if(Pos_Aleatoria == 2)
        {
            AssassinoSorteado = true;
        }
}
Jogador jogador4 = Jogador("nome",papel[Pos_Aleatoria]);

std::cout << "Digite o nome do quinto jogador: ";
std::cin >> nome;
if(AssassinoSorteado == true)
{
    Pos_Aleatoria = 0; //Para ser inocente
}
else
{
    Pos_Aleatoria = rand() % 5;
        if(Pos_Aleatoria == 2)
        {
            AssassinoSorteado = true;
        }
}
Jogador jogador5 = Jogador("nome",papel[Pos_Aleatoria]);

std::cout << "Digite o nome do sexto jogador: ";
std::cin >> nome;
if(AssassinoSorteado == false) // Nesse caso como é o último jogador verifica-se se já foi sorteado um assassino, caso contrário ele obrigatoriamente deverá ser.
{
    Pos_Aleatoria = 2; //Para ser assassino
}
else
{
    Pos_Aleatoria = 0; //Para ser inocente
}
Jogador jogador6 = Jogador("nome",papel[Pos_Aleatoria]);

}