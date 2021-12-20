char    *ft_strtrim(char const *s1, char const *set)
{
        char    *str;
        size_t  start;
        size_t  goal;
        size_t  i;

        if (!s1 || !set)
                return (NULL);
        start = 0;
        while (s1[start] && ft_strchr(set, s1[start]))
                start++;
        goal = ft_strlen(s1);
        while (goal > start && ft_strrchr(set, s1[goal - 1]))
                goal--;
        str = (char *)malloc(sizeof(*s1) * (goal - start + 1));
        if (!str)
                return (NULL);
        i = 0;
        while (start < goal)
                str[i++] = s1[start++];
        str[i] = 0;
        return (str);
}
