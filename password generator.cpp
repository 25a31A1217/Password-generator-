#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to evaluate password strength
string checkStrength(const string &password) {
    bool hasLower = false, hasUpper = false;
    bool hasDigit = false, hasSymbol = false;

    for (char c : password) {
        if (islower(c)) hasLower = true;
        else if (isupper(c)) hasUpper = true;
        else if (isdigit(c)) hasDigit = true;
        else hasSymbol = true;
    }

    int score = hasLower + hasUpper + hasDigit + hasSymbol;

    if (password.length() >= 12 && score == 4)
        return "Strong 💪";
    else if (password.length() >= 8 && score >= 3)
        return "Medium ⚠️";
    else
        return "Weak ❌";
}

// Function to generate password
string generatePassword(int length, bool useNumbers, bool useSymbols) {
    string lower = "abcdefghijklmnopqrstuvwxyz";
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numbers = "0123456789";
    string symbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    string allChars = lower + upper;

    if (useNumbers)
        allChars += numbers;
    if (useSymbols)
        allChars += symbols;

    string password = "";

    for (int i = 0; i < length; i++) {
        int index = rand() % allChars.length();
        password += allChars[index];
    }

    return password;
}

int main() {
    srand(time(0));

    int length;
    char choiceNumbers, choiceSymbols;

    cout << "Enter password length: ";
    cin >> length;

    cout << "Include numbers? (y/n): ";
    cin >> choiceNumbers;

    cout << "Include symbols? (y/n): ";
    cin >> choiceSymbols;

    bool useNumbers = (choiceNumbers == 'y' || choiceNumbers == 'Y');
    bool useSymbols = (choiceSymbols == 'y' || choiceSymbols == 'Y');

    string password = generatePassword(length, useNumbers, useSymbols);

    cout << "\nGenerated Password: " << password << endl;
    cout << "Strength: " << checkStrength(password) << endl;

    return 0;
}