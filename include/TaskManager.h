
#include "Task.h"

#include <vector>
#include <memory>

class ToDoList
{
    std::vector<std::unique_ptr<Task>> tasks;

    public:
     ToDoList() = default;
    ~ToDoList() = default;

    void push(std::unique_ptr<Task> task);
    void show_tasks() const;
    void sort();

    size_t size();
    const Task& operator[](size_t index) const;
};