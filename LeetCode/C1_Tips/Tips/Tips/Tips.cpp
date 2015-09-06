#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
	cout << "判断是否是奇数" << endl;
	cout << "3 % 2 = " << 3 % 2 << endl;
	cout << "2 % 2 = " << 2 % 2 << endl;
	cout << "1 % 2 = " << 1 % 2 << endl;
	cout << "0 % 2 = " << 0 % 2 << endl;
	cout << "-1 % 2 = " << -1 % 2 << endl;
	cout << "-2 % 2 = " << -2 % 2 << endl;
	cout << "-3 % 2 = " << -3 % 2 << endl;
	cout << "所以判断一个整数是否是奇数应该是：" << endl 
	<< "if (n % 2 > 0)" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "用char做数组下标时：" << endl;
	cout << "char => unsigned char => 做下标" << endl;
	int row_num = 3;
	int col_num = 3;
	vector< vector<int> > ary(row_num, vector<int>(col_num, 0));
	for(int i=0; i<row_num; i++)
	{
		for(int j=0; j<col_num; j++)
		{
			cout << ary[i][j] << "	";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
