#include <iostream>

using namespace std;

class TimeTrack{
    int hr;
    int min;
    public:
    void inputTime(){
        cout << "enter the number of hours: ";
        cin >> hr;
        cout << "enter the number of minutes: ";
        cin >> min;
    }
    void showWorkTime(){
        cout << "Hrs: " << hr << '\n';
        cout << "Mins: " << min << '\n';
    }
    friend void totalTime(const TimeTrack&, const TimeTrack&);
};

void totalTime(const TimeTrack& t1, const TimeTrack& t2){
    int totalMins = t1.min + t2.min;
    int totalHrs = t1.hr + t2.hr;
    if(totalMins >= 60){
        totalHrs += totalMins/60;
        totalMins = totalMins - ((totalMins/60) * 60);
    }
    cout << "Hrs: " << totalHrs << '\n';
    cout << "Mins: " << totalMins << '\n';
}

int main(){
    TimeTrack t1;    
    t1.inputTime();
    TimeTrack t2;    
    t2.inputTime();
    totalTime(t1, t2);
}
