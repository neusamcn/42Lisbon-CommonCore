/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:45:34 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/07/27 20:11:20 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list  *current;

    while (*begin_list)
    {
        if (cmp(data_ref, (*begin_list)->data) == 0)
        {
            current = (*begin_list)->next;
            free((*begin_list)->data);
            free(*begin_list);
            *begin_list = current;
        }
        else
            begin_list = &(*begin_list)->next;
    }
}
// FOR TESTING ONLY:
#include <stdio.h>

// int cmp(void *data_ref, void *data_lst)
// {
//     char    d_ref;
//     char    d_lst;

//     data_ref = &d_ref;
//     data_lst = &d_lst;
    
//     if (d_ref == d_lst)
//         return (0);
//     return (1);
// }

int cmp(void *data_ref, void *data_lst)
{
    return (*(char *)data_ref != *(char *)data_lst);
}

int main()
{
    t_list  *node1 = malloc(sizeof(t_list));
    if (!node1)
        return (1);
    t_list  *node2 = malloc(sizeof(t_list));
    if (!node2)
        return (1);
    t_list  *node3 = malloc(sizeof(t_list));
    if (!node3)
        return (1);

    char    *char_a1 = malloc(sizeof(char));
    if (!char_a1)
        return (1);
    *char_a1 = 'a';
    char    *char_a2 = malloc(sizeof(char));
    if (!char_a2)
        return (1);
    *char_a2 = 'a';
    char    *char_c = malloc(sizeof(char));
    if (!char_c)
        return (1);
    *char_c = 'c';
    
    node1->data = char_a1;
    node1->next = node2;
    node2->data = char_c;
    node2->next = node3;
    node3->data = char_a2;
    node3->next = NULL;

    t_list *head_lst = node1;

    char    char_ref = 'c';
    void    *data_ref = &char_ref;
    printf("Before ft_list_remove_if():\n");
    t_list  *current = head_lst;
    int node_i = 1;
    while (current)
    {
        printf("node%d: '%c'\n", node_i, *(char *)current->data);
        current = current->next;
        node_i++;
    }
    printf("\n");
    ft_list_remove_if(&head_lst, data_ref, cmp);
    printf("After ft_list_remove_if():\n");
    current = head_lst;
    node_i = 1;
    while (current)
    {
        printf("node%d: '%c'\n", node_i, *(char *)current->data);
        current = current->next;
        node_i++;
    }

    
    while (head_lst)
    {
        current = head_lst->next;
        free(head_lst->data);
        free(head_lst);
        head_lst = current;
    }
    return (0);
}