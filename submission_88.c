int        ft_printf(const char *format, ...)
{
        int                i;
        int                ret;
        va_list        ar;
        t_flags        flags;

        ret = 0;
        i = 0;
        va_start(ar, format);
        while (format[i] != '\0')
        {
                if (format[i] == '%')
                {
                        ft_init_flags(&flags);
                        ret += check_spec(&format[i], &flags, ar, &i);
                        i++;
                }
                else
                        i += ft_putstr_p(&format[i], &ret);
        }
        va_end(ar);
        return (ret);
}
