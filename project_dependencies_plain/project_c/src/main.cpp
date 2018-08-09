// WILL NOT WORK ON PURPOSE: we included project_a as private
//#include <project_a/public/project_a_public.h>

#include <project_b/project_b.h>
#include <iostream>

int main() {
  std::cout << "from project c call project_b_function():\n ";
  project_b_function();

  project_b_header_only_function(15);

  // WILL NOT WORK ON PURPOSE: see above
  //  project_a_my_public_function();
}
