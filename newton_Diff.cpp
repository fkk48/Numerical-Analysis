#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
#pragma warning(disable:6385)
#pragma warning(disable:6386)
#pragma warning(disable:26451)

int main() {
	int n;
	cout << "��������֪�������:" << endl;
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
		y[i] = stod(str.substr(idx + 1, str.length() - 1));
	}
	cout << "������������xֵ:" << endl;
	double input_x=0.0;
	cin >> input_x;
	double h = x[1] - x[0];
	double t = (input_x - 0) / h;
	//������ֱ�
	cout << "��ֱ�����:" << endl;
	double** diff = new double* [n];
	for (int i = 0; i < n; i++) {
		diff[i] = new double[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			diff[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				diff[i][j] = y[i];
			}
			else {
				diff[i][j] = diff[i][j - 1] - diff[i - 1][j - 1];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//��������
			cout << setw(10) << setiosflags(ios::left) << diff[i][j];
		}
		cout << endl;
	}
	double result = y[0];
	cout << "������ţ��ǰ�幫ʽ�Ĵ���:" << endl;
	double count=0.0;
	cin >> count;
	for (int i = 0; i < count; i++) {
		double w = 1.0, ww = 1.0;
		for (int j = 0; j <= i; j++) {
			w *= (j + 1);
			ww *= (t - j);
		}
		result += (ww / w) * diff[i + 1][i + 1];
	}
	cout << "f(" << input_x << ") = " << result << endl;
	return 0;
}