int        add_node(t_avl *new, t_avl **node)
{
        int        ret;

        ret = 0;
        if (node == NULL || new == NULL
                || (*node && (new->val == (*node)->val)))
                return (-1);
        else if (*node == NULL)
                *node = new;
        else if (new->val < (*node)->val)
                ret = add_node(new, &(*node)->left);
        else
                ret = add_node(new, &(*node)->right);
        if (ret == 1)
                new->parent = *node;
        if ((*node)->depth < ret)
                (*node)->depth = ret;
        return (rotate_avl(node) + 1);
}
