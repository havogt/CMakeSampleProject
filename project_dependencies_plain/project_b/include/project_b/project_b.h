#pragma once

#include <project_a_header_only/project_a_header_only.h>
#include <iostream>

void project_b_function();

template <typename T>
void project_b_header_only_function(T t) {
  std::cout << "project_b_header_only_function() -> forwarding t" << std::endl;
  project_a_header_only_function(t);
}
