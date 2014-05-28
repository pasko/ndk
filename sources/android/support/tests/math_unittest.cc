#include <math.h>

#include <minitest/minitest.h>

TEST(math, sizeof_long_double) {
#ifdef __ANDROID__
#  ifdef __LP64__
    EXPECT_EQ(16U, sizeof(long double));
#  else
    EXPECT_EQ(8U, sizeof(long double));
#  endif
#endif
}

TEST(math, nexttoward) {
    double x = 2.0;
    EXPECT_EQ(x, nexttoward(x, (long double)x));
    EXPECT_GT(x, nexttoward(x, (long double)(x * 2.)));
    EXPECT_LT(x, nexttoward(x, (long double)(x - 1.0)));
}

TEST(math, nexttowardf) {
    float x = 2.0;
    EXPECT_EQ(x, nexttowardf(x, (long double)x));
    EXPECT_GT(x, nexttowardf(x, (long double)(x * 2.)));
    EXPECT_LT(x, nexttowardf(x, (long double)(x - 1.0)));
}

TEST(math, nexttowardl) {
    long double x = 2.0;
    EXPECT_EQ(x, nexttowardf(x, x));
    EXPECT_GT(x, nexttowardf(x, x * 2.));
    EXPECT_LT(x, nexttowardf(x, x - 1.0));
}
