cmake_minimum_required(VERSION 3.15)

# Версия проекта
set(PATCH_VERSION "0.0.1" CACHE INTERNAL "Patch version")
project(laba6 VERSION ${PATCH_VERSION})

# Генерация version.h (опционально)
configure_file(version.h.in version.h)

# Настройки C++
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Исходники - все компоненты
set(SRC_FILES
    main.cpp
    primitives/Circle.cpp
    primitives/Sqare.cpp
    primitives/Document.cpp
    core/Core.cpp
    output/Output.cpp
)

# Исполняемый файл
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}
)

# Установка
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_CONTACT "example@example.com")

include(CPack)