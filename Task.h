#pragma once

#include <time.h>
#include <string>

class Task
{
private:
    std::string _name;

    clock_t _timeSpent;
    bool _active;
    bool _finished;

    clock_t _activationTime;

public:

    Task(std::string name, clock_t start);
    Task(std::string name);

    bool activate();
    bool deactivate();
    bool close();
    bool reopen();

    clock_t timeSpent();

    std::string name() const;
    bool isActive() const;
    bool isFinished() const;
};