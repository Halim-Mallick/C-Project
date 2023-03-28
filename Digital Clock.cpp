#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
using namespace std;

class DigitalClock {
  private:
    int sec_prev;
    int seconds, minutes, hours;
    
  public:
    DigitalClock() : sec_prev(0), seconds(0), minutes(0), hours(0) {}
    
    void displayTime() {
      string str;

      time_t now = time(0);
      tm *ltm = localtime(&now);

      seconds = ltm->tm_sec;
      minutes = ltm->tm_min;
      hours = ltm->tm_hour+6;
      if(hours>12){
          hours=hours-12;
      }

      str = (hours >= 12) ? "PM" : "AM";
      hours = (hours > 12) ? (hours - 12) : hours;
      hours = (hours == 0) ? 12 : hours;
    
      
      if (seconds == sec_prev + 1 || (sec_prev == 59 && seconds == 0)) {
        system("clear");
        cout<<"\n============================\n"<<endl;
        printf("\t %02d:%02d:%02d %s\n", hours, minutes, seconds, str.c_str());
        cout<<"\n============================\n"<<endl;  
      }
      sec_prev = seconds;
    }
     
    void run() {
      while (true) {
        displayTime();
        this_thread::sleep_for(chrono::seconds(1));
      }
    }
};

int main() {
  DigitalClock clock;
  clock.run();

  return 0;
}
