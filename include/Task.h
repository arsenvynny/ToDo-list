#include <string>
#include <Enums.h>

class Task
{
    protected:

    std::string description;
    Priority priority;
    bool status;

    public:

    Task(std::string description = "", Priority priority = Priority::low, bool status = false);
    
    virtual void show() const = 0;
    void show_priority() const;
};

class daily_task
    : public Task
{
    public:

    virtual void show() const override;
};

class weekly_task
    : public Task
{
    Days day;

    public:
    weekly_task(std::string description = "", Priority priority = Priority::low, bool status = false, Days = Days::monday)
        : Task("", Priority::low, false), day(Days::monday) {}
        
    void show_day() const;
    virtual void show() const override;
};

class monthly_task
    : public Task
{
    Months month;

    public:
    monthly_task(std::string description = "", Priority priority = Priority::low, bool status = false, Days = Days::monday)
        : Task("", Priority::low, false), month(Months::january) {}
        
    void show_month() const;
    virtual void show() const override;
};