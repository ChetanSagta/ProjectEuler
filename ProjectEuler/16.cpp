#include<iostream>
#include<vector>

int multiplyandSum(int base, int power) {

	int sum = 0;
	int values[1024] = {1};
	bool carry = false;
	int carryValue = 0;

	std::cout << "Values : ";
	/*for (int i = 63; i >= 0; i--) {
		std::cout << values[i];
	}*/

	for (int i = 0; i < power; i++) {
		for (int j = 0; j < 1023; j++) {
			values[j] *= base;
			values[j] += carryValue;
			carryValue = values[j] / 10;
			if (carryValue > 0) {
				values[j] %= carryValue * 10;
			}
		}
	}

	/*std::cout << "\nValues : ";
	for(int i = 63; i >= 0; i--) {
		std::cout << values[i];
	}*/


	for (int i = 0; i <1023; i++) {
		sum += values[i];
	}



	return sum;
}

int main() {

	int base = 2, power = 1000, sum=0;

	std::cout << "\nSum: "<<multiplyandSum(base, power);

	return 0;
}