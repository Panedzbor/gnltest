/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:22:47 by earutiun          #+#    #+#             */
/*   Updated: 2025/02/18 14:23:51 by earutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNLB_H
# define GNLB_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10000000
#endif

typedef struct s_statvals
{
    char                *left;
    int                 check;
    char                buffer[BUFFER_SIZE + 1];
    int                 fd;
    ssize_t             blen;
    struct s_statvals   *next;
    char                *str;
} t_st;

char    *get_next_line(int fd);
ssize_t init_or_count(t_st *st, int fd, char *str, int mode);
char    *erase_left(t_st *st);
t_st    *check_fd(int fd, t_st **st);
char    *del_el(t_st **start, t_st *to_remove, char *next_line);

#endif
