#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


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

	void add (int number){
		for(int i = 0; i < number; i++){
			inc();
		}
	}

	void reinc(){
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
			reinc();
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

	void print () {
		for(int i = length()-1; i >= 0; i--){
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


	a.put(10000);
	a.reduce(5119);
	a.print();

    return 0;
}
