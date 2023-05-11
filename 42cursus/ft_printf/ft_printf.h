/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:59:48 by soohlee           #+#    #+#             */
/*   Updated: 2023/02/08 13:42:29 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *arg, ...);
int		ft_prf_putchar_fd(char c, int fd, int *prfcnt);
int		ft_prf_putstr_fd(char *s, int fd, int *prfcnt);
size_t	ft_prf_strlen(const char *s);
int		ft_prf_putnbr_fd(int n, int fd, int *prfcnt);
int		ft_prf_put_addrhex(void *ap, int *prfcnt, int fd);
int		ft_prf_put_hex(unsigned int ap, int *prfcnt, char format, int fd);
int		ft_prf_unsigned_putnbr_fd(unsigned int n, int fd, int *prfcnt);

#endif
