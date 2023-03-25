#include <iostream>
#include <cstdlib> // Used to seed the random number generator used to generate the password
#include <ctime>
#include <string>

using namespace std;

class PasswordGenerator {
    private:
        int length;
    public:
        PasswordGenerator(int len) {
            length = len;
        }
        string generatePassword() {
            string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-={}[]|:;<>?/~";
            srand(time(NULL));
            string password = "";
            for (int i = 0; i < length; i++) {
                password += chars[rand() % chars.length()];
            }
            return password;
        }
};

int main() {
    while (true) {
        int length;
        cout << "Enter password length: ";
        cin >> length;
        if (length < 8) {
            cout << "Password length must be at least 8 characters." << endl;
            continue;
        }
        PasswordGenerator p(length);
        string password = p.generatePassword();
        cout << "Your password is: " << password << endl;
        break;
    }
    return 0;
}
