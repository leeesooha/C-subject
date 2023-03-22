#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int     sh_re;
    int     re;

    sh_re = ft_printf("asdf");
    printf("\nsh_return value : %d\n", sh_re);
    re = printf("asdf");
    printf("\nreturn value : %d\n", re);
    return (0);
}