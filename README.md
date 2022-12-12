**TEMA: Jogo no estilo de Cidade Dorme (também bastante conhecido como Lobisomem ou Máfia)**
https://pt.wikipedia.org/wiki/Cidade_dorme 

Integrantes do grupo:  
- Gabriel Vitor Antunes Carvalho;  
- João Henrique Costa Moreira;  
- João Márcio Calazans Britto;  
- João Victor Souza de Andrade;  

**USER STORIES:**
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
      - Desenvolvimento de um timer para o tempo de discussão.  
  
-  Como jogador, quero que tenham momentos de votação no jogo para realizar a escolha de qual jogador deve ser eliminado de acordo com a suspeita da maioria.  
   -  **Critérios de aceite:**
      - Organização em uma lista dos jogadores presentes no jogo;
      - Função para eliminar o jogador escolhido do jogo.  
  
-  Como jogador, quero que o jogo termine automaticamente quando os critérios para terminar forem atingidos, determinando também qual foi o grupo vencedor.  
   - **Critérios de aceite:**
     - Detectar ao fim de cada rodada se restam assassinos, caso a resposta seja não, finalizar o jogo e informar que os inocentes ganharam;  
     - Determinar razão máxima de assassinos para inocentes;
     - Verificar se a razão de assassinos para inocentes na partida é maior do que a pré-estabelecida, caso a resposta seja sim, finalizar o jogo e informar que os assassinos ganharam.  
