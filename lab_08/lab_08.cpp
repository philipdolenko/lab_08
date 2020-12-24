// lab_08.cpp :4. Переставить строки матрицы так, чтобы элементы первого
// столбца были отсортированы по неубыванию.


#include "pch.h"
#include <iostream>
using namespace std;

void printMatrix(int c, int r, int ** mrx) {
	for (int i = 0; i < r; i++)
	{
		cout << "  " << endl;
		for (int j = 0; j < c; j++)
		{
			cout << "  " << mrx[i][j];
		}
	}
	cout << endl;
}

void moveRowBack(int **arr, int i)
{
	int* buff;
	buff = arr[i];
	arr[i] = arr[i - 1];
	arr[i - 1] = buff;
}

void lab() {
	int totalSwaps = 0, totalCycles = 0, totalCompars = 0;

	int ** arr = new int*[50];
	int rowsSize, columnsSize;

	cout << "Rows : ";
	cin >> rowsSize;
	cout << endl;

	cout << "Colums : ";
	cin >> columnsSize;
	cout << endl;

	for (int i = 0; i < rowsSize; i++)
	{
		arr[i] = new int[50];
		for (int j = 0; j < columnsSize; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> arr[i][j];
		}
	}

	cout << "Before sort : " << endl;
	printMatrix(columnsSize, rowsSize, arr);

	int start = 1;//comparing element with prev => ignoring index № 0 
	int end = rowsSize - 1;

	while (start <= end)
	{
		int localSwaps = 0, localCompars = 0;

		for (int i = end; i >= start; i--) {
			localCompars++;

			if (arr[i - 1][0] > arr[i][0]) {
				moveRowBack(arr, i);
				localSwaps++;
			}
		}
		start++;

		for (int i = start; i <= end; i++) {
			localCompars++;

			if (arr[i - 1][0] > arr[i][0]) {
				moveRowBack(arr, i);
				localSwaps++;
			}
		}
		end--;

		totalCompars += localCompars;
		totalSwaps += localSwaps;
		totalCycles++;

		cout << "Cycle No " << totalCycles << endl;
		cout << "Matrix: \n";
		printMatrix(columnsSize, rowsSize, arr);
		cout << "Cycles stats:\nCompars - " << localCompars << "\n";
		cout << "Swaps - " << localSwaps << "\n";
	}

	cout << "After sort : " << endl;
	printMatrix(columnsSize, rowsSize, arr);
	cout << "Sort stats:\nTotal compars - " << totalCompars << "\n";
	cout << "Total swaps - " << totalSwaps << "\n";
}

void loopTask(void(*task)(void)) {
	char userInput;

	do {
		task();
		cout << "Enter 'y' to continue any other kay to exit.\n";
		cin >> userInput;
	} while (userInput == 'y' || userInput == 'Y');
}

int main()
{
	loopTask(lab);
}