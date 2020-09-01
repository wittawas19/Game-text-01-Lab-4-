#include <stdio.h>
#include <windows.h>


void gotoxy(int x, int y);
void drawShip(void);



int main()
{
	gotoxy(10, 5);
	drawShip();
}





void drawShip(void)
{

	printf("<-0->");
	
}
void gotoxy(int x, int y)
{
	COORD c = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}