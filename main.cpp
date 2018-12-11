#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

const string ERROR = "Non valide";
const int MIN = 1;
const int MAX = 4999;

string intToRoman(int unit, int multiple);

int romanChar2Int(char romanChar);

int roman2Int(string romanNumber);

char int2RomanChar(int value);

string number2Roman(int value);

string toUpperCase(string romanNumber);

int main() {

    string userInput;
    while (getline(cin, userInput) && !userInput.empty()) {

        stringstream ss(userInput);

        int value;
        if (ss >> value) {
            cout << number2Roman(value);

        } else {

            userInput = toUpperCase(userInput);
            int number =  roman2Int(userInput);
            if(userInput != number2Roman(number))
                cout << ERROR;
            else
                cout << number;
        }
        cout << endl;
    }

    return 0;
}

string number2Roman(int value) {

    if (value < MIN || value > MAX)
        return ERROR;

    int nbDigits = (int) (log10(value)) + 1;
    string romanNumber;

    for (int i = nbDigits - 1; i >= 0; --i) {
        int multiple = (int) pow(10, i);
        int unit = (value / multiple) * multiple;
        if (unit != 0 && i + 1 != 0)
            romanNumber += intToRoman(unit, multiple);
        value = value % multiple;
    }
    return romanNumber;
}

int roman2Int(string romanNumber) {

    int result = 0;
    for (size_t i = 0; i < romanNumber.length(); ++i) {
        int value = romanChar2Int(romanNumber[i]);
        if (i < romanNumber.length() - 1 && value < romanChar2Int(romanNumber[i + 1])) {
            value *= (-1);
        }
        result += value;
    }

    return result;
}

string intToRoman(int unit, int multiple) {

    size_t mod = (size_t) (unit / multiple);
    // thousand, 3000 => MMM, 4123 => MMMM
    if (unit > 1000)
        return string(mod, int2RomanChar(multiple));

        // case when it has to subtract
    else if (unit == 9 * multiple || unit == 4 * multiple)
        return string(1, int2RomanChar(multiple)) + string(1, int2RomanChar(unit + multiple));
        // case when it has to add
    else if (unit >= multiple && unit < 4 * multiple)
        return string(mod, int2RomanChar(multiple));
        // case when it has to add to a 5 * 10^n multiple (5 = V, 50 = L, 500 = D), 5 => V,6=> VI, 70 => LII , 800 => DCCC
    else if (unit >= 5 * multiple && unit < 9 * multiple)
        return int2RomanChar(5 * multiple) + string(mod - 5, int2RomanChar(multiple));

    return "0";
}

char int2RomanChar(int value) {

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

int romanChar2Int(char romanChar) {

    switch (romanChar) {
        case 'M' :
            return 1000;
        case 'D' :
            return 500;
        case 'C' :
            return 100;
        case 'L' :
            return 50;
        case 'X' :
            return 10;
        case 'V' :
            return 5;
        case 'I' :
            return 1;
        default:
            return (char) 0;
    }

}

string toUpperCase(string romanNumber) {

    transform(romanNumber.begin(), romanNumber.end(), romanNumber.begin(),
              [](unsigned char c) -> unsigned char { return (unsigned char) toupper(c); });
    return romanNumber;
}