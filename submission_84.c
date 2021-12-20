void        key_x_func_mul(char *buf, t_string *command, t_minishell *info, int key)
{
        if (key == KEY_UP)
                trace_history_up(buf, command, info);
        else if (key == KEY_DOWN)
                trace_history_down(buf, command, info);
        else if (key == KEY_LEFT)
                move_cursor_left(buf, command, info);
        else if (key == KEY_RIGHT)
                move_cursor_right(buf, command, info);
        else if (key == CTRL_D)
                ctrl_d_put_error(buf, command, info);
        else if (key == CTRL_L)
                clear_terminal(buf, command, info);
        else if (key == KEY_DELETE)
                delete_displayed_char(buf, command, info);
        else if (key == NORMAL_CHAR)
                print_user_pushed_char(buf, command, info);
        else if (key == KEY_NEWLINE)
                pushed_newline(buf, command, info);
        else
                key_x_func_2(buf, command, info, key);
}
