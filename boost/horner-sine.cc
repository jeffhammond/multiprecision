#include <iostream>
#include <utility>

#include <boost/math/constants/constants.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

using boost::multiprecision::cpp_dec_float;
typedef boost::multiprecision::number<cpp_dec_float<64> > mp_type;

mp_type mysin(const mp_type& x)
{
  // Approximation of sin(x * pi/2) for -1 <= x <= 1, using an order 63 polynomial.
  static const std::array<mp_type, 32U> coefs =
  {{
    mp_type("+1.5707963267948966192313216916397514420985846996875529104874722961539082031431044993140174126711"), //"),
    mp_type("-0.64596409750624625365575656389794573337969351178927307696134454382929989411386887578263960484"), // ^3
    mp_type("+0.07969262624616704512050554949047802252091164235106119545663865720995702920146198554317279"), // ^5
    mp_type("-0.0046817541353186881006854639339534378594950280185010575749538605102665157913157426229824"), // ^7
    mp_type("+0.00016044118478735982187266087016347332970280754062061156858775174056686380286868007443"), // ^9
    mp_type("-3.598843235212085340458540018208389404888495232432127661083907575106196374913134E-6"), // ^11
    mp_type("+5.692172921967926811775255303592184372902829756054598109818158853197797542565E-8"), // ^13
    mp_type("-6.688035109811467232478226335783138689956270985704278659373558497256423498E-10"), // ^15
    mp_type("+6.066935731106195667101445665327140070166203261129845646380005577490472E-12"), // ^17
    mp_type("-4.377065467313742277184271313776319094862897030084226361576452003432E-14"), // ^19
    mp_type("+2.571422892860473866153865950420487369167895373255729246889168337E-16"), // ^21
    mp_type("-1.253899540535457665340073300390626396596970180355253776711660E-18"), // ^23
    mp_type("+5.15645517658028233395375998562329055050964428219501277474E-21"), // ^25
    mp_type("-1.812399312848887477410034071087545686586497030654642705E-23"), // ^27
    mp_type("+5.50728578652238583570585513920522536675023562254864E-26"), // ^29
    mp_type("-1.461148710664467988723468673933026649943084902958E-28"), // ^31
    mp_type("+3.41405297003316172502972039913417222912445427E-31"), // ^33
    mp_type("-7.07885550810745570069916712806856538290251E-34"), // ^35
    mp_type("+1.31128947968267628970845439024155655665E-36"), // ^37
    mp_type("-2.18318293181145698535113946654065918E-39"), // ^39
    mp_type("+3.28462680978498856345937578502923E-42"), // ^41
    mp_type("-4.48753699028101089490067137298E-45"), // ^43
    mp_type("+5.59219884208696457859353716E-48"), // ^45
    mp_type("-6.38214503973500471720565E-51"), // ^47
    mp_type("+6.69528558381794452556E-54"), // ^49
    mp_type("-6.47841373182350206E-57"), // ^51
    mp_type("+5.800016389666445E-60"), // ^53
    mp_type("-4.818507347289E-63"), // ^55
    mp_type("+3.724683686E-66"), // ^57
    mp_type("-2.6856479E-69"), // ^59
    mp_type("+1.81046E-72"), // ^61
    mp_type("-1.133E-75"), // ^63
  }};

  const mp_type v = x * 2 / boost::math::constants::pi<mp_type>();
  const mp_type x2 = (v * v);
  //
  // Polynomial evaluation follows, if mp_type allocates memory then
  // just one such allocation occurs - to initialize the variable "sum" -
  // and no temporaries are created at all.
  //
  const mp_type sum = (((((((((((((((((((((((((((((((     + coefs[31U]
                                                     * x2 + coefs[30U])
                                                     * x2 + coefs[29U])
                                                     * x2 + coefs[28U])
                                                     * x2 + coefs[27U])
                                                     * x2 + coefs[26U])
                                                     * x2 + coefs[25U])
                                                     * x2 + coefs[24U])
                                                     * x2 + coefs[23U])
                                                     * x2 + coefs[22U])
                                                     * x2 + coefs[21U])
                                                     * x2 + coefs[20U])
                                                     * x2 + coefs[19U])
                                                     * x2 + coefs[18U])
                                                     * x2 + coefs[17U])
                                                     * x2 + coefs[16U])
                                                     * x2 + coefs[15U])
                                                     * x2 + coefs[14U])
                                                     * x2 + coefs[13U])
                                                     * x2 + coefs[12U])
                                                     * x2 + coefs[11U])
                                                     * x2 + coefs[10U])
                                                     * x2 + coefs[9U])
                                                     * x2 + coefs[8U])
                                                     * x2 + coefs[7U])
                                                     * x2 + coefs[6U])
                                                     * x2 + coefs[5U])
                                                     * x2 + coefs[4U])
                                                     * x2 + coefs[3U])
                                                     * x2 + coefs[2U])
                                                     * x2 + coefs[1U])
                                                     * x2 + coefs[0U])
                                                     * v;

  return sum;
}

int main(void)
{
    mp_type pid4 = boost::math::constants::pi<mp_type>() / 4;
    std::cout << std::setprecision(std::numeric_limits< ::mp_type>::digits10) << std::scientific;
    std::cout << mysin(pid4) << std::endl;
    return 0;
}
