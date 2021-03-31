#include <atomic>
// x86-64 clang 10.0.0 -stdlib=libc++ -O2 -Wall -Wextra -std=c++11
// ARM64 GCC 8.2 -O2 -Wall -Wextra -std=c++11
extern double dvalue;
extern int ivalue;

bool set_values(double dv, int iv) {
    ::dvalue = dv;
    ::std::atomic_signal_fence(::std::memory_order_seq_cst);
    ::ivalue = iv;
    return true;
}