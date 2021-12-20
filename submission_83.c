void        ft_printf_internal(const char *format, va_list va, t_format *fmt)
{
        while (*format && !fmt->error)
        {
                if (*format != '%' && !fmt->error)
                {
                        ft_join_buf(format, fmt);
                        format++;
                        continue ;
                }
                else
                        format++;
                if (*format == '%' && !fmt->error)
                {
                        ft_out_char('%', fmt);
                        format++;
                }
                else if (!fmt->error)
                {
                        ft_flags(&format, fmt);
                        ft_width(&format, fmt);
                        ft_precision(&format, fmt);
                        ft_type(&format, va, fmt);
                }
        }
}
