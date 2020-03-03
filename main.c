#include "libftprintf/includes/ft_printf.h"

int main ()
{
    char *zob = "zob";
    ft_printf("%zu--%s--\n", ft_strlen(zob), zob);
    return (0);
}