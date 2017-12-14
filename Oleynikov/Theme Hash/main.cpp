#include <iostream>

using namespace std;

// контракт equals и hashcode

//0/ hash(a) == hash(a)
//1. if (a == b ) => hash(a) == hash(b)
// if ((a != b) && hash(a) == hash(b)) => коллизи€

int hash1 (string s){
	int hash = 0;
	for (int i = 0; i < s.length(); i++){
		hash += s[i];
	}
	return hash;
}

// h _ ello _ p

int hash1next(char oldchar, int oldhash, char newchar){
	return oldhash - oldchar + newchar
}

int hash2(string s){
	int E = 2 << 31 - 1; // == 2^32 -1
	int x = 13;
	int hash = 0;
	for (int i = 0; i < s.length(); i++){
		hash =  (hash*x + s[i]) % E;
	}
}


//a[n] = символ строки
//x - любое простое число

// P(x) = a[1]*x^n + a[2]*x^n-1 + ... + a[n-1]*x + a[n]*1


// nohash >> O(wl*tl)
// wihash >> O(wl*tl) + O(tl*1)
// smhash >> O(wl*1 ) + O(tl*1)

// ѕолиномиальный хеш

wl + wl*1 + 1*tl

ewdrhmqwcrgelc   => O(l)
 wdrhmqwcrgelck  => O(1)
  drhmqwcrgelcko => O(1)


// wh = O(wl)


//40000000 l = length
//3 k = comparison сравнений
//3000000 n - количество строк

//int nohash = (O(k*l));
//int wihash = (O(n*l));



int main()
{
	//hashcode
	string a = "hello "; //5d41402abc4b2a76b9719d911017c592
	string b = " ellou"; //7c141bf8db7d6a7bac0c03357a983aa3

	string c = "lello";  //741251a82e793eb9181ceedff8240bb8

	abacabadabacaba

	int hash_a = hash1(a);
	int hash_b = hash1(b);
	int hash_c = hash1(c);

	cout << hash_a << " : "<< hash_b << " : " << hash_c;

    return 0;
}
