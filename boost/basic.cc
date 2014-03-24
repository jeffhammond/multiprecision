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
    /* prints the numerical precision i.e. 64 */
    std::cout << std::numeric_limits<mp_type>::digits10 << std::endl;

    mp_type a = 2;
    mp_type b = boost::math::constants::pi<mp_type, boost::math::policies::policy<boost::math::policies::digits2<64> > >();
    mp_type c = pow(b,a);
    mp_type d = exp(a);
    mp_type e = 1/b;
    mp_type f = 1./b;

    std::cout << std::setprecision(std::numeric_limits<mp_type>::max_digits10) << a << std::endl;
    std::cout << std::setprecision(std::numeric_limits<mp_type>::max_digits10) << b << std::endl;
    std::cout << std::setprecision(std::numeric_limits<mp_type>::max_digits10) << c << std::endl;
    std::cout << std::setprecision(std::numeric_limits<mp_type>::max_digits10) << d << std::endl;
    std::cout << std::setprecision(std::numeric_limits<mp_type>::max_digits10) << e << std::endl;
    std::cout << std::setprecision(std::numeric_limits<mp_type>::max_digits10) << f << std::endl;

    return 0;
}
