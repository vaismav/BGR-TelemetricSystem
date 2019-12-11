cmake_minimum_required(VERSION 3.13)
project(cserver C)

find_package (libmongoc-1.0 1.7 REQUIRED)

message ("--   mongoc found version \"${MONGOC_VERSION}\"")
message ("--   mongoc include path \"${MONGOC_INCLUDE_DIRS}\"")
message ("--   mongoc libraries \"${MONGOC_LIBRARIES}\"")


set(CMAKE_C_STANDARD 99)

set(GCC_COVERAGE_COMPILE_FLAGS "-pthread")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
add_executable(cserver src/main.c includes/output.h src/output.c includes/handleMessage.h src/handleMessage.c src/tools.c includes/tools.h src/dbTools.c includes/dbTools.h src/semiBlockingQueue.c includes/semiBlockingQueue.h)
target_include_directories (cserver PRIVATE "${MONGOC_INCLUDE_DIRS}")
target_link_libraries (cserver PRIVATE "${MONGOC_LIBRARIES}")
target_compile_definitions (cserver PRIVATE "${MONGOC_DEFINITIONS}")