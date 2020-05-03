#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char str[]);

int main() {
    printf("%f\n", atof("  -246.444E-3"));

    return 0;
}

double atof(char str[]) {
    float number;
    int sign, i, power, expSign, exp;
    for (i = 0; isspace(str[i]); i++)
        ;
    sign = str[i] == '-' ? -1 : 1;
    if (str[i] == '-' || str[i] == '+') {
        i++;
    }
    for (number = 0.0; isnumber(str[i]); i++) {
        number  = number * 10 + (str[i] - '0');
    }
    if (str[i] == '.') {
        i++;
    }
    for (power = 1.0; isnumber(str[i]); i++, power *= 10) {
        number = number * 10 + (str[i] - '0');
    }

    if (str[i] == 'e' || str[i] == 'E') {
        i++;
        expSign = str[i] == '-' ? 1 : -1;
        if (str[i] == '-' || str[i] == '+') {
            i++;
        }
        for (exp = 0; isnumber(str[i]); i++) {
            exp  = exp * 10 + (str[i] - '0');
        }
        exp = pow(10, exp);
        power = expSign < 0 ? power / exp : power * exp;
    }

    return sign * number / power;
}