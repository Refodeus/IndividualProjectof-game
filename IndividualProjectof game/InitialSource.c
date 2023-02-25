#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include "DefinitionOfFunctions.h"
const CountOfSteps = 10;
const Health = 5;
void HealthPoints(int* Arrow, int firstCoordinate, int secondCoordinate, int HorizontalCoordinate, int VerticalCoordinate, int *HP, int *CountStep, int *RightAns)
{
	(* CountStep)++;
	if (Arrow[(secondCoordinate - 1) * HorizontalCoordinate + firstCoordinate - 1] != '#')
	{
		(*HP)--;
	}
	else
		RightAns++;
	system("cls");
	if (*CountStep != CountOfSteps)
	{
		if (*HP != 0)
		{
			printf("\t    Игра \"Звездочки\"\n");
			printf("Всего жизней: %d\n", *HP);
			for (int i = 0; i < VerticalCoordinate; i++)
			{
				for (int j = 0; j < HorizontalCoordinate; j++)
					*(Arrow + i * HorizontalCoordinate + j) = '*';
			}
			RandomGeneration(Arrow, HorizontalCoordinate, VerticalCoordinate, HP, CountStep, RightAns);
		}
		else
		{
			int variant;
			printf("\t    Игра \"Звездочки\"\n");
			printf("Количество правильных ответов: %d\t", *RightAns);
			printf("Количество ходов: %d\n", *CountStep);
			free(Arrow);
			do
			{
				printf("Начать игру заново?\n1)Да.\n2)Нет.\n");
				scanf("%d", &variant);
				switch (variant)
				{
				case 1: system("cls"); printf("\t    Игра \"Звездочки\"\n"); RenderingField(Arrow); break;
				case 2: break;
				default: printf("Введите правильный вариант!\n");
				}
			} while ((variant < 1) || (variant > 2));

		}
	}
	else
	{
		int variant;
		printf("\t    Игра \"Звездочки\"\n");
		printf("\t    В Ы   П О Б Е Д И Л И!\n");
		do
		{
			printf("Начать игру заново?\n1)Да.\n2)Нет.\n");
			scanf("%d", &variant);
			switch (variant)
			{
			case 1: system("cls"); printf("\t    Игра \"Звездочки\"\n"); RenderingField(Arrow); break;
			case 2: break;
			default: printf("Введите правильный вариант!\n");
			}
		} while ((variant < 1) || (variant > 2));
	}
}
void ComparingCoordinate(int* Arrow, int HorizontalCoordinate, int VerticalCoordinate, int *HP, int *CountStep, int *RightAns)
{
	int firstCoordinate, secondCoordinate;
	do
	{
		printf("Введите предполагаемые координаты:\n");
		scanf("%d", &firstCoordinate); scanf("%d", &secondCoordinate);
	} while (firstCoordinate <= 0 || secondCoordinate <= 0 || (firstCoordinate > HorizontalCoordinate || secondCoordinate > VerticalCoordinate));
	HealthPoints(Arrow, firstCoordinate, secondCoordinate, HorizontalCoordinate, VerticalCoordinate, HP, CountStep, RightAns);
}
void RandomGeneration(int* Arrow, int HorizontalCoordinate, int VerticalCoordinate, int *HP, int *CountStep, int *RightAns)
{
	int NumberCell, Choose;
	srand(time(NULL));
	NumberCell = rand() % (HorizontalCoordinate * VerticalCoordinate);
	*(Arrow + NumberCell) = '#';
	for (int i = 0; i < VerticalCoordinate; i++)
	{
		printf("\t\t");
		for (int j = 0; j < HorizontalCoordinate; j++)
			printf("%c ", *(Arrow + i * HorizontalCoordinate + j));
		printf("\n");
	}
	ComparingCoordinate(Arrow, HorizontalCoordinate, VerticalCoordinate, HP, CountStep, RightAns);
}
void RenderingField(int* Arrow)
{
	int HorizontalCoordinate, VerticalCoordinate, HP = 5, CountStep = 0, RightAns = 0;
	printf("    Для начала задайте размеры выводимого поля (Значения от 2 и более):\n");
	do
	{
		printf("  По горизонтали: "); scanf("%d", &HorizontalCoordinate);
		printf("  По вертикали: "); scanf("%d", &VerticalCoordinate);
	} while (HorizontalCoordinate < 2 || VerticalCoordinate < 2);
	system("cls");
	printf("\t    Игра \"Звездочки\"\n");
	printf("Всего жизней: %d\n", HP);
	Arrow = (char*)malloc(HorizontalCoordinate * VerticalCoordinate * sizeof(char*));
	for (int i = 0; i < VerticalCoordinate; i++)
	{
		for (int j = 0; j < HorizontalCoordinate; j++)
			*(Arrow + i * HorizontalCoordinate + j) = '*';
	}
	RandomGeneration(Arrow, HorizontalCoordinate, VerticalCoordinate, &HP, &CountStep, &RightAns);
}
