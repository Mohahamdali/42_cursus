/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:43:51 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/05 16:03:44 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <limits.h>
typedef struct node
{
    int data;
    long index;
    struct node *next;
} t_node;

t_node *create_node(int data);
void push_front (t_node **head,int data);
void push_back (t_node **head,int data);
int pop (t_node **head);
void sa (t_node **stack_a);
void sb (t_node *stack_b);
void ss (t_node *stack_a,t_node *stack_b);
void print_list (t_node *list);
void pa (t_node **stack_a,t_node **stack_b);
void pb (t_node **stack_a,t_node **stack_b);
void ra (t_node **stack_a);
void rb (t_node **stack_b);
void rr (t_node **stack_a,t_node **stack_b);
void rotate (t_node **stack,int n);
void rrr (t_node **stack_a, t_node **stack_b);
void check_numbre (t_node *head);
int check_valid_numbre (char *str);
void check_numbre_overflow (long n,int sign);
int ft_list_size(t_node *begin_list);
void intel_sort (t_node **stack_a,t_node **stack_b,int range);
int find_max_index (t_node **stack_a,int *max);
#endif