/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:46:55 by hturkatr          #+#    #+#             */
/*   Updated: 2019/11/22 15:54:25 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include "arg_list.h"

typedef struct				s_arg
{
	void	*addr;
	int		type;
	char	*flags;
	int		uns;
	int		width;
	int		base;
	int		precision;
	int		number;
	int		plus;
	int		min_field_width;
	int		alignment;
	int		gap;
	int		zeroing;
}							t_arg;

# define LEAPOCH (946684800LL + 86400 * (31 + 29))
# define DAYS_PER_400Y (365 * 400 + 97)
# define DAYS_PER_100Y (365 * 100 + 24)
# define DAYS_PER_4Y   (365 * 4 + 1)
# define LONG_FLAG 1000
# define SHORT_FLAG 1001
# define CHAR_FLAG 1002
# define LONG_FLOAT_FLAG 1003
# define DEFAULT 1004
# define LEFT_ALIGN -1
# define RIGHT_ALIGN 1
# define TYPES2 'X', '%', 'e', 'g', 'b', 'r', 'k'
# define TYPES char *types = {'d', 'i', 'u', 'f', 'o',  'x', TYPES2};
# define INIT_TYPES char *types = "dsifoxXegbrkpcuEG%UZ"
# define INIT_VALID_FLAGS char *valid_flags = "US+- '.0123456789Llh#Y"
# define INIT_COUNTER(X) int X = 0
# define INT 0
# define STR 1
# define INT_I 2
# define RAW_STR 21
# define FLOAT 3
# define OCTAL 4
# define LIL_HEX 5
# define HEX 6
# define BIN 9
# define PTR 12
# define CHAR 13
# define UNS 14
# define LONG_FLOAT 305
# define LONG_EXP 15
# define EXP 7
# define G_STUFF 8
# define L_G_STUFF 16
# define PERC 17
# define OTHER_UNS 18
# define Z 19
# define UNPRINT 10
# define TIME 11
# define NWHILE(X, Y) X; while(Y) {
# define END_NWHILE(X) X; }
# define IF(X) if (X) {
# define ENDIF }
# define FLAGS char *flags = {'-', '+', ' ', '0', '#'};
# define LENGTH char **length = {"hh", "h", "l", "ll", "L"};

typedef struct				s_f
{
	char	**output;
	int		*t;
	int		*z;
	int		*times;
	long	*before_point;
	int		*zeroes;
}							t_f;

typedef struct				s_time
{
	int		year;
	int		month;
	int		yearday;
	int		hour;
	int		sec;
	int		min;
	int		month_day;
}							t_time;

typedef struct				s_timestamp
{
	long	days;
	long	secs;
	int		remdays;
	int		remsecs;
	int		remyears;
	int		qc_cycles;
	int		c_cycles;
	int		q_cycles;
	int		wday;
	int		yday;
	int		leap;
	int		years;
	int		months;
}							t_timestamp;

typedef struct				s_arg_list_stuff
{
	char				*temp_str_arg;
	char				*temp_flags;
	char				*asterisk_replacement;
	unsigned long		temp_long;
	long double			temp_l_double;
	double				temp_double;
	intptr_t			temp_ptr;
	int					i;
	int					start;
	int					number;
	int					type;
}							t_arg_list_stuff;

typedef struct				s_vector
{
	size_t		capacity;
	size_t		last_item_index;
	size_t		data_sizeof;
	void		*data;
	void		(*push)(struct s_vector *this, void *data);
	void		(*pop)(struct s_vector *this);
	void		(*erase)(struct s_vector *this);
	void		*(*at)(struct s_vector *this, size_t index);
	size_t		(*size)(struct s_vector *this);
}							t_vector;

void						ft_make_t_vector2(t_vector *object);
t_vector					*ft_make_t_vector(size_t capacity,
				size_t data_sizeof);
void						ft_destroy_t_vector(t_vector *object);

char						*ft_sprintf(int num, ...);
char						*ft_ftoa(long double num, int times);
char						*ft_itoa_base(long long nb, int base);
char						*ft_utoa_base(unsigned long
					long nb, int base);
void						make_arg_vector(t_vector *vec,
					va_list valist, int num);
int							parse_for_arg(char *str, int *start);
char						*freejoin(char *s1, char *s2);
int							ft_printf(char *to_print, ...);
int							get_type(char c);
int							check_long_float(char *flags);
char						*string_handling(t_arg_list *arg);
void						find_precision(t_arg_list *arg);
char						*int_handling(t_arg_list *arg);
char						*int_to_str(t_arg_list *arg);
char						*int_precision(t_arg_list *arg, int size);
char						*check_extra_flags(t_arg_list *arg, char **output);
void						check_plus(t_arg_list *arg);
char						*float_handling(t_arg_list *arg);
char						*insert_replacement(char *s,
				char *replacement, int loc, int size);
char						*handle_double_mod(char *s);
int							validate_input_s(char *s);
void						check_min_width(t_arg_list *arg);
char						*process_flags(t_arg_list *arg, char **output);
void						check_gap(t_arg_list *arg);
char						*handle_gap(t_arg_list *arg, char *input);
char						*pointer_handling(t_arg_list *arg);
void						str_to_low(char **str);
char						*get_color(char *s, int start);
char						*is_color(char *s, int start);
int							get_color_size(char *s, int start);
char						*color_handling(char *s);
void						check_hash(t_arg_list *arg);
char						*add_base_hash(t_arg_list *arg, char *input);
char						*exp_handling(t_arg_list *arg);
void						check_exp(t_arg_list *arg);
char						*g_stuff_handling(t_arg_list *arg);
int							g_c(long nb);
int							validate_args(t_arg_list **head, int args);
int							check_flag_gap(char **s, int loc);
int							parse_ws(const char *str);
int							handle_overflow(const char *str,
								int neg, int index);
long						ft_atol(const char *str);
char						*timestamp_to_s(t_arg_list *arg);
char						*print_unprintable(t_arg_list *arg);
t_arg_list					*make_arg_list(char *s, va_list valist);
void						process_asterisk(char **s, va_list valist,
								t_arg_list_stuff *a);
void						destroy_arg_list(t_arg_list **head);
void						process_ptr(char *s, va_list valist,
						t_arg_list **args, t_arg_list_stuff *a);
void						process_perc(char *s,
					t_arg_list **args, t_arg_list_stuff *a);
void						process_z(char *s,
					t_arg_list **args, t_arg_list_stuff *a);
void						process_time(char *s, va_list valist,
					t_arg_list **args, t_arg_list_stuff *a);
void						process_str(char *s, va_list valist,
						t_arg_list **args, t_arg_list_stuff *a);
void						process_unprint(char *s, va_list valist,
						t_arg_list **args, t_arg_list_stuff *a);
void						process_raw_str(char *s,
							t_arg_list **args, t_arg_list_stuff *a);
void						process_float(char *s, va_list valist,
				t_arg_list **args, t_arg_list_stuff *a);
char						*create_gap(t_arg_list *arg, int
					len, char **output);
char						*is_valid_color(char *color);
char						*test_round(char **s, int precision);
void						check_long(t_arg *arg);
char						*handle_plus(char *number);
char						*freecopy(char *dest, char *src, size_t n);

#endif
