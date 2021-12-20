void        flag_quote(t_list *cur_token, int *flag_dquote, int *flag_squote)
{
        if ((((t_token *)cur_token->content)->type) == DQUOTE)
                *flag_dquote ^= 1;
        if ((((t_token *)cur_token->content)->type) == SQUOTE)
                *flag_squote ^= 1;
}
