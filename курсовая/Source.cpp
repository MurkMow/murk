#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <locale.h>
#include <string.h>
#include <windows.h >
const int N = 2; // ���������� ������
	struct Team {
		char cape[15];
		int all;
		int win;
		int lose;
		int point;
		float NNR;
		const char* winlose[100];
	};
	int main()
	{
		char name4[15];
		int sw = 0;
		int n = 0;
		int num = 0;
	     int num2 = 0;
		 //char name4[15];
		int k = 0, b = 0;
		system("chcp 1251");
		system("cls");
		Team commande[N];
		commande[0].all = 15;
		commande[0].win = 15;
		commande[0].lose = 5;
		commande[0].point = 8;
		commande[0].NNR = 0.392;
		commande[1].all = 25;
		commande[1].win = 35;
		commande[1].lose = 25;
		commande[1].point = 28;
		commande[1].NNR = 0.492;
		//for (int i = 0; i < N; i++) {
			//printf("������� �������� �������: \n");
			//gets_s(commande[i].cape);
		//}
		for (int i = 0; i < N; i++) {
			printf("������� �������� �������: \n");
			scanf("%s", &commande[i].cape);
			//printf("������� ���-�� ��� �������: \n");
			//scanf("%d", &commande[i].all);
			//printf("������� ���-�� ����� ��������: \n");
			//scanf("%d", &commande[i].win);
			//printf("������� ���-�� ��������� �������: \n");
			//scanf("%d", &commande[i].lose);
			//printf("������� ���-�� ����� �������: \n");
			//scanf("%d", &commande[i].point);
			//printf("������� NNR �������: \n");
			//scanf("%f", &commande[i].NNR);
			printf("������� ����� ��� �������: \n");
			scanf("%s", &commande[i].winlose);
		}
		for (int q = 0; q < 100; q++) {
			int m = 0;
			printf("�������� ����� �� ���� \n");
			printf("1. ����� ������� ����������� \n");
			printf("2. ���������� ������ �� ���������� (��������) \n");
			printf("3. ����� ������� \n");
			printf("4. ����� �� ���������\n");
			printf("-->");
			scanf_s("%d", &sw);
			switch (sw) {
			case 1: {
				printf("----------------------------------------------------------------------------\n");
				printf("|%3s|%14s|%10s|%6s|%6s|%6s|%6s|%13s|\n", "�", "��� �������", "��� �����", "�����", "���������", "�����", "NNR", "������� �����");
				printf("----------------------------------------------------------------------------");
				for (int i = 0; i < N; i++) {
					printf("\n");
					printf("|%2d|", i + 1);
					printf("|%14s|", commande[i].cape);
					printf("|%8d|", commande[i].all);
					printf("|%6d|", commande[i].win);
					printf("|%8d|", commande[i].lose);
					printf("|%5d|", commande[i].point);
					printf("|%6.3f|", commande[i].NNR);
					printf("|%9s  |", commande[i].winlose);

				}
				printf("\n");
				printf("----------------------------------------------------------------------------\n");
				break;
			}
			case 2 : {
				for (int i = 0; i < N; i++)
				{
					for (int j = i + 1; j < N; j++)
					{
						if (commande[i].point < commande[j].point)
						{
							Team commande1 = commande[i];
							commande[i] = commande[j];
							commande[j] = commande1;
						}
						else if (commande[i].point == commande[j].point)
						{
							if (commande[i].NNR < commande[j].NNR)
							{
								Team commande1 = commande[i];
								commande[i] = commande[j];
								commande[j] = commande1;
							}
						}
					}
					
				}
				printf(" ������ ������� �������������\n");
				break;
			}//����� 2 �����
			case 3: {
				num = 0;
				printf("������� �������� �������: \n");
				fflush(stdin);
				//gets_s(name4,15);
				scanf("%s", &name4);
				for (int i = 0; i < N; i++) {
					if (strcmp(name4, commande[i].cape) == 0) {
						num2 = num2 + 1;
						printf("----------------------------------------------------------------------------\n");
						printf("|%3s|%14s|%10s|%6s|%6s|%6s|%6s|%13s|\n", "�", "��� �������", "��� �����", "�����", "���������", "�����", "NNR", "������� �����");
						printf("----------------------------------------------------------------------------");
						printf("\n");
						printf("|%2d|", num+1);
						printf("|%14s|", commande[num].cape);
						printf("|%8d|", commande[num].all);
						printf("|%6d|", commande[num].win);
						printf("|%8d|", commande[num].lose);
						printf("|%5d|", commande[num].point);
						printf("|%6.3f|", commande[num].NNR);
						printf("|%9s  |", commande[num].winlose);
						printf("\n");
						printf("----------------------------------------------------------------------------\n");
					}
					num += 1;
				}
					if (num2==0) printf("�������� �� �������, ��������� ����� \n");
					break;
				}
			case 4: {
				return(0);
			}
			default:
				printf("������� �������� ��������");
				break;
			}
			}

		}
	
