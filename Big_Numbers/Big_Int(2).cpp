#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int	zeros = 0;

struct BigInt{
	vector<int> digits = vector<int>(0);

	void put(int value){
		digits.erase(digits.begin(), digits.end());
		while(value >= 10){
			digits.push_back(value % 10);
			value /= 10;
		}
		digits.push_back(value);
	}

	void inc(){
		digits[0]++;
		wave();
	}

	/*void add (int number){
		for(int i = 0; i < number; i++){
			inc();
		}
	}*/

	void add (int number){
		int u = 0, x = number;
		while(x > 10){
			x /= 10;
			u++;
		}
		if(u > length()){
			int m, l = length();
			for(int i = length(); i <= u; i++){
				digits.push_back(0);
				digits[i] = number % 10;
				number /= 10;
			}
			digits[length() - 1] = number / 10;
		} else {
			digits[0] += number;
			for(int i = 0; i < length(); i++){
				digits[i + 1] += digits[i] / 10;
				digits[i] %= 10;
			}
		}
	}

	void multiply(int number){
		for(int i = 0; i < length(); i++){
			digits[i] *= number;
		}
		for(int i = 0; i < length() - 1; i++){
			digits[i + 1] += digits[i] / 10;
			digits[i] %= 10;
		}
		int i = length();
		int n = digits[length() - 1];
		while(n > 10){
			digits[i] = 0;
			n /= 10;
            digits[i] += digits[i - 1] / 10;
            digits[i - 1] %= 10;
            zeros++;
			i++;
		}
	}

	void dec(){
		if(digits[0] == 0){
			int i = 0;
			while(digits[i] == 0){
				digits[i] = 10;
				i++;
			}
			digits[i]--;

			int z = 0;
			while(digits[z] == 10){
				digits[z]--;
				z++;
			}
		} else {
			digits[0]--;
		}
		if(digits[length() - 1] == 0){
			digits.pop_back();
		}
	}

	void reduce(int number){
		for(int i = 0; i < number; i++){
			dec();
		}
	}

	void wave(){
		for(int i = 0; i < length(); i++){
			if(digits[i] > 9){
					// FIXME
				digits[i+1] += digits[i] / 10;
				digits[i] %= 10;
			}
		}
	}

	void wave_broken(){
		for(int i = 0; i < length(); i++){
			if(digits[i] > 9){
				digits[i] = 0;
				digits[i + 1]++;
			}
		}
	}

	int length(){
		return digits.size();
	}

	void print () {  //WARNING CHANGES
		for(int i = length()-1 + zeros; i >= 0; i--){
			cout << digits[i] << ' ';
		}
		cout << endl;
	}

};

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


	a.put(200000099);
	a.add(55);
	a.print();

    return 0;
}
