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
    cout<< "Do you want to create your password Automatically?";
    while(true){
    int length;
    cout <<endl<< "Enter password length: ";
    cin >> length;
    PasswordGenerator p(length);
    string password = p.generatePassword();
    cout << "Your password is: " << password << endl;
   }
    return 0;
}
