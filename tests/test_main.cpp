#include <gtest/gtest.h>
#include <fstream>

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
TEST(ToDoListTest, EquelTaskTest){

    daily_task   a("jd", Priority::high, false), 
                 b("jd", Priority::high, false);
    
    weekly_task  c("f", Priority::low, false, Days::friday), 
                 d("f", Priority::low, false, Days::friday);
   
    monthly_task e("vjf", Priority::medium, false, Months::april, 1), 
                 f("vjf", Priority::medium, false, Months::april, 1);


    EXPECT_TRUE(a == b);
    EXPECT_TRUE(c == d);
    EXPECT_TRUE(e == f);
}
TEST(ToDoListTest, EquelListTest){

    ToDoList work, anwork;

    work.push(std::make_unique<daily_task>("evnjl", Priority::low, false));
    work.push(std::make_unique<daily_task>("vjmif", Priority::medium, false));
    work.push(std::make_unique<daily_task>("yolhk", Priority::high, false));

    anwork.push(std::make_unique<daily_task>("evnjl", Priority::low, false));
    anwork.push(std::make_unique<daily_task>("vjmif", Priority::medium, false));
    anwork.push(std::make_unique<daily_task>("yolhk", Priority::high, false));

    EXPECT_TRUE(work == anwork);
}
TEST(ToDoListTest, JSONtest){

    ToDoList work, anwork;

    work.push(std::make_unique<daily_task>("evnjl", Priority::low, false));
    work.push(std::make_unique<daily_task>("vjmif", Priority::medium, false));
    work.push(std::make_unique<daily_task>("yolhk", Priority::high, false));


    work.saveToFile("test.json");
    anwork.loadFromFile("test.json");

    EXPECT_TRUE(work == anwork);
}