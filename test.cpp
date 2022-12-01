#include <gtest/gtest.h>
#include "matrix_oop.h"

double case_1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
double case_2[] = {1, 4, 6, 7, 9, -5, 7, 8, 4};
double case_3[] = {6, 7.5, 9, -3, 6.8, 0, 15, -1, 2.9};
double case_4[] = {7, 11.5, 15, 4, 15.8, -5, 22, 7, 6.9};
double case_5[] = {1, 7, 7, 4, 9, 8, 6, -5, 4};
double case_6[] = {1, 7, 7, 4, 9, 8};
double case_7[] = {1};
double case_8[] = {76, -63, -7, 32, -38, 20, -74, 47, -19};
double case_9[] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
double case_10[] = {1, -1, 1, -38, 41, -34, 27, -29, 24};
double case_11[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
double case_12[] = {2, 4, 6, 8, 10, 12, 14, 16, 18};

TEST(Constructor, test1) {
    Matrix t1;
    t1.fill_matrix(case_1);
    Matrix t2(3, 3);
    ASSERT_EQ(t1 == t2, true);
}

TEST(Constructor, test2) {
    Matrix t1(3, 3);
    t1.fill_matrix(case_2);
    Matrix t2(t1);
    ASSERT_EQ(t1 == t2, true);
    Matrix t3(3, 3);
    ASSERT_EQ(t1 == t3, false);
}

TEST(Constructor, test3) {
    Matrix t1(3, 3);
    t1.fill_matrix(case_2);
    Matrix t2(t1);
    ASSERT_EQ(t1 == t2, true);
    Matrix t3(std::move(t2));
    ASSERT_EQ(t1 == t3, true);
}

TEST(Functions, test4_sum_matrix) {
    Matrix t1(3, 3);
    t1.fill_matrix(case_2);
    Matrix t2(3, 3);
    t2.fill_matrix(case_3);
    Matrix res(3, 3);
    res.fill_matrix(case_4);
    t1.sum_matrix(t2);
    Matrix t4(2, 2);
    ASSERT_EQ(t1 == res, true);
    ASSERT_EQ(t4 == res, false);
}

TEST(Functions, test5_sub_matrix) {
    Matrix t1(3, 3);
    t1.fill_matrix(case_2);
    Matrix t2(3, 3);
    t2.fill_matrix(case_5);
    Matrix res(3, 3);
    res = t1.transpose();
    ASSERT_EQ(res == t2, true);
    Matrix t4(2, 2);
}

TEST(Functions, test6_mul_matrix) {
    Matrix t1(3, 3);
    t1.fill_matrix(case_1);
    Matrix t2(3, 3);
    t2.fill_matrix(case_2);
    Matrix res(3, 3);
    res.fill_matrix(case_1);
    t1.mul_matrix(t2);
    Matrix t3(2, 2);
    ASSERT_EQ(t1 == res, true);
}

TEST(Functions, test7_mul_number) {
    Matrix t1(3, 3);
    t1.fill_matrix(case_2);
    Matrix t2(3, 3);
    t2.fill_matrix(case_2);
    Matrix t3(3, 3);
    t3.fill_matrix(case_1);
    t1.mul_number(0.0);
    t2.mul_number(1.0);
    ASSERT_EQ(t1 == t3, true);
    ASSERT_EQ(t2 == t2, true);
}

TEST(Functions, test8_transpose) {
    Matrix t1(3, 3);
    t1.fill_matrix(case_2);
    Matrix t2(3, 3);
    t2.fill_matrix(case_2);
    Matrix t3(3, 3);
    t3.fill_matrix(case_1);
    t1.mul_number(0.0);
    t2.mul_number(1.0);
    ASSERT_EQ(t1 == t3, true);
    ASSERT_EQ(t2 == t2, true);
}

TEST(Functions, test9_determinant) {
    Matrix t1(3, 3);
    t1.fill_matrix(case_2);
    double x = t1.determinant();
    ASSERT_EQ(x == -218, true);
    Matrix t3(1, 1);
    t3.fill_matrix(case_7);
    double z = t3.determinant();
    ASSERT_EQ(z == 1, true);
}

TEST(Functions, test10_calc_complements) {
    Matrix t1(3, 3);
    t1.fill_matrix(case_2);
    Matrix t2(3, 3);
    t2 = t1.calc_complements();
    Matrix t3(3, 3);
    t3.fill_matrix(case_8);
    ASSERT_EQ(t2 == t3, true);
}

TEST(Functions, test11_inverse_matrix) {
    Matrix t1(3, 3);
    t1.fill_matrix(case_9);
    Matrix t2(3, 3);
    t2 = t1.inverse_matrix();
    Matrix t3(3, 3);
    t3.fill_matrix(case_10);
    ASSERT_EQ(t2 == t3, true);
}

TEST(Operators, test12) {
    Matrix t1(3, 3);
    t1.fill_matrix(case_2);
    Matrix t2(3, 3);
    t2.fill_matrix(case_3);
    Matrix t3(3, 3);
    t3.fill_matrix(case_4);
    Matrix t4(3, 3);
    t4 = t1 + t2;
    Matrix t5(3, 3);
    ASSERT_EQ(t4 == t3, true);
    t4 = t3 - t2;
    ASSERT_EQ(t1 == t4, true);
    t4 = t1 * 1;
    ASSERT_EQ(t1 == t4, true);
    t4 = 1 * t1;
    ASSERT_EQ(t1 == t4, true);
    t4 = t1 * t5;
    ASSERT_EQ(t4 == t5, true);
}

TEST(Operators, test13) {
    Matrix t1(3, 3);
    t1.fill_matrix(case_2);
    Matrix t2(3, 3);
    t2.fill_matrix(case_3);
    Matrix t3(3, 3);
    t3.fill_matrix(case_4);
    t1 += t2;
    ASSERT_EQ(t1 == t3, true);
}

TEST(Operators, test14) {
    Matrix t1(3, 3);
    t1.fill_matrix(case_2);
    Matrix t2(3, 3);
    t2.fill_matrix(case_3);
    Matrix t3(3, 3);
    t3.fill_matrix(case_4);
    t3 -= t2;
    ASSERT_EQ(t1 == t3, true);
}

TEST(Operators, test15) {
    Matrix t1(3, 3);
    t1.fill_matrix(case_1);
    Matrix t2(3, 3);
    t2.fill_matrix(case_2);
    Matrix res(3, 3);
    res.fill_matrix(case_1);
    t1 *= t2;
    ASSERT_EQ(t1 == res, true);
    Matrix t3(3, 3);
    t3.fill_matrix(case_11);
    Matrix t4(3, 3);
    t4.fill_matrix(case_12);
    t3 *= 2;
    ASSERT_EQ(t3 == t4, true);
    ASSERT_EQ(t4(0, 0) == 2, true);
}

TEST(Operators, test16) {
    Matrix t1(3, 2);
    t1.fill_matrix(case_12);
    ASSERT_EQ(t1.getRows() == 3, true);
    ASSERT_EQ(t1.getCols() == 2, true);
    Matrix t2;
    t2.setRows(t1.getRows());
    t2.setCols(t1.getCols());
    ASSERT_EQ(t2.getRows() == 3, true);
    ASSERT_EQ(t2.getCols() == 2, true);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
