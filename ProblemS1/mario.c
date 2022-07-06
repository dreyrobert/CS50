#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // criei as variaveis
    int height, line, columm, j;
    // pergunta ao usuário o tamanho da altura
    do
    {
        height = get_int("Height: ");
    }
    // Ele vai perguntar novamente ao usuário se o input for menor do que 0 ou maior do que 9
    while (height < 1 || height > 8);
    // repetir o codigo para quando a linha for menor que a altura
    for (line = 0; line < height; line++)
    {
        // se j for menor que altura-linha-1, então printa espaço
        for (j = 0; j < height - line - 1; j++)
        {
            printf(" ");
        }
        // se a coluna for menor ou igual a linha, ele printa #, sabendo q (coluna e j são iguais)
        for (columm = 0; columm <= line; columm++)
        {
            printf("#");
        }
        // espaço para separar as duas partes de piramide
        printf("  ");
        // se a coluna for menor ou igual que a linha, ele printa #
        for (columm = 0; columm <= line; columm++)
        {
            printf("#");
        }
        printf("\n");
    }
}