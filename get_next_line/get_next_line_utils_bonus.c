/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:25:47 by earutiun          #+#    #+#             */
/*   Updated: 2025/02/22 14:23:51 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_st *create_el(t_st **st);

t_st    *check_fd(int fd, t_st **start)
{
    t_st    *current;
    t_st    *new_el;
    t_st    *last_el;

    if (!*start)
        return(create_el(start));
    current = *start;
    while (current)
    {
        if (current->fd == fd)
            break ;
        current = current->next;
    }
    if (current)
        return (current);
    create_el(&new_el);
    last_el = *start;
    while (last_el->next)
        last_el = last_el->next;
    last_el->next = new_el;
    return (new_el);
}

static t_st *  create_el(t_st **ptr)
{
    *ptr = (t_st *)malloc(sizeof(t_st));
    if (!*ptr)
        return (NULL);
    (*ptr)[0].left = NULL;
    (*ptr)[0].next = NULL;
    return (*ptr);
}

char    *del_el(t_st **start, t_st *to_remove, char *next_line)
{
    t_st    *current;

    if (*start != to_remove)
    {
        current = *start;
        while (current->next != to_remove)
            current = current->next;
        current->next = current->next->next;
    }
    else
        *start = (*start)->next;
    free((void *)to_remove);
    to_remove = NULL;
    return (next_line);
}

ssize_t init_or_count(t_st *st, int fd, char *str, int mode)
{
    ssize_t i;

    i = 0;
    if (mode == 1)
    {
        st->left = NULL;
        st->check = 0;
        st->fd = fd;
        st->blen = 0;
        st->str = NULL;
    }
    else
    {
        if (!str)
            return (0);
        while (str[i] != '\0')
            i++;
    }
    return (i);
}

char    *erase_left(t_st *st)
{
    if (st->left)
    {
        free((void *)st->left);
        st->left = NULL;
    }
    st->check = 0;
    return (NULL);
}
