cmake_minimum_required(VERSION 3.10)

project(Math)

add_custom_command(
        OUTPUT ${PROJECT_BINARY_DIR}/parser.h ${PROJECT_BINARY_DIR}/parser.cpp
        COMMAND bison --defines=${PROJECT_BINARY_DIR}/parser.h -o ${PROJECT_BINARY_DIR}/parser.cpp ${PROJECT_SOURCE_DIR}/src/Math.y
        DEPENDS ${PROJECT_SOURCE_DIR}/src/Math.y
)

add_custom_command(
        OUTPUT ${PROJECT_BINARY_DIR}/lexer.cpp
        COMMAND flex -o ${PROJECT_BINARY_DIR}/lexer.cpp ${PROJECT_SOURCE_DIR}/src/Math.l
        DEPENDS ${PROJECT_SOURCE_DIR}/src/Math.l
)

add_executable(Math ${PROJECT_BINARY_DIR}/parser.h ${PROJECT_BINARY_DIR}/parser.cpp ${PROJECT_BINARY_DIR}/lexer.cpp src/Math.cpp src/AdditionExpression.cpp src/BinaryOperatorExpression.cpp src/DivisionExpression.cpp src/Expression.cpp src/MultiplicationExpression.cpp src/NumberExpression.cpp src/ParenthesisExpression.cpp src/PowerExpression.cpp src/SubtractionExpression.cpp src/VariableExpression.cpp include/ExpressionBuilder.h src/ExpressionBuilder.cpp src/Equation.cpp include/Equation.h)
set_property(TARGET Math PROPERTY CXX_STANDARD 11)

set_source_files_properties(${PROJECT_BINARY_DIR}/lexer.cpp PROPERTIES LANGUAGE CXX)
set_source_files_properties(${PROJECT_BINARY_DIR}/parser.cpp PROPERTIES LANGUAGE CXX)

target_include_directories(Math PUBLIC ${PROJECT_BINARY_DIR})
target_include_directories(Math PUBLIC include)
