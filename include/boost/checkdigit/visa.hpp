//  Boost checks/visa.hpp header file
// (C)Copyright Pierre Talbot 2011 - 2012
//  Distributed under the Boost Software License, Version 1.0.(See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//  See http://www.boost.org for updates, documentation, and revision history.

/*! \file
    \brief This file provides tools to compute and validate a Visa credit card number.
*/

#ifndef BOOST_CHECKDIGIT_VISA_HPP
#define BOOST_CHECKDIGIT_VISA_HPP

#ifdef _MSC_VER
    #pragma once
#endif

#include <boost/range/rbegin.hpp>
#include <boost/range/rend.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/checkdigit/checksum.hpp>

#include <boost/checkdigit/luhn.hpp>
#include <boost/checkdigit/checkdigit.hpp>
#include <boost/checkdigit/precheck.hpp>

/*!
  \brief This macro defines the size of a Visa number.
*/
#define VISA_SIZE 16

namespace boost {
    namespace checkdigit{

typedef features
<
  luhn,
  VISA_SIZE
> visa;

/*!
    \brief Validate a sequence according to the visa_check_algorithm type.

    \pre x is a valid range.

    \tparam check_range is a valid range type.
    \param x is the sequence of value to check.

    \throws std::invalid_argument if x doesn't contain exactly VISA_SIZE digits.
    \throws std::invalid_argument if the first digit(from the leftmost)doesn't match the Visa pattern.

    \returns @c true if the check digit is correct, @c false otherwise.
*/
template <typename check_range>
bool check_visa(const check_range& x)
{
  return check_sequence<visa>(x);
}

bool check_visa(const std::string& x)
{
  return check_sequence<visa>(make_precheck<digit>(x));
}

/*!
    \brief Calculate the check digit of a sequence according to the visa_compute_algorithm type.

    \pre x is a valid range.

    \tparam check_range is a valid range type.
    \param x is the sequence of value to check.

    \throws std::invalid_argument if x doesn't contain exactly VISA_SIZE_WITHOUT_CHECKDIGIT digits.
    \throws std::invalid_argument if the first digit(from the leftmost)doESn't match the Visa pattern.
    \throws boost::checkdigit::translation_exception if the check digit cannot be translated into the checkdigit type.

    \returns The check digit. The check digit is in the range [0..9].
*/
template <typename check_range>
size_t compute_visa(const check_range& x)
{
  return compute_checkdigit<visa>(x);
}

size_t compute_visa(const std::string& x)
{
  return compute_checkdigit<visa>(make_precheck<digit>(x));
}

}}  // namespace boost   namespace checkdigit
#endif // BOOST_CHECKDIGIT_VISA_HPP
