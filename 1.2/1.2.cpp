// 1.2.cpp : ***********************Крестики нолики*****************


// 1 - крестики
// 2 - нолики

#include <iostream>
using namespace std;
void map_show(int map[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << map[j][i];
		}
		cout << endl;
	}
}
void comp(int map[3][3])
{
	int a = 0, b = 0;
	do
	{
		a = rand() % 3;
		b = rand() % 3;
	} while (map[a][b] != 0);
	map[a][b] = 2;

}
bool game_over(int map[3][3], char val)
{
	int c0 = 0;
	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (map[j][i] == val)
				c0++;
			if (map[i][j] == val)
				c1++;
			if (map[j][j] == val)
				c2++;
			if (map[2 - j][j] == val)
				c3++;
		}
		if (c0 == 3 || c1 == 3 || c2 == 3 || c3 == 3)
		{
			
			return true;
			break;
		}
		c0 = 0;
		c1 = 0;
		c2 = 0;
		c3 = 0;
	}


	return false;
}



int main()

{
	srand(time(NULL));
	int a=0, b=0;
	int map[3][3] = { 0 };


	while (true)
	{
		cout << "Введите координаты ";
		cin >> a >> b;
		map[a][b] = 1;
		map_show(map);

		if (game_over(map,1) == true)
		{
			cout << "Вы победили!" << endl;

			break;
		}
		cout << "Ход компьютера....." << endl;
	    comp(map);
		map_show(map);
		if (game_over(map,2) == true)
		{
			cout << "Вы проиграли!" << endl;

			break;
		}
		
	}
	
	
}
