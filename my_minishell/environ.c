#include "environ.h"
#include "utils.h"
#include <stdio.h>
#include <errno.h>

int	env_init(void)
{
	extern char	**environ;
	int			i;

	i = lineCount(environ);
	if (i == 0)
		return (0);
	g_env = malloc((i + 1) * sizeof(char *));
	if (g_env == NULL)
		return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
	i = 0;
	while (environ[i])
	{
		g_env[i] = ft_strdup(environ[i]);
		if (g_env[i] == NULL)
		{
			ft_free_split(&g_env);
			return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
		}
		i++;
	}
	g_env[i] = NULL;
	return (0);
}