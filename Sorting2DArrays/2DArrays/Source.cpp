#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <time.h>

void display(int arr[][20], int n, int m) // METHOD FOR SHOWING ARRAY
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			printf("%4d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// сортування двовимірного масиву методом Бульбашки
// сортування 2D масиву відбувається за аналогією сортування 1D масиву розміру rows * columns
// додатковий масив для сортування не створюється
void genericSortingFirstWay(int arr[][20], int rowsNumber, int columnsNumber)
{
	// HARD FOR UNDERSTANDING . NOT RECOMMENDED. FEEL FRY TO FIND YOUR WAY
	int temporary;
	int rowIndex, rowNextIndex;
	int columnIndex, columnNextIndex;
	// складаємо загальний розмір масиву (переводимо у вигляд 1D)
	// -1 , бо розрахунок починаємо з 0-го індекса
	int totalSize = rowsNumber * columnsNumber - 1;

	for (int i = 0; i < totalSize; ++i)
	{
		for (int j = 0; j < totalSize - i; ++j)
		{
			rowIndex = j / columnsNumber;
			columnIndex = j % columnsNumber;
			rowNextIndex = (j + 1) / columnsNumber;
			columnNextIndex = (j + 1) % columnsNumber;
			printf("%4d%4d%4d%4d\n", rowIndex, columnIndex, rowNextIndex, columnNextIndex);

			if (arr[rowIndex][columnIndex] > arr[rowNextIndex][columnNextIndex])
			{
				temporary = arr[rowNextIndex][columnNextIndex];
				arr[rowNextIndex][columnNextIndex] = arr[rowIndex][columnIndex];
				arr[rowIndex][columnIndex] = temporary;
			}
		}
	}
} // 1 WAY FOR ITERATING THROUGHT 2D ARRAY AS 1D

void genericSortingSecondWay(int arr[][20], int rowsNumber, int columnsNumber)
{
	int temporary;
	int l;
	for (int i = 0; i < rowsNumber; i++)
	{
		for (int j = 0; j < columnsNumber; j++)
		{
			temporary = arr[i][j];
			l = j + 1;
			for (int k = i; k < columnsNumber; k++)
			{
				while (l < columnsNumber)
				{
					/* buuble method swapping the data */
					if (temporary > arr[k][l])
					{
						temporary = arr[k][l];
						arr[k][l] = arr[i][j];
						arr[i][j] = temporary;
					}
					l++;
				}
				l = 0;
			}
		}
	}
}//2 WAY FOR ITERATING THROUGHT 2D ARRAY AS 1D

void sortVibir(int arr[][20], int rowsNumber, int columnsNumber)
{
	// SORTING BY DESCENDING ORDER
	int temporary;
	int maxElement = 0;
	int maxElementRowsIndex = 0;
	int maxElementColumnsIndex = 0;
	int l;
	for (int i = 0; i < rowsNumber; i++)
	{
		for (int j = 0; j < columnsNumber; j++)
		{
			temporary = arr[i][j];
			printf("\n Temporary : %d", temporary);
			maxElement = arr[i][j];
			l = j + 1;
			for (int k = i; k < columnsNumber; k++)// searching for max value from temporary +1 and to the end of array
			{
				while (l < columnsNumber)
				{
					if (maxElement < arr[k][l])
					{
						maxElement = arr[k][l];
						maxElementRowsIndex = k;
						maxElementColumnsIndex = l;
						printf("\n MaxElement : %d", maxElement);
					}
					l++;
				}
				l = 0;
			}
			if (arr[i][j] < arr[maxElementRowsIndex][maxElementColumnsIndex]) // CHECKING IF WE NEED TO SWAP VALUES
			{
				printf("\n CHANGING %d <  %d\n", arr[i][j], arr[maxElementRowsIndex][maxElementColumnsIndex]);
				arr[i][j] = arr[maxElementRowsIndex][maxElementColumnsIndex];
				arr[maxElementRowsIndex][maxElementColumnsIndex] = temporary;
			}
			else 
			{
				printf("\n NO CHANGES. It is already MAXED\n");
			}
			display(arr, rowsNumber, columnsNumber);
		}
	}
} // EXAMPLE HOW TO USE 


int main()
{
	int rowsNumber, columnsNumber;
	int arr[20][20];

	printf("Enter Number of Rows: ");
	scanf_s("%d", &rowsNumber);
	printf("Enter Number of Columns: ");
	scanf_s("%d", &columnsNumber);

	for (int i = 0; i < rowsNumber; ++i)
	{
		for (int j = 0; j < columnsNumber; ++j)
		{
			arr[i][j] = rand() % 50 + 1;
		}
	}

	display(arr, rowsNumber, columnsNumber);
	//sortBubble(arr, rowsNumber, columnsNumber);
	sortVibir(arr, rowsNumber, columnsNumber);
	printf("\nArray After Sorting: \n");
	display(arr, rowsNumber, columnsNumber);
}