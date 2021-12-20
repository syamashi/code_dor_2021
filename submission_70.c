static pid_t        do_pipe(t_pipe_list *first, t_pipe_list *node, int last_pipe_fd[2])
{
        int                new_pipe_fd[2];
        pid_t        child_pid;

        if (preparation_fork(node, new_pipe_fd) < 0)
                return (-1);
        signal(SIGINT, nothing);
        signal(SIGQUIT, nothing);
        child_pid = fork();
        if (child_pid < 0)
        {
                close_and_unlink(&node->heredoc, TRUE);
                return (child_pid);
        }
        if (child_pid == 0)
        {
                child_operate_pipe_fd(first, node, last_pipe_fd, new_pipe_fd);
                child_exec_cmd(node);
        }
        else
        {
                close_and_unlink(&node->heredoc, FALSE);
                parent_operate_pipe_fd(node, last_pipe_fd, new_pipe_fd);
        }
        return (child_pid);
}
