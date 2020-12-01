#pragma once
#include "pch.h"
#include <string>
/// <summary>
/// Class Under test
/// </summary>

#define ERR_FORMAT -2
#define ERR_PARAM_COUNT -1
#define ERR_NULL_PTR -3
#define ERR_CHANGE_DELIMITER_FORMAT -4
#define NO_ERR 0

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

	typedef enum {
		NUMBER,
		DELIMITER,
		ERROR,
	}paramType_t;

private:

	char newDelimiter = 0;

	char* checkNewDelimiter(char* c, int* error);
	bool isDelimiter(char* c);
	bool isValidNum(char* c);
	int getNum(char* p, int* error);
	bool isDig(char* c);
	char* getNextNum(char* p, int* error);
	char* getEndNum(char* n);

};

