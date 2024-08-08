/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:15:14 by umosse            #+#    #+#             */
/*   Updated: 2024/02/02 14:57:47 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

typedef struct s_client{
	int		index;
	char	*str;
	int		size;
	pid_t	pid;
}	t_client;

static struct s_client	g_client;

static void	send_bit(int index)
{
	int	bit;

	bit = (g_client.str[index / 8] >> (index % 8)) & 1;
	if (index >= g_client.size * 8)
		return ;
	if (bit == 1)
	{
		kill(g_client.pid, SIGUSR2);
	}
	else if (bit == 0)
	{
		kill(g_client.pid, SIGUSR1);
	}
}

static void	reception(int sig, siginfo_t *signinfo, void *ptr)
{
	(void)sig;
	(void)signinfo;
	(void)ptr;
	send_bit(g_client.index);
	g_client.index++;
}

int	main(int argc, char *argv[])
{
	struct sigaction	storeaction;

	if (argc == 3)
	{
		storeaction.sa_flags = SA_SIGINFO;
		storeaction.sa_sigaction = (void *)reception;
		sigaction(SIGUSR1, &storeaction, NULL);
		sigaction(SIGUSR2, &storeaction, NULL);
		g_client.pid = ft_atoi(argv[1]);
		g_client.str = argv[2];
		g_client.size = ft_strlen(g_client.str) + 1;
		g_client.index = 1;
		send_bit(0);
		while (g_client.index < g_client.size * 8)
			pause();
	}
}
