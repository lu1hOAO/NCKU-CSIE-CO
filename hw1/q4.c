#include<stdio.h>
int main()
{
	int i=0;
	int h[9]={0}, x[3]={0}, y[3]={0};
	FILE *input = fopen("../input/4.txt","r");
	for(i = 0; i<9; i++) fscanf(input, "%d", &h[i]);
	for(i = 0; i<3; i++) fscanf(input, "%d", &x[i]);
	for(i = 0; i<3; i++) fscanf(input, "%d", &y[i]);
	fclose(input);
	int *p_x = &x[0] ;
	int *p_h = &h[0] ;
	int *p_y = &y[0] ;
	asm volatile(
		"addi t6, zero, 0\n\t"
		"addi t0, zero, 3\n\t"
		"loop:"
		"lw t1, 0(%[ph])\n\t"
		"lw t2, 4(%[ph])\n\t"
		"lw t3, 8(%[ph])\n\t"
		"lw t4, 0(%[py])\n\t"
		"mul t5, t1, %[X1]\n\t"
		"add t4, t4, t5\n\t"
		"mul t5, t2, %[X2]\n\t"
		"add t4, t4, t5\n\t"
		"mul t5, t3, %[X3]\n\t"
		"add t4, t4, t5\n\t"
		"sw t4, 0(%[py])\n\t"
		"addi t6, t6, 1\n\t"
		"addi %[ph], %[ph], 12\n\t"
		"addi %[py], %[py], 4\n\t"
		"bne t6, t0, loop\n\t"
		:[ph] "+r"(p_h),[py] "+r"(p_y)
		:[X1] "r"(*p_x),[X2] "r"(*(p_x+1)), [X3] "r"(*(p_x+2))
  		:"t0","t1","t2","t3","t4","t5","t6"		  
			);
	p_y = &y[0];
	for(i = 0; i<3; i++)
		printf("%d \n", *p_y++);
	return(0) ;
}
