#include "../../include/project_a/public/project_a_public.h"
#include <iostream>
#include "../private/project_a_private.h"

void project_a_my_public_function() {
  // use some cxx11 but not in the public API
  auto my_message = "project_a_my_public_function()";
  std::cout << my_message << std::endl;
  std::cout << "calling from public function:\n " << std::flush;
  project_a_my_private_function();
}
