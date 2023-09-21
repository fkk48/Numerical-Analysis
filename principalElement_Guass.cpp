#include<iostream>
#include<iomanip>
using namespace std;
#pragma warning(disable:6385)
#pragma warning(disable:6386)

int main() {
	int n;
	cout << "请输入阶数:" << endl;
	cin >> n;
	double** a = new double* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new double[n];
	}
	cout << "请输入系数矩阵（按行）:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	double* b = new double[n];
	cout << "请输入常数项矩（按行）:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	//进行选主元操作
	double alpha = 1.0;
	for (int i = 0; i < n; i++) {
		int idx = i;
		double max_val = abs(a[i][i]);
		for (int j = i; j < n; j++) {
			if (abs(a[j][i]) > max_val) {
				max_val = a[j][i];
				idx = j;
			}
		}
		if (idx != i) {
			alpha *= -1.0;
		}
		//交换系数矩阵和未知项的位置
		for (int j = 0; j < n; j++) {
			double temp;
			temp = a[i][j];
			a[i][j] = a[idx][j];
			a[idx][j] = temp;
		}
		double temp = b[i];
		b[i] = b[idx];
		b[idx] = temp;
	}
	double** mm = new double* [n - 1];
	for (int i = 0; i < n - 1; i++) {
		mm[i] = new double[n - 1];
	}
	int k = 0, p = 0, q = 0;
	//消元过程
	for (int i = 0; i < 2; i++) {
		k = i + 1;
		//计算乘数
		for (int j = 0; j < 2 - i; j++) {
			mm[i][j] = a[k][i] / a[i][i];
			k++;
		}
		//修改系数矩阵以及常数项
		p = 0;
		q = 0;
		for (int m = i + 1; m < 3; m++) {
			p = i;
			for (int n = 0; n < 3; n++) {
				a[m][n] = a[m][n] - mm[p][q] * a[p][n];
			}
			b[m] = b[m] - mm[p][q] * b[i];
			q++;
		}
	}
	double det = 1.0;
	for (int i = 0; i < n; i++) {
		det *= a[i][i];
	}
	cout << "系数行列式的值为:" << alpha*det << endl;
	//回代过程
	double* x = new double[n];
	for (int i = n - 1; i >= 0; i--) {
		if (i != n - 1) {
			for (int j = i + 1; j < n; j++) {
				b[i] = b[i] - x[j] * a[i][j];
			}
		}
		x[i] = b[i] / a[i][i];
	}
	//输出结果
	cout << "运算结果为:" << endl;
	for (int i = 0; i < n; i++) {
		cout << "x" << i + 1 << " = " << setprecision(4) << x[i] << endl;
	}
	return 0;
}