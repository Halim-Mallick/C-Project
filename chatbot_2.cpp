#include <iostream>
#include <string>
#include <sstream> //strings to other data types and vice versa.
#include <algorithm> //use uppercase and lowercase and transform
#include <chrono> // for sleep or delay of given milliseconds
#include <thread> //pause the execution of the program for a specific period of time
using namespace std;

class Chatbot {
public:
    //// convert input to lowercase for easier matching
    string getResponse(string input) {
        transform(input.begin(), input.end(), input.begin(), ::tolower);
        
        //English reply
        if (input == "hello" || input == "hi" || input=="hlw") {
            return "Hi, how can I help you?";
        } 
        else if (input == "how are you" || input == "how are you doing" || input == "how about you") {
            return "I'm doing well, you?";
           
        } 
        else  if(input == "fine" || input == "well" || input == "very well"){
                return "okay, how can i help you?";
        }
        
        else  if(input == "tell me your name" || input == "what is your name" || input == "your name"){
                return "My name is 'Rocky'.I'm not human, I'm a chat bot.\n My creator gave me this name";
        }
        else if(input == "age" || input == "how old are you" || input == "your age"){
                return "My date of birth 25-03-2023.\nAs such I am only 5 days old today!";
        }
        
        else if(input == "you are intelligence" || input == "so intelligence at this age" || input == "intelligence"){
                return "I am not that intelligent, \nI may not know what you ask but But I am being intelligence";
        }
            
        else if (input == "goodbye" || input == "bye") {
            return "Goodbye!";
        } 
        else if (input == "calculate") {
            return calculate();
        } 
        
        else if (input == "what are you doing" || input == "what you do" || input == "how do you do") {
            return "i'm talk to with you";
            
        }
        
        //Banglish reply
        else if (input == "ki koro" || input == "ki kro" || input == "ki korteco") {
            return "tmar sathe kotha boli?";
        }
        else if (input == "prem korba" || input == "prem korte paro" || input == "prem korbo") {
            return "ami robot, tai amar apnader moto kono kritim buddhimotta ba saririk onuvuti nei,\n tai ami prem korte parina.";
        } 
        else {
            return "I'm sorry! I didn't understand that.\nI think you have a spelling mistake or I don't understand what you ask me.";
        }
    }

private:
    string calculate() {
        string input;
        double num1, num2;
        char op;

        cout << "Enter num1 operator num2 (e.g. 2 + 3): ";
        getline(cin, input);

        stringstream ss(input); 
        ss >> num1 >> op >> num2; 

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

        stringstream result_ss;
        result_ss << result;
        return result_ss.str();
    }
};

void printSlowly(string message) {
    for (char c : message) { //range-based for loop.
        cout << c <<flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
}

int main() {
    Chatbot bot;
    string input;
    cout << "\t\t   *Rockey Bhai Chatbot*"<<endl;
    cout << "\t\t   Created by Team Ak-47"<<endl;
    cout << "\t\t   -----------------------"<<endl;
    while (true) {
        cout<<endl <<  "You: ";
        getline(cin, input);
        if (input == "exit") 
            printSlowly("Okay, Have a nice day!");
            break;
        string response = bot.getResponse(input);
        printSlowly("Bot: " + response + "\n");
    }
    return 0;
}
