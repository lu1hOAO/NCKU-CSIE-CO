#include<stdio.h>
int main(){
	int a,b;
	FILE *input=fopen("../input/1.txt","r");
	fscanf(input,"%d %d",&a,&b);
	fclose(input);
	asm volatile(
		"sub %[A], %[A], %[B]\n\t"
		:[A] "+r"(a) //read and write
		:[B] "r"(b) 
		);
	printf("%d\n",a);
	return 0;
}
		
