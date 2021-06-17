#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char *ptr;
	char *ptr_null;

	ptr_null = 0;
	ptr = (char*)malloc(1 * sizeof(char));
	ptr[0] = '\0';

	printf("Address of allocated memory with value of nul character\n\
			: %p\nAddress of NULL pointer :\n%p\n", ptr, ptr_null);
	return (0);
}
