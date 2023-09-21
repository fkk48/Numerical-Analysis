#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

int main() {
	//�������Ľ�����ϵ������ͳ��������
	int n;
	cout << "���������:" << endl;
	cin >> n;
	double** a = new double* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new double[n];
	}
	//�����ַ�����ʽ�ķ�����������Ӧ�ķָ�
	cout << "������ϵ������(����):" << endl;
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
	cout << "�����볣����أ����У�:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	//����ֽ���LU���󲢽��г�ʼ��
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
	//���ϵ������ֽ���LU����
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
	cout << "*********L����************" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << l[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\n*********U����************" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << u[i][j] << "\t";
		}
		cout << endl;
	}
	//���y����
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
	cout << "\n*********y����************" << endl;
	for (int i = 0; i < n; i++) {
		cout << y[i] << "\t";
	}
	cout << endl;
	//���x���󣬼����Ľ��
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
	cout << "\n*********������Ľ������************" << endl;
	for (int i = 0; i < n; i++) {
		cout << "x" << i + 1 << " = " << x[i] << endl;
	}
	return 0;
}