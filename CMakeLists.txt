cmake_minimum_required(VERSION 3.15)

set(PATCH_VERSION "0.0.1" CACHE INTERNAL "Patch version")
project(laba6 VERSION ${PATCH_VERSION})

configure_file(version.h.in version.h)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#bruh
add_executable(${PROJECT_NAME}
    main.cpp
    primitives/Circle.cpp
    primitives/Sqare.cpp
    primitives/Document.cpp
    core/Core.cpp
    output/Output.cpp
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/primitives
    ${CMAKE_CURRENT_SOURCE_DIR}/core
    ${CMAKE_CURRENT_SOURCE_DIR}/output
)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_CONTACT "example@example.com")

include(CPack)