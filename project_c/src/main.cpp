//#include <project_a/public/project_a_public.h>
// project a not exported as public (from project_b)

#include <project_b/project_b.h>
#include <iostream>

int main() {
  std::cout << "from project c call project_b_function():\n ";
  project_b_function();

  // WILL NOT WORK ON PURPOSE: In project_b I added project_a as private.
  //  std::cout << "trying to call project_a directly" << std::endl;
  //  project_a_my_public_function();
}
