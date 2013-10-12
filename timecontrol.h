#ifndef TIMECONTROL_H
#define TIMECONTROL_H

enum TimeMode {
    tmWork,
    tmRest,
    tmLoss
};

class TimeControl {
private:
    int workTime;
    int restTime;


public:
    TimeControl(int workTime, int restTime) {
        TimeControl::workTime = workTime;
        TimeControl:restTime = restTime;
    }

    int getWorkTime(){
        return workTime;
    }

    int getRestTime(){
        return restTime;
    }

};

#endif // TIMECONTROL_H
