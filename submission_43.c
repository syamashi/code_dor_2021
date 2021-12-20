int        print_str(char *s, t_format *flags, int freecheck)
{
        int                i;
        char        *sstr;
        int                sstrlen;
        int                slen;

        s = (!s) ? "(null)" : s;
        if (flags->conversion == 's' && flags->zerof == '0' && flags->hyphf == '-')
                flags->zerof = 0;
        slen = flags->conversion == 'c' ? 1 : ft_strlen(s);
        if (!(flags->prec < 0 || slen < flags->prec || flags->precsw == -1))
                slen = flags->prec;
        i = 0;
        sstrlen = slen < flags->width ? flags->width - slen : 0;
        if (!(sstr = (char *)malloc(sizeof(char) * sstrlen + 1)))
                return (-1);
        while (i < sstrlen)
                sstr[i++] = flags->zerof == '0' ? '0' : ' ';
        write(1, sstr, flags->hyphf == '-' || flags->hyphf == '-' ? 0 : i);
        write(1, s, slen);
        write(1, sstr, flags->hyphf == '-' || flags->hyphf == '-' ? i : 0);
        free(sstr);
        if (freecheck == 1)
                free(s);
        return (slen + i);
}
