#include <iostream>

using namespace std;
//пейспяхъ
int Fib(int x){
	if(x == 0){
		return 0;
	}
	if(x == 1){
		return 1;
	}
	return Fib(x - 1) + Fib(x - 2);
}

int main()
{
	int a;

    cin >> a;
    if(a == 1)
		cout << 0;
	else
		cout << Fib(a);

    return 0;
}
