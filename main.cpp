#include <exception>
#include <iostream>
#include <ostream>
#include <string>

#include "jogador.h"
#include "rodadas.h"

int main() {
//Foi decidido que o jogo apresentará um número fixo de jogadores, diminuindo assim as variáveis a serem trabalhadas. Atualmente esse número é de - 6 - jogadores. //!Atualizar caso for alterado
const char* papel[6] = { "Inocente", "Inocente", "Assassino", "Inocente","Inocente","Inocente"}; //Esse array armazena os papeis disponíveis, foi feito dessa forma pois diminui a complexidade do código, mantendo o mesmo funcionamento caso fosse utilizada uma classe para os papéis.
std::string nome;
int Pos_Aleatoria;
bool AssassinoSorteado = false;
Jogador jogador[6];

    for (int i = 0; i < 6;i++)
    {
        std::cout << "Digite o nome do " << i << "º jogador"<<std::endl;
        std::cin >> nome;
        jogador[i].setNome(nome);
    
        if(AssassinoSorteado == false)
        {
            Pos_Aleatoria = rand() % 5;
            
            if (Pos_Aleatoria == 2)
            {
                AssassinoSorteado = true;
                jogador[i].setPapel(papel[Pos_Aleatoria]);
            }

            else
            {   
                jogador[i].setPapel(papel[Pos_Aleatoria]);
            }
        }

        else
        {
            jogador[i].setPapel(papel[0]); //Se assassino já foi sorteado todos após ele são obrigatoriamente inocentes
        }

        if((i == 5) && (AssassinoSorteado == false))
        {
            jogador[i].setPapel(papel[2]); //Se for o ultimo da lista e ainda nao tiver sido sorteado um assassino é obrigatoriamente assassino.
        }
        
        jogador[i].setEstado("Vivo"); //Os participantes começam todos vivos
    }
    
}