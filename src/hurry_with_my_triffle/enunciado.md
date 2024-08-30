# Pressa com meu pavê

Alice marcou de se encontrar com seus amigos no clube para um piquenique.
Cada um deles combinou de levar um lanche ou sobremesa para compartilhar.

Ela, que é uma ótima confeiteira, decidiu preparar um pavê de limão com cobertura de chocolate, o qual sabia que seria um sucesso.
Alice fez a receita com muito carinho mas, ao começar a se arrumar para sair, percebeu que o pavê não poderia ficar fora da geladeira por muito **tempo**!

Felizmente, o clube dispõe de um freezer no local, onde poderia deixar o pavê uma vez que chegasse.
Entretanto ela mora longe de lá e precisa pegar alguma **linha de ônibus**, os quais costumam demorar bastante.

O aplicativo de transporte público informa que há $N$ linhas de ônibus disponíveis, numeradas de 1 a $N$.
Cada linha faz um trajeto **circular**, passando por diferentes pontos da cidade cada uma, de forma que o tempo de viagem entre cada parada é variável.
Em todas elas, Alice chegará ao clube, mesmo que tenha que dar a volta pelo ponto final primeiro.

Segundo o aplicativo, a parada mais próxima à sua **casa** tem o identificador **7**.
Já a parada do **clube** tem o identificador **29**.
Sabendo disso, Alice deseja descobrir qual é a rota de ônibus que a levará o **menor** tempo rodando pela cidade até chegar ao clube, para que seu pavê não derreta no caminho.

## Entrada

A entrada é composta por duas partes.

A primeira linha contém um inteiro $N$ $(1 \leq N \leq 10^3)$, representando o **número de linhas de ônibus** disponíveis passando pela casa de Alice.

A segunda parte da entrada contém $N$ linhas, cada uma descrevendo uma linha de ônibus.
As linhas são circulares, ou seja, se o ônibus chega ao ponto final, ele continua a viagem a partir do ponto inicial.

Cada linha começa com um inteiro $L$ $(1 \leq L \leq 10^3)$, representando o **número da linha**.\
Em seguida, são dados $M$ $(2 \leq M \leq 10^3)$ pares de inteiros $I$ e $T$ $(1 \leq I \leq 10^3, 1 \leq T \leq 10^3)$, representando o **identificador do ponto** e o **tempo de viagem** até o próximo ponto, respectivamente.
Cada par estará cercado por parênteses e separado por um espaço.

O primeiro par de inteiros de cada linha representa o ponto inicial da linha, e o último par representa o ponto final.

## Saída

Seu programa deve imprimir uma **única** linha, contendo o **número** da linha de ônibus que levará Alice ao clube no menor tempo possível, seguido do **tempo** total de viagem, em minutos.

Caso haja mais de uma linha com o mesmo tempo mínimo, imprima a linha que apareceu primeiro na entrada.

## Exemplos

//TODO: Adicionar exemplos

<table>
    <thead>
        <tr>
            <th>Entrada</th>
            <th>Saída</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>3</td>
            <td>2 12</td>
        </tr>
        <tr>
            <td>
                1 (2 5) (7 6) (8 5) (9 10) (10 7) (29 9) (3 7) (12 4)
            </td>
        </tr>
        <tr>
            <td>
                2 (5 9) (7 5) (8 3) (9 4) (29 5) (14 7)
            </td>
        </tr>
        <tr>
            <td class="last-entry">
                3 (7 4) (8 4) (9 5) (29 6) (14 7)
            </td>
        </tr>
        <tr>
            <td>5</td>
            <td></td>
        </tr>
        <tr>
            <td>
                1 (3 6) (29 5) (6 8) (11 5) (13 9) (15 7) (20 10) (7 8) (25 6) (30 4)
            </td>
        </tr>
        <tr>
            <td>
                2 (4 8) (6 7) (11 4) (13 6) (20 5) (25 9)
            </td>
        </tr>
        <tr>
            <td>
                3 (6 5) (29 2) (11 3) (8 6) (7 8) (25 6)
            </td>
        </tr>
        <tr>
            <td>
                4 (29 4) (11 6) (13 5) (15 7) (20 8) (25 6) (7 5)
            </td>
        </tr>
        <tr>
            <td class="last-entry">
                5 (7 4) (11 5) (13 7) (15 8) (20 6) (25 5) (29 6)
            </td>
        </tr>
    </tbody>
</table>

### Observações

No **primeiro exemplo**, a linha 2 é a que levará Alice ao clube no menor tempo possível, com um tempo total de 12 minutos.

No **segundo exemplo**, a linha

<link defer rel="stylesheet" type="text/css" href="../style.css">
