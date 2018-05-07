
project(exception)

set(HEDEAR_FILES Exception.h)
set(SOURCE_FILES Exception.cpp)

add_library(libexception STATIC ${SOURCE_FILES})
target_include_directories(libexception PUBLIC .)

add_executable(exception ${SOURCE_FILES} main.cpp)

target_link_libraries(exception libexception)

