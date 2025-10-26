#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class TextUtils {
public:
    // Chuyển std::string UTF-8 sang sf::String
    static sf::String utf8(const std::string& str) {
        return sf::String::fromUtf8(str.begin(), str.end());
    }
};
