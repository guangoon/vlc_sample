cmake_minimum_required(VERSION 3.0.0)
project(vlc_sample VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(PkgConfig REQUIRED)
pkg_check_modules(VLC_PKG  libvlc)

add_executable(vlc_sample main.cpp)
include_directories(${VLC_PKG_INCLUDE_DIRS})
target_link_libraries(vlc_sample  vlc)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
