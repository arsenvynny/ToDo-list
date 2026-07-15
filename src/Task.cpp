#include "Task.h" 

#include <iostream>
#include <memory>

Task::Task(std::string description, Priority priority, bool status)
{
    this->description = description;
    this->priority    = priority; 
    this->status      = status;
}

std::string Task::show_priority() const
{
    std::string info;
    switch (priority)
    {
        case Priority::high:
        info = "Висока   ";

        case Priority::medium:
        info = "Середня   ";

        case Priority::low:
        info =  "Низька   ";
    }
    return info;
}

std::string weekly_task::show_day() const
{
    std::string info;

    switch (day)
    {
        case Days::monday:
        info = "Понеділок";

        case Days::tuesday:
        info = "Вівторок";

        case Days::wednesday:
        info = "Середа";

        case Days::thursday:
        info = "Четвер";

        case Days::friday:
        info = "П'ятниця";

        case Days::saturday:
        info = "Субота";

        case Days::sunday:
        info = "Неділя";
    }
    return info;
}
std::string monthly_task::show_month() const
{
    std::string info;

    switch (month)
    {
        case Months::january:
        info = "Січень";

        case Months::february:
        info = "Лютий";

        case Months::march:
        info = "Березень";

        case Months::april:
        info = "Квітень";

        case Months::may:
        info = "Травень";

        case Months::june:
        info = "Червень";

        case Months::july:
        info = "Липень";

        case Months::august:
        info = "Серпень";

        case Months::september:
        info = "Вересень";

        case Months::october:
        info = "Жовтень";

        case Months::november:
        info = "Листопад";

        case Months::december:
        info = "Грудень";
    }
    return info;
}

std::string daily_task::show() const
{
    std::string info;

    info =  description + '\n' + '\n' + show_priority();
    return info;
}
std::string weekly_task::show() const
{
    std::string info;

    info =  description + '\n' + '\n' + show_priority() + '\n' + show_day();
    return info;
}
std::string monthly_task::show() const
{
    std::string info;

    info =  description + '\n' + '\n' + show_priority() + '\n' + show_month();
    return info;
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
bool operator==(const Task& a, const Task& b)
{
    if(a.description == b.description && 
        a.priority   == b.priority && 
        a.status     == b.status)
        return true;
    return false;
}
bool Task::isEqual(const std::unique_ptr<Task>& other) const
{
    return *this == *other;
}
bool daily_task::isEqual(const std::unique_ptr<Task>& other) const
{
    const daily_task* p = dynamic_cast<const daily_task*>(other.get());

    return *this == *p;
}
bool weekly_task::isEqual(const std::unique_ptr<Task>& other) const
{
    const weekly_task* p = dynamic_cast<const weekly_task*>(other.get());

    return *this      == *p && 
            this->day == p->day;
}
bool monthly_task::isEqual(const std::unique_ptr<Task>& other) const
{
    const monthly_task* p = dynamic_cast<const monthly_task*>(other.get());

    return *this        == *p && 
            this->date  == p->date && 
            this->month == p->month;
}
