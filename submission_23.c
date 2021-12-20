char        *minishell_expand(char *arg, void (*handler)(t_list *))
{
        t_list        *separated;
        char        *ret;

        if (arg == NULL)
                ft_fatal("minishell_expand : Invalid argument");
        if (*arg == '\0')
        {
                return (ft_xstrdup(arg));
        }
        separated = separate_to_lst(arg, "\'\"\t\n\v\f\r\? $");
        handler(separated);
        ret = lst_join_str(separated, "");
        ft_lstclear(&separated, free);
        return (ret);
}
