char        *ft_convert_base(size_t nbr, char *base)
{
    size_t  base_num;
    size_t        digit;
    size_t  tmp;
    char        *nbr_c;
    
    base_num = ft_strlen(base);
    digit = 0;
    tmp = nbr;
    if (nbr == 0)
        digit = 1;
    while (tmp != 0)
    {
        tmp /= base_num;
        digit ++;
    }
    nbr_c = (char *)malloc(sizeof(*base) * (digit + 1));
    if (!nbr_c)
        return (NULL);
    nbr_c[digit] = '\0';
    while (digit --)
    {
        nbr_c[digit] = base[nbr % base_num];
        nbr /= base_num; 
    }
    return (nbr_c);
}
