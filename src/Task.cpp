#include "Enums.h"
#include "Task.h" 

#include <iostream>

Task::Task(std::string description, Priority priority, bool status)
{
    this->description = description;
    this->priority    = priority; 
    this->status      = status;
}

void Task::show_priority() const
{
    if (priority == Priority::low)
        std::cout << "низька "; 
    else
        if (priority == Priority::medium)
            std::cout << "середня ";
        else
            if (priority == Priority::high)
                std::cout << "висока ";
}

void daily_task::show() const
{
    std::cout << description << "  "; show_priority();
    std::cout << '\n';
}