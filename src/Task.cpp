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
        std::cout << "низька   "; 
    else
        if (priority == Priority::medium)
            std::cout << "середня   ";
        else
            if (priority == Priority::high)
                std::cout << "висока   ";
}

void weekly_task::show_day() const
{
    if (day == Days::monday)
        std::cout << "Понеділок"; 
     else
        if (day == Days::tuesday)
             std::cout << "Вівторок"; 
        else
            if (day == Days::wednesday)
                 std::cout << "Середа"; 
            else
                if (day == Days::thursday)
                     std::cout << "Четвер";
                else
                    if (day == Days::friday)
                        std::cout << "П'ятниця";
                    else
                        if (day == Days::saturday)
                            std::cout << "Субота";
                        else
                            if (day == Days::sunday)
                                 std::cout << "Неділя";  
}
void monthly_task::show_month() const
{
    if (month == Months::january)
        std::cout << "Січень"; 
     else
        if (month == Months::february)
            std::cout << "Лютий"; 
         else
            if (month == Months::march)
                 std::cout << "Березень"; 
            else
                if (month == Months::april)
                     std::cout << "Квітень"; 
                else
                    if (month == Months::may)
                         std::cout << "Травень"; 
                    else
                        if (month == Months::june)
                            std::cout << "Червень"; 
                        else
                            if (month == Months::july)
                                std::cout << "Липень"; 
                            else
                                if (month == Months::august)
                                    std::cout << "Серпень"; 
                                else
                                    if (month == Months::september)
                                        std::cout << "Вересень"; 
                                    else
                                        if (month == Months::october)
                                            std::cout << "Жовтень"; 
                                        else
                                            if (month == Months::november)
                                                std::cout << "Листопад"; 
                                            else
                                                if (month == Months::december)
                                                    std::cout << "Грудень"; 
}

void daily_task::show() const
{
    std::cout << description << "  "; show_priority();
    std::cout << '\n';
}
void weekly_task::show() const
{
    std::cout << description << "  "; show_priority(); show_day();
    std::cout << '\n';
}
void monthly_task::show() const
{
    std::cout << description << "  "; show_priority(); show_month();
    std::cout << '\n';
}