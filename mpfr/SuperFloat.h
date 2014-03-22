/***************************************************************************
 *   Copyright (C) 2008 by Jeff Hammond                                    *
 *   jeff.science@gmail.com                                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef SUPERFLOAT_HPP
#define SUPERFLOAT_HPP

#include <cstdio>
#include <mpfr.h>

namespace SuperFloat
{
    /*! \def SUPERFLOAT_BITS
    *   \brief A macro that sets the default precision of SuperFloatEnv.
    *
    *  The precision to use when the default constructor is used.
    *
    */
    #define SUPERFLOAT_BITS 128

    /*! \def SUPERFLOAT_RMODE
    *   \brief A macro that sets the default rounding mode of SuperFloatEnv.
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
    class SuperFloatEnv
    {
        public:
            SuperFloatEnv(){ mpfr_set_default_prec(SUPERFLOAT_BITS); }
            SuperFloatEnv(int Bits){ mpfr_set_default_prec(Bits); }
            ~SuperFloatEnv(){ mpfr_free_cache (); }

    };

    /*! \brief Class defining arbitrary-precision value.
    *
    *  Detailed description starts here.
    *
    */
    class SuperFloat
    {
        private:
            mpfr_t internal;

        public:
            SuperFloat(){ mpfr_init2(internal,SUPERFLOAT_BITS); };
            SuperFloat(const SuperFloat& right){ mpfr_init_set(internal, right.internal, SUPERFLOAT_RMODE); }
            SuperFloat(unsigned long int right){ mpfr_init_set_ui(internal, right, SUPERFLOAT_RMODE); }
            SuperFloat(signed long int right){ mpfr_init_set_si(internal, right, SUPERFLOAT_RMODE); }
            SuperFloat(unsigned int right){ mpfr_init_set_ui(internal, right, SUPERFLOAT_RMODE); }
            SuperFloat(signed int right){ mpfr_init_set_si(internal, right, SUPERFLOAT_RMODE); }
            SuperFloat(double right){ mpfr_init_set_d(internal, right, SUPERFLOAT_RMODE); }
            SuperFloat(long double right){ mpfr_init_set_ld(internal, right, SUPERFLOAT_RMODE); }

            // This is a temporary utility function which should disappear from the production version
            void copy_internal(mpfr_t target){ mpfr_init_set(target, internal, SUPERFLOAT_RMODE); }

            /*! \brief Assignment operators.
            *
            *  Detailed description starts here.
            *
            */





            SuperFloat& operator+=(const SuperFloat& right){ mpfr_add(internal,internal,right.internal,SUPERFLOAT_RMODE); return *this;}
            SuperFloat& operator+=(unsigned long int right){ mpfr_add_ui(internal,internal,right,SUPERFLOAT_RMODE); return *this;}
            SuperFloat& operator+=(signed long int right){ mpfr_add_si(internal,internal,right,SUPERFLOAT_RMODE); return *this;}
            SuperFloat& operator+=(unsigned int right){ mpfr_add_ui(internal,internal,right,SUPERFLOAT_RMODE); return *this;}
            SuperFloat& operator+=(signed int right){ mpfr_add_si(internal,internal,right,SUPERFLOAT_RMODE); return *this;}
    };


}

#endif

