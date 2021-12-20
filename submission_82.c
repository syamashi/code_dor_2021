static void        put_num_recursive(unsigned long long nb,
                        t_store *store, void (*put[])(t_store *, char))
{
        if (nb >= (unsigned long long)store->base)
        {
                put_num_recursive(nb / store->base, store, put);
                put_num_recursive(nb % store->base, store, put);
        }
        else
                put[store->flag](store, store->basestr[nb]);
}
