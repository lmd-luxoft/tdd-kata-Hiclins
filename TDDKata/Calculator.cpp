#include "pch.h"
#include "Calculator.h"

int Calculator::Add(std::string expression)
{
    return 0;
}

int Calculator::Add(char* expression)
{

    int summ = 0;
    int error = 0;
    
    if (expression == NULL) {
        return ERR_NULL_PTR;
    }

    if (!strlen(expression)) {
        return 0;
    }

    expression = checkNewDelimiter(expression, &error);
    if (error) return error;

    do {
        summ += getNum(expression, &error);
        if (error) break;
        expression = getEndNum(expression);
        if (*expression != '\0') {
            expression = getNextNum(expression, &error);
        }
    } while (!error && *expression != '\0');

    if (error) return error;
    return summ;
}


char* Calculator::checkNewDelimiter(char* c, int* error) {
	if (c[0] == '/' && c[1] == '/') {
		if (c[0] == '/' &&
			c[1] == '/' &&
			(c[2] <= '0' || c[2] >= '9') && c[2] != '\n' && c[2] != '\0' &&
			c[3] == '\n') {
			newDelimiter = c[2];
			return &c[4];
		}
		else {
			*error = ERR_CHANGE_DELIMITER_FORMAT;
		}
	}
	return c;
}



bool Calculator::isDelimiter(char* c) {
	if (!newDelimiter) {
		if (*c == ',' || *c == '\n')
			return true;
		else
			return false;
	}
	else {
		if (*c == newDelimiter)
			return true;
		else
			return false;
	}
}

bool Calculator::isValidNum(char* c) {
	int num, res;
	res = sscanf(c, "%d", &num);
	if (res && num >= 0)
		return true;
	else
		return false;

}

int Calculator::getNum(char* p, int* error) {
	int num;
	int res = sscanf(p, "%d", &num);
	if (!res || num < 0)
		*error = ERR_FORMAT;
	return num;
}

bool Calculator::isDig(char* c) {
	if (*c >= '0' && *c <= '9')
		return true;
	return false;
}

char* Calculator::getNextNum(char* p, int* error) {
	if (isDelimiter(p)) {
		if (!isDig(++p))
			*error = ERR_FORMAT;
	}
	else {
		*error = ERR_FORMAT;
	}
	return p;
}

char* Calculator::getEndNum(char* n) {
	while (*n >= '0' && *n <= '9') {
		n++;
	}
	return n;
}