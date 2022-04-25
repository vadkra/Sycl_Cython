#include <CL/sycl.hpp>

int add() {
	cl::sycl::float4 a = { 1.0, 2.0, 3.0, 4.0 };
	cl::sycl::float4 b = { 4.0, 3.0, 2.0, 1.0 };
	cl::sycl::float4 c = { 0.0, 0.0, 0.0, 0.0 };
	
	cl::sycl::default_selector device_selector;
	cl::sycl::queue q{device_selector};

	return 0;
}