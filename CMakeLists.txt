cmake_minimum_required(VERSION 3.0.0)
project(MyTest VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

#包含头文件
include_directories(./inc)

#添加第三方库
find_package(PkgConfig)
pkg_search_module(GLIB REQUIRED glib-2.0)
include_directories(${GLIB_INCLUDE_DIRS})
link_directories(${GLIB_LIBRARY_DIRS})
MESSAGE(STATUS "glib-2.0 dirs:" ${GLIB_INCLUDE_DIRS})
MESSAGE(STATUS "glib-2.0 libbin:" ${GLIB_LIBRARIES})
MESSAGE(STATUS "glib-2.0 libdir:" ${GLIB_LIBRARY_DIRS})

#工程目录下的原文件,命名为ROOT_SOURCE
aux_source_directory(. ROOT_SOURCE)
MESSAGE(STATUS "src files:" ${ROOT_SOURCE})

#添加src下元文件
aux_source_directory(./src SRC_FILE)
MESSAGE(STATUS "src files:" ${SRC_FILE})

add_executable(MyTest ${ROOT_SOURCE} ${SRC_FILE})
target_link_libraries(MyTest ${GLIB_LIBRARIES})


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
