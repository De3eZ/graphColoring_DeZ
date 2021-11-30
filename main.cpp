#include <iostream>

using namespace std;

struct vertex
{
	int number;
	int degree=0;
	int color = 0;
};

void paint(int** graf, int size)
{
	vertex* arr = new vertex[size];

	for (int i = 0; i < size; i++)
	{
		arr[i].number = i;

		for (int j = 0; j < size; j++)
		{
			if (graf[i][j] != 0)
			{
				arr[i].degree++;
			}
		}
	}

	for (int i = 0, maxDegree; i < size; i++)
	{
		maxDegree = 0;
		for (int j = i; j < size; j++)
		{
			if (arr[j].degree > maxDegree)
			{
				maxDegree = arr[j].degree;

				int tmpDegree = arr[j].degree;
				int tmpNumber = arr[j].number;

				arr[j] = arr[i];
				arr[i].degree = tmpDegree;
				arr[i].number = tmpNumber;
			}
		}
	}

	cout << "\nСтепени вершин:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i].number + 1 << ": " << arr[i].degree << endl;
	}

	for (int i = 0, color = 1; i < size; i++, color++)
	{
		for (int j = 0; j < size; j++)
		{
			bool paint = true;

			for (int n = 0; n < size; n++)
			{
				if (arr[j].color == 0)
				{
					if (graf[arr[j].number][n] == 1)
					{
						vertex tmp;

						for (int m = 0; m < size; m++)
						{
							if (arr[m].number == n)
							{
								tmp = arr[m];
							}
						}

						if (tmp.color == color)
						{
							paint = false;
						}
					}
				}
			}
			if (paint && arr[j].color == 0)
			{
				arr[j].color = color;
			}
		}
	}

	cout << "\nЦвета вершин:" << endl;
	for (int i = 0; i < size; i++)
	{
		vertex tmp;

		for (int m = 0; m < size; m++)
		{
			if (arr[m].number == i)
			{
				tmp = arr[m];
			}
		}

		cout << tmp.number + 1 << ": Цвет " << tmp.color << endl;
	}

	int min = 0, min2 = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].degree > 3)
		{
			min++;
		}
		if (arr[i].degree > 2)
		{
			min2++;
		}
	}

	cout << endl << "Планарность:" << endl;
	if (min>4|| min2 > 5)
	{
		if ((size * (size - 1) / 2) <= (3 * size - 6))
		{
			cout << "Граф планарен" << endl;
		}
		else
		{
			cout << "Граф не планарен" << endl;
		}
	}
	else
	{
		cout << "Граф планарен" << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int size;
	cout << "Введите количество элементов графа: ";
	cin >> size;

	int** graf = new int* [size];

	for (int i = 0; i < size; i++)
	{
		graf[i] = new int[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			graf[i][j] = 0;
		}
	}

	cout << "Заполните граф" << endl;

	for (int i = 0, var; i < size; i++)
	{
		var = 1;

		cout << "Введите с какими вершинами соединён " << i + 1 << " используя цифры, если ввели все вершины, то введите 0" << endl;

		while (var != 0)
		{
			cin >> var;

			if (var != 0)
			{
				graf[i][var - 1] = 1;
			}
		}
	}

	system("cls");

	cout << "Матрица смежности: " << endl;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << graf[i][j] << " ";
		}
		cout << endl;
	}

	paint(graf, size);

	return 0;
}