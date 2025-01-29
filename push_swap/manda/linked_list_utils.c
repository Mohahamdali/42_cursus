/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:43:24 by mhamdali          #+#    #+#             */
/*   Updated: 2025/01/29 14:59:52 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <libc.h>

t_node *create_node(int data)
{
    t_node *node;
    node = malloc (sizeof(t_node));
    if(!node)
        return (NULL);
    
    node->data = data;
    node->next = NULL;
    return (node);
}

void push_front (t_node **head,int data)
{
    if (head || *head)
        return ;
    t_node *node4 = create_node(data);
    if (!node4)
        return  ;
    node4 ->next = *head;
    *head = node4;
}

void push_back (t_node **head,int data)
{
    t_node *node4 = create_node(data);
    t_node *temp = *head;
    if (!node4)
        return ;
    if(*head == NULL)
        *head = node4;
    else
    {
        while (temp->next)
        {
            temp = temp ->next;
        }
    
    temp ->next = node4;
    }
}

int pop (t_node **head)
{
    int value;
    t_node *temp;
    if (!head || !*head)
        return (0);

    value = (*head)->data;
   temp = *head;
   *head = (*head) -> next;
   free(temp);
   return (value);
}

void print_list (t_node *list)
{
    t_node *temp = list;
    while (temp)
    {
        printf("%d ",temp -> data);
        temp = temp->next;
    }
}

