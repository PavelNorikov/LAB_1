#include <iostream>
using namespace std;

int  r = 0, antir = 0, s = 0, antis = 0, t = 0;

void ref(int** v, int n)
{
	int checker = 0;
	for (int i = 0; i < n; i++) {
		if (v[i][i] == 1)
			checker++;
	}
	if (checker == n) {
		cout << "Отношение рефлексивно" << endl;
		r++;
	}
	else if (checker == 0) {
		cout << "Отношение антирефлексивно" << endl;
		antir++;
	}
	else {
		cout << "Отношение НЕ рефлексивно" << endl;
		cout << "Отношение НЕ антирефлексивно" << endl;
	}
}


void sim(int** v, int n)
{
	int checker_not_sim = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[i][j] != v[j][i])
				checker_not_sim++;
		}
	}
	if (checker_not_sim == 0) {
		cout << "Отношение симметрично" << endl;
		s++;
	}
	else {
		cout << "Отношение НЕ симметрично" << endl;
	}
}


void antisim(int** v, int n)
{
	int checker_not_antisim = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] == v[j][i])
				if (i != j)
					checker_not_antisim++;
		}
	}
	if (checker_not_antisim == 0) {
		cout << "Отношение антисимметрично" << endl;
		antis++;
	}
	else {
		cout << "Отношение НЕ антисимметрично" << endl;
	}
}


void tran(int** v, int n)
{
	int checker = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] == 1) {
				for (int k = 0; k < n; k++) {
					if (v[j][k] == 1)
						if (v[i][k] == 0)
							checker++;
				}
			}
		}
	}
	if (checker == 0) {
		cout << "Отношение транзитивно" << endl;
		t++;
	}
	else {
		cout << "Отношение НЕ транзитивно" << endl;
	}
}


void make_ref(int** v, int n)
{
	for (int i = 0; i < n; i++)
		v[i][i] = 1;
}


void make_sim(int** v, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (v[i][j] == 1)
				v[j][i] = 1;
}


void make_tran(int** v, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (v[j][k] == 1) {
					for (int p = 0; p < n; p++) {
						if (v[k][p] == 1)
							v[j][p] = 1;
					}
				}
			}
		}
	}
}

void print_ar(int** v, int n, int which) {
	int** v2;
	v2 = new int* [n];
	for (int i = 0; i < n; i++) {
		v2[i] = new int[n];
		for (int j = 0; j < n; j++) {
			v2[i][j] = v[i][j];
		}
	}

	if (which == 1) {
		make_ref(v2, n);
		cout << "Замыкание рефлексивности:" << endl;
	}
	if (which == 2) {
		make_sim(v2, n);
		cout << "Замыкание симметричности:" << endl;
	}
	if (which == 3) {
		make_tran(v2, n);
		cout << "Замыкание транзитивности:" << endl;
	}
	if (which == 4) {
		make_ref(v2, n);
		make_sim(v2, n);
		make_tran(v2, n);
		cout << "Замыкание эквивалентности:" << endl;
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << v2[i][j] << ' ';
		cout << endl;
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите количество элементов. n = ";
	cin >> n;
	int** v;
	v = new int* [n];
	cout << "Введите матрицу бинарного отношения. А = " << endl;
	for (int i = 0; i < n; i++) {
		v[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}

	ref(v, n);
	sim(v, n);
	tran(v, n);
	antisim(v, n);
	if (r == 1 && s == 1 && t == 1)
		cout << "Отношение является отношением эквивалентности" << endl;
	else {
		cout << "Отношение НЕ является отношением эквивалентности" << endl;
	}
	if (r == 1 && antis == 1 && t == 1)
		cout << "Отношение является отношением частичного порядка" << endl;
	else {
		cout << "Отношение НЕ является отношением частичного порядка" << endl;
	}
	if (r == 1 && t == 1)
		cout << "Отношение является отношением квазипорядка" << endl;
	else {
		cout << "Отношение НЕ является отношением квазипорядка" << endl;
	}
	print_ar(v, n, 1);
	print_ar(v, n, 2);
	print_ar(v, n, 3);
	print_ar(v, n, 4);

	return 0;
}