//  Boost checks/upc.hpp header file
//  (C) Copyright Pierre Talbot 2011 - 2012
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//  See http://www.boost.org for updates, documentation, and revision history.

/*! \file
    \brief This file provides tools to compute and validate an Universal Product Code.
*/

#ifndef BOOST_CHECKDIGIT_UPC_HPP
#define BOOST_CHECKDIGIT_UPC_HPP

#ifdef _MSC_VER
    #pragma once
#endif

#include <boost/range/rbegin.hpp>
#include <boost/range/rend.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/checkdigit/checksum.hpp> 

#include <boost/checkdigit/weight.hpp>
#include <boost/checkdigit/basic_checks.hpp>
#include <boost/checkdigit/modulus10.hpp>
#include <boost/checkdigit/weighted_sum.hpp>

/*!
  \brief This macro defines the size of an UPC-A.
*/
#define UPCA_SIZE 12

namespace boost {
    namespace checkdigit{

/*!
  \brief This is the weight used by UPC system.
*/
typedef weight<1,3> upc_weight;

typedef weighted_sum<upc_weight> upc_processor;

typedef features
<
  checksum
  <
    upc_processor,
    mod10_validation,
    mod10_checkdigit
  >,
  UPCA_SIZE
> upca;

/*!
    \brief Validate a sequence according to the upc_check_algorithm type.

    \pre x is a valid range.

    \tparam check_range is a valid range type.
    \param x is the sequence of value to check.

    \throws std::invalid_argument if x doesn't contain exactly UPCA_SIZE digits.

    \returns @c true if the check digit is correct, @c false otherwise.
*/
template <typename check_range>
bool check_upca (const check_range& x)
{
  return check_sequence<upca>(x);
}

bool check_upca (const std::string& x)
{
  return check_sequence<upca>(make_precheck<digit>(x));
}

/*!
    \brief Calculate the check digit of a sequence according to the upc_compute_algorithm type.

    \pre x is a valid range.

    \tparam check_range is a valid range type.
    \param x is the sequence of value to check.

    \throws std::invalid_argument if x doesn't contain exactly UPCA_SIZE_WITHOUT_CHECKDIGIT digits.
    \throws boost::checkdigit::translation_exception if the check digit cannot be translated into the checkdigit type.

    \returns The check digit. The check digit is in the range [0..9].
*/
template <typename check_range>
size_t compute_upca(const check_range& x)
{
  return compute_checkdigit<upca>(x);
}

size_t compute_upca(const std::string& x)
{
  return compute_checkdigit<upca>(make_precheck<digit>(x));
}

}} // namespace boost   namespace checkdigit
#endif // BOOST_CHECKDIGIT_UPCA_HPP
