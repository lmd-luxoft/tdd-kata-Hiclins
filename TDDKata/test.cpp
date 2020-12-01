#include "pch.h"
#include "Calculator.h"

	TEST(TDDKata, NoStr) {
		Calculator calc;
		ASSERT_EQ(calc.Add(""), 0);
		ASSERT_TRUE(true);
	}

	TEST(TDDKata, TestName1) {
		Calculator calc;
		ASSERT_EQ(calc.Add("1"), 1);
		ASSERT_TRUE(true);
	}

	TEST(TDDKata, TestName19) {
		Calculator calc;
		ASSERT_EQ(calc.Add("123456789"), 123456789);
		ASSERT_TRUE(true);
	}

	TEST(TDDKata, TestName2) {
		Calculator calc;
		ASSERT_EQ(calc.Add("1,1"), 2);
		ASSERT_TRUE(true);
	}

	TEST(TDDKata, TestName3333) {
		Calculator calc;
		ASSERT_EQ(calc.Add("1111,2222"), 3333);
		ASSERT_TRUE(true);
	}


	TEST(TDDKata, TestName3) {
		Calculator calc;
		ASSERT_EQ(calc.Add("1,1,1"), 3);
		ASSERT_TRUE(true);
	}

	TEST(TDDKata, Zero) {
		Calculator calc;
		ASSERT_EQ(calc.Add("0,1"), 1);
		ASSERT_TRUE(true);
	}

	TEST(TDDKata, Zero2) {
		Calculator calc;
		ASSERT_EQ(calc.Add("00,1"), 1);
		ASSERT_TRUE(true);
	}

	TEST(TDDKata, Zero1) {
		Calculator calc;
		ASSERT_EQ(calc.Add("00,000"), 0);
		ASSERT_TRUE(true);
	}

	TEST(TDDKata, Zero3) {
		Calculator calc;
		ASSERT_EQ(calc.Add("01,002"), 3);
		ASSERT_TRUE(true);
	}

	TEST(TDDKata, Neg) {
		Calculator calc;
		ASSERT_EQ(calc.Add("-1,2"), -2);
		ASSERT_TRUE(true);
	}

	TEST(TDDKata, Dot) {
		Calculator calc;
		ASSERT_EQ(calc.Add("1.1"), -2);
		ASSERT_TRUE(true);
	}

	TEST(TDDKata, Dot2) {
		Calculator calc;
		ASSERT_EQ(calc.Add("1,1.1"), -2);
		ASSERT_TRUE(true);
	}

	TEST(TDDKata, Format) {
		Calculator calc;
		ASSERT_EQ(calc.Add(",1,1"), -2);
		ASSERT_TRUE(true);
	}

	TEST(TDDKata, Format2) {
		Calculator calc;
		ASSERT_EQ(calc.Add("1,1,"), -2);
		ASSERT_TRUE(true);
	}

	TEST(TDDKata, Format3) {
		Calculator calc;
		ASSERT_EQ(calc.Add("a,z"), -2);
		ASSERT_TRUE(true);
	}

	TEST(TDDKata, Param5) {
		Calculator calc;
		ASSERT_EQ(calc.Add("1,1,1,1,1"), 5);
		ASSERT_TRUE(true);
	}

	TEST(TDDKata, maxParam) {
		Calculator calc;
		ASSERT_EQ(calc.Add("1,1,1,1,1,1,1,1,1,1,1,1,1,1,1000001"), 1000015);
		ASSERT_TRUE(true);
	}

	TEST(TDDKata, NullTest) {
		Calculator calc;
		ASSERT_EQ(calc.Add(NULL), -3);
		ASSERT_TRUE(true);
	}


	TEST(TDDKata, TestDelimiter) {
		Calculator calc;
		ASSERT_EQ(calc.Add("1,1\n1,1,1,1,1\n1,1,1,1,1,1\n1,1"), 15);
		ASSERT_TRUE(true);
	}

	TEST(TDDKata, TestDelimiter1) {
		Calculator calc;
		ASSERT_EQ(calc.Add("1,1,\n1,1,1,1,1,1,1,1,1,1,1,1,1"), -2);
		ASSERT_TRUE(true);
	}

	TEST(TDDKata, TestDelimiter2) {
		Calculator calc;
		ASSERT_EQ(calc.Add("1,1\n,1,1,1,1,1,1,1,1,1,1,1,1,1"), -2);
		ASSERT_TRUE(true);
	}

	TEST(TDDKata, TestDelimiter3) {
		Calculator calc;
		ASSERT_EQ(calc.Add("1,1\n\n1,1,1,1,1,1,1,1,1,1,1,1,1"), -2);
		ASSERT_TRUE(true);
	}