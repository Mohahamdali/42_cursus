#include "minishell.h"

void free_env_list(t_env *env)
{
    t_env *temp;
    while (env)
    {
        temp = env;
        env = env->next;
        free(temp->key);
        free(temp->value);
        free(temp);
    }
}