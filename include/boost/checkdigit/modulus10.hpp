//  Boost checks/modulus10.hpp header file
//  (C) Copyright Pierre Talbot 2011
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//  See http://www.boost.org for updates, documentation, and revision history.

#ifndef BOOST_CHECKDIGIT_MOD10_HPP
#define BOOST_CHECKDIGIT_MOD10_HPP

#ifdef _MSC_VER
    #pragma once
#endif

#include <cstddef>
#include <boost/checkdigit/checkdigit.hpp>
#include <boost/checkdigit/modulus.hpp>

namespace boost{
  namespace checkdigit{

typedef modulus<10> mod10_basic;
typedef modulus_inv<10> mod10_inv_basic;
typedef checkdigit_encoder<> mod10_basic_encoder;

typedef checkdigit<mod10_basic, mod10_basic_encoder> mod10_basic_checkdigit;
typedef checkdigit<mod10_inv_basic, mod10_basic_encoder> mod10_inv_basic_checkdigit;

}}  // namespace boost   namespace checkdigit

#endif //BOOST_CHECKDIGIT_MOD10_HPP
