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

#include "primordialmachine/relational_functors/include.hpp"
#include "gtest/gtest.h"

TEST(relational_functors_test, lower_than_functor_test)
{
  using namespace primordialmachine;
  ASSERT_FALSE((lower_than_functor<float, float>()(1.0f, 1.0f)));
  ASSERT_TRUE((lower_than_functor<float, float>()(1.0f, 2.0f)));
  ASSERT_FALSE((lower_than_functor<float, float>()(2.0f, 1.0f)));
  ASSERT_TRUE((lower_than_functor<float, float>()(0.0f, 1.0f)));
}

TEST(relational_functors_test, lower_than_or_equal_to_functor_test)
{
  using namespace primordialmachine;
  ASSERT_TRUE((lower_than_or_equal_to_functor<float, float>()(1.0f, 1.0f)));
  ASSERT_TRUE((lower_than_or_equal_to_functor<float, float>()(1.0f, 2.0f)));
  ASSERT_FALSE((lower_than_or_equal_to_functor<float, float>()(2.0f, 1.0f)));
  ASSERT_TRUE((lower_than_or_equal_to_functor<float, float>()(0.0f, 1.0f)));
}

TEST(relational_functors_test, greater_than_functor_test)
{
  using namespace primordialmachine;
  ASSERT_FALSE((greater_than_functor<float, float>()(1.0f, 1.0f)));
  ASSERT_FALSE((greater_than_functor<float, float>()(1.0f, 2.0f)));
  ASSERT_TRUE((greater_than_functor<float, float>()(2.0f, 1.0f)));
  ASSERT_FALSE((greater_than_functor<float, float>()(0.0f, 1.0f)));
}

TEST(relational_functors_test, greater_than_or_equal_to_functor_test)
{
  using namespace primordialmachine;
  ASSERT_TRUE((greater_than_or_equal_to_functor<float, float>()(1.0f, 1.0f)));
  ASSERT_FALSE((greater_than_or_equal_to_functor<float, float>()(1.0f, 2.0f)));
  ASSERT_TRUE((greater_than_or_equal_to_functor<float, float>()(2.0f, 1.0f)));
  ASSERT_FALSE((greater_than_or_equal_to_functor<float, float>()(0.0f, 1.0f)));
}

TEST(relational_functors_test, equal_to_functor_test)
{
  using namespace primordialmachine;
  ASSERT_TRUE((equal_to_functor<float, float>()(1.0f, 1.0f)));
  ASSERT_FALSE((equal_to_functor<float, float>()(1.0f, 2.0f)));
  ASSERT_FALSE((equal_to_functor<float, float>()(2.0f, 1.0f)));
  ASSERT_FALSE((equal_to_functor<float, float>()(0.0f, 1.0f)));
}

TEST(relational_functors_test, not_equal_to_functor_test)
{
  using namespace primordialmachine;
  ASSERT_FALSE((not_equal_to_functor<float, float>()(1.0f, 1.0f)));
  ASSERT_TRUE((not_equal_to_functor<float, float>()(1.0f, 2.0f)));
  ASSERT_TRUE((not_equal_to_functor<float, float>()(2.0f, 1.0f)));
  ASSERT_TRUE((not_equal_to_functor<float, float>()(0.0f, 1.0f)));
}
