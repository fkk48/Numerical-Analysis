#include<iostream>
#include<iomanip>
using namespace std;
#pragma warning(disable:6385)
#pragma warning(disable:6386)

int main() {
	int n;
	cout << "���������:" << endl;
	cin >> n;
	double** a = new double* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new double[n];
	}
	cout << "������ϵ�����󣨰��У�:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	double* b = new double[n];
	cout << "�����볣����أ����У�:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	//����ѡ��Ԫ����
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
		//����ϵ�������δ֪���λ��
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
	//��Ԫ����
	for (int i = 0; i < 2; i++) {
		k = i + 1;
		//�������
		for (int j = 0; j < 2 - i; j++) {
			mm[i][j] = a[k][i] / a[i][i];
			k++;
		}
		//�޸�ϵ�������Լ�������
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
	cout << "ϵ������ʽ��ֵΪ:" << alpha*det << endl;
	//�ش�����
	double* x = new double[n];
	for (int i = n - 1; i >= 0; i--) {
		if (i != n - 1) {
			for (int j = i + 1; j < n; j++) {
				b[i] = b[i] - x[j] * a[i][j];
			}
		}
		x[i] = b[i] / a[i][i];
	}
	//������
	cout << "������Ϊ:" << endl;
	for (int i = 0; i < n; i++) {
		cout << "x" << i + 1 << " = " << setprecision(4) << x[i] << endl;
	}
	return 0;
}