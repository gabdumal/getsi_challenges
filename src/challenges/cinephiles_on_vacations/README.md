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

A entrada é composta por duas partes.

A primeira parte contém um inteiro $N$ $(1 \leq N \leq 10^3)$, representando a quantidade de **notas depositadas** na urna.

A segunda parte contém $N$ linhas, cada uma das notas.
Cada linha se forma por uma string $S$, que representa o **nome do filme**, e $5$ inteiros, $E$, $A$, $D$, $T$ e $S$ $(1 \leq E, A, D, T, S \leq 5)$, representando as notas de **enredo**, **atuação**, **direção**, **trilha sonora** e **efeitos especiais**, respectivamente.

## Saída

A saída é composta por $M$ linhas.

Cada linha contém o nome de um filme e a média das notas de _enredo_, _atuação_, _direção_, _trilha sonora_ e _efeitos especiais_, com **_uma casa decimal_**.
As médias devem ter **duas** casas decimais.

## Exemplos

<link rel="stylesheet" type="text/css" href="../../style.css">

<table>
    <thead>
        <tr>
            <th>Entrada</th>
            <th>Saída</th>
        </tr>
    </thead>
    <tbody>
        <tr class="entry-opening">
            <td colspan="2">Exemplo 1</td>
        </tr>
        <tr>
            <td>7</td>
            <td>
                E_o_Vento_Levou 5.00 3.00 5.00 5.00 5.00
            </td>
        </tr>
        <tr>
            <td>
                O_Poderoso_Chefao 5 5 5 5 5
            </td>
            <td>
                O_Rei_Leao 5.00 5.00 5.00 5.00 5.00
            </td>
        </tr>
        <tr>
            <td>
                Titanic 5 4 5 4 5
            </td>
            <td>
                Titanic 5.00 4.50 5.00 4.50 5.00
            </td>
        </tr>
        <tr>
            <td>
               O_Rei_Leao 5 5 5 5 5
            </td>
            <td>
               O_Poderoso_Chefao 5.00 4.33 5.00 4.66 5.00
            </td>
        </tr>
        <tr>
            <td>
                O_Poderoso_Chefao 5 3 5 4 5
            </td>
        </tr>
        <tr>
            <td>
                O_Poderoso_Chefao 5 5 5 5 5
            </td>
        </tr>
        <tr>
            <td>
                Titanic 5 5 5 5 5
            </td>
        </tr>
        <tr class="last-entry">
            <td>
                E_o_Vento_Levou 5 3 5 5 5
            </td>
        </tr>
    </tbody>

</table>

### Observações

No exemplo, o filme _O Poderoso Chefão_ foi assistido 3 vezes, recebendo notas diferentes.
A média das notas de _enredo_ foi $5.0$, a de _atuação_ foi $4.33$, a de _direção_ foi $5.0$, a de _trilha sonora_ foi $4.66$ e a de _efeitos especiais_ foi $5.0$.
