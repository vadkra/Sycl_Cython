#include <CL/sycl.hpp>

using namespace cl::sycl;


int main()
{
    float a[] = {1.0, 2.0, 3.0, 4.0};
    float b[] = {1.0, -1.0, 1.0, -1.0};
    float out[4];
    unsigned int n = 4;
    
    queue q;
    {
        buffer<float> aBuf(a, n);
        buffer<float> bBuf(b, n);
        buffer<float> outBuf(out, n);
        q.submit([&](handler& h)
                 {
                     auto aAcc = aBuf.get_access<access::mode::read>(h);
                     auto bAcc = bBuf.get_access<access::mode::read>(h);
                     auto outAcc = outBuf.get_access<access::mode::write>(h);
                     h.parallel_for<class sycl_kernel>(range<1>(n), [=](id<1> id)
                     {
                         outAcc[id] = aAcc[id] + bAcc[id];
                     });
                 });
    }

    return 0;
}