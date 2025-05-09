cmake_minimum_required(VERSION 3.14)
project(MyApp LANGUAGES CXX)

# Explicitly find MyLibUtils before MyLibA
find_package(MyLibUtils REQUIRED)
find_package(MyLibA REQUIRED)

add_executable(MyApp
    src/main.cpp
)

target_link_libraries(MyApp PRIVATE MyLibA::MyLibA)

install(TARGETS MyApp
    RUNTIME DESTINATION bin
)
