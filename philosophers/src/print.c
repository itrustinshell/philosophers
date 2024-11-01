#include "philo.h"

int	print_if_die(t_thread_pmt	*pmt, int i, long time)
{
	if (time > pmt[i].time_to_die)
	{
		*pmt[i].no_more_to_print = 1;
		*pmt[i].someone_is_dead = 1;
		printf("%s%ld %d %s%s\n", RED,
			get_time() - pmt[i].start_simulation,
			pmt[i].id, DIED, RESET);
		return (0);
	}
	return (1);
}

