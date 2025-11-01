// constants.h
#pragma once
#include <string>

namespace Constants {
    namespace Action {
        namespace MENU {
            const std::string START_CONTINUE = "START_CONTINUE";
            const std::string START_NEW_GAME = "START_NEW_GAME";
            const std::string GET_HISTORY = "GET_HISTORY";
            const std::string GET_CONFIG = "GET_CONFIG";
            const std::string EXIT_GAME = "EXIT_GAME";
        }
    }

    namespace StoragePath {
        const std::string MENU_STORAGE_PATH = "../../src/data/storage/menu.json";
    }

    namespace GameConfig {
        constexpr int MAX_LIVES = 3;

        namespace UI {
            constexpr float BUTTON_WIDTH = 250.f;
            constexpr float BUTTON_HEIGHT = 50.f;
            const std::string GAME_TITLE = "Learn Game v1";
        }

        namespace Audio {
            constexpr float MASTER_VOLUME = 0.8f;
            constexpr float MUSIC_VOLUME = 0.5f;
        }
    }
}
