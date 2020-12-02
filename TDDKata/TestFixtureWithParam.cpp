#include "pch.h"
#include "TestFixtureWithParam.h"
#include <vector>

//INSTANTIATE_TEST_CASE_P(ParametrizedTest, TestFixtureWithParam,
//	::testing::Values(Param("2,3", 5), Param("4", 4)));

std::vector<Param> CreateParametersSet()
{
	std::vector<Param> p;
    p.push_back(Param("", 0));
    p.push_back(Param("123456789", 123456789));
    p.push_back(Param("1,1", 2));
    p.push_back(Param("1111,2222", 3333));
    p.push_back(Param("1,1,1", 3));
    p.push_back(Param("0,1", 1));
    p.push_back(Param("00,1", 1));
    p.push_back(Param("00,000", 0));
    p.push_back(Param("01,002", 3));
    p.push_back(Param("-1,2", ERR_FORMAT));
    p.push_back(Param("1.1", ERR_FORMAT));
    p.push_back(Param("1,1.1", ERR_FORMAT));
    p.push_back(Param(",1,1", ERR_FORMAT));
    p.push_back(Param("1,1,", ERR_FORMAT));
    p.push_back(Param("a,z", ERR_FORMAT));
    p.push_back(Param("1,1,1,1,1", 5));
    p.push_back(Param("1,1,1,1,1,1,1,1,1,1,1,1,1,1,1000001", 1000015));
    p.push_back(Param((char*)NULL, -3));
    p.push_back(Param("1,1\n1,1,1,1,1\n1,1,1,1,1,1\n1,1", 15));
    p.push_back(Param("1,1,\n1,1,1,1,1,1,1,1,1,1,1,1,1", ERR_FORMAT));
    p.push_back(Param("1,1\n,1,1,1,1,1,1,1,1,1,1,1,1,1", ERR_FORMAT));
    p.push_back(Param("1,1\n\n1,1,1,1,1,1,1,1,1,1,1,1,1", ERR_FORMAT));
    p.push_back(Param("//;\n1;1;1;1;1;1;1;1;1;1;1;1;1;1;1", 15));
    p.push_back(Param("//\n;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1", ERR_CHANGE_DELIMITER_FORMAT));
    p.push_back(Param("//\n\n;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1", ERR_CHANGE_DELIMITER_FORMAT));
    p.push_back(Param("//z\nz1z1z1", ERR_FORMAT));
    p.push_back(Param("//z\n1z1z1", 3));
    p.push_back(Param("//z\n1z1,1", ERR_FORMAT));
    p.push_back(Param("//1\n1211223121", ERR_CHANGE_DELIMITER_FORMAT));
    p.push_back(Param("1//.\n,1,1,1,1,1,1,1,1,1,1,1,1,1,1", ERR_FORMAT));
	return p;
}

INSTANTIATE_TEST_CASE_P(ParametrizedTest, TestFixtureWithParam,
	::testing::ValuesIn(CreateParametersSet()));