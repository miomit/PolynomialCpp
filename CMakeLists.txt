cmake_minimum_required (VERSION 3.8)

project ("PolynomialCpp")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (PolynomialCpp "Main.cpp"  "Fraction.h" "Fraction.cpp" "Algorithm.h" "Algorithm.cpp" "Polynomial.cpp" "Polynomial.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET PolynomialCpp PROPERTY CXX_STANDARD 20)
endif()
