/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:14:41 by janhan            #+#    #+#             */
/*   Updated: 2024/02/23 16:29:59 by janhan           ###   ########.fr       */
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

/**
 * @brief
 * 부모 프로세스에서 임의의 자식이 종료 되는것을 기다림
 * WEIXTSTATUS(child_status) 를 사용해서 FINISH_EAT과 같지 않으면(죽거나 그외 오류) 다른 자식에게 kill 시그널 전송
 * @param philo
 */
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

void	check(void)
{
	system("leaks philo_bonus");
}
/**
 * @brief
 * 세마포어를 사용해서 philo를 생성
 * @각 철학자의 pid를 담을 배열 생성
 * @param ac
 * @param av
 * @return int
 */
int	main(int ac, char **av)
{
	t_philo philo;

	atexit(check);
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
