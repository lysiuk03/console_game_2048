#include <iostream>
#include <iomanip>
#include<windows.h>
#include <ctime>
#include <conio.h>
#include <cstdlib>
using namespace std;
void textcolor(int color_code) 
{
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, color_code);
}
void hide() 
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(handle, &CursorInfo);
}
void Clear(int arr[][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			arr[i][j] = 0;
		}
	}
}
void paint(int count, int symbol)
{
	for (int i = 0; i < count; i++)
	{
		cout << (char)symbol;
	}
}
void space(int count)
{
	cout << setw(count);
}
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void frame()
{
	paint(52, 176);
	cout << endl;
	paint(23, 176);
	cout << " 2048 ";
	paint(23, 176);
	cout << endl;
	paint(52, 176);
	cout << endl;
	for (int i = 0; i < 13; i++)
	{
		paint(1, 176);
		space(51);
		paint(1, 176);
		cout << endl;
	}
	paint(52, 176);
}
void table()
{
	gotoxy(4, 6);
	paint(1, 201);
	paint(6, 205);
	paint(1, 209);
	paint(6, 205);
	paint(1, 209);
	paint(6, 205);
	paint(1, 209);
	paint(6, 205);
	paint(1, 187);
	cout << endl;
	int p = 6;
	for (int i = 0; i < 3; i++)
	{
		p++;
		gotoxy(4, p);
		paint(1, 186);
		space(7);
		paint(1, 179);
		space(7);
		paint(1, 179);
		space(7);
		paint(1, 179);
		space(7);
		paint(1, 186);
		cout << endl;

		p++;
		gotoxy(4, p);
		paint(1, 199);
		paint(6, 196);
		paint(1, 197);
		paint(6, 196);
		paint(1, 197);
		paint(6, 196);
		paint(1, 197);
		paint(6, 196);
		paint(1, 182);
	}

	gotoxy(4, 13);
	paint(1, 186);
	space(7);
	paint(1, 179);
	space(7);
	paint(1, 179);
	space(7);
	paint(1, 179);
	space(7);
	paint(1, 186);
	cout << endl;

	gotoxy(4, 14);
	paint(1, 200);
	paint(6, 205);
	paint(1, 207);
	paint(6, 205);
	paint(1, 207);
	paint(6, 205);
	paint(1, 207);
	paint(6, 205);
	paint(1, 188);
	cout << endl;
}
void menu()
{
	gotoxy(37, 7);
	cout << "W- up;" << endl;
	gotoxy(37, 8);
	cout << "S- down;" << endl;
	gotoxy(37, 9);
	cout << "A- left;" << endl;
	gotoxy(37, 10);
	cout << "D- right;" << endl;
}
void arrcolors(int arr)
{
	switch (arr)
	{
	case 2:
		textcolor(7);
		break;
	case 4:
		textcolor(8);
		break;
	case 8:
		textcolor(3);
		break;
	case 16:
		textcolor(11);
		break;
	case 32:
		textcolor(9);
		break;
	case 64:
		textcolor(14);
		break;
	case 128:
		textcolor(4);
		break;
	case 256:
		textcolor(5);
		break;
	case 512:
		textcolor(13);
		break;
	case 1024:
		textcolor(2);
		break;
	case 2048:
		textcolor(3);
		break;
	default:
		break;
	}
}
void show(int arr[][4])
{
	int j;
	j = 7;
	for (int i = 0; i < 4; i++)
	{
		gotoxy(6, j);
		if (arr[i][0] != 0)
		{
			arrcolors(arr[i][0]);
			cout << arr[i][0];
			textcolor(15);
		}
		j = j + 2;
	}
	j = 7;
	for (int i = 0; i < 4; i++)
	{
		gotoxy(13, j);
		if (arr[i][1] != 0)
		{
			arrcolors(arr[i][1]);
			cout << arr[i][1];
			textcolor(15);
		}
		j = j + 2;
	}
	j = 7;
	for (int i = 0; i < 4; i++)
	{
		gotoxy(20, j);
		if (arr[i][2] != 0)
		{
			arrcolors(arr[i][2]);
			cout << arr[i][2];
			textcolor(15);
		}
		j = j + 2;
	}
	j = 7;
	for (int i = 0; i < 4; i++)
	{
		gotoxy(27, j);
		if (arr[i][3] != 0)
		{
			arrcolors(arr[i][3]);
			cout << arr[i][3];
			textcolor(15);

		}
		j = j + 2;
	}
}
void SHOW(int arr[][4])
{
	frame();
	table();
	menu();
	show(arr);
}
void add(int arr[][4])
{
	int i = rand() % 4;
	int j = rand() % 4;
	while (arr[i][j] != 0)
	{
		i = rand() % 4;
		j = rand() % 4;
	}
	int t = rand() % 100 + 1;
	if (t > 20)
	{
		arr[i][j] = 2;
	}
	else
	{
		arr[i][j] = 4;
	}
}
int scores(int score_)
{
	static int score = 0;
	score += score_;
	return score;
}
int bestscores(int score)
{
	static int bestscore = 0;
	if (bestscore < score)
	{
		bestscore = score;
	}
	return bestscore;
}
void up(int arr[4][4], int& score)
{
	for (int j = 0; j < 4; j++) 
	{
		for (int i = 0; i < 4; i++) 
		{
			if (arr[i][j] > 0) 
			{
				int y = i;
				while (y > 0)
				{
					if (arr[y - 1][j] == 0)
					{
						arr[y - 1][j] = arr[y][j];
						arr[y][j] = 0;
					}
					else if (arr[y - 1][j] == arr[y][j])
					{
						arr[y - 1][j] = arr[y][j] * 2;
						score = scores(arr[y - 1][j]);
						arr[y][j] = 0;
						break;
					}
					y--;
				}
			}
		}
	}
	score = scores(0);
}
void down(int arr[4][4], int& score)
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 2; i >= 0; i--)
		{
			if (arr[i][j] > 0)
			{
				int y = i;
				while (y < 3)
				{
					if (arr[y + 1][j] == 0) 
					{
						arr[y + 1][j] = arr[y][j];
						arr[y][j] = 0;
					}
					else if (arr[y + 1][j] == arr[y][j]) 
					{
						arr[y + 1][j] = arr[y][j] * 2;
						score = scores(arr[y + 1][j]);
						arr[y][j] = 0;
						break;
					}
					y++;
				}
			}
		}
	}
	score = scores(0);
}
void right(int arr[4][4], int& score)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j >= 0; j--)
		{
			if (arr[i][j] > 0)
			{
				int x = j;
				while (x < 3) {
					if (arr[i][x + 1] == 0)
					{
						arr[i][x + 1] = arr[i][x];
						arr[i][x] = 0;
					}
					else if (arr[i][x + 1] == arr[i][x])
					{
						arr[i][x + 1] = arr[i][x] * 2;
						score = scores(arr[i][x + 1]);
						arr[i][x] = 0;
						break;
					}
					x++;
				}
			}
		}
	}
	score = scores(0);
}
void left(int arr[4][4], int& score)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) 
		{
			if (arr[i][j] > 0)
			{
				int x = j;
				while (x >= 1) {
					if (arr[i][x - 1] == 0) 
					{
						arr[i][x - 1] = arr[i][x];
						arr[i][x] = 0;
					}
					else if (arr[i][x - 1] == arr[i][x])
					{
						arr[i][x - 1] = arr[i][x] * 2;
						score = scores(arr[i][x - 1]);
						arr[i][x] = 0;
						break;
					}
					x--;
				}
			}
		}
	}
	score = scores(0);
}
void scor(int score, int bestscore)
{
	gotoxy(6, 4);
	cout << "SCORE: " << score << endl;
	gotoxy(20, 4);
	cout << "BEST: " << bestscores(score) << endl;
}
int gameover(int game, int arr[][4])
{
	game = 0;//гри не буде
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[i][j] == 0)
			{
				game = 1;//гра буде
			}
			if (arr[i][j] == 2048)
			{
				game = 0;
			}
		}
	}
	return game;
}
void play(int arr[][4], int score, int bestscore, int game)
{
	char key = _getch();
	switch (key)
	{
	case'w':
		up(arr, score);
		break;
	case 's':
		down(arr, score);
		break;
	case 'a':
		left(arr, score);
		break;
	case'd':
		right(arr, score);
		break;
	case'n':
		break;
	default:
		break;
	}
	system("cls");
	add(arr);
	SHOW(arr);
	scor(score, bestscore);
	game = gameover(game, arr);
	if (game == 0)
	{
		system("cls");
		game = 1;
		Clear(arr);
		add(arr);
		frame();
		gotoxy(3, 5);
		cout << " Score: " << score;
		gotoxy(3, 7);
		int a=0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (arr[i][j]==2048)
				{
					a = 1;
				}
			}
		}
		if (a==0)
		{
			textcolor(4);
			cout << " You lost! Do you want to restart? (y/n): ";
		}
		if (a == 1)
		{
			textcolor(10);
			cout << " You win! Do you want to restart? (y/n): ";
		}
		gotoxy(3, 9);
		textcolor(15);
		cout << " Your choise: ";
		scores(-score);
		char c;
		cin >> c;
		switch (c)
		{
		case 'y':
			while (game)
			{
				play(arr, score,bestscore, game);
			}
			break;
		case 'n':
			system("cls");
			frame();
			gotoxy(14, 9);
			textcolor(14);
			cout << " OK! Before meeting) ";
			textcolor(15);
			break;
		}
	}
}
void start(int arr[][4], int score, int bestscore,int game)
{
	frame();
	gotoxy(3, 7);
	cout << "If you want to start the game click         [1]";
	gotoxy(3, 8);
	cout << "If you want to see the rules of the game    [2]";
	int key;
	gotoxy(3, 10);
	cout << " Your choise: ";
	cin >> key;
	char u;
	switch (key)
	{
	case 1:
		while (game)
		{
			play(arr, score, bestscore, game);
		}
		break;
	case 2:
		system("cls");
		frame();
		gotoxy(3, 5);
		cout << "HOW TO PLAY:";
		gotoxy(3, 6);
		cout << "-Use your arrow keys to move the tiles.";
		gotoxy(3, 7);
		cout << "-Tiles with the same number merge into";
		gotoxy(3, 8);
		cout << "  one when they touch.";
		gotoxy(3, 9);
		cout << "-Add them up to reach 2048!";
		gotoxy(3, 13);
		cout << "To return, press u :";
		cin >> u;
		if (u == 'u')
		{
			system("cls");
			start(arr, score, bestscore, game);
		}
		break;
	default:
		break;
	}
}
void main()
{
	hide();
	int arr[4][4];
	int score = 0;
	int bestscore = 0;
	int game = 1;
	Clear(arr);
	add(arr);
	start(arr, score,bestscore, game);
	gotoxy(0, 50);
}
