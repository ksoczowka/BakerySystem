cmake_minimum_required(VERSION 3.14)
set(CXX_STANDARD_REQUIRED 20)

project(SimpleShop)

set(APP_DIR ${CMAKE_SOURCE_DIR}/app/)

set(API_DIR ${APP_DIR}/api)
set(CLIENT_DIR ${APP_DIR}/client)

set(PRODUCTS_DIR ${API_DIR}/products)

set(SHOP_TESTS_DIR ${API_DIR}/tests)
set(PRODUCTS_TESTS_DIR ${PRODUCTS_DIR}/tests)

add_library(SHOP_LIB ${API_DIR}/shop.cpp)
add_library(PRODUCTS_LIB ${PRODUCTS_DIR}/products.cpp)

add_executable(${PROJECT_NAME} ${CLIENT_DIR}/app.cpp)

target_link_libraries(${PROJECT_NAME} ${SHOP_LIB} ${PRODUCTS_LIB})

# Tests related content below
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(TESTS_EXEC_NAME ${PROJECT_NAME}-tests)
set(
    TESTS 
    ${SHOP_TESTS_DIR}/shop_tests.cpp
    ${PRODUCTS_TESTS_DIR}/products_tests.cpp
)
add_executable(${TESTS_EXEC_NAME} ${TESTS})

target_link_libraries(
    ${TESTS_EXEC_NAME}
    ${SHOP_LIB} 
    ${PRODUCTS_LIB}
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${TESTS_EXEC_NAME})