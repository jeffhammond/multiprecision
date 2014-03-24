/* based upon http://www.boost.org/doc/libs/1_55_0/libs/multiprecision/doc/html/boost_multiprecision/tut/floats/cpp_dec_float.html
 * Use, modification and distribution are subject to the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 * Copyright ???? 20??. */

#include <iostream>
#include <utility>

#include <boost/math/constants/constants.hpp>
#include <boost/math/special_functions/gamma.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

using boost::multiprecision::cpp_dec_float;
typedef boost::multiprecision::number<cpp_dec_float<64> > mp_type;

int main(void)
{
    // Operations at fixed precision and full numeric_limits support:
    mp_type b = 2;
    std::cout << std::numeric_limits<mp_type>::digits << std::endl;
    // Note that digits10 is the same as digits, since we're base 10! :
    std::cout << std::numeric_limits<mp_type>::digits10 << std::endl;
    // We can use any C++ std lib function, lets print all the digits as well:
    std::cout << std::setprecision(std::numeric_limits<mp_type>::max_digits10) << log(b) << std::endl; // print log(2)
    // We can also use any function from Boost.Math:
    std::cout << boost::math::tgamma(b) << std::endl;
    // These even work when the argument is an expression template:
    std::cout << boost::math::tgamma(b * b) << std::endl;
    // And since we have an extended exponent range we can generate some really large numbers here (4.0238726007709377354370243e+2564):
    std::cout << boost::math::tgamma(mp_type(1000)) << std::endl;

    return 0;
}
