#include <iostream>
using namespace std;
// 在此处补充你的代码
int main(int argc, char* argv[])
{
	int t;
	cin >> t;
	while (t--) {
		int n, i, j;
		cin >> n >> i >> j;
		int result = 0;
		if (n &(1 << i)) {//n的第i位为1，如果是0不需要改变
			result |= 1 << i;
		}
		if (!(n & (1 << j)))//n的第j位为0,如果是1不需要改变
		{
			result |= 1 << j;
		}
		for (int k = i + 1; k < j; k++)
		{
			result |= 1 << k;
		}
		cout << hex << result << endl;
	}
	return 0;
}