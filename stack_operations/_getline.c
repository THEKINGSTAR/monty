#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGHT 100

int main(int argc, char *argv[])
{
	FILE *read;
	char line[MAX_LINE_LENGHT];

	if (argc < 2)
	{
                printf("usage ./monty file_name\n");
                return (1);
        }

	read = fopen(argv[1], "r");

	while (fgets(line, MAX_LINE_LENGHT, read)!= NULL)
	{
		printf("%s",line);
	}
	return (0);
}
