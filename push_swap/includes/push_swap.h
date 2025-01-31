/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:43:51 by mhamdali          #+#    #+#             */
/*   Updated: 2025/01/31 19:55:47 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <limits.h>
typedef struct node
{
    int data;
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
void rotate (t_node **stack);
void rrr (t_node **stack_a, t_node **stack_b);
void check_numbre (t_node *head);
int check_valid_numbre (char *str);
void check_numbre_overflow (long n,int sign);
void quick_sort (t_node **stack_a, t_node **stack_b,int size,int check);
int ft_list_size(t_node *begin_list);
void push_swap(t_node **stack_a, t_node **stack_b);
void merge_sort_1(t_node **stack_a, t_node **stack_b,int size);
#endif