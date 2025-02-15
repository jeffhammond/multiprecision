/* based upon http://www.boost.org/doc/libs/1_55_0/libs/multiprecision/doc/html/boost_multiprecision/tut/floats/cpp_dec_float.html
 * Use, modification and distribution are subject to the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 * Copyright ???? 20??. */

#include <iostream>
#include <utility>

#include <boost/math/constants/constants.hpp>
#include <boost/math/special_functions/gamma.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_bin_float.hpp>
#include <boost/multiprecision/float128.hpp>

typedef boost::multiprecision::number<
            boost::multiprecision::backends::cpp_bin_float<
                106,
                boost::multiprecision::backends::digit_base_2,
                void,
                boost::int16_t, -1022, 1023>,
            boost::multiprecision::et_off>
        cpp_bin_float_double_double;

using boost::multiprecision::cpp_dec_float;
using boost::multiprecision::cpp_bin_float_single;
using boost::multiprecision::cpp_bin_float_double;
using boost::multiprecision::cpp_bin_float_double_extended;
using boost::multiprecision::cpp_bin_float_quad;
using boost::multiprecision::float128;


template <typename T>
void foo(void)
{
    std::cout << "========================" << std::endl;

    /* prints the numerical precision i.e. 64 */
    std::cout << std::numeric_limits<T>::digits10 << std::endl;

    T a = 2;
    //T b = boost::math::constants::pi<T, boost::math::policies::policy<boost::math::policies::digits2<64> > >();
    T b = boost::math::constants::pi<T>();
    T c = exp(a);
    T d = pow(c,c);
    T e = a/c;

    std::cout << std::setprecision(std::numeric_limits<T>::max_digits10) << a << std::endl;
    std::cout << std::setprecision(std::numeric_limits<T>::max_digits10) << b << std::endl;
    std::cout << std::setprecision(std::numeric_limits<T>::max_digits10) << c << std::endl;
    std::cout << std::setprecision(std::numeric_limits<T>::max_digits10) << d << std::endl;
    std::cout << std::setprecision(std::numeric_limits<T>::max_digits10) << e << std::endl;
}

int main(void)
{
    //foo<boost::multiprecision::cpp_bin_float_single >(); // see bug.cc
    foo<boost::multiprecision::cpp_bin_float_double >();
    foo<boost::multiprecision::cpp_bin_float_double_extended >();
    foo<cpp_bin_float_double_double >();
    foo<boost::multiprecision::cpp_bin_float_quad >();
    foo<boost::multiprecision::float128 >();
    foo<boost::multiprecision::number<cpp_dec_float<64> > >();

    return 0;
}
