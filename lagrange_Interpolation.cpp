#include<iostream>
#include<string>
using namespace std;

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
		y[i] = stod(str.substr(idx + 1, str.length() - 1));
	}
	double input_x;
	cout << "������ҪԤ�������x:" << endl;
	cin >> input_x;
	double result = 0.0;
	//���μ������Բ�ֵ������
	for (int i = 0; i < n; i++) {
		double w = 1.0;
		double ww = 1.0;
		for (int j = 0; j < n; j++) {
			if(j != i){
				w *= (x[i] - x[j]);
				ww *= (input_x - x[j]);
			}
		}
		//���������������ۼ�
		result += y[i] * ww / w;
	}
	cout << "�����������:" << endl;
	cout << "f(" << input_x << ") = " << result << endl;
}