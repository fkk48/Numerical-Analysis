#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

int main() {
	//输入矩阵的阶数，系数矩阵和常数项矩阵
	int n;
	cout << "请输入阶数:" << endl;
	cin >> n;
	double** a = new double* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new double[n];
	}
	//输入字符串形式的分数并进行相应的分割
	cout << "请输入系数矩阵(按行):" << endl;
	string str;
	for (int i = 0; i < n; i++) {
		double aa=1.0, bb=1.0;
		for (int j = 0; j < n; j++) {
			cin >> str;
			int idx = str.find("/");
			if (idx != -1) {
				aa = stod(str.substr(0, idx));
				bb = stod(str.substr(idx + 1, str.length()-1));
				a[i][j] = aa / bb;
			}
			else {
				a[i][j] = stod(str);
			}
		}
	}
	double* b = new double[n];
	cout << "请输入常数项矩（按行）:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	//定义分解后的LU矩阵并进行初始化
	double** l = new double* [n];
	for (int i = 0; i < n; i++) {
		l[i] = new double[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			l[i][j] = 0;
		}
	}
	double** u = new double* [n];
	for (int i = 0; i < n; i++) {
		u[i] = new double[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			u[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		l[i][i] = 1;
	}
	//求解系数矩阵分解后的LU矩阵
	for (int i = 0; i < n; i++) {
		u[0][i] = a[0][i];
		l[i][0] = a[i][0] / u[0][0];
	}
	double sum = 0;
	for (int i = 1; i < n; i++) {
		for (int j = i; j < n; j++) {
			sum = 0.0;
			for (int k = 0; k < i; k++) {
				sum += l[i][k] * u[k][j];
			}
			u[i][j] = a[i][j] - sum;
			sum = 0.0;
			for (int m = i + 1; m < n; m++) {
				for (int k = 0; k < i; k++) {
					sum += l[m][k] * u[k][i];
				}
				l[m][i] = (a[m][i] - sum) / u[i][i];
			}
		}
	}
	cout << "*********L矩阵************" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << l[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\n*********U矩阵************" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << u[i][j] << "\t";
		}
		cout << endl;
	}
	//求解y矩阵
	double* y = new double[n];
	for (int i = 0; i < n; i++) {
		sum = 0.0;
		if (i == 0) {
			y[i] = b[0];
		}
		else {
			for (int k = 0; k < i; k++) {
				sum += l[i][k] * y[k];
			}
			y[i] = b[i] - sum;
		}
	}
	cout << "\n*********y矩阵************" << endl;
	for (int i = 0; i < n; i++) {
		cout << y[i] << "\t";
	}
	cout << endl;
	//求解x矩阵，即最后的结果
	double* x = new double[n];
	for (int i = n - 1; i >= 0; i--) {
		sum = 0.0;
		if (i == n - 1) {
			x[i] = y[i] / u[i][i];
		}
		else {
			for (int k = i + 1; k < n; k++) {
				sum += u[i][k] * x[k];
			}
			x[i] = (y[i] - sum) / u[i][i];
		}
	}
	cout << "\n*********计算出的结果如下************" << endl;
	for (int i = 0; i < n; i++) {
		cout << "x" << i + 1 << " = " << x[i] << endl;
	}
	return 0;
}