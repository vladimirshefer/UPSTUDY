#include <iostream>

using namespace std;

int a[100];


int main()
{
	int m, n;
	cin >> n >> m;
	for(int i = 1; i <= m*2; i++){
		int z;
		cin >> z;
		a[z]++;
	}
	for(int i = 1; i <= n; i++){
		cout << a[i] << ' ';
	}
    return 0;
}
