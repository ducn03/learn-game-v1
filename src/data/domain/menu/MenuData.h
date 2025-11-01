#pragma once
#include <string>
#include <vector>

#include "MenuItem.h"

struct MenuData {
    std::string title;
    std::pmr::vector<MenuItem> items;
};
