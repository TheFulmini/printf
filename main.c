#include <stdio.h>
#include "./includes/ft_printf.h"
#include <stdlib.h>
#include <fcntl.h>

int		main()
{
	int	result;
	int	true_result;
    char *test;
    int value;
    char c;

    test = "hello, poto. les potos de mes potos sonty mes potos";
    value = 1000;
    c = 'a';


	result = ft_printf("helloooo potooos\n");
	true_result = printf("helloooo potooos\n");

    	if (true_result == result)
		printf("\033[32mtest passed\033[0m\n");
    else
        printf("\033[31mtest failed\033[0m\n");

    result = ft_printf("%d\n", value);
	true_result = printf("%d\n",value);

    	if (true_result == result)
		printf("\033[32mtest passed\033[0m\n");
    else
        printf("\033[31mtest failed\033[0m\n");

    result = ft_printf("%9s\n", "hello");
    true_result = printf("%9s\n", "hello");

	if (true_result == result)
		printf("\033[32mtest passed\033[0m\n");
    else
        printf("\033[31mtest failed\033[0m\n");

    printf("p0 %.3s\n", "ccccccc");
    ft_printf("p0 %.3s \n", "ccccccc");
	printf("pp %.50d\n", 10000);
    ft_printf("pp %.50d\n",10000);
	printf("p1 %.4s\n", "ccccccc");
    ft_printf("p1 %.4s\n", "ccccccc");
	printf("p2 %.10s\n", "ccccccc");
    ft_printf("p2 %.10s\n", "ccccccc");
	printf("p3 %.4s\n", NULL);
    ft_printf("p3 %.4s\n", NULL);
	printf("p4 %.5s\n", "aaaaaaaa");
    ft_printf("p4 %.5s\n", "aaaaaaaa");
	printf("p5 %.3d\n", 100);
    ft_printf("p5 %.3d\n", 100);
	printf("p6 %.0d\n", 100);
    ft_printf("p6 %.0d\n", 100);
	printf("p7 %.5d\n", 100);
    ft_printf("p7 %.5d\n", 100);
	printf("p8 %.10d\n", 100);
    ft_printf("p8 %.10d\n", 100);
	printf("p9 %.50d\n", 100);
    ft_printf("p9 %.50d\n", 100);
	printf("p10 %.1d\n", 100);
    ft_printf("p10 %.1d\n", 100);
    printf("p11 %.3d\n", 100);
    ft_printf("p11 %.3d\n",100);
	printf("p12 %.0d\n", 0);
    ft_printf("p12 %.0d\n", 0);
	printf("p13 %.3i\n", 100);
    ft_printf("p13 %.3i\n", 100);
	printf("p14 %.0i\n", 100);
    ft_printf("p14 %.0i\n", 100);
	printf("p15 %.4i\n", 100);
    ft_printf("p15 %.4i\n", 100);
	printf("p16 %.10i\n", 100);
    ft_printf("p16 %.10i\n", 100);
	printf("p17 %.50i\n", 100);
    ft_printf("p17 %.50i\n", 100);
	printf("p18 %.1i\n", 100);
    ft_printf("p18 %.1i\n", 100);
	printf("p19 %.3x\n", 100);
    ft_printf("p19 %.3x\n", 100);
	printf("p20 %.0x\n", 0);
    ft_printf("p20 %.0x\n", 0);
	printf("p21 %.3x\n", 100);
    ft_printf("p21 %.3x\n", 100);
	printf("p22 %.0x\n", 100);
    ft_printf("p22 %.0x\n", 100);
	printf("p23 %.4x\n", 100);
    ft_printf("p23 %.4x\n", 100);
	printf("p24 %.10x\n", 100);
    ft_printf("p24 %.10x\n", 100);
	printf("p25 %.50x\n", 100);
    ft_printf("p25 %.50x\n", 100);
	printf("p26 %.1x\n", 100);
    ft_printf("p26 %.1x\n", 100);
	printf("p27 %.3x\n", 100);
    ft_printf("p27 %.3x\n", 100);
	printf("p28 %.0x\n", 0);
    ft_printf("p28 %.0x\n", 0);
	printf("p29 %.3u\n", 100);
    ft_printf("p29 %.3u\n", 100);
	printf("p30 %.0u\n", 100);
    ft_printf("p30 %.0u\n", 100);
	printf("p31 %.4u\n", 100);
    ft_printf("p31 %.4u\n", 100);
	printf("p32 %.10u\n", 100);
    ft_printf("p32 %.10u\n", 100);
	printf("p33 %.50u\n", 100);
    ft_printf("p33 %.50u\n", 100);
	printf("p34 %.1u\n", 100);
    ft_printf("p34 %.1u\n", 100);
	printf("p35 %.3u\n", 100);
    ft_printf("p35 %.3u\n", 100);
	printf("p36 %.0u\n", 0);
    ft_printf("p36 %.0u\n", 0);

	printf("%d  %d", result, true_result);


    system("leaks a.out > leaks_printf.txt");
	return (0);
   
}


