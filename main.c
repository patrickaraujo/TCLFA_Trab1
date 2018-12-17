#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
*   @author Patrick Araújo: https://github.com/patrickaraujo
*   Trabalho 1 de Teoria da Computação, Linguagens Formais e Autômatos
*/

int scanner(char *x){
    int i = 0;
    char c;


    q0: c = x[i];
    if(c == 'a'){
        i++;
        goto q0;
    }
    else if(c == 'b'){
        i++;
        goto q1;
        //  return scanner2(x);
    }
    else return 0;


    q1: c = x[i];
    //  if(c == 'a' || c == 'b'){
    if(c == 'b'){
        i++;
        goto q2;
    }
    else if (c == 'a'){
        i++;
        goto q3;
        //  return scanner2(x);
    }
    else return 0;


    q2: c = x[i];
    if(c == 'b'){
        i++;
        goto q4;
    }
    else if(c == 'a'){
        i++;
        goto q5;
    }
    else return 0;


    q3: c = x[i];
    if(c == 'b'){
        i++;
        goto q6;
    }
    else if(c == 'a'){
        i++;
        goto q7;
    }
    else return 0;


    q4: c = x[i];
    if( !c )
        return 1;
    else if( c == 'b'){
        i++;
        goto q4;
    }
    else if( c == 'a'){
        i++;
        goto q5;
    }
    else return 0;


    q5: c = x[i];
    if( !c )
        return 1;
    else if( c == 'b'){
        i++;
        goto q6;
    }
    else if( c == 'a'){
        i++;
        goto q7;
    }
    else return 0;


    q6: c = x[i];
    if( !c )
        return 1;
    else if( c == 'b'){
        i++;
        goto q2;
    }
    else if( c == 'a'){
        i++;
        goto q3;
    }
    else return 0;


    q7: c = x[i];
    if( !c )
        return 1;
    else if( c == 'b'){
        i++;
        goto q1;
    }
    else if( c == 'a'){
        i++;
        goto q0;
    }
    else return 0;
}

char *EntraString(){
    fflush(stdin);
    char tecla;
    char *retorno=NULL;
    int tam=0;
    do {
        tecla=getchar();
        if(!retorno)
            retorno=(char*)malloc(sizeof(char));
        else
            retorno=(char*)realloc(retorno,tam+1);
        if(tecla != '\n')
            retorno[tam]=tecla;
        tam++;
    } while(tecla!='\n');
    retorno[tam-1]='\0';
    return retorno;
}

int main(){
    printf("\nEntre com a palavra:\t");
    char *palavra = EntraString();
    if(scanner(palavra))
        printf("\nPalavra reconhecida");
    else
        printf("\nPalavra nao reconhecida");
    return 0;
}
