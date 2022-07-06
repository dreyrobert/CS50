#include <stdio.h>
#include <cs50.h>

bool verify_trian(int n1, int n2, int n3);

int main(void)
{
    int x = get_int("Cateto: ");
    int y = get_int("Cateto: ");
    int z = get_int("Hipotenusa: ");
    bool valid = verify_trian(x, y, z);
    if (valid)
    {
        printf("TRUE!\n");
    }
    else
    {
        printf("FALSE!\n");
    }
}

bool verify_trian(int x, int y, int z)
{
    if (x <= 0 || y <= 0 || z <= 0)
    {
        return false;
    }

    if ((x + y <= z) || (x + z) <= y || (y + z) <= x)
    {
        return false;
    }
    return true;
}