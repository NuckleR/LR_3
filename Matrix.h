#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <Windows.h>

static int counter_1, counter_2,
counter_3, temp, check_point;

//================================================================= Classes ================================================================================//


class Matrix {
private:
	int size;
	int mat_index;
	int str, stb;
	double* matrix;
public:

	//--------------------------------------- Конструкторы -------------------------------------//

	Matrix() {					//Конструктор по умолчанию
		std::cout << "\n\t\tЗапущен конструктор по умолчанию!\n";
		str = 0;
		stb = 0;
		size = 0;
		mat_index = 0;
		matrix = nullptr;
		//Sleep(1500);
	}

	Matrix(int s_r, int  s_b, int index) {					//Конструктор инициализации
		std::cout << "\n\t\tЗапущен конструктор инициализации!\n";
		matrix = new double[s_r * s_b];
		str = s_r;
		stb = s_b;
		size = s_r * s_b;
		mat_index = index;
		//Sleep(1500);
	}

	Matrix(const Matrix& mat) : str(mat.str)				//Конструктор копирования
		, stb(mat.stb), matrix(mat.matrix), size(mat.size)
		, mat_index(mat.mat_index)
	{
		std::cout << "\n\t\tЗапущен конструктор копирования!\n";
		matrix = new double[mat.stb * mat.str];
		for (int i = 0; i < mat.str; i++)
			for (int j = 0; j < mat.stb; j++) {
				matrix[mat.stb * i + j] = mat.matrix[mat.stb * i + j];
			}
		//Sleep(1500);
	}

	~Matrix() {					//Деструктор
		std::cout << "\n\t\tЗапущен деструктор!\n";
		if (matrix != nullptr) {
			delete[] matrix;
		}
		//Sleep(1500);
	}

	//-----------------------------------------------------------------------------------------------//

	//---------------------------------- Функции (методы) -------------------------------------------//

	void set_index(int index) {
		mat_index = index;
	}

	double get_size() {				//Выдает размер матрицы
		size = str * stb;
		return size;
	}

	void show_matrix() {				//Или get_matrix выводит матрицу
		std::cout << "matrix_" << mat_index << "\n\n";
		for (int i = 0; i < str; i++) {
			for (int j = 0; j < stb; j++) {
				std::cout << matrix[stb * i + j] << "  ";
			}
			std::cout << "\n";
		}
	}

	void set_mt_size(int s_r, int s_b) {		//Устанавливает размер матрицы
		delete[] matrix;
		str = s_r;
		stb = s_b;
		matrix = new double[str * stb];
	}

	int get_str() {				//Выдает кол-во строк
		return str;
	}

	int get_stb() {				//Выдает кол-во столбцов
		return stb;
	}

	int get_index() {
		return mat_index;
	}

	//-----------------------------------------------------------------------------------------------//

	//---------------------------------------- Перегрузка операторов --------------------------------//

	Matrix operator = (Matrix mat) {					//Перегрузка оператора =
		std::cout << "\n\t\tПерегрузка оператора =!\n";
		//Sleep(1500);
		size = mat.size;
		str = mat.str;
		stb = mat.stb;
		matrix = new double[mat.str * mat.stb]; /*mat.matrix;*/
		for (int i = 0; i < mat.str; i++)
			for (int j = 0; j < mat.stb; j++) {
				matrix[mat.stb * i + j] = mat.matrix[mat.stb * i + j];
			}
		return *this;
	}

	double* operator [] (int index) {						//Перегрузка оператора []
		std::cout << "\n\t\tПерегрузка оператора []!\n";
		//Sleep(1500);
		return &matrix[index];
	}

	Matrix operator --() {							//Перегрузка оператора --
		std::cout << "\n\t\tПерегрузка оператора --!\n";
		//Sleep(1500);
		for (int i = 0; i < str; i++)
			for (int j = 0; j < stb; j++) {
				matrix[stb * i + j]--;
			}
		return *this;
	}

	//-----------------------------------------------------------------------------------------------//
};


//==========================================================================================================================================================//


void clear_count() {
	counter_1 = 0;
	counter_2 = 0;
	counter_3 = 0;
}

int menu() {		//Обычное меню выбора без проверки на числа
	int k = 0;

	do {
		system("CLS");
		if (k < 0 || k > 5) {
			std::cout << "\n\n\t\tТакого пункта в меню не существует!";
			Sleep(2000);  system("CLS");
		}
		std::cout << "=================================\n"
			<< "1 - Вывод доступных динамических матриц\n"
			<< "2 - Задать новые динамические матрицы\n"
			<< "3 - Скопировать матрицы при помощи оператора =\n"
			<< "4 - Уменьшить значения определенной матрицы (оператор --)\n"
			<< "5 - Уменьшить значения определенного массива\n"
			<< "0 - выход\n"
			<< "=================================\n";
		std::cin >> k;
	} while (k < 0 || k > 5);

	system("CLS");

	return k;
}

void show_alone(Matrix* MT_3, int amnt_of_mt) {
	for (counter_1 = 0; counter_1 < amnt_of_mt; counter_1++) {
		MT_3[counter_1].show_matrix();
	} clear_count();
}

void see_all_dMatrix(Matrix* MT_3, Matrix* MT_4,
	int amnt_of_mt_3, int amnt_of_mt_4) {

	std::cout << "\n\nMT_3: \n";
	for (counter_1 = 0; counter_1 < amnt_of_mt_3; counter_1++) {
		MT_3[counter_1].show_matrix();
	}clear_count();
	std::cout << "\n\nMT_4: \n";
	for (counter_1 = 0; counter_1 < amnt_of_mt_4; counter_1++) {
		MT_4[counter_1].show_matrix();
	}clear_count();
}

Matrix* set_new_dMatrix(Matrix* MT_3, int& amnt_of_mt) {
	int stb, str;

	std::cout << "Введите кол-во матриц: ";
	std::cin >> amnt_of_mt;

	MT_3 = new Matrix[amnt_of_mt];

	for (counter_1 = 0; counter_1 < amnt_of_mt; counter_1++) {
		std::cout << "\nВведите кол-во столбцов для матрицы из динам. массива: ";
		std::cin >> stb;
		std::cout << "\nВведите кол-во строк для матрицы из динам. массива: ";
		std::cin >> str;
		//temp = counter_1 + 3;
		MT_3[counter_1].set_mt_size(str, stb);
		MT_3[counter_1].set_index(temp);
		for (counter_2 = 0; counter_2 < str; counter_2++) {
			for (counter_3 = 0; counter_3 < stb; counter_3++) {
				std::cout << "\nВведите MT_" << (temp) << "[" << counter_2 << "][" << counter_3 << "] :";
				std::cin >> *MT_3[counter_1][stb * counter_2 + counter_3];
			}
		}
		temp++;
	} clear_count();
	std::cout << "\n\n\t\tМатрицы созданы!";
	system("pause");

	return MT_3;
}

Matrix* copy_dMatrix(Matrix* MT_3, int amnt_of_mt_3, Matrix* MT_4) {

	MT_4 = new Matrix[amnt_of_mt_3];

	for (counter_1 = 0; counter_1 < amnt_of_mt_3; counter_1++) {
		MT_4[counter_1] = MT_3[counter_1];   //Передача значений одной матрицы заданной динамически в другую
		MT_4[counter_1].set_index(temp);
		temp++;
	} clear_count();
	std::cout << "\n\n\t\tМатрицы переехали!";
	Sleep(2000);

	return MT_4;
}

int find_index(Matrix* MT_3, int amnt_of_mt, int poisk) {
	for (counter_1 = 0; counter_1 < amnt_of_mt; counter_1++) {
		if (poisk == MT_3[counter_1].get_index()) {
			std::cout << "\n\n\t\tМатрица найдена!\n\t\tНомер: " << poisk;
			check_point = counter_1;
			return MT_3[counter_1].get_index();
		}
	}
	return -1;
}

void minus_one_dMatrix(Matrix* MT_3, int index) {

	--MT_3[index];
	std::cout << "\n\n\t\tМатрица уменьшилась!";


	Sleep(1500);
	system("pause");
}

