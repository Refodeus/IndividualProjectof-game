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
			printf("\t    ���� \"���������\"\n");
			printf("����� ������: %d\n", *HP);
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
			printf("\t    ���� \"���������\"\n");
			printf("���������� ���������� �������: %d\t", *RightAns);
			printf("���������� �����: %d\n", *CountStep);
			free(Arrow);
			do
			{
				printf("������ ���� ������?\n1)��.\n2)���.\n");
				scanf("%d", &variant);
				switch (variant)
				{
				case 1: system("cls"); printf("\t    ���� \"���������\"\n"); RenderingField(Arrow); break;
				case 2: break;
				default: printf("������� ���������� �������!\n");
				}
			} while ((variant < 1) || (variant > 2));

		}
	}
	else
	{
		int variant;
		printf("\t    ���� \"���������\"\n");
		printf("\t    � �   � � � � � � � �!\n");
		do
		{
			printf("������ ���� ������?\n1)��.\n2)���.\n");
			scanf("%d", &variant);
			switch (variant)
			{
			case 1: system("cls"); printf("\t    ���� \"���������\"\n"); RenderingField(Arrow); break;
			case 2: break;
			default: printf("������� ���������� �������!\n");
			}
		} while ((variant < 1) || (variant > 2));
	}
}
void ComparingCoordinate(int* Arrow, int HorizontalCoordinate, int VerticalCoordinate, int *HP, int *CountStep, int *RightAns)
{
	int firstCoordinate, secondCoordinate;
	do
	{
		printf("������� �������������� ����������:\n");
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
	printf("    ��� ������ ������� ������� ���������� ���� (�������� �� 2 � �����):\n");
	do
	{
		printf("  �� �����������: "); scanf("%d", &HorizontalCoordinate);
		printf("  �� ���������: "); scanf("%d", &VerticalCoordinate);
	} while (HorizontalCoordinate < 2 || VerticalCoordinate < 2);
	system("cls");
	printf("\t    ���� \"���������\"\n");
	printf("����� ������: %d\n", HP);
	Arrow = (char*)malloc(HorizontalCoordinate * VerticalCoordinate * sizeof(char*));
	for (int i = 0; i < VerticalCoordinate; i++)
	{
		for (int j = 0; j < HorizontalCoordinate; j++)
			*(Arrow + i * HorizontalCoordinate + j) = '*';
	}
	RandomGeneration(Arrow, HorizontalCoordinate, VerticalCoordinate, &HP, &CountStep, &RightAns);
}
