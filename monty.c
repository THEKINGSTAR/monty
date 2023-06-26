#include "monty.h"

/**
 * main - the start fo the program
 * main fucntion fo the program
 * @argc: coutn of argumnets
 * @argv: args
 *
 * Return: 0 if success
 *
 *
 */

int main(int argc, char *argv[])
{
	FILE *fl_read;
	char *bufr = NULL;
	size_t bufr_siz = 0, lines = 0, lenght = 0;
	stack_t *op_stck = NULL;

	if (argc != 2)
	{
		dprintf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fl_read = fopen(argv[1], "r");
	if (!fl_read)
	{
		dprintf("Cant open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	lenght = getline(&bufr, bufr_siz, fl_read);
	while (lenght > 0)
	{
		lines++;
		opcod_stack(buf, lines, op_stck);
		lenght = getline(&bufr, bufr_siz, fl_read);
	}
	free(bufr);
	fclose(fl_read);
	free_stck(op_stck);
	return (0);
}
