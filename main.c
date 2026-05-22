/**
*   @author Patrick Araújo: https://github.com/patrickaraujo
*   Trabalho 1 de Teoria da Computação, Linguagens Formais e Autômatos
*/

#include <stdio.h>
#include <string.h>

typedef enum {
    Q0,     // palavra vazia
    QA, QB,
    QAA, QAB, QBA, QBB,
    QAAA, QAAB, QABA, QABB, QBAA, QBAB, QBBA, QBBB
} Estado;

/*
 Função de transição do AFD.
 Ela guarda sempre os últimos até 3 símbolos lidos.
*/
Estado delta(Estado q, char simbolo) {
    switch (q) {
        case Q0:
            if (simbolo == 'a') return QA;
            if (simbolo == 'b') return QB;
            break;

        case QA:
            if (simbolo == 'a') return QAA;
            if (simbolo == 'b') return QAB;
            break;

        case QB:
            if (simbolo == 'a') return QBA;
            if (simbolo == 'b') return QBB;
            break;

        case QAA:
            if (simbolo == 'a') return QAAA;
            if (simbolo == 'b') return QAAB;
            break;

        case QAB:
            if (simbolo == 'a') return QABA;
            if (simbolo == 'b') return QABB;
            break;

        case QBA:
            if (simbolo == 'a') return QBAA;
            if (simbolo == 'b') return QBAB;
            break;

        case QBB:
            if (simbolo == 'a') return QBBA;
            if (simbolo == 'b') return QBBB;
            break;

        case QAAA:
            if (simbolo == 'a') return QAAA;
            if (simbolo == 'b') return QAAB;
            break;

        case QAAB:
            if (simbolo == 'a') return QABA;
            if (simbolo == 'b') return QABB;
            break;

        case QABA:
            if (simbolo == 'a') return QBAA;
            if (simbolo == 'b') return QBAB;
            break;

        case QABB:
            if (simbolo == 'a') return QBBA;
            if (simbolo == 'b') return QBBB;
            break;

        case QBAA:
            if (simbolo == 'a') return QAAA;
            if (simbolo == 'b') return QAAB;
            break;

        case QBAB:
            if (simbolo == 'a') return QABA;
            if (simbolo == 'b') return QABB;
            break;

        case QBBA:
            if (simbolo == 'a') return QBAA;
            if (simbolo == 'b') return QBAB;
            break;

        case QBBB:
            if (simbolo == 'a') return QBBA;
            if (simbolo == 'b') return QBBB;
            break;
    }

    return -1;
}

/*
 Função de transição estendida.
 Caso base: se o tamanho da palavra é 0, retorna o próprio estado.
 Caso indutivo: processa a palavra até o penúltimo símbolo
 e depois aplica delta ao último símbolo.
*/
Estado deltaEstendida(Estado q, char palavra[], int tamanho) {
    if (tamanho == 0) {
        return q;
    }

    Estado estadoAnterior = deltaEstendida(q, palavra, tamanho - 1);
    return delta(estadoAnterior, palavra[tamanho - 1]);
}

int estadoFinal(Estado q) {
    return q == QBAA || q == QBAB || q == QBBA || q == QBBB;
}

int palavraValida(char palavra[]) {
    for (int i = 0; palavra[i] != '\0'; i++) {
        if (palavra[i] != 'a' && palavra[i] != 'b') {
            return 0;
        }
    }

    return 1;
}

int main() {
    char palavra[100];

    printf("Digite uma palavra sobre {a,b}: ");
    fgets(palavra, sizeof(palavra), stdin);

    palavra[strcspn(palavra, "\n")] = '\0';

    if (!palavraValida(palavra)) {
        printf("Palavra invalida. Use apenas os simbolos 'a' e 'b'.\n");
        return 1;
    }

    Estado estadoFinalAFD = deltaEstendida(Q0, palavra, strlen(palavra));

    if (estadoFinal(estadoFinalAFD)) {
        printf("Palavra ACEITA.\n");
    } else {
        printf("Palavra REJEITADA.\n");
    }

    return 0;
}
