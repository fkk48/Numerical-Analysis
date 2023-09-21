#include<iostream>
#include<string>
using namespace std;

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
		y[i] = stod(str.substr(idx + 1, str.length() - 1));
	}
	double input_x;
	cout << "请输入要预测的输入x:" << endl;
	cin >> input_x;
	double result = 0.0;
	//依次计算线性插值基函数
	for (int i = 0; i < n; i++) {
		double w = 1.0;
		double ww = 1.0;
		for (int j = 0; j < n; j++) {
			if(j != i){
				w *= (x[i] - x[j]);
				ww *= (input_x - x[j]);
			}
		}
		//计算结果，并进行累加
		result += y[i] * ww / w;
	}
	cout << "结果计算如下:" << endl;
	cout << "f(" << input_x << ") = " << result << endl;
}