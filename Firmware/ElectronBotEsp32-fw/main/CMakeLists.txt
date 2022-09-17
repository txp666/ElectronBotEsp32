idf_component_register(SRCS "robot.cpp" "main.cpp"
                    INCLUDE_DIRS ".")
target_compile_options(${COMPONENT_LIB} PRIVATE "-std=c++17")
set(CMAKE_CXX_STANDARD 17)

set(SOURCES Lib/CPPI2C/cppi2c.cpp)