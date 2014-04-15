#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef X
#error X is not defined
#endif

void line_ms_cp(int dst[X*X], int src[X*X])
{
	memcpy(dst, src, (X*X)*sizeof(int));

	return;
}

void line_ms_rotate(int ms[X*X])
{
	int i, j;
	int res[X*X];

	for(i=0; i<X; i++)
		for(j=0; j<X; j++)
			res[i+(X-j-1)*X]=ms[j+i*X];

	line_ms_cp(ms, res);

	return;
}

void line_ms_reverse(int ms[X*X])
{
	int i, j;
	int res[X*X];

	for(i=0; i<X; i++)
		for(j=0; j<X; j++)
			res[(X-j-1)+i*X]=ms[j+i*X];

	line_ms_cp(ms, res);

	return;
}

void str_to_ms(int ms[X*X], char *str)
{
        int i;

        for(i=0; i<X*X; i++)
                ms[i]=(int)strtol(str, &str, 10);

        return;
}

void line_ms_output(int ms[X*X])
{
	int i;

	for(i=0; i<X*X; i++)
		printf("%d%c", ms[i], i!=(X*X-1)?' ':'\n');

	return;
}

int main()
{
	char buf[0xffff];
	int ms[X*X];

	while(!feof(stdin)){
		if(!fgets(buf, 0xffff, stdin))
			break;
		str_to_ms(ms, buf);

#define ROTATESEQ	\
{	\
	line_ms_output(ms);	\
	line_ms_rotate(ms);	\
	line_ms_output(ms);	\
	line_ms_rotate(ms);	\
	line_ms_output(ms);	\
	line_ms_rotate(ms);	\
	line_ms_output(ms);	\
}

		ROTATESEQ
		line_ms_reverse(ms);
		ROTATESEQ
	}

	return 0;
}
