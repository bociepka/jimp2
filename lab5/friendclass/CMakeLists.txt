
project(friendclass)

set(HEDEAR_FILES FriendClass.h)
set(SOURCE_FILES FriendClass.cpp)

add_library(libfriendclass STATIC ${SOURCE_FILES})
target_include_directories(libfriendclass PUBLIC .)

add_executable(friendclass ${SOURCE_FILES} main.cpp)

target_link_libraries(friendclass libfriendclass)

