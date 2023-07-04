cmake_minimum_required(VERSION 3.24)

set(PROJECT_NAME SFML_Game)				 # имя проекта
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


add_definitions(-DSFML_STATIC)		 # дефайны

include_directories("ext/SFML/include/")	# добавляем директории
include_directories("inc/")
include_directories("src/")
link_directories("ext/SFML/lib/")

add_executable(SFML_Game main.cpp Game.cpp Game.h Object.cpp Object.h)

target_link_libraries("${PROJECT_NAME}" sfml-graphics-s-d
        sfml-window-s-d
        sfml-system-s-d
        opengl32
        freetype
        winmm
        gdi32
        sfml-audio-s-d
        openal32
        flac
        vorbisenc
        vorbisfile
        vorbis
        ogg)