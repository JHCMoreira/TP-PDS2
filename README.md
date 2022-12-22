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
De forma semelhante à compilação, para analisar os testes de unidade basta executar via terminal o comando: "**make tests**".  
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
