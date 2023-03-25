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
            string lowercase = "abcdefghijklmnopqrstuvwxyz";
            string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            string numbers = "0123456789";
            string specialChars = "!@#$%^&*()_+-={}[]|:;<>?/~";
            string allChars = lowercase + uppercase + numbers + specialChars;
            srand(time(NULL));
            string password = "";
            for (int i = 0; i < length; i++) {
                password += allChars[rand() % allChars.length()];
            }
            return password;
        }
};

int main() {
    int length = 0;
    while (true) {
        cout << "Enter password length (at least 8 characters): ";
        cin >> length;
 
        if (length >= 8) {
            PasswordGenerator p(length);
            string password = p.generatePassword();
            cout << "Your password is: " << password << endl; 
            break;
        }
        else {
            cout << "Password must be at least 8 characters.\n";
        }
    }
    return 0;
}
