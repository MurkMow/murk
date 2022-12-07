#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <locale.h>
#include <string.h>
#include <windows.h >
const int N = 2; // КОЛИЧЕСТВО КОМАНД
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
			//printf("Введите название команды: \n");
			//gets_s(commande[i].cape);
		//}
		for (int i = 0; i < N; i++) {
			printf("Введите название команды: \n");
			scanf("%s", &commande[i].cape);
			//printf("Введите кол-во игр команды: \n");
			//scanf("%d", &commande[i].all);
			//printf("Введите кол-во побед комманды: \n");
			//scanf("%d", &commande[i].win);
			//printf("Введите кол-во поражений команды: \n");
			//scanf("%d", &commande[i].lose);
			//printf("Введите кол-во очков команды: \n");
			//scanf("%d", &commande[i].point);
			//printf("Введите NNR команды: \n");
			//scanf("%f", &commande[i].NNR);
			printf("Введите серию игр команды: \n");
			scanf("%s", &commande[i].winlose);
		}
		for (int q = 0; q < 100; q++) {
			int m = 0;
			printf("Выберите пункт из меню \n");
			printf("1. Вывод таблицы результатов \n");
			printf("2. Сортировка команд по результату (убывание) \n");
			printf("3. Поиск команды \n");
			printf("4. Выход из программы\n");
			printf("-->");
			scanf_s("%d", &sw);
			switch (sw) {
			case 1: {
				printf("----------------------------------------------------------------------------\n");
				printf("|%3s|%14s|%10s|%6s|%6s|%6s|%6s|%13s|\n", "№", "Имя команды", "Игр всего", "Побед", "Поражений", "Очков", "NNR", "Текущая серия");
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
				printf(" Данные успешно отсортированы\n");
				break;
			}//конец 2 кейса
			case 3: {
				num = 0;
				printf("Введите название команды: \n");
				fflush(stdin);
				//gets_s(name4,15);
				scanf("%s", &name4);
				for (int i = 0; i < N; i++) {
					if (strcmp(name4, commande[i].cape) == 0) {
						num2 = num2 + 1;
						printf("----------------------------------------------------------------------------\n");
						printf("|%3s|%14s|%10s|%6s|%6s|%6s|%6s|%13s|\n", "№", "Имя команды", "Игр всего", "Побед", "Поражений", "Очков", "NNR", "Текущая серия");
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
					if (num2==0) printf("Комманда не найдена, повторите поиск \n");
					break;
				}
			case 4: {
				return(0);
			}
			default:
				printf("Введено неверное значение");
				break;
			}
			}

		}
	
