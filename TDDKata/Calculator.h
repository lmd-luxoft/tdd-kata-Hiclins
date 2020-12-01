#pragma once
#include "pch.h"
#include <string>
/// <summary>
/// Class Under test
/// </summary>

#define ERR_FORMAT -2
#define ERR_PARAM_COUNT -1

class Calculator
{
public:
	/// <summary>
	/// Sum of elements expression
	/// </summary>
	/// <param name="expression">Input expression</param>
	/// <returns>Value of sum expression of expression</returns>
	int Add(std::string expression);
	/// <summary>
	/// Sum of elements expression
	/// </summary>
	/// <param name="expression">Input expression</param>
	/// <returns>Value of sum expression of expression</returns>
	int Add(char* expression);
};

