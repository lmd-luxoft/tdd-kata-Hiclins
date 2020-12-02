#include "pch.h"
#include "Calculator.h"
#include "TestFixture.h"

	TEST_F(TestFixture, NoStr) {
		char* op = ""; 
		int expected = 0;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}

	TEST_F(TestFixture, TestName1) {
		char* op = "1";
		int expected = 1;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}

	TEST_F(TestFixture, TestName19) {
		char* op = "123456789";
		int expected = 123456789;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}

	TEST_F(TestFixture, TestName2) {
		char* op = "1,1";
		int expected = 2;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}

	TEST_F(TestFixture, TestName3333) {
		char* op = "1111,2222";
		int expected = 3333;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}


	TEST_F(TestFixture, TestName3) {
		char* op = "1,1,1";
		int expected = 3;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}

	TEST_F(TestFixture, Zero) {
		char* op = "0,1";
		int expected = 1;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}

	TEST_F(TestFixture, Zero2) {
		char* op = "00,1";
		int expected = 1;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}

	TEST_F(TestFixture, Zero1) {
		char* op = "00,000";
		int expected = 0;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}

	TEST_F(TestFixture, Zero3) {
		char* op = "01,002";
		int expected = 3;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}

	TEST_F(TestFixture, Neg) {
		char* op = "-1,2";
		int expected = -2;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}
	
	TEST_F(TestFixture, Dot) {
		char* op = "1.1";
		int expected = -2;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}
	
	TEST_F(TestFixture, Dot2) {
		char* op = "1,1.1";
		int expected = -2;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}
	
	TEST_F(TestFixture, Format) {
		char* op = ",1,1";
		int expected = -2;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}

	TEST_F(TestFixture, Format2) {
		char* op = "1,1,";
		int expected = -2;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}

	TEST_F(TestFixture, Format3) {
		char* op = "a,z";
		int expected = -2;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}
	
	TEST_F(TestFixture, Param5) {
		char* op = "1,1,1,1,1";
		int expected = 5;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}

	TEST_F(TestFixture, maxParam) {
		char* op = "1,1,1,1,1,1,1,1,1,1,1,1,1,1,1000001";
		int expected = 1000015;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}

	TEST_F(TestFixture, NullTest) {
		char* op = NULL;
		int expected = -3;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}


	TEST_F(TestFixture, TestDelimiter) {
		char* op = "1,1\n1,1,1,1,1\n1,1,1,1,1,1\n1,1";
		int expected = 15;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}
	
	TEST_F(TestFixture, TestDelimiter1) {
		char* op = "1,1,\n1,1,1,1,1,1,1,1,1,1,1,1,1";
		int expected = -2;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}

	TEST_F(TestFixture, TestDelimiter2) {
		char* op = "1,1\n,1,1,1,1,1,1,1,1,1,1,1,1,1";
		int expected = -2;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}

	TEST_F(TestFixture, TestDelimiter3) {
		char* op = "1,1\n\n1,1,1,1,1,1,1,1,1,1,1,1,1";
		int expected = -2;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}
	
	TEST_F(TestFixture, TestNewDelimiter) {
		char* op = "//;\n1;1;1;1;1;1;1;1;1;1;1;1;1;1;1";
		int expected = 15;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}

	TEST_F(TestFixture, TestNewDelimiter1) {
		char* op = "//\n;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1";
		int expected = ERR_CHANGE_DELIMITER_FORMAT;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}
	TEST_F(TestFixture, TestNewDelimiter2) {
		char* op = "//\n\n;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1";
		int expected = ERR_CHANGE_DELIMITER_FORMAT;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}

	TEST_F(TestFixture, TestNewDelimiter3) {
		char* op = "//z\nz1z1z1";
		int expected = ERR_FORMAT;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}

	TEST_F(TestFixture, TestNewDelimiter5) {
		char* op = "//z\n1z1z1";
		int expected = 3;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}

	TEST_F(TestFixture, TestNewDelimiter6) {
		char* op = "//z\n1z1,1";
		int expected = ERR_FORMAT;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}

	TEST_F(TestFixture, TestNewDelimiter4) {
		char* op = "//1\n1211223121";
		int expected = ERR_CHANGE_DELIMITER_FORMAT;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}


	TEST_F(TestFixture, TestNewDelimiter7) {
		char* op = "1//.\n,1,1,1,1,1,1,1,1,1,1,1,1,1,1";
		int expected = ERR_FORMAT;

		int actual = calc->Add(op);
		ASSERT_EQ(expected, actual);
	}

