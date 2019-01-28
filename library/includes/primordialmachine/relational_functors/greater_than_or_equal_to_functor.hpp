///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Relational Functors Library
// Copyright (C) 2017-2019 Michael Heilmann
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the
// use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "primordialmachine/functors/include.hpp"

namespace primordialmachine {

template<typename LEFT_OPERAND, typename RIGHT_OPERAND, typename ENABLED = void>
struct greater_than_or_equal_to_functor;

template<typename LEFT_OPERAND, typename RIGHT_OPERAND>
auto
greater_than_or_equal_to(
  const LEFT_OPERAND& left_operand,
  const RIGHT_OPERAND&
    right_operand) noexcept(noexcept(greater_than_or_equal_to_functor<LEFT_OPERAND,
                                                                      RIGHT_OPERAND>()(
  left_operand,
  right_operand)))
  -> decltype(greater_than_or_equal_to_functor<LEFT_OPERAND, RIGHT_OPERAND>()(
    left_operand,
    right_operand))
{
  return greater_than_or_equal_to_functor<LEFT_OPERAND, RIGHT_OPERAND>()(
    left_operand, right_operand);
}

template<typename A, typename B>
auto
operator>=(const A& a,
           const B& b) noexcept(noexcept(greater_than_or_equal_to(a, b)))
  -> decltype(greater_than_or_equal_to(a, b))
{
  return greater_than_or_equal_to(a, b);
}

template<typename T, typename ENABLED = void>
struct has_greater_than_or_equal_to_functor : public false_type
{}; // struct has_greater_than_or_equal_to_functor

template<typename A, typename B>
constexpr bool has_greater_than_or_equal_to_functor_v =
  has_greater_than_or_equal_to_functor<
    greater_than_or_equal_to_functor<A, B>>::value;

template<typename A, typename B>
struct has_greater_than_or_equal_to_functor<
  greater_than_or_equal_to_functor<A, B>,
  decltype(typeid(greater_than_or_equal_to_functor<A, B>), void())>
  : public true_type
{}; // struct has_greater_than_or_equal_to_functor

} // namespace primordialmachine
