#include <stdio.h>

int day_of_year(unsigned int y, unsigned int m, unsigned int d);
void month_day(unsigned int year, unsigned int dayofyear, unsigned int * m, unsigned int * d);

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main() {
    unsigned int m;
    unsigned int d;

    printf("Day of year: %d\n", day_of_year(2020, 5, 32));
    month_day(2020, 400, &m, &d);
    printf("Day: %d, %d\n", m, d);

    return 0;
}

int day_of_year(unsigned int y, unsigned int m, unsigned int d) {
    int i, leap;
    if (m > 12 || d > 31) {
        printf("ERROR: The date is wrong\n");
        return -1;
    }
    leap = y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
    for (i = 1; i < m; i++) {
        d += daytab[leap][i];
    }

    return d;
}

void month_day(unsigned int y, unsigned int dayofyear, unsigned int * m, unsigned int * d) {
    int i, leap;

    if (dayofyear > 365) {
        printf("ERROR: there is no such day\n");
        *m = 0;
        *d = 0;
        return;
    }

    leap = y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
    for (i = 1; dayofyear > daytab[leap][i]; i++) {
        dayofyear -= daytab[leap][i];
    }

    *m = i;
    *d = dayofyear;
}

