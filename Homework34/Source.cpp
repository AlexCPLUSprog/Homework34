#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
void fill_arr(T arr[], const int length, T begin, T end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = begin + rand() % (end - begin);
}

template <typename T>
void show_arr(T arr[], const int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}

// ������ 1
template <typename T>
void uniq(T arr1[], const int length1, T arr2[], const int length2) {
	int size = length1 + length2;
	T* new_arr = new T[size];
	for (int i = 0; i < length1; i++)
		new_arr[i] = arr1[i];
	for (int i = 0; i < length2; i++)
		new_arr[length1 + i] = arr2[i];
	std::cout << "[";
	for (int i = 0; i < size; i++) {
		int counter = 0;
		for (int j = 0; j < size; j++) {
			if (new_arr[i] == new_arr[j])
				counter++;
		}
		if (counter == 1)
			std::cout << new_arr[i] << ", ";
	}
	std::cout << "\b\b]\n";
	delete[]new_arr;
}

// ������ 2
double fract(double num) {
	return num - (int)num;
}

// ������ 3
double double_rand() {
	return (rand() % 100) / 100.0;
}

int main() {
	setlocale(LC_ALL, "ru");

    // ������ 1   
	std::cout << "������ 1\n������ 1: ";
	const int size1 = 7, size2 = 8;
	int arr1[size1], arr2[size2];
	fill_arr(arr1, size1, 0, 10);
	fill_arr(arr2, size2, 5, 15);
	show_arr(arr1, size1);
	std::cout << "������ 2: ";
	show_arr(arr2, size2);
	std::cout << "���������� ��������: ";
	uniq(arr1, size1, arr2, size2);

	// ������ 2
	cout << "\n������ 2\n������� ������������ �����: ";
	double num;
	cin >> num;
	cout << "������� �����: " << fract(num) << "\n";

	// ������ 3
	cout << "\n������ 3\n��������� ������������ ����� �� 0 �� 1: " << double_rand();

	return 0;
}