cmake_minimum_required(VERSION 3.30)
project(Game)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE SOURCE_FILES
        ${CMAKE_SOURCE_DIR}/Source/*.c
        ${CMAKE_SOURCE_DIR}/Source/*.cpp
)

file(GLOB_RECURSE HEADER_FILES
        ${CMAKE_SOURCE_DIR}/Include/*.h
        ${CMAKE_SOURCE_DIR}/Include/*.hpp
)

find_package(SDL2 REQUIRED)
find_package(PNG REQUIRED)
find_package(Freetype REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)
find_package(ZLIB REQUIRED)

include_directories(${PROJECT_NAME} ${SDL2_INCLUDE_DIRS} ${ZLIB_INCLUDE_DIRS} ${PNG_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} WIN32 ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    SDL2::SDL2main
    SDL2::SDL2
    SDL2_image::SDL2_image
    SDL2_ttf::SDL2_ttf
    PNG::PNG
    ZLIB::ZLIB
)

target_include_directories(${PROJECT_NAME}
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Include
        PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/include
)

if (WIN32 AND false)
    set(DLLS
        SDL2::SDL2
        SDL2_image::SDL2_image
        SDL2_ttf::SDL2_ttf
        PNG::PNG
        ZLIB::ZLIB
        Freetype::Freetype
    )

    add_custom_target(copy_dlls ALL
        COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:Game>"
    )

    foreach(DLL ${DLLS})
        add_custom_command(
            TARGET copy_dlls POST_BUILD
            COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:${DLL}>" "$<TARGET_FILE_DIR:Game>"
            VERBATIM
        )
    endforeach()

    add_dependencies(${PROJECT_NAME} copy_dlls)
endif()
