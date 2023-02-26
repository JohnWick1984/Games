// ***************************Ход конем***************************
//

#include <iostream>
using namespace std;

#define DS 8

int desk[DS][DS];
int step[8][2] = { {1,-2}, {2,-1}, {2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2} };
int n;

void print_desk()
{
	
	for (int i = 0; i < DS; i++)
	{
		for (int j = 0; j < DS; j++)
			cout << desk[i][j] << "\t";
		cout << endl;
	}
}

bool set_horse(int x, int y)
{
	
	if ((x < 0) || (x >= DS) || (y < 0) || (y >= DS))
		return false;

	if (desk[x][y] != 0)
		return false;

	
	n++;
	desk[x][y] = n;

	
	if (n == DS * DS)
		return true;

	for (int i = 0; i < 8; i++)
		if (set_horse(x + step[i][0], y + step[i][1]))
			return true;
	n--;
	desk[x][y] = 0;

	return false;
}



int main()
{
	setlocale(0, "");
	int x, y;
	cout << "Введите координаты клетки, с которой конь начнет передвигаться \n";
	cout << " x = ";cin >> x;
	cout << " y = ";cin >> y;
	n = 0;
	for (int i = 0; i < DS; i++)
		for (int j = 0; j < DS; j++)
			desk[i][j] = 0;

	set_horse(x, y);

	print_desk();


}