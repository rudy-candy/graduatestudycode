//定数を利用する
#include <iostream>
using namespace std;
int main()
{
	const double pi = 3.1415;

	cout << "円周率の値は" << pi << "です\n";

	cout << "円周率の値は変更しません\n";
	
	//このような代入による変更はできません。
	//pi = 1.44

	return 0;
}
