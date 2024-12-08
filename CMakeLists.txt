cmake_minimum_required(VERSION 3.10)
project(QuadraticSolver)

add_executable(sinus 
	src/main.cpp
)

set_target_properties(
  sinus PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
)

set(POINTTYPE "long" CACHE STRING "Тип точности: short (float) или long (double)")
if(NOT POINTTYPE STREQUAL "short" AND NOT POINTTYPE STREQUAL "long")
    message(FATAL_ERROR "Неверный тип POINTTYPE. Используйте 'short' или 'long'.")
endif()

if(POINTTYPE STREQUAL "long")
    target_compile_definitions(sinus_taylor PRIVATE USE_DOUBLE_PRECISION)
endif()

set(LIB_TYPE "STATIC" CACHE STRING "Тип библиотеки: STATIC или SHARED")
if(NOT LIB_TYPE STREQUAL "STATIC" AND NOT LIB_TYPE STREQUAL "SHARED")
    message(FATAL_ERROR "Неверный тип библиотеки LIB_TYPE. Используйте 'STATIC' или 'SHARED'.")
endif()

add_library(sinus_taylor ${LIB_TYPE} src/sinus_taylor.cpp)
target_include_directories(sinus_taylor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Связь библиотек с основным исполняемым файлом
target_link_libraries(sinus PRIVATE sinus_taylor)