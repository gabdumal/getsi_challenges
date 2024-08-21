# Filas Preferenciais

A loja de artigos de costura _Pequeno Alfinete_ oferece produtos de qualidade a baixos preços.
Por esse motivo, ela é bastante frequentada por diferentes clientes.
Infelizmente, por ser um pequeno negócio, a loja conta com apenas um caixa.

Curiosamente, uma parte significativa da clientela são senhoras da melhor idade, que não devem enfrentar longas esperas.
Por isso, a loja decidiu estabelecer três diferentes filas: a **regular**, a **preferencial**, e a **urgente**.

O funcionamento das filas é o seguinte:

- A fila **urgente** se destina a clientes com 80 anos ou mais. Ela é atendida em primeiro lugar, sempre que houver alguém nela.
- A fila **preferencial** é destinada a clientes com idade entre 60 e 79 anos. Ela será atendida sempre que não houver ninguém na fila **urgente**.
- A fila **regular** é destinada a todos os outros clientes. Ela é a última a ser atendida.

Cada cliente gasta um tempo diferente no caixa, que varia entre 3 e 10 minutos.
Inicialmente, as filas estão vazias.
Com o passar do dia, clientes chegam à loja e se dirigem a uma delas, de acordo com sua idade.

Para verificar se a política de prioridade tem sido efetiva, o gerente deseja saber, ao final de um turno, qual foi a ordem de atendimento dos clientes, representada por suas categorias.

## Entrada

A entrada é composta por duas partes.

A primeira linha contém um inteiro $N$ $(1 \leq N \leq 10^3)$, representando o **número de clientes** que chegaram à loja.

As demais $N$ linhas contêm, cada uma, separado por espaços, os seguintes valores:

- um inteiro $I$ $(16 \leq I \leq 100)$, representando a **idade** do cliente;
- um inteiro $C$ $(0 \leq C \leq 180)$, representando o **momento de chegada** do cliente (em minutos, a partir de 0);
- um inteiro $T$ $(3 \leq T \leq 10)$, representando o **tempo de atendimento** do cliente.

## Saída

A saída é composta por 1 linha, contendo $N$ caracteres, representando a ordem de atendimento dos clientes, de acordo com as categorias **urgente** (U), **preferencial** (P) e **regular** (R).
