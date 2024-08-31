# Desafios de programação do GetSi

Cada desafio contém o enunciado em um arquivo README.md.
Ele descreve o problema, e apresenta o formato esperado de entrada e saída.

Para facilitar, este projeto contém métodos para executar os testes dos desafios automaticamente.
Alguns desafios disponibilizam os dados da entrada de forma parcialmente processada, como na estrutura de dados `vector` da STL do C++.
Em alguns desafios, são fornecidas `structs` para facilitar a organização dos dados.

Todas as entradas são `strings` e podem ser lidas de várias formas.
Alguns métodos que você pode usar para ler as entradas são:

```c++
#include <iostream>
#include <string>

...

/* Lendo uma linha do teclado */
std::string input;
std::getline(std::cin, input);

/* Lendo uma linha de um arquivo */
std::ifstream file("input.txt");
std::string input;
std::getline(file, input);

/* Lendo uma linha de uma sequência de caracteres */
std::string input = "123 456 789";
std::string first, second, third;
//
size_t separator_index = input.find(' '); // Encontra o primeiro espaço
first = input.substr(0, separator_index); // Pega a substring até o primeiro espaço
input = input.substr(separator_index + 1); // Atualiza a entrada para cortar a parte já lida
//
separator_index = input.find(' '); // Encontra o próximo espaço
second = input.substr(0, separator_index);
input = input.substr(separator_index + 1);
third = input; // Pega o restante da string

```

Alguns exemplos de manipulações da estrutura de dados `vector`:

```c++
#include <iostream>
#include <vector>

...

/* Lendo uma linha de strings */
std::string text = "abc, def, ghi, jkl, mno";
std::vector<string> words;
std::string separator = ", ";
size_t start = 0;
size_t end = text.find(separator); // Primeira ocorrência do separador
while (end != std::string::npos)
{
    std::string word = text.substr(start, end - start); // Separa a palavra
    words.push_back(word); // Adiciona a palavra ao vetor
    start = end + separator.length(); // Atualiza o início
    end = text.find(separator, start); // Atualiza o fim
}
words.push_back(text.substr(start)); // Última palavra

/* Lendo uma linha de inteiros */
std::string text = "1, 2, 3, 4, 5";
std::vector<int> numbers;
std::string separator = ", ";
size_t start = 0;
size_t end = text.find(separator); // Primeira ocorrência do separador
while (end != std::string::npos)
{
    int number = std::stoi(text.substr(start, end - start)); // Converte a substring para inteiro
    numbers.push_back(number); // Adiciona o número ao vetor
    start = end + separator.length(); // Atualiza o início
    end = text.find(separator, start); // Atualiza o fim
}
numbers.push_back(std::stoi(text.substr(start))); // Último número

/* Percorrendo um vetor de strings */
std::vector<std::string> words = {"abc", "def", "ghi", "jkl", "mno"};
for (std::string word : words) {
    std::cout << word << std::endl;
}

/* Percorrendo um vetor de inteiros */
std::vector<int> numbers = {1, 2, 3, 4, 5};
for (int number : numbers) {
    std::cout << number << std::endl;
}
```

Sinta-se livre para criar qualquer função ou `struct` que você achar necessário no arquivo `algorithm.cpp` referente ao desafio que você está resolvendo.

## Referências úteis

[GeeksForGeeks: Standard Template Library form C++](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/)

[GeeksForGeeks: Vector in C++ STL](https://www.geeksforgeeks.org/vector-in-cpp-stl/)

[GeeksForGeeks: Strings in C++](https://www.geeksforgeeks.org/strings-in-cpp/)

[GeeksForGeeks: Smart Pointers in C++](https://www.geeksforgeeks.org/smart-pointers-cpp/)

[GeeksForGeeks: Queue Data Structure](https://www.geeksforgeeks.org/queue-data-structure/)
