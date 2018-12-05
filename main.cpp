#include <iostream>
#include <cmath>

using namespace std;

string valeurRomaine(int unit, int multiple);

int main() {
	int chiffre;
	cin >> chiffre;

	int nbDigits = (int)(log10(chiffre)) + 1;
	string romanNumber;

	for (int i = nbDigits - 1; i >= 0; --i) {
		int multiple = (int)pow(10, i);
		int unit = (chiffre / multiple) * multiple;
		romanNumber += valeurRomaine(unit, multiple);
		chiffre = chiffre % multiple;
	}
	cout << romanNumber << endl;
	return 0;
}

string valeurRomaine(int unit, int multiple) {

	size_t mod = (size_t)(unit / multiple);
	if (unit > 1000)
		return string(mod, 'M');

	else if (unit > 500) {
		if (unit < 900)
			return 'D' + string(mod, 'C');
		else
			return "CM";
	}

	else if (unit > 100) {
		if (unit < 400)
			return string(mod, 'C');
		else
			return "CD";
	}

	else if (unit > 50) {
		if (unit < 90)
			return 'L' + string(mod, 'X');
		else
			return "XC";
	}

	else if (unit > 10) {
		if (unit < 40)
			return string(mod, 'X');
		else
			return "XL";
	}

	else if (unit > 5) {
		if (unit < 9)
			return 'V' + string(mod, 'I');
		else
			return "IX";
	}

	else if (unit > 1) {
		if (unit < 4)
			return string(mod, 'I');
		else
			return "IV";
	}
}