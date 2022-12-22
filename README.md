# TP PDS II: Jogo Lobisomem   
   Jogo no estilo de Lobisomem(também bastante conhecido como Cidade dorme ou Máfia). https://pt.wikipedia.org/wiki/Cidade_dorme 

Integrantes do grupo:  
- Gabriel Vitor Antunes Carvalho;  
- João Henrique Costa Moreira;  
- João Victor Souza de Andrade;  

## COMO COMPILAR E RODAR O JOGO  
Para compilar o jogo basta baixar os arquivos disponibilizados no repositório e rodar via terminal o comando: "**make jogo**". A partir disso será gerado um executável **Jogo.exe** e para jogar basta executá-lo.  
**Observação importante:** O único sistema operacional em que o jogo foi testado foi no Windows 10, então talvez aja algumas incompatibilidades com outros sistemas operacionais como Linux ou Mac. Por conta disso é fornecido no repositório o executável (**Lobisomem.exe**) necessário para rodar o jogo sem necessidade de compilação.  

## COMO VER OS RESULTADOS DOS TESTES DE UNIDADE  
De forma semelhante à compilação, para analisar os testes de unidade basta executar via terminal o comando: "**make tests**". **Observação:** A forma como o jogo foi feita faz com que poucas funções tenham qualquer retorno, ele apenas navega de uma função a outra de acordo com o andamento do jogo. Por conta disso não foi possível incluir muitas possibilidades de testes.  
## FUNCIONAMENTO DO JOGO  
O jogo Lobisomem funciona da seguinte forma:
-  Os jogadores são divididos entre 4 papéis diferentes:
   - **Médico** : Pode uma vez por noite proteger um jogador do ataque do lobisomem.
   - **Vidente** : Pode uma vez por noite descobrir se um jogador é um lobisomem ou humano.
   - **Camponês** : Não possui nenhuma habilidade especial, deve apenas tentar sobreviver.
   - **Lobisomem** : Pode atacar um jogador por noite.

-  Toda rodada é dividida em duas fases: a noite e o dia.
   - **Noite**: Os jogadores podem realizar ações relacionadas aos seus papéis, porém não é permitido que eles se comuniquem entre si.
   - **Dia**:  É aberto um momento de discussão onde os jogadores tentam descobrir quem é o lobisomem. A partir dessa discurssão é realizada uma votação que determina qual jogador deve ser eliminado do jogo. Em caso de empate nos votos ninguém é eliminado.

-  O objetivo dos humanos é eliminar todos os lobisomens.
-  O objetivo dos lobisomens é eliminar todos os humanos.
-  O jogo termina no momento em que um dos grupos atinge seu objetivo.  

## CLASSES DO PROGRAMA  
A documentação do programa está toda presente aqui e nos próprios arquivos de código. Ela não foi feita via Doxygen por conta de problemas e dificuldades na instalação do mesmo, porém buscamos seguir o mesmo modelo de documentação, detalhando ao máximo cada detalhe e deixando clara a funcionalidade do programa por inteiro.  
### Config:  
Responsável por armazenar as informações essenciais para o jogo, como o número de jogadores e papéis e a organização dos mesmos em listas.
#### Funções:  
##### addUsuario:  
Adiciona um usuario ao jogo.  
Recebe: string nome  
Retorna: Nada
##### embaralhaArr:  
Embaralha os papéis para que depois sejam sorteados entre os jogadores.  
Recebe: string *arr, int size  
Retorna: Nada
##### Config:  
Construtor da classe config, definindo o número de papeis de quais papéis existem.  
Recebe: Nada  
Retorna: Nada
##### setListaUsuarios:  
Determina quais serão todos os jogadores organizando-os em uma lista.  
Recebe: Nada  
Retorna: Nada
##### setListaPapeis:  
Determina quais serão os papéis de todos os jogadores organizando-os em uma lista.  
Recebe: Nada  
Retorna: Nada
##### setListaJogadores:  
Organiza os papéis para cada jogador, aleatorizando qual jogador fica com cada papel a cada jogo.  
Recebe: Nada  
Retorna: Nada
##### mostraPapeisJogadores:  
Como o nome indica, mostra o papel de cada jogador.  
Recebe: Nada  
Retorna: Nada
##### run:  
Função para rodar o jogo inicialmente. Ela possúi o menu inicial onde o jogador pode escolher entre configurar o jogo, iniciá-lo ou sair. O jogador apenas consegue iniciar o jogo quando o mesmo está configurado.  
Recebe: Nada  
Retorna: Nada
##### setJogo:  
Configura o jogo, definindo os jogadores e seus papéis.  
Recebe: Nada  
Retorna: Nada
##### iniciaJogo:  
Finaliza as configurações do jogo e inicia o mesmo.  
Recebe: Nada  
Retorna: Nada

### Jogador:  
Responsável por armazenar as informações sobre cada jogador (nome e papel).
#### Funções:  
##### Jogador:  
Construtor vazio para jogador.    
Recebe: Nada  
Retorna: Nada
##### Jogador:  
Construtor para um novo jogador fornecendo seu nome e papel.  
Recebe: string nome, string Papel  
Retorna: Nada
##### mostrarPapelJogador:  
Mostra o nome do jogador e o papel destinado a ele.  
Recebe: Nada  
Retorna: Nada
##### votar:  
Função utilizada em todas as rodadas como sistema de escolha e votação. Durante o dia é utilizada para a votação geral. Durante a noite é utilizada para que os jogadores realizem as ações relacionadas a seu papel.  
Recebe: Nada  
Retorna:  
##### getNome:  
Getter para o nome do jogador.  
Recebe: Nada  
Retorna: string nome  
##### getPapel:  
Getter para o papel do jogador.  
Recebe: Nada  
Retorna: string Papel  

### Jogo:  
Responsável por armazenar as informações essenciais para o jogo, como o número de jogadores e papéis e a organização dos mesmos em listas.
#### Funções:  
##### Dia:  
Função que agrupa os eventos que acontecem durante o dia no jogo, ou seja a votação geral.  
Recebe: Nada  
Retorna: Nada
##### Noite:  
Função que agrupa os eventos que acontecem durante a noite no jogo, ou seja a ação de cada jogador de acordo com seu papel.  
Recebe: Nada  
Retorna: Nada
##### mostraListaVotos:  
Mostra a lista contendo as opções de escolha em todas as rodadas.  
Recebe: Nada  
Retorna: Nada
##### mostraResultadoVotos:  
Mostra se algum jogador foi eliminado tanto na votação do dia quanto no período da noite por conta do lobisomem.  
Recebe: int deadJogadorKey  
Retorna: Nada
##### removeJogadorMorto:  
Elimina o jogador morto do jogo.  
Recebe: int deadJogadorKey  
Retorna: Nada
##### checaFimDeJogo:  
Detecta se o jogo chegou ao fim. Os critérios para isso são: Todos os lobisomens estão mortos. Garantindo vitória dos humanos; Apenas um ou nenhum humano restante. Garantindo vitória dos lobisomens.  
Recebe: Nada  
Retorna: Nada
##### Jogo:  
Construtor vazio para jogo.  
Recebe: Nada  
Retorna: Nada
##### Jogo:  
Construtor para o jogo a partir da lista e numero de jogadores.  
Recebe: Jogador *listaJogadores, int numJogadores  
Retorna: Nada
##### play:  
Função que dá início ao jogo.  
Recebe: Nada  
Retorna: Nada

## USER STORIES  
-  Como jogador, quero que o jogo possa ser jogado em um único dispositivo, não necessitando de conexão com internet ou vários dispositivos com o mesmo jogo.  
   - **Critérios de aceite:**
     - O jogo funciona sem necessidade de outros dispositivos.  
  
-  Como jogador, quero que os papéis dos jogadores sejam revelados apenas ao próprio jogador para forçar os jogadores a tentarem descobrir informações sobre os outros. 
   - **Critérios de aceite:**
     - Implementação de sistema de rodadas onde o jogo informa quando é a jogada de cada jogador;
     - Limpeza de tela ao fim da jogada de cada jogador.   
  
-  Como jogador, quero que o jogo seja capaz de sortear os papéis entre os jogadores no início da rodada para decidir qual o objetivo de cada um.    
   -  **Critérios de aceite:**
      - Desenvolvimento dos diferentes papéis disponíveis;
      - Função que sorteia os papéis para cada jogador, associando-os em uma lista.  
  
-  Como jogador, quero que haja um momento de discussão durante o jogo para tentar descobrir os papéis dos outros jogadores e introduzir estratégia ao jogo.  
   -  **Critérios de aceite:**
      - Função que detecta quando todos os jogadores já realizaram sua jogada;  
  
-  Como jogador, quero que tenham momentos de votação no jogo para realizar a escolha de qual jogador deve ser eliminado de acordo com a suspeita da maioria.  
   -  **Critérios de aceite:**
      - Organização em uma lista dos jogadores presentes no jogo;
      - Função para eliminar o jogador escolhido do jogo.  
  
-  Como jogador, quero que o jogo termine automaticamente quando os critérios para terminar forem atingidos, determinando também qual foi o grupo vencedor.  
   - **Critérios de aceite:**
     - Detectar ao fim de cada rodada se restam assassinos, caso a resposta seja não, finalizar o jogo e informar que os inocentes ganharam;  
     - Detectar ao fim de cada rodada se restam mias de um inocentes, caso a resposta seja não, finalizar o jogo e informar que os assassinos ganharam;
