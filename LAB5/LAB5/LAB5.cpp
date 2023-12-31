#include<stdio.h>
#include<windows.h>
#include<conio.h>

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_ship(int x , int y)
{
	gotoxy(x, y);
	printf(" <-0-> ");
	
}

void erase_ship(int x, int y)
{
	gotoxy(x, y);
	printf("       ");

}

int main()
{
	char ch = ' ';
	int x = 28, y = 28;
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (x != 0)
			{
				if (ch == 'a') { draw_ship(--x, y); }
			}
			if (x != 112)
			{
				if (ch == 'd') { draw_ship(++x, y); }
			}
			if (y != 0)
			{
				if (ch == 'w') { erase_ship(x, y); draw_ship(x, --y); }
			}
			if (y != 28)
			{
				if (ch == 's') { erase_ship(x, y); draw_ship(x, ++y); }
			}
			fflush(stdin);
		}
		Sleep(100);
		
	} while (ch != 'x');
	return 0;
}




