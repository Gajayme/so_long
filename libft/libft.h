/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:06:30 by gajayme           #+#    #+#             */
/*   Updated: 2021/12/25 00:44:41 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include<unistd.h>
# include<string.h>
# include<stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char			*ft_itoa(int n);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_lstsize(t_list *lst);
int				ft_atoi(const char *str);
t_list			*ft_lstlast(t_list *lst);
char			*ft_strdup(const char *s);
t_list			*ft_lstnew(void *content);
size_t			ft_strlen(const char *str);
void			ft_bzero(void *s, size_t n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_lstadd_front(t_list **lst, t_list *new);
char			*ft_strchr(const char *string, int symbol);
char			*ft_strrchr(const char *string, int symbol);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
void			*ft_memchr(const void *arr, int c, size_t n);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			*ft_memset(void *memptr, int val, size_t num);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
int				ft_strncmp(const char *str1, const char *str2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
const char		*f_strnstr(const char *s, const char *find, size_t slen);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

#endif
