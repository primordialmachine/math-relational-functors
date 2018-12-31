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
