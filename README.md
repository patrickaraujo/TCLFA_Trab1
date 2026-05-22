# Trabalho 1 de TCLFA (Teoria da computação, linguagens formais e autômatos) - AFD em C

Este projeto implementa, em linguagem C, um Autômato Finito Determinístico capaz de reconhecer palavras formadas pelos símbolos `a` e `b`.

O programa aceita apenas palavras em que o antepenúltimo símbolo seja `b`.

## Objetivo

Implementar computacionalmente um reconhecedor para a linguagem composta por palavras sobre o alfabeto `{a,b}` nas quais o antepenúltimo símbolo é `b`.

Exemplos de palavras aceitas:

```txt
baa
bab
bba
bbb
baaa
bbab
````

Exemplos de palavras rejeitadas:

```txt
a
b
ab
aa
aba
abb
aaa
```

## Como funciona

O programa simula um AFD que acompanha os últimos símbolos lidos da palavra.

Como o critério de aceitação depende do antepenúltimo símbolo, o autômato precisa manter informação suficiente sobre os três últimos símbolos processados.

Ao final da leitura, a palavra é aceita se o antepenúltimo símbolo for `b`.

## Estados do AFD

Os estados representam os últimos símbolos lidos até o momento.

Por exemplo:

```txt
Q0    -> nenhum símbolo lido
QA    -> último símbolo lido foi a
QB    -> último símbolo lido foi b
QBAA  -> últimos três símbolos são baa
QBAB  -> últimos três símbolos são bab
QBBA  -> últimos três símbolos são bba
QBBB  -> últimos três símbolos são bbb
```

Os estados finais são aqueles em que os últimos três símbolos começam com `b`:

```txt
QBAA
QBAB
QBBA
QBBB
```

Isso significa que o antepenúltimo símbolo da palavra é `b`.

## Função de transição

A função de transição do AFD recebe:

```txt
estado atual
símbolo lido
```

E retorna o próximo estado.

No código, essa função é implementada como:

```c
Estado delta(Estado q, char simbolo)
```

Essa função representa a transição simples do autômato.

## Função de transição estendida

A função de transição estendida processa a palavra inteira, símbolo por símbolo.

No código, ela é implementada como:

```c
Estado deltaEstendida(Estado q, char palavra[], int tamanho)
```

Ela segue a definição estudada em sala:

1. Se a palavra estiver vazia, o estado atual é mantido.
2. Caso contrário, a função processa a palavra até o penúltimo símbolo e depois aplica a transição ao último símbolo.

## Validação da entrada

O programa também verifica se a palavra digitada contém apenas os símbolos permitidos:

```txt
a
b
```

Caso outro caractere seja digitado, a palavra é considerada inválida.

## Como compilar

Use o `gcc`:

```bash
gcc trabalho1.c -o trabalho1
```

## Como executar

```bash
./trabalho1
```

Depois, digite uma palavra formada apenas por `a` e `b`.

Exemplo:

```txt
Digite uma palavra sobre {a,b}: baa
Palavra ACEITA.
```

Outro exemplo:

```txt
Digite uma palavra sobre {a,b}: aba
Palavra REJEITADA.
```

## Estrutura principal do código

O código contém:

```txt
1. Definição dos estados do AFD
2. Função de transição delta
3. Função de transição estendida
4. Verificação dos estados finais
5. Validação da palavra de entrada
6. Função main para entrada e saída
```

## Autor

Trabalho desenvolvido para a disciplina de Teoria da Computação, Linguagens Formais e Autômatos.

```
```
