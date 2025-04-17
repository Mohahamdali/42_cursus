#include "minishell.h"

t_env *create_env_node(char *key, char *value)
{
    t_env *new_node = malloc(sizeof(t_env));
    if (!new_node)
        return NULL;
    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = NULL;
    return new_node;
}

char *determine_key(char *argv)
{
    int i = 0;
    int j = 0;
    while (argv[i] && argv[i] != '=')
        i++;
    char *key = malloc(i + 1);
    if (!key)
        return NULL;
    while (j < i)
    {
        key[j] = argv[j];
        j++;
    }
    key[i] = '\0';
    return key;
}

char *determine_value (char *args)
{
    char *value = ft_strchr (args,'=');
    if (!value || !*(value + 1))
        return ft_strdup("");
    
    return (ft_strdup(value + 1));
}

void append_env_node(t_env **head, t_env *new_node)
{
    if (!*head)
    {
        *head = new_node;
        return;
    }
    t_env *current = *head;
    while (current->next)
        current = current->next;
    current->next = new_node;
}

void change_to_linked_list (t_command *cmd)
{
    char *key;
    char *value;
    int i = 0;
    t_env *node;
    while (cmd -> enve[i])
    {
        key = determine_key(cmd -> enve[i]);
        value = determine_value(cmd -> enve[i]);
        node = create_env_node(key,value);
        append_env_node(&cmd ->env, node);
        free(key);
        free(value);
        i++;
    }
}

void print_env(t_env *env)
{
    t_env *current = env;
    while (current)
    {
        if (ft_strlen(current -> value) == 0)
            printf("declare -x %s%s\n", current->key, current->value);
        else
            printf("declare -x %s=%s\n", current->key, current->value);
        current = current->next;
    }
}

void change_env_already (t_env *env, char *key, char *value)
{
    int i = 0;
    while (env)
    {
        if (ft_strncmp(env -> key, key, ft_strlen(key)) == 0)
        {
            free(env -> value);
            env ->value = value;
            return ;
        }
        env = env -> next;
    }
}

void export(t_command *cmd)
{
    int i = 0;
    char *key;
    char *value;
    t_env *new_node;
    if (!cmd -> env)
        change_to_linked_list(cmd);
    if (!cmd -> args[1])
        print_env(cmd -> env);
    else
    {
        key = determine_key(cmd -> args[1]);
        value = determine_value(cmd ->args[1]);
        change_env_already(cmd ->env, key, value);
        new_node = create_env_node(key,value);
        append_env_node(&cmd ->env,new_node);
        free(key);
        free(value);
    }
    free_env_list(cmd -> env);
}