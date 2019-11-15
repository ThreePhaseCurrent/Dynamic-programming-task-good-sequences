#include <iostream>
using namespace std;

unsigned long int mas[2001][2001];

int main()
{
	int a, b;
	cin >> a >> b;
	mas[0][1] = 1;
	for (int i = 1; i <= b; i++)
	{
		for (int j = 1; j <= a; j++)
		{
			for (int k = j; k <= a; k += j)
			{
				mas[i][k] = (mas[i][k] + mas[i - 1][j]) % 1000000007;
			}
		}
#ifdef _DEBUG
		for (int i = 0; i <= b + 1; i++)
		{
			for (int j = 0; j <= a + 1; j++)
			{
				cout << mas[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
#endif
	}

	unsigned long int result = 0;
	for (int i = 1; i <= a; i++)
	{
#ifdef _DEBUG
		cout << mas[b][i] << endl;
#endif
		result = (result + mas[b][i]) % 1000000007;
	}
	cout << result;
	return 0;
}