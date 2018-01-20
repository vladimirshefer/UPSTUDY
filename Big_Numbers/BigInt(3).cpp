#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int mod(int n, int m) {
	return ((n%m) + m) % m;
}

int divide(int n, int m) {
	double result = (double)n / m;
	if (result < 0) result--;
	return (int) result;
}

struct BigInt{

	vector<int> digits = vector<int>(0);
	bool negative = false;

	void put(int value){
		digits.erase(digits.begin(), digits.end());
		digits.push_back(value);
		wave();
	}


	void put(BigInt a){
		digits.erase(digits.begin(), digits.end());
		for(int i = a.length()-1; i >= 0; i--){
			digits.insert (digits.begin(), a.digit(i));
		}
		wave();
	}

	void inc(){
			digits[0]++;
			wave();
	}

	void add (int number){
		if(negative == 0 && number >= 0){
			digits[0] += number;
			wave();
		}
		if(negative == 0 && number < 0){
			reduce(number);
		}
		if(negative == 1 && number > 0){
			reduce(number);
		}
		if(negative == 1 && number < 0){
			digits[0] += number;
			negative = 1;
			wave();
		}
	}


	void multiply(int number){
		if(negative == 0 && number < 0 || negative == 1 && number > 0){
			negative = 1;
		}
		for(int i = 0; i < length(); i++){
			digits[i] *= number;
		}
		wave();
	}

	void dec(){
		if(negative == 1){
			inc();
		} else {
			digits[0]--;
			wave();
		}
	}

	void reduce(int number){
		if(negative == 1){
			add(number);
		} else {
			digits[0] -= number;
			wave();
		}
	}

	int digit(int n){
		if (n<length() && n>=0 ){
		    return digits[n];
		} else {
			return 0;
		}
	}

	void grow(int size){
		for (int i = length(); i < size; i++){
			digits.push_back(0);
		}
	}

	void add (BigInt arg) {
		if(negative){
			reduce(arg);
		} else {
		int maxlen = length() > arg.length() ? length() : arg.length();
		grow(maxlen);
		for (int i = 0; i< maxlen; i++){
			digits[i] += arg.digit(i);
		}
		wave();
		}
	}

	void wave(){
		for(int i = 0; i < length() - 1; i++){
			digits[i + 1] += divide(digits[i], 10);
			digits[i] = mod(digits[i],10);
		}
		while(digits[length()-1] > 9){
			digits.push_back(divide(digits[length() - 1], 10));
			digits[length() - 2] = mod(digits[length() - 2], 10);
		}

		trim();
	}

	void trim() {
		while(digits[length() - 1] == 0){
			digits.pop_back();
		}
	}

	int length(){
		return digits.size();
	}

	void print () {
		if(negative == 1){
			cout << "- ";
		}
		for(int i = length()-1; i >= 0; i--){
			cout << digits[i] << ' ';
		}

		cout << endl;
	}

	void reduce(BigInt a){
		int maxlen = length() > a.length() ? length() : a.length();
		grow(maxlen);
		//cout << digit(length()-1)<< endl;;
		if(digit(length()-1) != 0){
			for(int i = 0; i < maxlen; i++){
				digits[i] -= a.digit(i);
			}
		} else {
			BigInt supp;
			//BigInt th = (*this);

			supp = a;
			a.put(*this);
			put(supp);

			for(int i = 0; i < maxlen; i++){
				digits[i] -= a.digit(i);
			}
			negative = 1;
		}
		wave();
	}
	int compare(BigInt a){

			BigInt sup;
			sup.put(*this);
			sup.reduce(a);
			if(sup.length() == 1 && sup.digit(0) == 0){
				return 0;
			}
			if(sup.negative == true){
				return -1;
			}
			if(sup.negative == false){
				return 1;
			}

	}
	void negate() {
		negative = !negative;
	}

	void move_left(int n) {
		//auto it = ;
		digits.insert (digits.begin(), n, 0);
	}

	void move_right(int n) {
		//auto it = ;
		digits.push_back(0);
	}

	void multiply_BigInt(BigInt b){
	BigInt sup = *this;
	BigInt sum;
	sum.put(0);
	for(int i = 0; i < b.length(); i++){
		sup.put(*this);
		sup.multiply(b.digit(i));
		sup.move_left(i);
		sum.add(sup);
	}
	put(sum);
}
	void dividee(BigInt value) {
		BigInt ONE, ZERO;
		ONE.put(1);
		ZERO.put(0);
		if (compare(value) == 0) {
			put(1);
			return;
		}
		BigInt divider;
		divider.put(value);
		//negative = false;
		//divider.negative = false;
		BigInt ret;
		ret.put(0);
		ret.negative = (negative != value.negative);
		if (compare(divider) < 0) {
			put(0);
			return;
		}
		int cnt = 0;
		while (compare(ZERO) > 0) {
			BigInt d;
			d.put(1000);
			//if(ret.compare(d) < 0)


			if (compare(divider) > 0 || compare(divider) == 0){
				cout << "VALUE IF "; value.print();
				cout << "SELF IF "; print();
				reduce(divider);
				BigInt e;
				e.put(1);
				e.move_left(cnt);
				ret.add(e);
				divider.move_left(1);
				cnt++;
			} else {
				ret.print();
				divider = value;
				cnt = 0;
				cout << "VALUE"; value.print();
				cout << "SELF"; print();
				if (compare(value) < 0) {
					//ret.trim();
					put(ret);
					return;
				}
			}
			divider.negative = false;
		}
		ret.trim();
		put(ret);
	}
};

/*void multiply_BigInt (BigInt a, BigInt b){
	BigInt ans, pre;
	int zeros_after_sum = -1;

	for(int i = 0; i < b.length(); i++){
		zeros_after_sum++;
		for(int j = 0; j < a.length(); j++){
			pre.digits.push_back(a.digits[j] * b.digits[i]);
		}pre.print();
ans = pre;
		for(int j = 0; j < zeros_after_sum; j++){
			ans.digits.push_back(0);
		}

cout << 'A'; ans.print();
pre.digits.erase(pre.digits.begin(), pre.digits.end());
	}

}*/

/*void multiply_BigInt (BigInt a, BigInt b){
	BigInt ans;
	BigInt pre;
	for(int i = 0; i < a.length(); i++){
		pre.digits.push_back(a.digits[i] * b.digits[0]);
	}
	pre.print();
	ans.digits.push_back(0);
	for(int i = 0; i < a.length(); i++){
		ans.digits.push_back(a.digits[i] * b.digits[1]);
	}
	ans.print();
	for(int i = 0; i < ans.length(); i++){
		ans.digits[i] += pre.digits[i];
	}
	ans.print();
	for(int i = 2; i < b.length(); i++){

		pre = ans;

		ans.digits.erase(ans.digits.begin(), ans.digits.end());

		for(int j = 0; j < a.length(); j++){
			ans.digits.push_back(a.digits[j] * b.digits[i]);
		}

//BigInt sup = ans;

		ans.digits.erase(ans.digits.begin(), ans.digits.end());
        for(int j = 0; j <= i; j++){
			ans.digits.push_back(0);
        }
/*
		for(int j = 0; j < sup.length(); j++){
			ans.digits.push_back(sup.digits[j]);
		}*/
		/*pre.print();
		ans.print();
	}
}*/

/*void multiply_BigInt (BigInt& a, BigInt& b){
	int d = 1;
	BigInt s = b;
	for(int i = 0; i < s.length(); i++){
		cout << b.digit(i) << endl;
		a.multiply(b.digit(i));
		a.multiply(d);
		d *= 10;
		a.wave();
		b.add(a);
	}
	a.wave();
}*/

/*void multiply_BigInt(BigInt &a, BigInt b){
	int d = 1;
	BigInt sup;
	sup.put(0);
	for(int i = 0; i < b.length(); i++){
		a.multiply(b.digit(i));
		a.multiply(d);a.print(); cout << endl;
		a.add(sup);
		sup = a;
		d *= 10;
	}
}
*/

/*void multiply_BigInt(BigInt &a, BigInt b){
	BigInt sup = a;
	BigInt sum;
	sum.put(0);

	for(int i = 0; i < b.length(); i++){
		sup = a;
		sup.multiply(b.digit(i));
		sup.move_left(i);
		sum.add(sup);
	}
	a = sum;
}*/

/*void multiply_BigInt (BigInt a, BigInt b){
	int zeros_after_sum = 0;
	int zeros = 0;
	BigInt ans;
	BigInt pre;

	for(int i = 0; i <= b.length(); i++){


		for(int j = 0; j < a.length(); j++){
			pre.digits.push_back(a.digits[j] * b.digits[i]);
		}
		pre.print();

		ans.print();
ans = pre;
		pre.digits.erase(pre.digits.begin(), pre.digits.end());
	}
}*/


//99 mod 100 === (99 -100) mod 100

//n mod m === (n+km) mod m, k (- Z


int exp2 (int n) {
	int result = 1;
	for (int i = 0; i<n; i++){
		result *= 2;
	}
	return result;
}

int main()
{
//	for(int i = 0; i < 40; i++){
//			cout << exp2(i) << endl;
//	}

	BigInt a, b;
	a.put(1024);
	b.put(16);
	b.negative = 1;
	//cout << a.compare(b);
	a.dividee(b);
		a.print();


    return 0;
}
