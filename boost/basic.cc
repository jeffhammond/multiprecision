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

//typedef boost::multiprecision::number<cpp_dec_float<64> > mp_type;

// This is busted: https://svn.boost.org/trac/boost/ticket/11764
//typedef boost::multiprecision::cpp_bin_float_single mp_type;

//typedef boost::multiprecision::cpp_bin_float_double mp_type;
//typedef boost::multiprecision::cpp_bin_float_double_extended mp_type;
//typedef boost::multiprecision::cpp_bin_float_quad mp_type;
typedef cpp_bin_float_double_double mp_type;

int main(void)
{
    /* prints the numerical precision i.e. 64 */
    std::cout << std::numeric_limits<mp_type>::digits10 << std::endl;

    mp_type a = 2;
    //mp_type b = boost::math::constants::pi<mp_type, boost::math::policies::policy<boost::math::policies::digits2<64> > >();
    mp_type b = boost::math::constants::pi<mp_type>();
    mp_type c = exp(a);
    mp_type d = pow(c,c);
    mp_type e = 1./c;

    std::cout << std::setprecision(std::numeric_limits<mp_type>::max_digits10) << a << std::endl;
    std::cout << std::setprecision(std::numeric_limits<mp_type>::max_digits10) << b << std::endl;
    std::cout << std::setprecision(std::numeric_limits<mp_type>::max_digits10) << c << std::endl;
    std::cout << std::setprecision(std::numeric_limits<mp_type>::max_digits10) << d << std::endl;
    std::cout << std::setprecision(std::numeric_limits<mp_type>::max_digits10) << e << std::endl;

    return 0;
}
