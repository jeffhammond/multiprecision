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

#include "SuperFloat.h"

// #include <iostream>
// using namespace std;

int main(int argc, char **argv)
{
    SuperFloat::SuperFloat a(1.0);
    SuperFloat::SuperFloat b(7L);
    SuperFloat::SuperFloat c(a);
    mpfr_t a2,b2,c2;

    a.copy_internal(a2);
    fprintf(stdout,"a = ");
    mpfr_out_str(stdout, 10, 0, a2, SUPERFLOAT_RMODE);
    fprintf(stdout,"\n");

    b.copy_internal(b2);
    fprintf(stdout,"b = ");
    mpfr_out_str(stdout, 10, 0, b2, SUPERFLOAT_RMODE);
    fprintf(stdout,"\n");

    c.copy_internal(c2);
    fprintf(stdout,"c = ");
    mpfr_out_str(stdout, 10, 0, c2, SUPERFLOAT_RMODE);
    fprintf(stdout,"\n");

    c+=b;

    c.copy_internal(c2);
    fprintf(stdout,"c = ");
    mpfr_out_str(stdout, 10, 0, c2, SUPERFLOAT_RMODE);
    fprintf(stdout,"\n");

    return(0);

}
