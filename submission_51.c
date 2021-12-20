#include <stdlib.h>
#include <limits.h>

unsigned long long int  ft_strtollu(char *str)
{
        unsigned long long int        n_llu;
        size_t                                        i;

        n_llu = 0;
        i = 0;
        while ('0' <= *(str + i) && *(str + i) <= '9' && i < 19)
                n_llu = n_llu * 10 + *(str + i++) - '0';
        if ('0' <= *(str + i) && *(str + i) <= '9')
        {
                if (n_llu > ULLONG_MAX / 10)
                        n_llu = ULLONG_MAX;
                else
                        n_llu = n_llu * 10 + *(str + i) - '0';
        }
        return (n_llu);
}

