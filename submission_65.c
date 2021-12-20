int        ft_printf(const char *fmt, ...)
{
        va_list                ap;
        size_t                size;
        const char        *start;
        int                        flag;

        size = 0;
        va_start(ap, fmt);
        if (fmt == NULL)
                return (-1);
        while (*fmt)
        {
                start = fmt;
                if (*start != '%')
                        flag = ft_proc_plain(&start, &fmt, &size);
                else
                        flag = ft_proc_per(&start, &fmt, &size, &ap);
                if (flag)
                        return (-1);
        }
        va_end(ap);
        return ((int)size);
}
