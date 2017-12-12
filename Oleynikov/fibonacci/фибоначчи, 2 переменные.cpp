#include <iostream>

using namespace std;
//œ–Œ—“Œ Õ¿ œ–ﬂÃ”ﬁ
int Fib(int x){
	if(x == 1){
		return 0;
	}else{
	int i0 = 0, i1 = 1;
	for(int i = 1; i < x; i++){
		i1 += i0;
		i0 = i1 - i0;
	}
	return i1;
	}
}

int main()
{
	int a;
    cin >> a;

	cout << Fib(a);

    return 0;
}
