// 双方向循環リスト（番兵あり

void　        ft_clst_link(t_clist *now, t_clist *next)
{
        now->next = next;
        next->prev = now;
}

void        ft_clst_insert(t_clist *lst, t_clist *new)
{
        ft_clst_link(new, lst->next);
        ft_clst_link(lst, new);
}

void        ft_clstadd_front(t_clist *start, t_clist *new)
{
        ft_clst_insert(start, new);
}

void        ft_clstadd_back(t_clist *start, t_clist *new)
{
        ft_clst_insert(start->prev, new);
}

