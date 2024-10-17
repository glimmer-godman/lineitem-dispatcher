# 指定源文件目录
set(SOURCE_DIR .)
file(GLOB_RECURSE SOURCES ${SOURCE_DIR}/*.cpp)


add_executable(lineitem_dispatcher ${SOURCES})
set(THIRD_PARTY_DIR ${PROJECT_SOURCE_DIR}/third-party)
INCLUDE_DIRECTORIES(${THIRD_PARTY_DIR}/spdlog/include)
INCLUDE_DIRECTORIES(${THIRD_PARTY_DIR}/gflags/include)
INCLUDE_DIRECTORIES(include)

target_link_libraries(lineitem_dispatcher PRIVATE gflags)