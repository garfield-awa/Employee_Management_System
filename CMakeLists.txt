cmake_minimum_required(VERSION 3.10.0)
project(staff VERSION 0.1.0 LANGUAGES C CXX)

file(REMOVE_RECURSE "${PROJECT_BINARY_DIR}/build")

include_directories(${PROJECT_SOURCE_DIR}/headers) # 指定头文件目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

aux_source_directory(${PROJECT_SOURCE_DIR}/sources SRC_LIST)
add_executable(management_system ${SRC_LIST})




include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

