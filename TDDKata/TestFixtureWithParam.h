#pragma once
#include "pch.h"
#include "TestFixture.h"
#include <tuple>

struct Param
{
    char* op;
    int expected;
    Param(char* op, int expected) :
        op(op), expected(expected) {}
};

class TestFixtureWithParam :
    public TestFixture, public ::testing::WithParamInterface<Param>
{
};

