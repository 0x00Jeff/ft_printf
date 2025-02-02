/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:26:42 by afatimi           #+#    #+#             */
/*   Updated: 2023/03/22 11:42:03 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"ds_operations.h"
#include"helpers.h"

t_chunck	*ft_lstnew(char *fmt, long long content)
{
	t_chunck	*node;

	node = (t_chunck *)malloc(sizeof(t_chunck));
	if (!node)
		return (NULL);
	node -> fmt = fmt;
	if (*node -> fmt == '%')
		node -> content.placeholder = content;
	else
		node -> content.placeholder = 0;
	node -> valide_fmt = validate_fmt(node -> fmt);
	node -> next = NULL;
	return (node);
}

static	t_chunck	*ft_lstlast(t_chunck *lst)
{
	t_chunck	*ptr;

	if (!lst)
		return (NULL);
	ptr = lst;
	while (ptr -> next)
		ptr = ptr -> next;
	return (ptr);
}

void	ft_lstadd_back(t_chunck **lst, t_chunck *new)
{
	t_chunck	*ptr;

	if (!lst || !new)
		return ;
	ptr = *lst;
	if (ptr)
	{
		ptr = ft_lstlast(ptr);
		ptr -> next = new;
	}
	else
		*lst = new;
}

void	ft_lstdelone(t_chunck *lst)
{
	if (!lst)
		return ;
	lst -> content.placeholder = 0;
	free(lst -> fmt);
	free(lst);
}

void	ft_lstclear(t_chunck **lst)
{
	t_chunck	*ptr;
	t_chunck	*tmp;

	if (!lst || !*lst)
		return ;
	ptr = *lst;
	while (ptr)
	{
		tmp = ptr -> next;
		ft_lstdelone(ptr);
		ptr = tmp;
	}
	*lst = NULL;
}
