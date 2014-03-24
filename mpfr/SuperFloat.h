/***************************************************************************
 *   Copyright (C) 2008 by Jeff Hammond                                    *
 *   jeff.science@gmail.com                                                *
 ***************************************************************************/

#ifndef SUPERFLOAT_HPP
#define SUPERFLOAT_HPP

#include <iostream>
#include <cstdio>
#include <mpfr.h>

namespace SuperFloat
{
    /*! \def SUPERFLOAT_BITS
     *   \brief A macro that sets the default precision of Environment.
     *
     *  The precision to use when the default constructor is used.
     *
     */
    #define SUPERFLOAT_BITS 128

    /*! \def SUPERFLOAT_RMODE
     *   \brief A macro that sets the default rounding mode of Environment.
     *
     *  The rounding mode to use when the default constructor is used.
     *
     */
    #define SUPERFLOAT_RMODE GMP_RNDN

    /*! \brief Class defining arbitrary-precision environment.
     *
     *  While technically optionally, initializing the environment
     *  ensures that default precision will be what the user has set,
     *  either as SUPERFLOAT_DEFAULT_BITS or another value.
     *
     *  The destructor frees the MPFR cache to prevent memory leaks.
     *
     */
    class Environment
    {
        public:
            Environment(){ mpfr_set_default_prec(SUPERFLOAT_BITS); }
            Environment(int Bits){ mpfr_set_default_prec(Bits); }
            ~Environment(){ mpfr_free_cache(); }

    };

    /*! \brief Class defining arbitrary-precision value.
     *
     *  Detailed description starts here.
     *
     */
    class Number
    {
        private:
            mpfr_t internal;

        public:
            Number(){
                mpfr_init2(internal,SUPERFLOAT_BITS);
            }
            Number(const Number& right){
                mpfr_init_set(internal, right.internal, SUPERFLOAT_RMODE);
            }
            Number(unsigned long int right){
                mpfr_init_set_ui(internal, right, SUPERFLOAT_RMODE);
            }
            Number(signed int right){
                mpfr_init_set_si(internal, right, SUPERFLOAT_RMODE);
            }
            Number(double right){
                mpfr_init_set_d(internal, right, SUPERFLOAT_RMODE);
            }

            /*! \brief Assignment operators.
             *
             *  Detailed description starts here.
             *
             */


            /*! \brief IO stream operators.
             *
             *  Detailed description starts here.
             *
             */

            friend std::ostream& operator<<(std::ostream& os, const Number& n)
            {
                if ( &os == &std::cout ) {
                    mpfr_out_str(stdout, 10 /* base */, 0 /* print exactly */, n.internal, SUPERFLOAT_RMODE);
                } else if ( &os == &std::cerr ) {
                    mpfr_out_str(stderr, 10 /* base */, 0 /* print exactly */, n.internal, SUPERFLOAT_RMODE);
                } else {
                    os << "MPFR output to anything besides cout/cerr is unsupported!" << std::endl;
                }
                return os;
            }


            /*! \brief Mathematical operators.
             *
             *  Accumulate: +=
             *
             */

            Number& operator+=(const Number& right){
                mpfr_add(internal,internal,right.internal,SUPERFLOAT_RMODE);
                return *this;
            }
            Number& operator+=(unsigned int right){
                mpfr_add_ui(internal,internal,right,SUPERFLOAT_RMODE);
                return *this;
            }
            Number& operator+=(signed int right){
                mpfr_add_si(internal,internal,right,SUPERFLOAT_RMODE);
                return *this;
            }
            Number& operator+=(double right){
                mpfr_add_d(internal,internal,right,SUPERFLOAT_RMODE);
                return *this;
            }

            /*! \brief Mathematical operators.
             *
             *  Negative Accumulate: -=
             *
             */

            Number& operator-=(const Number& right){
                mpfr_sub(internal,internal,right.internal,SUPERFLOAT_RMODE);
                return *this;
            }
            Number& operator-=(unsigned int right){
                mpfr_sub_ui(internal,internal,right,SUPERFLOAT_RMODE);
                return *this;
            }
            Number& operator-=(signed int right){
                mpfr_sub_si(internal,internal,right,SUPERFLOAT_RMODE);
                return *this;
            }
            Number& operator-=(double right){
                mpfr_sub_d(internal,internal,right,SUPERFLOAT_RMODE);
                return *this;
            }

            /*! \brief Mathematical operators.
             *
             *  Scale: *=
             *
             */

            Number& operator*=(const Number& right){
                mpfr_mul(internal,internal,right.internal,SUPERFLOAT_RMODE);
                return *this;
            }
            Number& operator*=(unsigned int right){
                mpfr_mul_ui(internal,internal,right,SUPERFLOAT_RMODE);
                return *this;
            }
            Number& operator*=(signed int right){
                mpfr_mul_si(internal,internal,right,SUPERFLOAT_RMODE);
                return *this;
            }
            Number& operator*=(double right){
                mpfr_mul_d(internal,internal,right,SUPERFLOAT_RMODE);
                return *this;
            }

            /*! \brief Mathematical operators.
             *
             *  Divide: /=
             *
             */

            Number& operator/=(const Number& right){
                mpfr_div(internal,internal,right.internal,SUPERFLOAT_RMODE);
                return *this;
            }
            Number& operator/=(unsigned int right){
                mpfr_div_ui(internal,internal,right,SUPERFLOAT_RMODE);
                return *this;
            }
            Number& operator/=(signed int right){
                mpfr_div_si(internal,internal,right,SUPERFLOAT_RMODE);
                return *this;
            }
            Number& operator/=(double right){
                mpfr_div_d(internal,internal,right,SUPERFLOAT_RMODE);
                return *this;
            }
    };
}

#endif

