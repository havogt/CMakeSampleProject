# CMakeSampleProject

Illustates how to describe dependencies between projects with "modern" CMake.

## Setup

### project_a
- has a private and a public function which is compiled into a library
- exports a target (library + public header)

### project_a_header_only
- exports a target pointing to a header with a templated function

### project_b
- depends on `project_a` and `project_a_header_only`
- defines a public function which calls the function from `project_a`
- defines a templated function in a header which calls the templated function from `project_a_header_only`
- exports a target (library + header)
- via the target forwards the header-only project (via `target_link_libraries(PUBLIC ...)`) as the depender (`project_c`) needs to have the header available to compile the `project_b` templated function.
- keeps the dependency on `project_a` private

### project_c
- calls the functions from project_b
