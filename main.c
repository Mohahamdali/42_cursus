
#include "philosopher.h"
#include <pthread.h>
void check_argc (t_data *data, char **av)
{
    int i = 1;
   while (av[i])
   {
        check_valid_numbre(av[i]);
        ft_atoi(av[i]);
        i++;
   }
   data->num_philo = ft_atoi(av[1]);
   data->t_die = ft_atoi(av[2]);
   data->t_eat = ft_atoi(av[3]);
   data->t_sleep = ft_atoi(av[4]);

}





int main (int ac,char **av)
{
    t_data data;
    if (ac != 5)
       return(write(2,"Error arguments\n",16),0);
    check_argc(&data,av);
    t_philo philosopher[data.num_philo];
}