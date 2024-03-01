/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:14:41 by janhan            #+#    #+#             */
/*   Updated: 2024/03/02 08:04:53 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

/**
 * @brief
 * fork()시 부모 프로세스에서는 자식 프로세스들의 pid값이 리턴되는것과
 * @자식 프로세스에서는 pid가 0으로 나오는걸 활용하여 부모는 개별로 빠짐
 * @param philo
 */
static void	ft_create_child(t_philo *philo)
{
	long	index;

	index = 0;
	while (index < philo->num_of_philo)
	{
		philo->philo_id = index + 1;
		philo->child[index] = fork();
		if (philo->child[index] == 0)
			ft_child_routine(philo);
		index++;
	}
}

static void	ft_wait_child(t_philo *philo)
{
	long	index;
	int		child_status;
	int		child_exit_code;

	index = 0;
	while (index < philo->num_of_philo)
	{
		waitpid(-1, &child_status, 0);
		child_exit_code = WEXITSTATUS(child_status);
		if (child_exit_code != FINISH_EAT)
		{
			index = 0;
			while (index < philo->num_of_philo)
			{
				kill(philo->child[index], SIGINT);
				index++;
			}
			printf("%ld %d died\n", ft_current_time(philo), child_exit_code);
			return ;
		}
		index++;
	}
}

int	main(int ac, char **av)
{
	t_philo	philo;

	if (!(ac == 5 || ac == 6))
		return (ft_error("invalid argument count", EXIT_FAILURE));
	if (ft_philo_init(ac, av, &philo) == FAILURE)
		return (ft_error("invailid arguments vector", EXIT_FAILURE));
	if (ft_sem_init(&philo) == FAILURE)
		return (ft_error("sem_open error", EXIT_FAILURE));
	if (ft_time_init(&philo) == FAILURE)
		return (ft_error("gettimeofday() return -1(error)", EXIT_FAILURE));
	philo.child = (pid_t *)malloc(sizeof(pid_t) * philo.num_of_philo);
	if (philo.child == NULL)
		return (ft_error("pid_t malloc error", EXIT_FAILURE));
	ft_create_child(&philo);
	ft_wait_child(&philo);
	free(philo.child);
	sem_close(philo.fork_holder);
	return (EXIT_SUCCESS);
}
