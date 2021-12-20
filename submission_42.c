void        zsh_case(char *argv)
{
        int                split_count;
        char        **new_argv;
        t_stack        *a;
        t_stack        *b;

        split_count = ft_split_count(argv, ' ');
        zsh_number_is_int(argv, split_count);
        new_argv = ft_split(argv, ' ');
        ps_error_check(split_count, new_argv);
        a = zsh_make_list(split_count, new_argv);
        b = stack_setup();
        ary_check(a, split_count);
        if (split_count <= 2)
                do_swap_2(a, LIST_A);
        else if (split_count == 3)
                swap_3(a, LIST_A);
        else if (split_count == 4)
                swap_4(a, b);
        else if (split_count <= 5)
                do_swap_over_5(a, b);
        else
                do_swap_over_6(a, b, split_count);
}
