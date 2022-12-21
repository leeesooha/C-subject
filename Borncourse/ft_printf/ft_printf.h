/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:59:48 by soohlee           #+#    #+#             */
/*   Updated: 2022/12/09 19:45:54 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *arg, ...);
int		ft_putchar_fd(char c, int fd, int *prfcnt);
int		ft_putstr_fd(char *s, int fd, int *prfcnt);
size_t	ft_strlen(const char *s);
int		ft_putnbr_fd(int n, int fd, int *prfcnt);
int		ft_put_addrhex(void *ap, int *prfcnt, int fd);
int		ft_put_hex(unsigned int ap, int *prfcnt, char format, int fd);
int		ft_unsigned_putnbr_fd(unsigned int n, int fd, int *prfcnt);

#endif
