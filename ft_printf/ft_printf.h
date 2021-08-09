/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 16:57:57 by seungsle          #+#    #+#             */
/*   Updated: 2021/08/02 23:11:04 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdlib.h>
# include<stdarg.h>
# include<unistd.h>

# define SPECIFIER "cspdiuxX%"
# define FLAG_1 "# +"
# define FLAG_2 "-0"
# define PRECISION '.'
# define FLAG_1_HASH '#'
# define FLAG_1_SPACE ' '
# define FLAG_1_PLUS '+'
# define FLAG_2_DASH '-'
# define FLAG_2_ZERO '0'

# define CHAR 0
# define STR 1
# define DI 2
# define U 3
# define XX 4
# define P 5
# define PERSENT 6

typedef struct s_info
{
	int		idx;
	int		ret_idx;
	int		width;
	int		length;
	int		flag_1_hash;
	int		flag_1_space;
	int		flag_1_plus;
	int		flag_2_dash;
	int		flag_2_zero;
	int		precision;
	int		pre_idx;
	char	specifier;
	int		num_sign;
	int		num_type;
}	t_info;

int		ft_printf(const char *format, ...);

int		ft_get_persent_idx(char *format, t_info *info_t);
void	ft_get_specifier(char *format, t_info *info_t, char *specifiers);
void	ft_get_precision(char *format, t_info *info_t, char flags);
void	ft_set_t_info(char *format, t_info *info_t);
int		ft_parsing(va_list ap, char *format);

int		ft_check_flags(t_info *info_t);
void	ft_get_flags(char *format, t_info *info_t);
int		ft_get_width_length(char *format, t_info *info_t);
void	ft_get_fixed_factor(char *format, t_info *info_t);

int		ft_print_variable(va_list ap, t_info *info_t);
int		ft_which_specifier(va_list ap, t_info *info_t);
int		ft_print_c(int i, t_info *info_t);
int		ft_print_s(char *str, t_info *info_t);
int		ft_print_check_1(t_info *info_t, int type);
int		ft_print_check_2(t_info *info_t, int type);

int		ft_print_c_str(t_info *info_t, char *s, int type);
void	ft_length_print_char(t_info *info_t, char *s, int type);
void	ft_width_print_char(t_info *info_t, int len, int type);

int		ft_print_num(va_list ap, t_info *info_t, char type);
int		ft_print_ux(unsigned long long num, t_info *info_t, char type);
int		ft_print_d_i(int num, t_info *info_t);
void	ft_print_di_flag2(t_info *info_t, char *str);
void	ft_length_print_di(t_info *info_t, char *str);
void	ft_width_print_di(t_info *info_t, char *str, char *stype);
void	ft_print_di_flag1(t_info *info_t, char *str);
void	ft_check_sign(int num, t_info *info_t);

char	*ft_strchr(const char *s, int c);
char	*ft_strchr_size(const char *s, int c, int len);
void	*ft_memchr(const void *s, int c, size_t n);
void	ft_init_t_info(t_info *info_t);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);

void	ft_putchar(char *c, t_info *info_t);

void	ft_putstr(char *s, t_info *info_t, int c);
char	*ft_itoa(long n, t_info *info_t);
char	*ft_put_str(char *ret, long num, int size, t_info *info_t);
char	*ft_malloc(size_t size);
char	*ft_itoa_un(unsigned long long n, t_info *info_t, char type);
char	*ft_put_s_un(char *r, unsigned long long n, t_info *in_t, char t);
int		ft_num_size_un(unsigned long long n, t_info *info_t);

int		ft_num_size(long n, t_info *info_t);
int		ft_print_persent(t_info *info_t);
void	ft_width_print_prs(t_info *info_t);
#endif
