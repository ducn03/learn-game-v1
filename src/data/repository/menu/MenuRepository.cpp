#include "MenuRepository.h"
#include <fstream>
#include <sstream>
#include <filesystem>
#include "../lib/nlohmann/json.hpp"
#include "constant/constants.h"
#include "core/logger/Logger.h"

using json = nlohmann::json;

namespace MenuFields {
    constexpr auto TITLE = "title";
    constexpr auto ITEMS = "items";
    constexpr auto LABEL = "label";
    constexpr auto ACTION = "action";
}

std::string storageUrl = Constants::StoragePath::MENU_STORAGE_PATH;

MenuData MenuRepository::loadMenu() {
    MenuData menuData;

    // Đọc file toàn bộ vào string, để tránh vấn đề BOM/UTF-8
    std::ifstream file(storageUrl, std::ios::binary);
    if (!file.is_open()) {
        Logger::error(
            "❌ Failed to open menu.json\n"
            "Path: " + storageUrl + "\n"
            "File exists: " + (std::filesystem::exists(storageUrl) ? "Yes" : "No") + "\n"
            "Check working directory: " + std::filesystem::current_path().string()
        );
        return menuData;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();

    // Nếu có BOM UTF-8, loại bỏ
    if (content.size() >= 3 &&
        static_cast<unsigned char>(content[0]) == 0xEF &&
        static_cast<unsigned char>(content[1]) == 0xBB &&
        static_cast<unsigned char>(content[2]) == 0xBF)
    {
        content = content.substr(3);
    }

    try {
        json j = json::parse(content);

        menuData.title = j.value(MenuFields::TITLE, "");

        if (j.contains(MenuFields::ITEMS) && j[MenuFields::ITEMS].is_array()) {
            for (const auto& entry : j[MenuFields::ITEMS]) {
                menuData.items.push_back({
                    entry.value(MenuFields::LABEL, ""),
                    entry.value(MenuFields::ACTION, "")
                });
            }
        }

        Logger::info("Loaded menu: " + menuData.title);
        for (const auto& item : menuData.items) {
            Logger::info("Item: " + item.label + " -> " + item.action);
        }

    } catch (json::parse_error& e) {
        Logger::error("JSON parse error: " + std::string(e.what()));
    }

    return menuData;
}
