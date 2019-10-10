//2つ以上の数値を続けて入力する
#include <iostream>
using namespace std;
int main()
{
	int	num1, num2;

	cout << "整数を2つ入力してください";

	cin >> num1 >> num2; //cinはキーボードからの入力,二回続けて入力させます

	cout << "最初に" << num1 << "が入力されました。\n";

	cout << "次に" << num2 << "が入力されました。\n";
	
	return 0;
}
