#include <iostream>

using namespace std;

bool mark[100];
int a[100][100];
int sum, n, m;

int ans(int r)
{
	sum++;
	mark[r] = 1;
	for(int i = 0; i < n; i++){
		if(mark[i] == 0  && a[r][i] == 1) ans(i);
	}
	return sum - 1;
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	cout << ans(m - 1);
return 0;
}
