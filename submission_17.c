static ssize_t        send_bit(int pid, bool bit)
{
        if (bit)
                return (kill(pid, SIGUSR1));
        else
                return (kill(pid, SIGUSR2));
}

static ssize_t        send_byte(int pid, uint8_t c)
{
        int64_t        bit;

        bit = 0;
        while (bit < 8)
        {
                if (send_bit(pid, (c & (1 << bit)) != 0) == -1)
                        return (ERROR);
                if (usleep(TICK_US) == -1)
                        return (ERROR);
                bit++;
        }
        return (SUCCESS);
}
