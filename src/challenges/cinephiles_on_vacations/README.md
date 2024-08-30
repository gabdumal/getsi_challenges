# Cinéfilos de Férias

Um grupo de amigos tem uma tradição de assistir a filmes juntos, sempre que possível.
No período de férias, eles decidiram fazer uma maratona de filmes, assistindo a vários por dia.

Para incentivar a interação entre os amigos, eles decidiram que, ao final de cada filme, eles deveriam atribuir uma nota de **1 a 5** para cada uma das categorias: **enredo**, **atuação**, **direção**, **trilha sonora** e **efeitos especiais**.

Para evitar que fossem influenciados uns pelos outros, cada amigo escreveu suas notas em um papel, que foi depositado em uma **urna**.

Apesar de estarem de férias, os amigos são bastante ocupados e, por isso, não assistiram aos filmes todos juntos.
Então, alguns filmes receberam **mais notas** do que outros.

Ao final, eles perceberam que seriam muito trabalhoso calcular a **média de cada categoria** para cada filme.
Até porque foram tantos, que eles nem se lembravam mais a quantidade exata que assistiram.
Por isso, eles pediram a sua ajuda para automatizar esse processo.

## Entrada

A entrada é composta por $N$ $(1 \leq N \leq 10^3)$ linhas.

Cada uma delas contém uma string $S$, que representa o **nome do filme**, e $5$ inteiros, $E$, $A$, $D$, $T$ e $S$ $(1 \leq E, A, D, T, S \leq 5)$, representando as notas de **enredo**, **atuação**, **direção**, **trilha sonora** e **efeitos especiais**, respectivamente.

## Saída

A saída é composta por $M$ linhas.

Cada linha contém o nome de um filme e a média das notas de *enredo*, *atuação*, *direção*, *trilha sonora* e *efeitos especiais*, com ***uma casa decimal***.
As médias devem ser **arredondadas para cima**.

## Exemplo

### Entrada

```
O_Poderoso_Chefao 5 5 5 5 5
Titanic 5 4 5 4 5
O_Rei_Leao 5 5 5 5 5
O_Poderoso_Chefao 5 3 5 4 5
O_Poderoso_Chefao 5 5 5 5 5
Titanic 5 5 5 5 5
E_o_Vento_Levou 5 3 5 5 5
```

### Saída

```
O_Poderoso_Chefao 5.0 4.3 5.0 4.7 5.0
Titanic 5.0 4.7 5.0 4.7 5.0
O_Rei_Leao 5.0 5.0 5.0 5.0 5.0
E_o_Vento_Levou 5.0 3.0 5.0 5.0 5.0
```

### Observações

No exemplo, o filme *O Poderoso Chefão* foi assistido 3 vezes, recebendo notas diferentes.
A média das notas de *enredo* foi $5.0$, a de *atuação* foi $4.3$, a de *direção* foi $5.0$, a de *trilha sonora* foi $4.7$ e a de *efeitos especiais* foi $5.0$.
