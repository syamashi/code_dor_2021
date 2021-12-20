short        ft_puthex(unsigned int hex, char frmat)
{
        short        count;

        count = 0;
        if (hex >= 16)
                count = ft_puthex(hex / 16, frmat);
        hex %= 16;
        if (hex >= 10 && frmat == 'X')
        {
                hex += 'A' - 10;
                write(1, &hex, 1);
        }
        else if (hex >= 10 && frmat == 'x')
        {
                hex += 'a' - 10;
                write(1, &hex, 1);
        }
        else
        {
                hex += '0';
                write(1, &hex, 1);
        }
        return (count + 1);
}
