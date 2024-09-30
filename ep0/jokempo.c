#include <stdio.h>
#include <stdlib.h>

// 0 = pedra    1 = papel   2 = tesoura
int main()
{
    int escolha1, escolha2;

    printf("\n****Ladies and gentlemants, aqui vos apresento o JOKEMPOOOOO****\n\n");
    printf("-----Usuario 1, anote aqui sua escolha!!!-----\n");
    scanf("%d", &escolha1);
    printf("\n-----Usuario 2, anote aqui sua escolha!!!-----\n");
    scanf("%d", &escolha2);
    printf("\n\n");
    
    if (((escolha1 == 0) && (escolha2 == 0)) || ((escolha1 == 1) && (escolha2 == 1)) || ((escolha1 == 2) && (escolha2 == 2))){
        printf("empate\n\n");
    }
    else if (((escolha1 == 0) && (escolha2 == 1)) || ((escolha1 == 1) && (escolha2 == 2)) || ((escolha1 == 2) && (escolha2 == 0))){
        printf("Usuario 2 vence\n\n");
    }
    else if (((escolha1 == 0) && (escolha2 == 2)) || ((escolha1 == 1) && (escolha2 == 0)) || ((escolha1 == 2) && (escolha2 == 1))){
        printf("Usuario 1 vence \n\n");
    }
    system("pause");
    return 0;
}