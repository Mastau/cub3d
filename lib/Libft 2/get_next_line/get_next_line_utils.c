/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:31:39 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/25 00:43:27 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	search_new_line(t_list_gnl *storage)
{
	t_list_gnl	*current;
	int			i;

	current = storage;
	while (current != NULL)
	{
		i = 0;
		while (current->content[i])
		{
			if (current->content[i] == '\n')
				return (1);
			i++;
		}
		current = current->next;
	}
	return (0);
}

t_list_gnl	*last_node(t_list_gnl *storage)
{
	t_list_gnl	*current;

	current = storage;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	free_storage(t_list_gnl *storage)
{
	t_list_gnl	*current;
	t_list_gnl	*next;

	current = storage;
	while (current)
	{
		lp_free(current->content);
		next = current->next;
		lp_free(current);
		current = next;
	}
}

void	alloc_line(char **line, t_list_gnl *storage)
{
	int	i;
	int	len;

	len = 0;
	while (storage)
	{
		i = 0;
		while (storage->content[i])
		{
			len++;
			if (storage->content[i] == '\n')
				break ;
			i++;
		}
		storage = storage->next;
	}
	*line = lp_alloc(sizeof(char) * (len + 1));
	if (!*line)
		return ;
}

char	*copy_after_newline(const char *content, int start)
{
	char	*new_content;
	int		length;
	int		i;

	length = 0;
	while (content[start + length])
		length++;
	new_content = lp_alloc(sizeof(char) * (length + 1));
	if (!new_content)
		return (NULL);
	i = 0;
	while (content[start])
		new_content[i++] = content[start++];
	new_content[i] = '\0';
	return (new_content);
}
