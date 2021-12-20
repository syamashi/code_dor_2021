void        **rec_list_to_array(t_list *itr, size_t idx)
{
        void        **ret;

        if (!itr)
        {
                ret = malloc(sizeof(*ret) * idx + 1);
                if (ret)
                        ret[idx] = NULL;
                return (ret);
        }
        ret = rec_list_to_array(itr->next, idx + 1);
        if (ret)
                        ret[idx] = itr->content;
        return (ret);
}
