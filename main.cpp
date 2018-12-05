#include <iostream>
#include <cmath>

using namespace std;

string valeurRomaine(int unit, int multiple);
char romain(int value);

int main() {
	int chiffre;

	while(cin >> chiffre) {

		int nbDigits = (int) (log10(chiffre)) + 1;
		string romanNumber;

		for (int i = nbDigits - 1; i >= 0; --i) {
			int multiple = (int) pow(10, i);
			int unit = (chiffre / multiple) * multiple;
			if (unit != 0 && i + 1 != 0)
				romanNumber += valeurRomaine(unit, multiple);
			chiffre = chiffre % multiple;
		}
		cout << romanNumber << endl;
	}
	return 0;
}

string valeurRomaine(int unit, int multiple) {

	if (unit < 1 || unit > 4999)
		return "Entree invalide";

	size_t mod = (size_t)(unit / multiple);
	if (unit > 1000)
		return string(mod, romain(multiple));

	else if (unit == 9 * multiple || unit == 4 * multiple)
		return string(1, romain(multiple)) + string(1,romain(unit + multiple));

	else if (unit >= multiple && unit < 4 * multiple)
		return string(mod, romain(multiple));

	else if (unit >= 5 * multiple && unit < 9 * multiple)
		return romain(5 * multiple) + string(mod - 5, romain(multiple));

	/*else if (unit > 5 * multiple) {
		if (unit < 9 * multiple)
			return romain(5 * multiple) + string(mod, romain(multiple));
		else
			return string(1, romain(multiple)) + string(1,romain(unit + multiple));
	}

	else if (unit > 1 * multiple) {
		if (unit < 4 * multiple)
			return string(mod, romain(multiple));
		else
			return string(1, romain(multiple)) + string(1,romain(unit + multiple));
	}*/

	return "0";
}

char romain(int value) {

	switch (value) {
		case 1000 :
			return 'M';
		case 500 :
			return 'D';
		case 100 :
			return 'C';
		case 50 :
			return 'L';
		case 10 :
			return 'X';
		case 5 :
			return 'V';
		case 1 :
			return 'I';
		default:
			return (char) 0;
	}
}