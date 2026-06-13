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
    switch (priority)
    {
        case Priority::high:
        std::cout << "Висока   ";

        case Priority::medium:
        std::cout << "Середня   ";

        case Priority::low:
        std::cout << "Низька   ";
    }
}

void weekly_task::show_day() const
{
    switch (day)
    {
        case Days::monday:
        std::cout << "Понеділок";

        case Days::tuesday:
        std::cout << "Вівторок";

        case Days::wednesday:
        std::cout << "Середа";

        case Days::thursday:
        std::cout << "Четвер";

        case Days::friday:
        std::cout << "П'ятниця";

        case Days::saturday:
        std::cout << "Субота";

        case Days::sunday:
        std::cout << "Неділя";
    }
}
void monthly_task::show_month() const
{
    switch (month)
    {
        case Months::january:
        std::cout << "Січень";

        case Months::february:
        std::cout << "Лютий";

        case Months::march:
        std::cout << "Березень";

        case Months::april:
        std::cout << "Квітень";

        case Months::may:
        std::cout << "Травень";

        case Months::june:
        std::cout << "Червень";

        case Months::july:
        std::cout << "Липень";

        case Months::august:
        std::cout << "Серпень";

        case Months::september:
        std::cout << "Вересень";

        case Months::october:
        std::cout << "Жовтень";

        case Months::november:
        std::cout << "Листопад";

        case Months::december:
        std::cout << "Грудень";
    }
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
nlohmann::json Task::toJson() const
{
    nlohmann::json j;

    j["description"] = description;
    j["Priority"]    = static_cast<int>(priority);
    j["status"]      = status;

    return j;
}
nlohmann::json daily_task::toJson() const
{
    nlohmann::json j;

    j = Task::toJson();
    j["type"] = "daily";

    return j;
}
nlohmann::json weekly_task::toJson() const
{
    nlohmann::json j;

    j = Task::toJson();

    j["Day"]  = static_cast<int>(day);
    j["type"] = "weekly";

    return j;
}
nlohmann::json monthly_task::toJson() const
{
    nlohmann::json j;

    j = Task::toJson();

    j["date"]  = date;
    j["Month"] = static_cast<int>(month);
    j["type"]  = "monthly";

    return j;
}