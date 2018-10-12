#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>

int main(int argc, char* argv[])
{

	int *a, *b, *c;

	char arr[1024*1024*6];
	//syscall(333,getpid());
	//printf("pid = %d\n", getpid());
	//sleep(1);
	
	/* works fine */
	
	a = (int *)mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_ANON|MAP_PRIVATE, -1, 0);
	b = (int *)mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_ANON|MAP_SHARED, -1, 0);
	c = (int *)mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_ANON|MAP_SHARED, -1, 0);
	printf("a=%p, b=%p, c=%p\n",a,b,c);
	syscall(333,getpid());
	*a = 1;
	*b = 2;
	*c = 3;
	printf("accessing b first %d\n", *b);
	printf("accessing a next %d\n", *a);
	*(b+10) = 20;
	printf("accessing c last %d\n", *c);
	*(a+20) = 20;
	
	return 0;
}
