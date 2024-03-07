#include<stdio.h>
int main()
{
	int f,i=0;
	int h[9]={0}, x[3]={0}, y[3]={0};
	FILE *input = fopen("../input/3.txt","r");
	for(i = 0; i<9; i++) fscanf(input, "%d", &h[i]);
	for(i = 0; i<3; i++) fscanf(input, "%d", &x[i]);
	for(i = 0; i<3; i++) fscanf(input, "%d", &y[i]);
	fclose(input);
	int *p_x = &x[0] ;
	int *p_h = &h[0] ;
	int *p_y = &y[0] ;
	for (i = 0 ; i < 3; i++)
	{	
		p_x = &x[0] ;
		for (f = 0 ; f < 3; f++)
			asm volatile(
				"mul t0, %[X], %[H]\n\t"//t0 as reg(reference)
			       	"add %[Y], %[Y], t0\n\t"//add
				:[Y] "+r"(*(p_y+i))
				:[X] "r"(*(p_x+f)),[H] "r"(*(p_h+3*i+f))
				:"t0"
			);
	}
	p_y = &y[0];
	for(i = 0; i<3; i++)
		printf("%d \n", *p_y++);
	return(0) ;
}
