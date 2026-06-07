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