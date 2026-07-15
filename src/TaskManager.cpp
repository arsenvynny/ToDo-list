#include "TaskManager.h"

#include <fstream>
#include <algorithm>
#include <memory>

int ToDoList::count = 0;

void ToDoList::push(std::unique_ptr<Task> task)
{
    tasks.push_back(std::move(task));
    count++;
}
std::string ToDoList::show_tasks() const
{
    std::string info;
    for (const auto& i : tasks)
         info += i->show();
    return info;
}
void ToDoList::sort()
{
    std::sort(tasks.begin(), tasks.end(), 
    [](const std::unique_ptr<Task>& a, const std::unique_ptr<Task>& b) 
    {return a->get_prt() < b->get_prt();});
}
size_t ToDoList::size()
{
    return tasks.size();
}
const Task& ToDoList::operator[](size_t index) const 
{
    return *tasks[index]; 
}
void ToDoList::saveToFile(const std::string& file) const
{
    nlohmann::json finaljson = nlohmann::json::array();

    for (const auto& i : tasks)
        finaljson.push_back(i->toJson());
    
    std::ofstream f(file);

    if(f.is_open())
        f << finaljson.dump(4);
    
    f.close();
}
void ToDoList::loadFromFile(const std::string& file) 
{
    std::ifstream f(file);

    nlohmann::json parsedJson;

    if(!((f.is_open()))) return;
    
    f >> parsedJson;
    f.close();

    tasks.clear();
    for (const auto& i : parsedJson)
    {
        auto type        = i["type"];
        auto description = i["description"];
        auto priority    = static_cast<Priority>(i["Priority"]);
        auto status      = i["status"];

        if (type == "daily")
            push(std::make_unique<daily_task>(description, priority, status));
        
        else if (type == "weekly")
        {
            auto day = i["Day"];
            push(std::make_unique<weekly_task>(description, priority, status, day));
        }
        else if (type == "monthly")
        {
            auto date = i["date"];
            auto month = i["Month"];
            push(std::make_unique<monthly_task>(description, priority, status, month, date));
        }
    }
}
bool operator==(ToDoList& a, ToDoList& b)
{
    auto l = b.tasks.begin();

    for (const auto& i : a.tasks)
    {
        if (!((*i).isEqual(*l)))
            return false;
        
        else
            l++;
    }
    return true;
}