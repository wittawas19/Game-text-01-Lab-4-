#include <stdio.h>
#include <windows.h>
#include <conio.h>


void gotoxy(int x, int y);
void draw_ship(int x, int y);
void erase_ship(int x, int y);
int main()
{
	char ch = ' ';
	int x = 40 , y = 5;
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a') //ลองเปลี่ยนจาก ใส่เงื่อนไขถึงกดได้ เป็นถ้ากด ให้ทำตามเงื่อนไขแทน
			{
				if (x > 0)
				{
					draw_ship(x--, y);
				}
				else
				{
					draw_ship(x, y); 
				}
			}
			if (ch == 'd')
			{
				if (x < 81)
				{
					draw_ship(x++, y);
				}
				else
				{
					draw_ship(x, y);
				}
			}
			if (ch == 'w')
			{
				if(y > 0)
				{
					draw_ship(x, --y);
					erase_ship(x, y + 1);
				}
			}
			if (ch == 's')
			{
				if (y < 24)
				{
					draw_ship(x, ++y);
					erase_ship(x, y - 1);
				}
			}
		
		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}



void erase_ship(int x, int y)
{
	gotoxy(x, y);
	printf("        ");

}
void draw_ship(int x , int y)
{
	gotoxy(x , y);
	printf(" <-0-> ");
}
void gotoxy(int x, int y)
{
	COORD c = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}