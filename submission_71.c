
static int        _take_a_fork(t_info *info, int fork_nb)
{
        bool                got_fork;
        t_shared        *shared;
        int64_t                timestamp;

        got_fork = false;
        shared = info->shared;
        while (!got_fork)
        {
                pthread_mutex_lock(&shared->mutex_forks[fork_nb]);
                if (!shared->arr_forks[fork_nb])
                {
                        got_fork = true;
                        shared->arr_forks[fork_nb] = info->philo_id;
                        timestamp = print_timestamp_log(info, FORK);
                        if (timestamp == ERROR)
                                return (ERROR);
                        _set_timestamp_and_cnt_meal(info, timestamp, false);
                }
                pthread_mutex_unlock(&shared->mutex_forks[fork_nb]);
                if (!got_fork)
                        usleep(WAIT_TIME);
        }
        return (SUCCESS);
}
