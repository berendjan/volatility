#include <gtest/gtest.h>

#include <Variance.cpp>

#include <string>
#include <vector>

TEST(Main, TestVola)
{

    volatility::StreamingSlidingWindowVolatility vola;

    vola.add_point(2.0, 0);
    vola.add_point(2.0, 1);
    vola.add_point(4.0, 2);
    vola.add_point(4.0, 3);

    auto vol = vola.get_volatility();

    EXPECT_EQ(vol, 1.0);

    // ASSERT_EQ(result.size(), 2);
    // EXPECT_EQ(result[0], "9");
    // EXPECT_EQ(result[1], "12");
}

TEST(Main, TestVola2)
{

    volatility::StreamingSlidingWindowVolatility vola;

    for (int i = 0; i < 4320; i++)
    {
        vola.add_point(2.0, i);
    }

    for (int i = 0; i < 4320 / 2; i++)
    {
        vola.add_point(4.0, i);
    }

    auto vol = vola.get_volatility();

    EXPECT_EQ(vol, 1.0);

    // ASSERT_EQ(result.size(), 2);
    // EXPECT_EQ(result[0], "9");
    // EXPECT_EQ(result[1], "12");
}