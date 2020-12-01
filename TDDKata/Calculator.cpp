#include "pch.h"
#include "Calculator.h"

int Calculator::Add(std::string expression)
{
    return 0;
}

int Calculator::Add(char* expression)
{

    int summ = 0;
    

    if (!strlen(expression)) {
        return 0;
    }

    char* p = expression;
    summ = atoi(expression);

    if(summ < 0)
        return ERR_FORMAT;
    if(*expression == ',')
        return ERR_FORMAT;

    int paramCount = 1;
    do {
        if ((*p < '0' || *p > 'p') && *p != ',')
            return ERR_FORMAT;
        if (*p == ',') {
            int param = -1;
            paramCount++;
            int res = sscanf((p + 1), "%d", &param);
            if (res && param >= 0) {
                summ += param;
            }
            else {
                return ERR_FORMAT;
            }
            if (paramCount > 2) {
                return ERR_PARAM_COUNT;
            }
        }

        p++;
    } while (*p != '\0');

    return summ;
}
