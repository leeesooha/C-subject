#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int     sh_re;
    int     re;

    sh_re = ft_printf("asdf");
    ft_printf("%k");
    re = printf("asdf");
    printf("\nreturn value : %d\n", re);
    return (0);
}