cmake_minimum_required(VERSION 3.14)
set(CXX_STANDARD_REQUIRED 20)

project(SimpleShop)

set(APP_DIR ${CMAKE_SOURCE_DIR}/app/)

set(API_DIR ${APP_DIR}/BakerySystem/)
set(CLIENT_DIR ${APP_DIR}/client/)

# shop part
set(SHOP_DIR ${API_DIR}/shop/)
set(PRODUCTS_DIR ${SHOP_DIR}/products/)

set(PRODUCTS_TESTS_DIR ${PRODUCTS_DIR}/tests/)

# login part
set(LOGIN_DIR ${API_DIR}/login/)

set(LOGIN_TESTS_DIR ${LOGIN_DIR}/tests/)


# makes exec
add_executable(${PROJECT_NAME} ${CLIENT_DIR}/app.cpp)
target_link_libraries(${PROJECT_NAME})

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
  SHOP_TESTS 
  ${PRODUCTS_TESTS_DIR}/products_tests.cpp
  ${PRODUCTS_TESTS_DIR}/manager_tests.cpp
)

set(
  LOGIN_TESTS
  ${LOGIN_TESTS_DIR}/login_tests.cpp
  ${LOGIN_TESTS_DIR}/password_tests.cpp
)

set(
  TESTS
  ${SHOP_TESTS}
  ${LOGIN_TESTS}
)

add_executable(${TESTS_EXEC_NAME}-all ${TESTS})
add_executable(${TESTS_EXEC_NAME}-shop ${SHOP_TESTS})
add_executable(${TESTS_EXEC_NAME}-login ${LOGIN_TESTS})

target_link_libraries(
  ${TESTS_EXEC_NAME}-all
  GTest::gtest_main
)
target_link_libraries(
  ${TESTS_EXEC_NAME}-shop
  GTest::gtest_main
)
target_link_libraries(
  ${TESTS_EXEC_NAME}-login
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${TESTS_EXEC_NAME}-all)
gtest_discover_tests(${TESTS_EXEC_NAME}-shop)
gtest_discover_tests(${TESTS_EXEC_NAME}-login)