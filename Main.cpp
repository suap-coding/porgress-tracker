#include <iostream>
#include <time.h>
#include <vector>

#include "Task.h"

int main()
{
    using namespace std;

    //clock_t begin, end;
    //Task t(clock());

    vector<Task> tasks;

    // main loop
    bool proceed = true;
    while (proceed)
    {
        int taskNr = 1;
        int currentlyActive = 0;
        for (auto& task : tasks) {
            cout << taskNr << " - ";
            if (task.isActive())
            {
                cout << "ACTIVE - ";
                currentlyActive = taskNr;
            }
            if (task.isFinished()) cout << "FINISHED - ";
            cout << task.name() << " - " << task.timeSpent() << "s" << endl;
            taskNr++;
        }
        if (currentlyActive <= 0) cout << "No active tasks.\n";

        cout << "Pick:\n"
            << " # - to activate diferent task,\n"
            << " a - to add a new task,\n"
            << " f - to finish current task,\n"
            << " q - to close program.\n";
        char controlChar;
        cin >> controlChar;

        string name;
        switch (controlChar)
        {
        case 'a':            
            cout << "Task name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Want to start it now? [y/n]: ";
            char start;
            cin >> start;
            if (start == 'y')
            {
                tasks.push_back(Task(name, clock()));
                if (currentlyActive > 0) tasks[currentlyActive - 1].deactivate();
            }
            // TODO: fix the currently active issue
            else tasks.push_back(Task(name));
            break;
        case 'f':
            tasks[currentlyActive - 1].close();
            break;
        case 'q':
            proceed = false;
            break;
        // TODO: check if number was picked!
        default:
            if(currentlyActive > 0) tasks[currentlyActive - 1].deactivate();
            tasks[controlChar - 1 - '0'].activate();
        }
        cout << endl;
    }
}