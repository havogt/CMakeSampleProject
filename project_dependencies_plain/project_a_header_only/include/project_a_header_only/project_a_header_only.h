#pragma once

#include <iostream>

template <typename T>
void project_a_header_only_function(T t) {
  std::cout << "project_a_header_only_function(" << t << ")" << std::endl;
}
