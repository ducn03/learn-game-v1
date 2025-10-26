#pragma once
#include <string>
#include <iostream>

class Logger {
public:
    static void info(const std::string& msg) {
        std::cout << "ℹ️ " << msg << std::endl;
    }

    static void success(const std::string& msg) {
        std::cout << "✅ " << msg << std::endl;
    }

    static void error(const std::string& msg) {
        std::cerr << "❌ " << msg << std::endl;
    }
};
