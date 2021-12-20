int        print_number(unsigned long num, int base, int is_capital)
{
        char                buf[MAX_BUF];
        char                *p;
        const char        digs[] = "0123456789abcdef0123456789ABCDEF";
        int                        len;

        p = &buf[MAX_BUF - 1];
        *p-- = digs[num % base + 16 * is_capital];
        while (num / base != 0)
        {
                num /= base;
                *p-- = digs[num % base + 16 * is_capital];
        }
        len = &buf[MAX_BUF - 1] - p;
        while (++p != &buf[MAX_BUF])
        {
                if (ft_putchar_fd(*p, 1) == -1)
                        return (-1);
        }
        return (len);
}
