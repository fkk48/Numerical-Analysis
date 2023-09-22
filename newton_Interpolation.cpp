#include<iostream>
#include<string>
using namespace std;

#pragma warning(disable:26451)

int main() {
	int n;
	cout << "��������������:" << endl;
	cin >> n;
	double* x = new double[n];
	double* y = new double[n];
	cout << "����������(x,y)������:" << endl;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		str.replace(str.find("("), str.find("(") + 1, "");
		str.replace(str.find(")"), str.find(")") + 1, "");
		int idx = str.find(",");
		x[i] = stod(str.substr(0, idx));
		y[i] = stod(str.substr(idx+1, str.length()-1));
	}
	//���岢��ʼ���������
	double** f = new double* [n];
	for (int i = 0; i < n; i++) {
		f[i] = new double[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			f[i][j] = 0.0;
		}
	}
	//���������
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (i == 0) {
				f[j][i] = y[j];
			}
			else {
				f[j][i] = (f[j][i - 1] - f[j - 1][i - 1]) / (x[j] - x[j - i]);
			}
		}
	}
	double input_x;
	cout << "������ҪԤ���x��ֵ:" << endl;
	cin >> input_x;
	//���ݾ�������������Ľ���ֵ
	double result = 0.0;
	for (int i = 0; i < n; i++) {
		double w = 1.0;
		for (int j = 0; j < i; j++) {
			w *= (input_x - x[j]);
		}
		result += f[i][i] * w;
	}
	cout << "�����Ľ��Ϊ:" << endl;
	cout << "f(" << input_x << ") = " << result << endl;
}