#pragma once

#include <unordered_map>

#include "D:\Projects\ToDo list\include\TaskManager.h"

class Store
{
    std::unordered_map<std::int64_t, ToDoList> store;

    public:

    void Savetofile(const std::string& file, int64_t ID);
    void Loadfromfile(const std::string& file, int64_t ID);

    ToDoList operator[](std::int64_t ID) {return store[ID];}
};