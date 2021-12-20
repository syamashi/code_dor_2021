void        take_two_forks(t_philo *philo)
{
        less_delay_usleep(philo->number % 2 * 500, philo);
        wrap_sem_wait(philo->forks, NULL);
        print_timestamp(philo, TAKE);
        wrap_sem_wait(philo->forks, NULL);
        print_timestamp(philo, TAKE);
}
void        drop_two_forks(t_philo *philo)
{
        wrap_sem_post(philo->forks, NULL);
}
void        eat_spaghetti(t_philo *philo)
{
        print_timestamp(philo, EAT);
        setget_last_eat(philo, true);
        if (++philo->eat == philo->args->number_of_times_each_philosopher_must_eat)
                wrap_sem_post(philo->ate, NULL);
        less_delay_usleep(philo->args->time_to_eat * 1000, philo);
}
void        sleep_on_table(t_philo *philo)
{
        print_timestamp(philo, SLEEP);
        less_delay_usleep(philo->args->time_to_sleep * 1000, philo);
}
