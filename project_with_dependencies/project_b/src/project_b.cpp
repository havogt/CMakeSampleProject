#include "../include/project_b/project_b.h"
#include <project_a/public/project_a_public.h>
#include <iostream>

void project_b_function() {
  std::cout << "project_b_function()" << std::endl;
  std::cout << "calling project a public function:\n ";
  project_a_my_public_function();
}
