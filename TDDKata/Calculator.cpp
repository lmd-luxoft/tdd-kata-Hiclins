#include "pch.h"
#include "Calculator.h"

int Calculator::Add(std::string expression)
{
    return 0;
}

int Calculator::Add(char* expression)
{

    int summ = 0;
    
    if (expression == NULL) {
        return ERR_NULL_PTR;
    }

    if (!strlen(expression)) {
        return 0;
    }

    char* p = expression;
    summ = atoi(expression);

    if(summ < 0)
        return ERR_FORMAT;
    if(*expression == ',' || *expression == '\n')
        return ERR_FORMAT;

    int paramCount = 1;
    do {
        if ((*p < '0' || *p > 'p') && *p != ',' && *p != '\n')// �������� �� ���������� �������
            return ERR_FORMAT;
        if (*p == ',' || *p == '\n') {
            if (*(p + 1) == ',' || *(p + 1) == '\n') {// ���� 2 ����������� ������
                return ERR_FORMAT;
            }
            int param = -1;
            int res = sscanf((p + 1), "%d", &param);
            if (res && param >= 0) {
                summ += param;
            }
            else {
                return ERR_FORMAT;
            }
        }

        p++;
    } while (*p != '\0');

    return summ;
}
