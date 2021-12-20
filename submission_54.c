char        *split_line(char *buf, char **tmp)
{
        char                *line_after_n;
        char                *line_before_n;
        ssize_t                line_before_n_len;
        ssize_t                nlen;
        char                *tmp1;

        tmp1 = ft_strchr(buf, '\n');
        nlen = ft_strlen(buf);
        line_before_n_len = nlen - ft_strlen(tmp1);
        line_after_n = ft_substr(buf, line_before_n_len + 1, nlen);
        if (!line_after_n)
                return (NULL);
        *tmp = line_after_n;
        line_before_n = ft_strndup(buf, line_before_n_len + 1);
        if (!line_before_n)
                return (NULL);
        return (line_before_n);
}
