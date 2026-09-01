#pragma once
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
        break;

        case Priority::medium:
        info = "Середня   ";
        break;

        case Priority::low:
        info =  "Низька   ";
        break;
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
        break;

        case Days::tuesday:
        info = "Вівторок";
        break;

        case Days::wednesday:
        info = "Середа";
        break;

        case Days::thursday:
        info = "Четвер";
        break;

        case Days::friday:
        info = "П'ятниця";
        break;
        
        case Days::saturday:
        info = "Субота";
        break;

        case Days::sunday:
        info = "Неділя";
        break;
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
        break;

        case Months::february:
        info = "Лютий";
        break;

        case Months::march:
        info = "Березень";
        break;

        case Months::april:
        info = "Квітень";
        break;

        case Months::may:
        info = "Травень";
        break;

        case Months::june:
        info = "Червень";
        break;

        case Months::july:
        info = "Липень";
        break;

        case Months::august:
        info = "Серпень";
        break;

        case Months::september:
        info = "Вересень";
        break;

        case Months::october:
        info = "Жовтень";
        break;

        case Months::november:
        info = "Листопад";
        break;

        case Months::december:
        info = "Грудень";
        break;
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
    if (const daily_task* p = dynamic_cast<const daily_task*>(other.get()))
        return *this == *p;
    else
        return false;
}
bool weekly_task::isEqual(const std::unique_ptr<Task>& other) const
{
    if (const weekly_task* p = dynamic_cast<const weekly_task*>(other.get()))
    {
        return *this      == *p && 
                this->day == p->day;
    }
    else
        return false;
}
bool monthly_task::isEqual(const std::unique_ptr<Task>& other) const
{
    if (const monthly_task* p = dynamic_cast<const monthly_task*>(other.get()))
    {
        return *this        == *p && 
            this->date  == p->date && 
            this->month == p->month;
    }
    else
        return false;
}
