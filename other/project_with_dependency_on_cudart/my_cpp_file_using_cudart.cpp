#include <cuda_runtime.h>
#include <iostream>

int main() {
  double* device_data;
  cudaMalloc(&device_data, sizeof(double));
}
