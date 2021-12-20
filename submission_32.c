int        main(int argc, char *argv[])
{
        t_info info;

        init_info(&info);
        validate_args(argc, argv, &info);
        read_instructions(&info);
        print_checker_result(&info);
        clear_info(&info);
        return (EXIT_SUCCESS);
}
