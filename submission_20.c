int        ft_atoi(const char *str)
{
        long        ret;
        int                sign;

        sign = 1;
        ret = 0;
        while (('\t' <= *str && *str <= '\r') || *str == ' ')
                str++;
        if (*str == '+' || *str == '-')
                sign = 44 - *(str++);
        while ('0' <= *str && *str <= '9')
        {
                if (ret > (LONG_MAX - (*str - '0')) / 10)
                {
                        if (sign > 0)
                                return ((int)LONG_MAX);
                        else
                                return ((int)LONG_MIN);
                }
                ret = ret * 10 + (*str - '0');
                str++;
        }
        return (ret * sign);
}
