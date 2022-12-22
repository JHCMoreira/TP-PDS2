#include "doctest.h"
#include "jogador.h"

/*Foram feitos poucos casos de teste pois da forma como o programa foi estruturado praticamente todas as funções não apresentam nenhum retorno.
O programa funciona de forma sequencial com uma função chamando a outra de acordo com o procedimento do jogo.
Dessa forma foram feitos testes apenas para o construtor do jogador e os testes para pegar seu nome e papel.
*/
TEST_CASE("Teste construtor/nome/papel") {
    Jogador jogador = Jogador("Joao","LOBISOMEM");
    CHECK_EQ(jogador.getNome(),"Joao");
    CHECK_EQ(jogador.getPapel(),"LOBISOMEM");
    Jogador jogador2 = Jogador("Carla","VIDENTE");
    CHECK_EQ(jogador2.getNome(),"Carla");
    CHECK_EQ(jogador2.getPapel(),"VIDENTE");
    Jogador jogador3 = Jogador("Victor","MEDICO");
    CHECK_EQ(jogador3.getNome(),"Victor");
    CHECK_EQ(jogador3.getPapel(),"MEDICO");
}