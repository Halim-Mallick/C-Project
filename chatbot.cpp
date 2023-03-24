//Chatbot by Halim Mallick

#include <iostream>
#include <string>
#include <sstream> //for converting strings to numbers
#include <algorithm>

using namespace std;

class Chatbot {
public:
    string getResponse(string input) {
        transform(input.begin(), input.end(), input.begin(), ::tolower);
    // English reply 
        if (input == "hello" || input == "hi" || input=="hlw") {
            return "Hi, how can I help you?";
        } 
        else if (input == "how are you" || input == "how are you doing" || input == "how about you") {
            return "I'm doing well, thanks for asking!";
        } 
        else if (input == "goodbye" || input == "bye") {
            return "Goodbye!";
        } 
        else if (input == "calculate") { // if the user wants to calculate
            return calculate(); // call the calculate function
        } 
    //Banglish reply
        else if (input == "ki koro" || input == "ki kro" || input == "ki korteco") {
            return "tmar sathe kotha boli?";
        }
        
        else if (input == "prem korba" || input == "prem korte paro" || input == "prem korbo") {
            return "ami rotbot, tai amar apnader moto kono kritim buddhimotta ba saririk onuvuti nei, tai ami prem korte parina ";
        } 
        
        
        else {
            return "I'm sorry, I didn't understand that.";
        }
    }

private:
    string calculate() {
        string input;
        double num1, num2;
        char op;

        cout << "Enter num1 operator num2 (e.g. 2 + 3): ";
        getline(cin, input);

        // Use stringstream to extract the numbers and operator from the input string
        stringstream ss(input);
        ss >> num1 >> op >> num2;

        // Perform the calculation based on the operator
        double result;
        switch (op) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                result = num1 / num2;
                break;
            default:
                return "Invalid operator";
        }

        // Convert the result to a string and return it
        stringstream result_ss;
        result_ss << result;
        return result_ss.str();
    }
};

int main() {
    Chatbot bot;
    string input;
    cout << "   *Rockey Bhai Chatbot*"<<endl;
    cout << "   Created by Team Ak-47"<<endl;
    cout << "   -----------------------"<<endl;
    while (true) {
        cout<<endl <<  "You: ";
        getline(cin, input);
        if (input == "exit") {
            cout <<"Okay, Have a nice day!";
            break;
        }
        string response = bot.getResponse(input);
        cout << "Bot: " << response << endl;
    }
    return 0;
}
