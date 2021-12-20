void        ft_putnbr_len(long n, unsigned long radix, int *len)
{
        unsigned long        ans;

        if (n < 0)
        {
                ft_putchar('-', len);
                ans = (unsigned long)(n * -1);
        }
        else
                ans = (unsigned long)n;
        if (ans >= radix)
                ft_putnbr_len(ans / radix, radix, len);
        if ((ans % radix) >= 10)
                ft_putchar((ans % radix) - 10 + 'a', len);
        else
                ft_putchar((ans % radix + '0'), len);
        return ;
}
