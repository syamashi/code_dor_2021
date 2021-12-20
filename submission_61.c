char        *ft_strtrim(char const *str, char const *trim_set)
{
        size_t        start;
        size_t        end;

        if (!str)
                return (NULL);
        if (!trim_set)
                return (ft_strdup(str));
        start = 0;
        while (str[start] && ft_strchr(trim_set, str[start]))
                start++;
        end = ft_strlen(str);
        while (str[end - 1] && ft_strchr(trim_set, str[end - 1]))
                end--;
        return (ft_substr(str, start, end - start));
}
