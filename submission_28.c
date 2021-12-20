int        key_hook(int key_code, t_vars *vars)
{
        int        move;

        move = 0;
        if (key_code == W)
                move = move_player(vars, 0, -1);
        if (key_code == A)
                move = move_player(vars, -1, 0);
        if (key_code == S)
                move = move_player(vars, 0, 1);
        if (key_code == D)
                move = move_player(vars, 1, 0);
        if (key_code == ESC)
                destroy_and_exit(vars);
        if (move)
        {
                print_info(vars)
                vars->step_cnt++;
        }
        return (0);
}
