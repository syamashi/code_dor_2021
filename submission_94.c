#include <unistd.h>

// minishell
int        main(int argc, char **argv, char **envp)
{
    execve("/bin/bash", argv, envp);
}
