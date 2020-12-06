#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **str_split(char *buffer, char *delim, size_t *count)
{
	int len;
	char **retargs, *token, *rest;

	rest = buffer;
	len = strlen(buffer);
	retargs = malloc(1 * sizeof(char *));

	token = strtok_r(rest, delim, &rest);

	while(token)
	{
		retargs = realloc(retargs, (*count + 1) * sizeof(char *));
		retargs[(*count)++] = token;

		token = strtok_r(NULL, delim, &rest);
	}

	return retargs;
}

int main()
{
	size_t count = 0;
	char **argv;
	char buffer[] = "Im A Programmer";

	argv = str_split(buffer, " ", &count);

	printf("[%s] [%s] [%s]\n", argv[0], argv[1], argv[2]);

	free(argv);

	return 0;
}
