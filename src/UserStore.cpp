#include "UserStore.h"
#include "Task.h"
#include "TaskManager.h"

#include <fstream>

void Store::Savetofile(const std::string& file, int64_t ID)
{
    nlohmann::json j = nlohmann::json::array();
    std::ofstream f(file);

    if (!(f.is_open())) return;

    j = store[ID].tojson() << ID;
    f << j.dump(4);
}

void Store::Loadfromfile(const std::string& file, int64_t ID)
{
    std::ifstream f(file);

    nlohmann::json parsedJson;

    if(!((f.is_open()))) return;
    
    f >> parsedJson;
    f.close();

    
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