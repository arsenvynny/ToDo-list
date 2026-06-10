#include "TaskManager.h"
#include <algorithm>

void ToDoList::push(std::unique_ptr<Task> task)
{
    tasks.push_back(std::move(task));
}
void ToDoList::show_tasks() const
{
    for (const auto& i : tasks)
         i->show();
}
void ToDoList::sort()
{
    std::sort(tasks.begin(), tasks.end(), 
    [](const std::unique_ptr<Task>& a, const std::unique_ptr<Task>& b) 
    {return a->get_prt() > b->get_prt();});
}