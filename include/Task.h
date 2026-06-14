#pragma once

#include <string>
#include <Enums.h>
#include <nlohmann/json.hpp>

class Task
{
    protected:

    std::string description;
    Priority priority;
    bool status;

    public:

    Task(std::string description = "", Priority priority = Priority::low, bool status = false);
    virtual ~Task() {}
    
    Priority get_prt() const {return priority;}
   
    void show_priority() const;
    
    virtual void show() const = 0;
    virtual nlohmann::json toJson() const;
    virtual bool isEqual(const std::unique_ptr<Task>& other) const;

    friend bool operator==(const Task& a, const Task& b);
};

class daily_task
    : public Task
{
    public:

    daily_task(std::string description = "", Priority priority = Priority::low, bool status = false)
        : Task(description, priority, status) {}
    
    virtual void show() const override;
    virtual nlohmann::json toJson() const override;
    virtual bool isEqual(const std::unique_ptr<Task>& other) const override;
};

class weekly_task
    : public Task
{
    Days day;

    public:
    weekly_task(std::string description = "", Priority priority = Priority::low, bool status = false, Days day= Days::monday)
        : Task(description, priority, status), day(day) {}
    virtual ~weekly_task() {}
        
    void show_day() const;

    virtual void show() const override;
    virtual nlohmann::json toJson() const override;
    virtual bool isEqual(const std::unique_ptr<Task>& other) const override;
};

class monthly_task
    : public Task
{
    int date;
    Months month;

    public:
    monthly_task(std::string description = "", Priority priority = Priority::low, bool status = false, Months month = Months::january, int date = 1)
        : Task(description, priority, status), month(month), date(date) {}
    virtual ~monthly_task() {}
        
    void show_month() const;

    virtual void show() const override;
    virtual nlohmann::json toJson() const override;
    virtual bool isEqual(const std::unique_ptr<Task>& other) const override;
};