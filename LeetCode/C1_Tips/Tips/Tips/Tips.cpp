#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
	cout << "�ж��Ƿ�������" << endl;
	cout << "3 % 2 = " << 3 % 2 << endl;
	cout << "2 % 2 = " << 2 % 2 << endl;
	cout << "1 % 2 = " << 1 % 2 << endl;
	cout << "0 % 2 = " << 0 % 2 << endl;
	cout << "-1 % 2 = " << -1 % 2 << endl;
	cout << "-2 % 2 = " << -2 % 2 << endl;
	cout << "-3 % 2 = " << -3 % 2 << endl;
	cout << "�����ж�һ�������Ƿ�������Ӧ���ǣ�" << endl 
	<< "if (n % 2 > 0)" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "��char�������±�ʱ��" << endl;
	cout << "char => unsigned char => ���±�" << endl;
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
