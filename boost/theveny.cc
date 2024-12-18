// from http://perso.ens-lyon.fr/philippe.theveny/cise.pdf

#include <iostream>
#include <utility>
#include <cmath> // _Decimal64?

//#include <boost/tr1/cmath.hpp>
#include <boost/math/special_functions.hpp>
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

typedef boost::multiprecision::number<
            boost::multiprecision::backends::cpp_bin_float<
                1000,
                boost::multiprecision::backends::digit_base_2,
                void,
                boost::int16_t, -1022, 1023>,
            boost::multiprecision::et_off>
        cpp_bin_float_1000b;

using boost::multiprecision::cpp_dec_float;
using boost::multiprecision::cpp_bin_float_single;
using boost::multiprecision::cpp_bin_float_double;
using boost::multiprecision::cpp_bin_float_double_extended;
using boost::multiprecision::cpp_bin_float_quad;

typedef boost::multiprecision::number<cpp_dec_float<64> > mp_type;

// This is busted: https://svn.boost.org/trac/boost/ticket/11764
//typedef boost::multiprecision::cpp_bin_float_single mp_type;

//typedef boost::multiprecision::cpp_bin_float_double mp_type;
//typedef boost::multiprecision::cpp_bin_float_double_extended mp_type;
//typedef boost::multiprecision::cpp_bin_float_quad mp_type;
//typedef cpp_bin_float_double_double mp_type;
//typedef cpp_bin_float_1000b mp_type;

//typedef _Decimal64 mp_type;

int main (void)
{
    mp_type a = sin((mp_type)1e22);
    mp_type b = log((mp_type)17.1);
    mp_type c = exp((mp_type)0.42);
    mp_type d = 173746*a + 94228*b - 78487*c;
    std::cout << std::setprecision(std::numeric_limits<mp_type>::max_digits10) << d << std::endl;
    return 0;
}
