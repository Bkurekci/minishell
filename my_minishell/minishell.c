#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "environ.h"
#include "minishell.h"
#include "libft/libft.h"

static char *getInput(void)
{
    char *input;
    
    input = readline("\033[31mshell\033[0m$> ");
    if(input == NULL)
        return NULL;
    else if(input && input[0])
        add_history(input);
    return (input);
}

int main()
{
    char *input;

    g_env = NULL;
    signal(SIGQUIT, SIG_IGN);
    signal(SIGINT, signalhandler);
    if (env_init() == -1)
        return (1);
    while(1)
    {
        input = getInput();
        if(input == NULL)
        {
            if (isatty(STDERR_FILENO))
                ft_putendl_fd("exit", STDERR_FILENO);
            break;
        }
    }
}