#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//#include <cstring>
//#include <Windows.h>
#include "Matrix.h"

//static int counter_1, counter_2, 
//	counter_3, temp, check_point;
//
////================================================================= Classes ================================================================================//
//
//
//class Matrix {
//private:
//	int size;
//	int mat_index;
//	int str, stb;
//	double* matrix;
//public:
//
//	//--------------------------------------- ������������ -------------------------------------//
//
//	Matrix() {					//����������� �� ���������
//		std::cout << "\n\t\t������� ����������� �� ���������!\n";
//		str = 0;
//		stb = 0;
//		size = 0;
//		mat_index = 0;
//		matrix = nullptr;
//		//Sleep(1500);
//	}
//
//	Matrix(int s_r, int  s_b, int index) {					//����������� �������������
//		std::cout << "\n\t\t������� ����������� �������������!\n";
//		matrix = new double[s_r * s_b];
//		str = s_r;
//		stb = s_b;
//		size = s_r * s_b;
//		mat_index = index;
//		//Sleep(1500);
//	}
//
//	Matrix(const Matrix& mat) :	str(mat.str)				//����������� �����������
//		, stb(mat.stb), matrix(mat.matrix), size(mat.size)
//		, mat_index(mat.mat_index)
//	{
//		std::cout << "\n\t\t������� ����������� �����������!\n";
//		matrix = new double[mat.stb * mat.str];
//		for (int i = 0; i < mat.str; i++)
//			for (int j = 0; j < mat.stb; j++) {
//				matrix[mat.stb * i + j] = mat.matrix[mat.stb * i + j];
//			}
//		//Sleep(1500);
//	}
//
//	~Matrix() {					//����������
//		std::cout << "\n\t\t������� ����������!\n";
//		if (matrix != nullptr) {
//			delete[] matrix;
//		}
//		//Sleep(1500);
//	}
//
//	//-----------------------------------------------------------------------------------------------//
//
//	//---------------------------------- ������� (������) -------------------------------------------//
//
//	void set_index(int index) {
//		mat_index = index;
//	}
//
//	double get_size(){				//������ ������ �������
//		size = str * stb;
//		return size;
//	}
//
//	void show_matrix() {				//��� get_matrix ������� �������
//		std::cout << "matrix_"<<mat_index<<"\n\n";
//		for (int i = 0; i < str; i++) {
//			for (int j = 0; j < stb; j++) {
//				std::cout << matrix[stb * i + j] << "  ";
//			}
//			std::cout << "\n";
//		}
//	}
//
//	void set_mt_size(int s_r, int s_b) {		//������������� ������ �������
//		delete[] matrix;
//		str = s_r;
//		stb = s_b;
//		matrix = new double[str * stb];
//	}
//
//	int get_str() {				//������ ���-�� �����
//		return str;
//	}
//
//	int get_stb() {				//������ ���-�� ��������
//		return stb;
//	}
//
//	int get_index() {
//		return mat_index;
//	}
//
//	//-----------------------------------------------------------------------------------------------//
//
//	//---------------------------------------- ���������� ���������� --------------------------------//
//
//	Matrix operator = (Matrix mat) {					//���������� ��������� =
//		std::cout << "\n\t\t���������� ��������� =!\n";
//		//Sleep(1500);
//		size = mat.size;
//		str = mat.str;
//		stb = mat.stb;
//		matrix = new double[mat.str * mat.stb]; /*mat.matrix;*/
//			for (int i = 0; i < mat.str; i++)
//				for (int j = 0; j < mat.stb; j++) {
//					matrix[mat.stb * i + j] = mat.matrix[mat.stb * i + j];
//				}
//			return *this;
//	}
//
//	double* operator [] (int index) {						//���������� ��������� []
//		std::cout << "\n\t\t���������� ��������� []!\n";
//		//Sleep(1500);
//		return &matrix[index];
//	}
//
//	Matrix operator --() {							//���������� ��������� --
//		std::cout << "\n\t\t���������� ��������� --!\n";
//		//Sleep(1500);
//		for (int i = 0; i < str; i++)
//			for (int j = 0; j < stb; j++) {
//				matrix[stb * i + j]--;
//			}
//		return *this;
//	}
//
//	//-----------------------------------------------------------------------------------------------//
//};
//
//
////==========================================================================================================================================================//
//
//
//void clear_count() {
//	counter_1 = 0;
//	counter_2 = 0;
//	counter_3 = 0;
//}
//
////========================================================= Descriptions of functions ======================================================================//
//
//
//int menu();
//void minus_one_dMatrix(Matrix* MT_3, int index);
//int find_index(Matrix* MT_3, int amnt_of_mt, int poisk);
//Matrix* copy_dMatrix(Matrix* MT_3, int amnt_of_mt_3, Matrix* MT_4);
////void copy_dMatrix(Matrix* MT_3, int amnt_of_mt_3, Matrix* MT_4);
////int set_new_dMatrix(Matrix* MT_3);
//Matrix* set_new_dMatrix(Matrix* MT_3, int& amnt_of_mt);
//void see_all_dMatrix(Matrix* MT_3, Matrix* MT_4,
//	int amnt_of_mt_3, int amnt_of_mt_4);
//void show_alone(Matrix* MT_3, int amnt_of_mt);
//
////==========================================================================================================================================================//

//============================================================ Body and methods ============================================================================//


int main() {
	system("chcp 1251");
	system("CLS");

	Matrix MT_5 //��� �������� �������������� = 
		, MT_1, MT_2(2, 3, 2);	//���������� �������� ������
	Matrix* MT_3 = nullptr;	//��� ������������� ���������� ������
	Matrix* MT_4 = nullptr;   //��� ������� ����������� ������
	
	int stb, str; //������ � ������� ��� ����������� ���������� ����������� ������
	int amnt_of_mt; //���-�� ������ (�������� ������������� ��������� �����������)

	//------------------------------------------ ��� ���������� ���������� ------------------------------------------------
	
	std::cout << "\n������� ���-�� �������� ��� ���������� �������� ������: ";					
	std::cin >> stb;
	std::cout << "\n������� ���-�� ����� ��� ���������� �������� ������: ";
	std::cin >> str;
	MT_1.set_mt_size(str, stb);
	MT_1.set_index(1);

	for (counter_1 = 0; counter_1 < str; counter_1++) {
		for (counter_2 = 0; counter_2 < stb; counter_2++) {
			std::cout << "\n������� MT_1[" << counter_1 << "][" << counter_2 << "] :";
			std::cin >> *MT_1[stb * counter_1 + counter_2];
			//system("CLS");
		}
		//std::cout << "\n";
	}
	clear_count();
	MT_1.show_matrix();
	system("pause");

	//----------------------------------------------------------------------------------------------------------------------

	//------------------------------ ��� ���������� ���������������������� ���������� --------------------------------------

	for (counter_1 = 0; counter_1 < MT_2.get_str(); counter_1++) {
		for (counter_2 = 0; counter_2 < MT_2.get_stb(); counter_2++) {
			std::cout << "\n������� MT_2[" << counter_1 << "][" << counter_2 << "] :";
			std::cin >> *MT_2[MT_2.get_stb() * counter_1 + counter_2];
			//system("CLS");
		}
	/*	std::cout << "\n";*/
	}
	clear_count();
	MT_1.show_matrix();
	MT_2.show_matrix();
	system("pause");

	//----------------------------------------------------------------------------------------------------------------------

	//---------------------- �������� ������������� ���������� � ��������� �����������--------------------------------------

	std::cout << "\n\n\n\n�������� ������ �������������� ��������� -- �� ������� matrix_1 � matrix_2." //���������� ��������� --
		<<"\n��� �������� � �������� ����������� �� 1."
		<<"\n�� ��������������: \n";
	MT_1.show_matrix();
	MT_2.show_matrix(); system("pause");
	--MT_1; --MT_2;
	std::cout << "\n\n����� ��������������: \n";
	MT_1.show_matrix();
	MT_2.show_matrix(); system("pause");


	std::cout << "\n\n\n\n�������� ������ �������������� ��������� =." //���������� ��������� =
		<< "\n��� �������� �� �������� ������� (matrix_1) ������������ � ���������� ������� (matrix_5)"
		<< "\n\t\t\t ������ � ��� ������ ����� ���� �������, ��� ��� ������ �������."
		<< "\n�� ��������������: \n";
	MT_5.set_index(5);
	MT_1.show_matrix();
	MT_5.show_matrix(); system("pause");
	MT_5 = MT_1;
	std::cout << "\n\n����� ��������������: \n";
	MT_5.set_index(5);
	MT_1.show_matrix();
	MT_5.show_matrix(); system("pause");


	std::cout << "\n\n\n\n�������� ������ �������������� ��������� -- �� ������� matrix_5." //���������� ��������� --
		<< "\n��� �������� � ������� ����������� �� 1."
		<< "\n�� ��������������: \n";
	MT_5.show_matrix(); system("pause");
	--MT_5;
	std::cout << "\n\n����� ��������������: \n";
	MT_5.show_matrix();
	std::cout << "\n\nMT_1 ����� ��������������: \n";
	MT_1.show_matrix();  system("pause");

	//----------------------------------------------------------------------------------------------------------------------

	//---------------------------------- ������������ �������� ����������� ������ ------------------------------------------
	
	std::cout << "\n\n\n\n������������ �������� ����������� ������ (������)\n"
		<<"������� ���-�� ������: ";
	std::cin >> amnt_of_mt;

	MT_3 = new Matrix[amnt_of_mt];

	for (counter_1 = 0; counter_1 < amnt_of_mt; counter_1++) {
		std::cout << "\n������� ���-�� �������� ��� ������� �� �����. �������: ";
		std::cin >> stb;
		std::cout << "\n������� ���-�� ����� ��� ������� �� �����. �������: ";
		std::cin >> str;
		temp = counter_1 + 3;
		MT_3[counter_1].set_mt_size(str, stb);
		MT_3[counter_1].set_index(temp);
		for (counter_2 = 0; counter_2 < str; counter_2++) {
			for (counter_3 = 0; counter_3 < stb; counter_3++) {
				std::cout << "\n������� MT_"<< (temp) <<"[" << counter_2 << "][" << counter_3 << "] :";
				std::cin >> *MT_3[counter_1][stb * counter_2 + counter_3];
			}
		}
	}
	clear_count();
	show_alone(MT_3, amnt_of_mt);
	system("pause");

	//----------------------------------------------------------------------------------------------------------------------

	//---------------------- �������� ������������� ���������� � ������������ ����������� ----------------------------------

	std::cout << "\n\n\n\n�������� ������ �������������� ��������� -- �� ������� ����������� �������� ������." //���������� ��������� --
		<< "\n��� �������� � ������� ����������� �� 1."
		<< "\n�� ��������������: \n";
	show_alone(MT_3, amnt_of_mt);
	for (counter_1 = 0; counter_1 < amnt_of_mt; counter_1++) {
		--MT_3[counter_1];
	} clear_count();
	std::cout << "\n\n����� ��������������: \n";
	show_alone(MT_3, amnt_of_mt);
	system("pause");

	std::cout << "\n\n\n\n�������� ������ �������������� ��������� = �� ������� ������������ ��������." //���������� ��������� =
		<< "\n��� �������� �� �������� ������ ������������ � *MT_4"
		<< "\n\t\t\t ������ � ��� ������ ����� ���� �������, ��� ��� ������ �������."
		<< "\nMT_3 �� ��������������: \n";
	show_alone(MT_3, amnt_of_mt);

	MT_4 = new Matrix[amnt_of_mt];   
	for (counter_1 = 0; counter_1 < amnt_of_mt; counter_1++) {
		MT_4[counter_1] = MT_3[counter_1];   //�������� �������� ����� ������� �������� ����������� � ������
		temp = counter_1 + amnt_of_mt + 3;
		MT_4[counter_1].set_index(temp);
	} clear_count();

	std::cout << "\n\nMT_4 ����� ��������������: \n";
	show_alone(MT_4, amnt_of_mt);
	std::cout << "\n\nMT_3 ����� ��������������: \n";
	show_alone(MT_3, amnt_of_mt);
	system("pause");

	std::cout << "\n\n\n\n�������� ������ �������������� ��������� -- �� ������� MT_4." //���������� ��������� --
		<< "\n��� �������� � ������� ����������� �� 1.";
		std::cout << "\n\nMT_4 �� ��������������: \n";
	show_alone(MT_4, amnt_of_mt);
	for (counter_1 = 0; counter_1 < amnt_of_mt; counter_1++) {
		--MT_4[counter_1];
	} clear_count();
	std::cout << "\n\nMT_4 ����� ��������������: \n";
	show_alone(MT_4, amnt_of_mt);
	std::cout << "\n\nMT_3 ����� ��������������: \n";
	show_alone(MT_3, amnt_of_mt);
	system("pause");

	std::cout << "��� ������� �� ���������: ";
	see_all_dMatrix(MT_3, MT_4, amnt_of_mt, amnt_of_mt);
	MT_5.show_matrix();
	MT_1.show_matrix();
	MT_2.show_matrix();
	system("pause");

	//----------------------------------------------------------------------------------------------------------------------
	int amnt_of_mt_3 = amnt_of_mt
		, amnt_of_mt_4 = amnt_of_mt, ch;

	while (true) {
		switch (menu()) {
		case 1:
			see_all_dMatrix(MT_3, MT_4, amnt_of_mt_3, amnt_of_mt_4);
			system("pause");
			continue;
		case 2:
			see_all_dMatrix(MT_3, MT_4, amnt_of_mt_3, amnt_of_mt_4);
			std::cout << "\n�������� ������������ ������ ������ ��� ������������ " 
				<< "MT_3(1) ��� MT_4(2) (0-�����): ";
			std::cin >> ch;
			if (ch == 1) {
				MT_3 = set_new_dMatrix(MT_3, amnt_of_mt_3);
			}
			if (ch == 2) {
				MT_4 = set_new_dMatrix(MT_4, amnt_of_mt_4);
			}
			continue;
		case 3:
			see_all_dMatrix(MT_3, MT_4, amnt_of_mt_3, amnt_of_mt_4);
			std::cout << "\n�������� ������ ������, �������" 
				<<" �� ����������� � ������� ������� ������" 
				<<" MT_3(1) ��� MT_4(2) (0-�����): ";
			std::cin >> ch;
			if (ch == 1) {
				MT_4 = copy_dMatrix(MT_3, amnt_of_mt_3, MT_4);
				amnt_of_mt_4 = amnt_of_mt_3;
			}
			if (ch == 2) {
				MT_3 = copy_dMatrix(MT_4, amnt_of_mt_4, MT_3);
				amnt_of_mt_3 = amnt_of_mt_4;
			}
			continue;
		case 4:
			see_all_dMatrix(MT_3, MT_4, amnt_of_mt_3, amnt_of_mt_4);
			std::cout << "�������� ������� �� �������: ";
			std::cin >> ch;
			if (ch == find_index(MT_3, amnt_of_mt_3, ch)) {
				minus_one_dMatrix(MT_3, check_point);
			}
			else if (ch == find_index(MT_4, amnt_of_mt_4, ch)) {
				minus_one_dMatrix(MT_4, check_point);
			}
			else {
				std::cout << "\n\n\t\t������ � ����� �������� ���!";
				Sleep(2000);
			}
			continue;
		case 5:
			see_all_dMatrix(MT_3, MT_4, amnt_of_mt_3, amnt_of_mt_4);
			std::cout << "\n�������� ������ ������, �������"
				<< " �� ������ ��������� MT_3(1) ��� MT_4(2) (0-�����): ";
			std::cin >> ch;
			if (ch == 1) {
				for (counter_1 = 0; counter_1 < amnt_of_mt_3; counter_1++) {
					--MT_3[counter_1];
				} clear_count();
			}
			if (ch == 2) {
				for (counter_1 = 0; counter_1 < amnt_of_mt_4; counter_1++) {
					--MT_4[counter_1];
				} clear_count();
			}

			continue;
		case 0: return 0;
		}
	}
}

//==========================================================================================================================================================//

//========================================================= Functions ======================================================================================//

//int menu() {		//������� ���� ������ ��� �������� �� �����
//	int k=0;
//
//	do {
//		system("CLS");
//		if (k < 0 || k > 5) {
//			std::cout << "\n\n\t\t������ ������ � ���� �� ����������!";
//			Sleep(2000);  system("CLS");
//		}
//		std::cout << "=================================\n"
//			<< "1 - ����� ��������� ������������ ������\n"
//			<< "2 - ������ ����� ������������ �������\n"
//			<< "3 - ����������� ������� ��� ������ ��������� =\n"
//			<< "4 - ��������� �������� ������������ ������� (�������� --)\n"
//			<< "5 - ��������� �������� ������������� �������\n"
//			<< "0 - �����\n"
//			<< "=================================\n";
//		std::cin >> k;
//	} while (k < 0 || k > 5);
//
//	system("CLS");
//
//	return k;
//}
//
//void show_alone(Matrix *MT_3, int amnt_of_mt) {
//	for (counter_1 = 0; counter_1 < amnt_of_mt; counter_1++) {
//		MT_3[counter_1].show_matrix();
//	} clear_count();
//}
//
//void see_all_dMatrix( Matrix *MT_3, Matrix *MT_4,
//	int amnt_of_mt_3, int amnt_of_mt_4) {
//
//	std::cout << "\n\nMT_3: \n";
//	for (counter_1 = 0; counter_1 < amnt_of_mt_3; counter_1++) {
//		MT_3[counter_1].show_matrix();
//	}clear_count();
//	std::cout << "\n\nMT_4: \n";
//	for (counter_1 = 0; counter_1 < amnt_of_mt_4; counter_1++) {
//		MT_4[counter_1].show_matrix();
//	}clear_count();
//}
//
//Matrix* set_new_dMatrix(Matrix *MT_3, int &amnt_of_mt) {
//	int stb, str;
//
//	std::cout << "������� ���-�� ������: ";
//	std::cin >> amnt_of_mt;
//
//	MT_3 = new Matrix[amnt_of_mt];
//
//	for (counter_1 = 0; counter_1 < amnt_of_mt; counter_1++) {
//		std::cout << "\n������� ���-�� �������� ��� ������� �� �����. �������: ";
//		std::cin >> stb;
//		std::cout << "\n������� ���-�� ����� ��� ������� �� �����. �������: ";
//		std::cin >> str;
//		//temp = counter_1 + 3;
//		MT_3[counter_1].set_mt_size(str, stb);
//		MT_3[counter_1].set_index(temp);
//		for (counter_2 = 0; counter_2 < str; counter_2++) {
//			for (counter_3 = 0; counter_3 < stb; counter_3++) {
//				std::cout << "\n������� MT_" << (temp) << "[" << counter_2 << "][" << counter_3 << "] :";
//				std::cin >> *MT_3[counter_1][stb * counter_2 + counter_3];
//			}
//		}
//		temp++;
//	} clear_count();
//	std::cout << "\n\n\t\t������� �������!";
//	system("pause");
//
//	return MT_3;
//}
//
//Matrix* copy_dMatrix(Matrix *MT_3, int amnt_of_mt_3, Matrix *MT_4) {
//
//	MT_4 = new Matrix[amnt_of_mt_3];
//
//	for (counter_1 = 0; counter_1 < amnt_of_mt_3; counter_1++) {
//		MT_4[counter_1] = MT_3[counter_1];   //�������� �������� ����� ������� �������� ����������� � ������
//		MT_4[counter_1].set_index(temp);
//		temp++;
//	} clear_count();
//	std::cout << "\n\n\t\t������� ���������!";
//	Sleep(2000);
//
//	return MT_4;
//}
//
//int find_index(Matrix* MT_3, int amnt_of_mt , int poisk) {
//	for (counter_1 = 0; counter_1 < amnt_of_mt; counter_1++) {
//		if (poisk == MT_3[counter_1].get_index()) {
//			std::cout << "\n\n\t\t������� �������!\n\t\t�����: " << poisk;
//			check_point = counter_1;
//			return MT_3[counter_1].get_index();
//		}
//	}
//	return -1;
//}
//
//void minus_one_dMatrix(Matrix * MT_3, int index) {
//
//	--MT_3[index];
//	std::cout << "\n\n\t\t������� �����������!";
//
//	
//	Sleep(1500);
//	system("pause");
//}

//==========================================================================================================================================================//


