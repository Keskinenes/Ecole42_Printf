/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkeskin < enkeskin@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:01:39 by enkeskin          #+#    #+#             */
/*   Updated: 2022/08/01 18:12:23 by enkeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"


int	ft_type_control(char c, va_list arg)
{
	if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == 'd' || c == 'i')
		return (ft_abs(va_arg(arg, int)));
	else if (c == 'p')
	{
		ft_putstr("0x");
		return (ft_convert(va_arg(arg, unsigned long), "0123456789abcdef") + 2);
	}
	else if (c == 'u')
		return (ft_convert(va_arg(arg, unsigned int), "0123456789"));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'x')
		return (ft_convert(va_arg(arg, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_convert(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		j;

	va_start(arg, str);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			j += ft_type_control(str[i + 1], arg);
			i++;
		}
		else
			j += write(1, &str[i], 1);
		i++;
	}
	va_end(arg);
	return (j);
}

/*
int main()
{
	ft_printf("%%%");
}
*/

int ortalama(int a, ...)
{
	va_list arg;
	int c = 0;
	int b = a;

	va_start(arg, a);
	
	while (a)
	{
		c += va_arg(arg, int);
		a--;
	}
	c = c / b;
	va_end(arg);
	return c;
}

int main()
{
	//ft_printf("%d", ortalama(3,1,1));
	//int c = ft_printf("5%d32", 32);
	//ft_printf("%d",ft_printf("Yakışıklı Enes")); 
	ft_printf("%d", 0);
	
}