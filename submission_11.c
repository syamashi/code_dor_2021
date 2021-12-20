int        ms_executer(t_pipeline *pl, t_master *master, t_ex_state *state)
{
        if (pl == NULL)
                return (0);
        if (pl->clause->next != NULL)
                exec_pipe_command(pl, master, state);
        else
                g_ex_states = exec_simple_command(pl->clause, master, state);
        while (pl && !ms_pipeline_check(pl))
                pl = pl->next;
        if (pl && ms_pipeline_check(pl))
        {
                if (!master->exited)
                        ms_executer(pl->next, master, state);
        }
        return (0);
}
