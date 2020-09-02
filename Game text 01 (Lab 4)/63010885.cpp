#include <stdio.h>
#include <windows.h>
#include <conio.h>


void gotoxy(int x, int y);
void draw_ship(int x, int y);
void erase_ship(int x, int y);
// ลอลคิดกลับดูเป็นจาก condition = printf เป็น
int main()
{
	char ch = ' ';
	int x = 79 , y = 0;
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (x < 81 && y > 0 && x > 0 && y < 24 )
			{
				if (ch == 'a') { draw_ship(--x, y); }
				if (ch == 'd') {draw_ship(++x, y) ; }
				if (ch == 'w') {draw_ship(x, --y);erase_ship(x, y+1); }
				if (ch == 's') {draw_ship(x, ++y);erase_ship(x, y-1); }
				fflush(stdin);
			}
			else if (y <= 0 && x >= 81)
			{
				if (ch == 'a') { draw_ship(--x, y); }
				if (ch == 's') { draw_ship(x, ++y); erase_ship(x, y - 1); }
				fflush(stdin);
			}
			else if (x <= 0 && y <= 0)
			{
				if (ch == 'd') { draw_ship(++x, y); }
				if (ch == 's') { draw_ship(x, ++y); erase_ship(x, y - 1); }
				fflush(stdin);
			}
			else if (x <= 0 && y >= 24)
			{
				if (ch == 'd') { draw_ship(++x, y); }
				if (ch == 'w') { draw_ship(x, --y); erase_ship(x, y + 1); }
				fflush(stdin);
			}
			else if (y >= 24 && x >= 81)
			{
				if (ch == 'a') { draw_ship(--x, y); }
				if (ch == 'w') { draw_ship(x, --y); erase_ship(x, y + 1); }
				fflush(stdin);
			}
			else if (x <= 0)
			{
				if (ch == 'd') { draw_ship(++x, y); }
				if (ch == 'w') { draw_ship(x, --y); erase_ship(x, y + 1); }
				if (ch == 's') { draw_ship(x, ++y); erase_ship(x, y - 1); }
				fflush(stdin);
			}
			else if (y >= 24)
			{
				if (ch == 'a') { draw_ship(--x, y); }
				if (ch == 'd') { draw_ship(++x, y); }
				if (ch == 'w') { draw_ship(x, --y); erase_ship(x, y + 1); }
				fflush(stdin);
			}
			else if (x >= 81)
			{
				if (ch == 'a') { draw_ship(--x, y); }
				if (ch == 'w') { draw_ship(x, --y); erase_ship(x, y + 1); }
				if (ch == 's') { draw_ship(x, ++y); erase_ship(x, y - 1); }
				fflush(stdin);
			}
			else if (y <= 0)
			{
				if (ch == 'a') { draw_ship(--x, y); }
				if (ch == 'd') { draw_ship(++x, y); }
				if (ch == 'w') { draw_ship(x, y); erase_ship(x, y + 1); }
				if (ch == 's') { draw_ship(x, ++y); erase_ship(x, y - 1); }
				fflush(stdin);
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