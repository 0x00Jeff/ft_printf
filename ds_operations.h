/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds_operations.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:29:25 by afatimi           #+#    #+#             */
/*   Updated: 2023/03/22 14:45:46 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DS_OPERATIONS_H
# define DS_OPERATIONS_H
# include "stdarg.h"

typedef union u_content
{
	long long		placeholder;
	void			*address;
	unsigned int	hex;
	unsigned int	u;
	int				nbr;
	char			*str;
	char			c;
}					t_content;

typedef struct s_chunck
{
	char				*fmt;
	t_content			content;
	int					valide_fmt;
	struct s_chunck		*next;
}						t_chunck;
t_chunck	*ft_lstnew(char *fmt, long long content);
void		ft_lstadd_back(t_chunck **lst, t_chunck *new);
void		ft_lstiter(t_chunck *lst, void (*f)(t_chunck *chunck, int debug));
int			ft_lstsize(t_chunck *lst);
void		ft_lstclear(t_chunck **lst);
void		ft_lstdelone(t_chunck *lst);
#endif
