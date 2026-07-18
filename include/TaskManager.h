#pragma once
#include "Task.h"

#include <vector>
#include <memory>

class ToDoList
{
    std::vector<std::unique_ptr<Task>> tasks;

    public:
     ToDoList()  = default;  
     ~ToDoList() = default; 

    void push(std::unique_ptr<Task> task);
    std::string show_tasks() const;
    void sort();

    size_t size();
    
    const Task& operator[](size_t index) const;
    
    void saveToFile(const std::string& file) const;
    void loadFromFile(const std::string& file);

    const std::vector<std::unique_ptr<Task>>& getTasks() const {return tasks;}
    friend bool operator==(ToDoList& a, ToDoList& b);
};