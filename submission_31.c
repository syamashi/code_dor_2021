void         ft_put_unsigned_base(unsigned u, char *digit)
{
        unsigned        exp;
        const size_t        base = ft_strlen(digit);

        if (b < 2)
                return ;
        exp = 1;
        while (u / exp >= base)
                exp *= base;
        while (exp > 0)
        {
                ft_putchar_fd(digit[u / exp % base], fd);
                exp /= base;
        }
}

