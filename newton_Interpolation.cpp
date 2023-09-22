#include<iostream>
#include<string>
using namespace std;

#pragma warning(disable:26451)

int main() {
	int n;
	cout << "请输入给定点个数:" << endl;
	cin >> n;
	double* x = new double[n];
	double* y = new double[n];
	cout << "请输入形如(x,y)的坐标:" << endl;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		str.replace(str.find("("), str.find("(") + 1, "");
		str.replace(str.find(")"), str.find(")") + 1, "");
		int idx = str.find(",");
		x[i] = stod(str.substr(0, idx));
		y[i] = stod(str.substr(idx+1, str.length()-1));
	}
	//定义并初始化均差矩阵
	double** f = new double* [n];
	for (int i = 0; i < n; i++) {
		f[i] = new double[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			f[i][j] = 0.0;
		}
	}
	//求解均差矩阵
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
	cout << "请输入要预测的x的值:" << endl;
	cin >> input_x;
	//根据均差矩阵求解输入的近似值
	double result = 0.0;
	for (int i = 0; i < n; i++) {
		double w = 1.0;
		for (int j = 0; j < i; j++) {
			w *= (input_x - x[j]);
		}
		result += f[i][i] * w;
	}
	cout << "计算后的结果为:" << endl;
	cout << "f(" << input_x << ") = " << result << endl;
}