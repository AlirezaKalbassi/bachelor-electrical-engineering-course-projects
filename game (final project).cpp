#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <Windows.h>


void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

void main_page ();

void clrscr()
{
	system("cls");
}

void game_over();
void you_win();


int main()
{
	int x12=2, x21=1, x22=2, x23=3, x31=1, x33=3, y12=1, y21=2, y22=2, y23=2, y31=3, y33=3, chances=3;
	int  bx1 = 1, by1 = 5, bm1 = 0, bx2 = 1, by2 = 9, bm2 = 0, bx3 = 16, by3 = 14, bm3 = 0,bn3=0, bx4 = 17, by4 = 7, bm4 = 0;
	int  bx5 = 34, by5 = 12, bm5 = 0, bx6 = 34, by6 = 16, bm6 = 0, bx7 = 8, by7 = 26, bm7 = 0, bx8 = 8, by8 = 30, bm8 = 0;
	while (1)
	{
		main_page();
		//mane haye safe
		gotoxy(bx1, by1); // mane e 1 safe 1 
		printf("*");
		while (bm1 < 15)
		{
			if (bm1 > 13)
			{
				bx1 = 1;
				bm1 = 0;
				break;
			}
			bx1++;
			bm1++;
			break;
		}

		gotoxy(bx2, by2); // mane e 2 safe 1 
		printf("*");
		while (bm2 < 15)
		{
			if (bm2 > 13)
			{
				bx2 = 1;
				bm2 = 0;
				break;
			}
			bx2++;
			bm2++;
			break;
		}

		gotoxy(bx3, by3); // mane e 1 safe 2 
		printf("*");
		while (bm3 < 10)
		{
			if (bm3 > 8)
			{
				by3 = 14;
				bm3 = 0;
				break;
			}
			by3++;
			bm3++;
			break;
		}

		while (bn3 < 10)
		{
			if (bm3 > 8)
			{
				by3 = 16;
				bn3 = 0;
				break;
			}
			bx3++;
			bn3++;
			break;
		}

		gotoxy(bx4, by4); // mane e 2 safe 2 
		printf("*");
		while (bm4 < 16)
		{
			if (bm4 > 14)
			{
				bx4 = 17;
				bm4 = 0;
				break;
			}
			bx4++;
			bm4++;
			break;
		}

		gotoxy(bx5, by5); // mane e 1 safe 3 
		printf("*");
		while (bm5 < 19)
		{
			if (bm5 > 17)
			{
				bx5 = 34;
				bm5 = 0;
				break;
			}
			bx5++;
			bm5++;
			break;
		}

		gotoxy(bx6, by6); // mane e 2 safe 3 
		printf("*");
		while (bm6 < 19)
		{
			if (bm6 > 17)
			{
				bx6 = 34;
				bm6 = 0;
				break;
			}
			bx6++;
			bm6++;
			break;
		}

		gotoxy(bx7, by7); // mane e 1 safe 4 
		printf("*");
		while (bm7 < 45)
		{
			if (bm7 > 43)
			{
				bx7 = 8;
				bm7 = 0;
				break;
			}
			bx7++;
			bm7++;
			break;
		}

		gotoxy(bx8, by8); // mane e 2 safe 4 
		printf("*");
		while (bm8 < 45)
		{
			if (bm8 > 43)
			{
				bx8 = 8;
				bm8 = 0;
				break;
			}
			bx8++;
			bm8++;
			break;
		}
		// etmame kode mane haye safe
		//**********************************************************************************************************************************************************************************************************************************************************************
		//sakhtare adamak
		gotoxy(x12, y12);
		printf("*");
		gotoxy(x21, y21);
		printf("*");
		gotoxy(x22, y22);
		printf("*");
		gotoxy(x23, y23);
		printf("*");
		gotoxy(x31, y31);
		printf("*");
		gotoxy(x33, y33);
		printf("*");
		//**********************************************************************************************************************************************************************************************************************************************************************
		//kod haye harekate adamak
		if (_kbhit())
		{
			switch (_getch())
			{
			case 119:
				y12--;
				y21--;
				y22--;
				y23--;
				y31--;
				y33--;
				break;
			case 97:
				x12--;
				x21--;
				x22--;
				x23--;
				x31--;
				x33--;
				break;
			case 115:
				y12++;
				y21++;
				y22++;
				y23++;
				y31++;
				y33++;
				break;
			case 100:
				x12++;
				x21++;
				x22++;
				x23++;
				x31++;
				x33++;
				break;
			}
		}
			//**********************************************************************************************************************************************************************************************************************************************************************
			//kodhaye emale ghavanin
			if (x21 == 0 || y12 == 0 || x23 == 53 || y31 == 34) // 4 divare 
			{
				clrscr();
				game_over();
				return 0;
			}
			if (x21 == 16 && y21 >= 1 && y21 <= 13 || x23 == 16 && y21 >= 1 && y21 <= 13) // khate amoodiye 1
			{
				clrscr();
				game_over();
				return 0;
			}
			if (x21 == 33 && y21 >= 7 && y21 <= 24 || x23 == 33 && y21 >= 7 && y21 <= 24) // khate amoodiye 2
			{
				clrscr();
				game_over();
				return 0;
			}
			if (x21 == 7 && y21 >= 20 && y21 <= 30 || x23 == 7 && y21 >= 20 && y21 <= 30) // khate amoodiye 3
			{
				clrscr();
				game_over();
				return 0;
			}
			if (y12 == 7 && x12 >= 33 && x12 <= 40 || y12 == 7 && x12 >= 46 && x12 <= 52 || y31 == 7 && x31 >= 33 && x31 <= 40 || y31 == 7 && x31 >= 46 && x31 <= 52) // khate ofoghiye 1 az bala
			{
				clrscr();
				game_over();
				return 0;
			}
			if (y12 == 13 && x12 >= 0 && x12 <= 5 || y12 == 13 && x12 >= 11 && x12 <= 16 || y31 == 13 && x31 >= 0 && x31 <= 5 || y31 == 13 && x31 >= 11 && x31 <= 16) // khate ofoghiye 2 az bala
			{
				clrscr();
				game_over();
				return 0;
			}
			if (y12 == 20 && x12 >= 33 && x12 <= 40 || y12 == 20 && x12 >= 46 && x12 <= 52 || y31 == 20 && x31 >= 33 && x31 <= 40 || y31 == 20 && x31 >= 46 && x31 <= 52) // khate ofoghiye 3 az bala
			{
				clrscr();
				game_over();
				return 0;
			}
			if (y12 == 24 && x12 >= 8 && x12 <= 34 || y31 == 24 && x31 >= 8 && x31 <= 34) // khate ofoghiye 4 az bala
			{
				clrscr();
				game_over();
				return 0;
			}
			//**********************************************************************************************************************************************************************************************************************************************************************
			//kod haye barkhorde toop ha ba adamak
			if (x12 == bx1 && y12 == by1 || x12 == bx2 && y12 == by2 || x12 == bx3 && y12 == by3 || x12 == bx4 && y12 == by4 || x12 == bx5 && y12 == by5 || x12 == bx6 && y12 == by6 || x12 == bx7 && y12 == by7 || x12 == bx8 && y12 == by8) //setare 1 (satr) 1 (sotoon) az adamak
			{
				chances--;
				if (chances == 0)
				{
					clrscr();
					game_over();
					return 0;
				}
			}
			if (x21 == bx1 && y21 == by1 || x21 == bx2 && y21 == by2 || x21 == bx3 && y21 == by3 || x21 == bx4 && y21 == by4 || x21 == bx5 && y21 == by5 || x21 == bx6 && y21 == by6 || x21 == bx7 && y21 == by7 || x21 == bx8 && y21 == by8) //setare 21 az adamak
			{
				chances--;
				if (chances == 0)
				{
					clrscr();
					game_over();
					return 0;
				}
			}
			if (x22 == bx1 && y22 == by1 || x22 == bx2 && y22 == by2 || x22 == bx3 && y22 == by3 || x22 == bx4 && y22 == by4 || x22 == bx5 && y22 == by5 || x22 == bx6 && y22 == by6 || x22 == bx7 && y22 == by7 || x22 == bx8 && y22 == by8) //setare 22 az adamak
			{
				chances--;
				if (chances == 0)
				{
					clrscr();
					game_over();
					return 0;
				}
			}
			if (x23 == bx1 && y23 == by1 || x23 == bx2 && y23 == by2 || x23 == bx3 && y23 == by3 || x23 == bx4 && y23 == by4 || x23 == bx5 && y23 == by5 || x23 == bx6 && y23 == by6 || x23 == bx7 && y23 == by7 || x23 == bx8 && y23 == by8) //setare 23 az adamak
			{
				chances--;
				if (chances == 0)
				{
					clrscr();
					game_over();
					return 0;
				}
			}
			if (x31 == bx1 && y31 == by1 || x31 == bx2 && y31 == by2 || x31 == bx3 && y31 == by3 || x31 == bx4 && y31 == by4 || x31 == bx5 && y31 == by5 || x31 == bx6 && y31 == by6 || x31 == bx7 && y31 == by7 || x31 == bx8 && y31 == by8) //setare 31 az adamak
			{
				chances--;
				if (chances == 0)
				{
					clrscr();
					game_over();
					return 0;
				}
			}
			if (x33 == bx1 && y33 == by1 || x33 == bx2 && y33 == by2 || x33 == bx3 && y33 == by3 || x33 == bx4 && y33 == by4 || x33 == bx5 && y33 == by5 || x33 == bx6 && y33 == by6 || x33 == bx7 && y33 == by7 || x33 == bx8 && y33 == by8) //setare 33 az adamak
			{
				chances--;
				if (chances == 0)
				{
					clrscr();
					game_over();
					return 0;
				}
			}
			if (x33 == 52 && y33 == 33)
			{
				clrscr();
				you_win();
				return 0;
			}
			gotoxy(0, 35);
			printf("\nyour hearts : ");
			for (int i = 0; i < chances; i++)
			{
				printf("*");
			}
		clrscr();
	}
		return 0;
}






void main_page()
{
	printf("|----------------------------------------------------|\n");
	printf("|               |                                    |\n");
	printf("|               |                                    |\n");
	printf("|               |                                    |\n");
	printf("|               |                                    |\n");
	printf("|               |                                    |\n");
	printf("|               |                                    |\n");
	printf("|               |                |-------     -------|\n");
	printf("|               |                |                   |\n");
	printf("|               |                |                   |\n");
	printf("|               |                |                   |\n");
	printf("|               |                |                   |\n");
	printf("|               |                |                   |\n");
	printf("|-----     -----|                |                   |\n");
	printf("|                                |                   |\n");
	printf("|                                |                   |\n");
	printf("|                                |                   |\n");
	printf("|                                |                   |\n");
	printf("|                                |                   |\n");
	printf("|                                |                   |\n");
	printf("|                                |-------     -------|\n");
	printf("|                                |                   |\n");
	printf("|                                |                   |\n");
	printf("|                                |                   |\n");
	printf("|      |-------------------------|                   |\n");
	printf("|      |                                             |\n");
	printf("|      |                                             |\n");
	printf("|      |                                             |\n");
	printf("|      |                                             |\n");
	printf("|      |                                             |\n");
	printf("|      |                                             |\n");
	printf("|      |                                             |\n");
	printf("|      |                                             |\n");
	printf("|      |                                             |\n");
	printf("|------|---------------------------------------------|\n");
}

void game_over()
{
	printf("|------------------------------------------------------|\n");
	printf("|  GAME OVER                                           |\n");
	printf("|            GAME OVER                                 |\n");
	printf("|                      GAME OVER                       |\n");
	printf("|                                GAME OVER             |\n");
	printf("|                                          GAME OVER   |\n");
	printf("|                                          GAME OVER   |\n");
	printf("|                                GAME OVER             |\n");
	printf("|                      GAME OVER                       |\n");
	printf("|            GAME OVER                                 |\n");
	printf("|  GAME OVER                                           |\n");
	printf("|  GAME OVER                                           |\n");
	printf("|            GAME OVER                                 |\n");
	printf("|                      GAME OVER                       |\n");
	printf("|                                GAME OVER             |\n");
	printf("|                                          GAME OVER   |\n");
	printf("|                                          GAME OVER   |\n");
	printf("|                                GAME OVER             |\n");
	printf("|                      GAME OVER                       |\n");
	printf("|            GAME OVER                                 |\n");
	printf("|  GAME OVER                                           |\n");
	printf("|  GAME OVER                                           |\n");
	printf("|            GAME OVER                                 |\n");
	printf("|                      GAME OVER                       |\n");
	printf("|                                GAME OVER             |\n");
	printf("|                                          GAME OVER   |\n");
	printf("|                                          GAME OVER   |\n");
	printf("|                                GAME OVER             |\n");
	printf("|                      GAME OVER                       |\n");
	printf("|            GAME OVER                                 |\n");
	printf("|  GAME OVER                                           |\n");
	printf("|  GAME OVER                                           |\n");
	printf("|            GAME OVER                                 |\n");
	printf("|                       GAME OVER                      |\n");
	printf("|                                GAME OVER             |\n");
	printf("|                                          GAME OVER   |\n");
	printf("|------------------------------------------------------|\n");
}

void you_win()
{
	printf("|------------------------------------------------------|\n");
	printf("|  YOU WIN!!                                           |\n");
	printf("|            YOU WIN!!                                 |\n");
	printf("|                      YOU WIN!!                       |\n");
	printf("|                                YOU WIN!!             |\n");
	printf("|                                          YOU WIN!!   |\n");
	printf("|                                          YOU WIN!!   |\n");
	printf("|                                YOU WIN!!             |\n");
	printf("|                      YOU WIN!!                       |\n");
	printf("|            YOU WIN!!                                 |\n");
	printf("|  YOU WIN!!                                           |\n");
	printf("|  YOU WIN!!                                           |\n");
	printf("|            YOU WIN!!                                 |\n");
	printf("|                      YOU WIN!!                       |\n");
	printf("|                                YOU WIN!!             |\n");
	printf("|                                          YOU WIN!!   |\n");
	printf("|                                          YOU WIN!!   |\n");
	printf("|                                YOU WIN!!             |\n");
	printf("|                      YOU WIN!!                       |\n");
	printf("|            YOU WIN!!                                 |\n");
	printf("|  YOU WIN!!                                           |\n");
	printf("|  YOU WIN!!                                           |\n");
	printf("|            YOU WIN!!                                 |\n");
	printf("|                      YOU WIN!!                       |\n");
	printf("|                                YOU WIN!!             |\n");
	printf("|                                          YOU WIN!!   |\n");
	printf("|                                          YOU WIN!!   |\n");
	printf("|                                YOU WIN!!             |\n");
	printf("|                      YOU WIN!!                       |\n");
	printf("|            YOU WIN!!                                 |\n");
	printf("|  YOU WIN!!                                           |\n");
	printf("|  YOU WIN!!                                           |\n");
	printf("|            YOU WIN!!                                 |\n");
	printf("|                       YOU WIN!!                      |\n");
	printf("|                                YOU WIN!!             |\n");
	printf("|                                          YOU WIN!!   |\n");
	printf("|------------------------------------------------------|\n");
}
