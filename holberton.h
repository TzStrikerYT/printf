#ifndef _PRINT_F
#define _PRINT_F

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct opc - Struct to find function
 * @c: char to check
 * @f: Pointer to function to call
 */

typedef struct opc
{
	char *c;
	int (*f)();
} print_opc;

int _puts(char *str);
int print_u(va_list valist);
int _print_binary(va_list valist);
char *convert(unsigned long int num, int base);
int _putchar(int c);
int buffchar(char c);
void write_buffer(char buffer[], int *bufflen, int *buffpos);
void create_buffer(char buffer[]);
int _printf(const char *format, ...);
int print_c(va_list args, char buffer[], int *bufflen, int *buffpos);
int print_s(va_list args, char buffer[], int *bufflen, int *buffpos);
int numbers(int n, char buffer[], int *bufflen, int *buffpos);
int print_int(va_list args, char buffer[], int *bufflen, int *buffpos);

int opc_print(char formatter, print_opc opc[], char buffer[],
	      int *bufflenptr, int *buffposptr, va_list print_this);

int to_format(const char *format, va_list print, char buffer[],
	      int *bufflenptr, int *buffposptr, print_opc opc[]);

int copy_buffer(char formatter, char buffer[],
		int *bufflenptr, int *buffposptr);

#endif
