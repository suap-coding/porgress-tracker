#include "Task.h"

Task::Task(std::string name, clock_t start) :
    _name(name),
    _activationTime(start),
    _finished(false),
    _active(true),
    _timeSpent(0)
{}

Task::Task(std::string name) :
    _name(name),
    _activationTime(0),
    _finished(false),
    _active(false),
    _timeSpent(0)
{}

bool Task::isActive() const
{
    return _active;
}

bool Task::activate()
{
    if (_active || _finished)
        return false;
    else
    {
        _active = true;
        _activationTime = clock();
        return true;
    }
}

bool Task::deactivate()
{
    if (!_active)
        return false;
    else
    {
        _active = false;
        _timeSpent += clock() - _activationTime;
        return true;
    }
}

bool Task::close()
{
    if (_finished)
        return false;
    else
    {
        _finished = true;
        if(_active) deactivate();
        return true;
    }
}

bool Task::reopen() {
    if (!_finished)
        return false;
    else
    {
        _finished = false;
        return true;
    }
}

clock_t Task::timeSpent()
{
    // TODO: some SEXY way of printing this
    if (_active)
        return (_timeSpent + clock() - _activationTime) / 1000;
    else
        return _timeSpent / 1000;
}

std::string Task::name() const
{
    return _name;
}

bool Task::isFinished() const
{
    return _finished;
}