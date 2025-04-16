cmake_minimum_required(VERSION 3.27)
project(Typer)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY  https://github.com/fmtlib/fmt
        GIT_TAG         10.2.1

)

set(BUILD_SHARED_LIBS FALSE)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)

FetchContent_MakeAvailable(SFML)

FetchContent_MakeAvailable(fmt)

add_executable(Typer main.cpp
        WordsFromFile.cpp
        WordsFromFile.h
        PrintingWords.cpp
        PrintingWords.h
        Word.cpp
        Word.h
        Generate.cpp
        Generate.h
        Background.cpp
        Background.h
        StarsBig.cpp
        StarsBig.h
        Key.cpp
        Key.h
        Textures.cpp
        Textures.h
        Menu.cpp
        Menu.h
        MenuItems.cpp
        MenuItems.h
        Fonts.cpp
        Fonts.h
)

target_link_libraries(Typer sfml-graphics)
target_link_libraries(Typer fmt)
