CelestialOdyssey/                    # Tên dự án game
├── README.md                        # Thông tin dự án
├── LICENSE                          # Giấy phép
├── CMakeLists.txt                   # Build configuration
├── .gitignore                       # Git ignore file
│
├── assets/                          # Tài nguyên game
│   ├── textures/                    # Hình ảnh, sprites
│   ├── audio/                       # Âm thanh, nhạc
│   │   ├── music/
│   │   └── sfx/
│   ├── fonts/                       # Font chữ
│   ├── shaders/                     # Shader files
│   ├── models/                      # 3D models
│   └── data/                        # Game data (JSON, XML)
│       ├── levels/
│       └── configs/
│
├── src/                             # Source code chính
│   ├── main.cpp                     # Entry point
│   │
│   ├── core/                        # Core engine systems
│   │   ├── Engine.h/cpp             # Game engine chính
│   │   ├── Application.h/cpp        # Application wrapper
│   │   ├── Window.h/cpp             # Window management
│   │   └── Time.h/cpp               # Time/Delta time
│   │
│   ├── graphics/                    # Rendering system
│   │   ├── Renderer.h/cpp
│   │   ├── Texture.h/cpp
│   │   ├── Sprite.h/cpp
│   │   ├── Camera.h/cpp
│   │   └── Animation.h/cpp
│   │
│   ├── input/                       # Input handling
│   │   ├── InputManager.h/cpp
│   │   ├── Keyboard.h/cpp
│   │   └── Mouse.h/cpp
│   │
│   ├── audio/                       # Audio system
│   │   ├── AudioManager.h/cpp
│   │   ├── Sound.h/cpp
│   │   └── Music.h/cpp
│   │
│   ├── physics/                     # Physics & collision
│   │   ├── PhysicsWorld.h/cpp
│   │   ├── Collider.h/cpp
│   │   └── RigidBody.h/cpp
│   │
│   ├── entities/                    # Game objects/entities
│   │   ├── Entity.h/cpp             # Base entity class
│   │   ├── Player.h/cpp
│   │   ├── Enemy.h/cpp
│   │   └── Projectile.h/cpp
│   │
│   ├── components/                  # ECS Components (nếu dùng ECS)
│   │   ├── Component.h
│   │   ├── TransformComponent.h/cpp
│   │   ├── SpriteComponent.h/cpp
│   │   └── ColliderComponent.h/cpp
│   │
│   ├── systems/                     # Game systems
│   │   ├── EntityManager.h/cpp
│   │   ├── ResourceManager.h/cpp
│   │   └── SceneManager.h/cpp
│   │
│   ├── scenes/                      # Game scenes/states
│   │   ├── Scene.h/cpp              # Base scene
│   │   ├── MenuScene.h/cpp
│   │   ├── GameScene.h/cpp
│   │   └── PauseScene.h/cpp
│   │
│   ├── ui/                          # User Interface
│   │   ├── UIManager.h/cpp
│   │   ├── Button.h/cpp
│   │   ├── Text.h/cpp
│   │   └── HUD.h/cpp
│   │
│   └── utils/                       # Utilities
│       ├── Math.h/cpp               # Math helpers
│       ├── Logger.h/cpp             # Logging system
│       ├── Config.h/cpp             # Configuration
│       └── Random.h/cpp             # Random utilities
│
├── include/                         # Public headers (nếu tách)
│   └── CelestialOdyssey/
│
├── lib/                             # External libraries (static)
│   ├── SDL2/
│   ├── SFML/
│   └── json/
│
├── external/                        # External dependencies (submodules)
│   └── README.md
│
├── build/                           # Build output (gitignore)
│   ├── debug/
│   └── release/
│
├── bin/                             # Compiled executables
│   ├── debug/
│   └── release/
│
├── docs/                            # Documentation
│   ├── design/                      # Game design docs
│   ├── technical/                   # Technical docs
│   └── api/                         # API documentation
│
└── tests/                           # Unit tests
├── core_tests/
├── physics_tests/
└── entity_tests/