#include "TaskManager.h"

#include <fstream>
#include <algorithm>
#include <memory>

void ToDoList::push(std::unique_ptr<Task> task)
{
    tasks.push_back(std::move(task));
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
nlohmann::json ToDoList::tojson() const
{
    nlohmann::json finaljson = nlohmann::json::array();

    for (const auto& i : tasks)
        finaljson.push_back(i->toJson());
    
   return finaljson;
}
bool operator==(ToDoList& a, ToDoList& b)
{
    if(a.size() != b.size())
     return false;
     
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