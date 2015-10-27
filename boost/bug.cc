#include <iostream>
#include <utility>

#include <boost/math/constants/constants.hpp>
#include <boost/multiprecision/cpp_bin_float.hpp>

using boost::multiprecision::cpp_bin_float_single;
using boost::multiprecision::cpp_bin_float_double;

typedef boost::multiprecision::cpp_bin_float_single f32;
typedef boost::multiprecision::cpp_bin_float_double f64;

int main(void)
{
#if BUGTEST_PRECISION == 32
    //f32 pi32 = boost::math::constants::pi<f32, boost::math::policies::policy<boost::math::policies::digits2<32> > >();
    f32 pi32 = boost::math::constants::pi<f32>();
    std::cout << pi32 << std::endl;
#elif BUGTEST_PRECISION == 64
    //f64 pi64 = boost::math::constants::pi<f64, boost::math::policies::policy<boost::math::policies::digits2<64> > >();
    f64 pi64 = boost::math::constants::pi<f64>();
    std::cout << pi64 << std::endl;
#else
#error Set BUGTEST_PRECISION to 32 or 64.
#endif
    return 0;
}
