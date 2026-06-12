#include <gtest/gtest.h>

#include "TaskManager.h"



TEST(ToDoListTest, pushTest) {
    
    ToDoList work;

    for (int i = 0; i < 3; i++)
        work.push(std::make_unique<daily_task>("", Priority::high, false));
    
    EXPECT_EQ(work.size(), 3);
}
TEST(ToDoListTest, sortTest){

    ToDoList work;

    work.push(std::make_unique<daily_task>("", Priority::low, false));
    work.push(std::make_unique<daily_task>("", Priority::low, false));
    work.push(std::make_unique<daily_task>("", Priority::high, false));
    work.push(std::make_unique<daily_task>("", Priority::medium, false));
    work.push(std::make_unique<daily_task>("", Priority::high, false));

    work.sort();

    EXPECT_EQ(work[0].get_prt(), Priority::high);
    EXPECT_EQ(work[2].get_prt(), Priority::medium);
    EXPECT_EQ(work[4].get_prt(), Priority::low);
}