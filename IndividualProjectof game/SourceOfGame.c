#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include "DefinitionOfFunctions.h"
int main()
{
	char* Arrow = NULL;
	setlocale(LC_ALL, "Russian");
	printf("\t\tИгра \"Звездочки\"\n");
	RenderingField(Arrow);
	return 0;
}