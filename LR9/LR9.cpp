#include <stdio.h>
#define N 30 // максимальний розмір масиву

int main()
{
	double arr[N]; // оголошення масиву для зберігання введених чисел
	int k = 0;// лічильник введених чисел
	printf("Enter numbers for the array (minimum 2 and maximum %d)"
		" to complete the input enter any non-numeric character\n"
		"Array:", N
	); // інструкція для користувача
	while (k < N) {
		if (scanf_s("%lf", &arr[k]) == 0) {// завершення вводу при нечисловому значенні
			break;
		}
		k++;
	}

	if (k < 2) { // перевірка на мінімальну кількість введених чисел
		printf("You entered less than 2 numbers. Exiting the program.");
		return 1;
	}
	double min1 = arr[0], min2 = arr[1];
	min1 = arr[0]; // ініціалізація першого мінімального значення
	min2 = arr[1]; // ініціалізація другого мінімального значення
	int index1 = 0, index2 = 1; // індекси мінімальних значень

	if (min2 < min1) { 
		double buf = min1;
		min1 = min2;
		min2 = buf;
		buf = index1;
		index1 = index2;
		index2 = buf;//зміна місцями, якщо друге менше першого
	}

	for (int i = 2; i < k; i++) {
		if (arr[i] < min1) { // перевірка на мінімальне значення
			min2 = min1;
			index2 = index1;
			min1 = arr[i];
			index1 = i;// оновлення першого мінімального значення
		}
		else if (arr[i] < min2) { // перевірка на друге мінімальне значення
			min2 = arr[i];
			index2 = i;// оновлення другого мінімального значення
		}
	}
	printf("The first min number: %lf, index: %d\n"
		"The second min number: %lf, index: %d", 
		min1, (index1 + 1), min2, (index2 + 1) 
	);// виведення результату
	return 0;
}
