#pragma once
#include <vector>
#include "data/domain/menu/MenuData.h"

class MenuRepository {
public:
    static MenuData loadMenu();
};
