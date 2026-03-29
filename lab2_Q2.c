#include <stdio.h>
/* Function to check leap year */
int isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else
        return 0;
}
/* Function to get starting day of the month */
int getStartDay(int month, int year)
{
    int days = 0;
    int i;

    int monthDays[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    /* Add days for previous years */
    for (i = 1; i < year; i++)
    {
        days += isLeapYear(i) ? 366 : 365;
    }

    /* Add days for previous months of current year */
    for (i = 0; i < month - 1; i++)
    {
        days += monthDays[i];
    }

    /* Leap year adjustment */
    if (month > 2 && isLeapYear(year))
        days += 1;

    return days % 7;
}

int main()
{
    int month, year, i;
    int startDay, daysInMonth;

    char *months[] = {"January","February","March","April","May","June",
                      "July","August","September","October","November","December"};

    char *days[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

    int monthDays[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    printf("Enter month (1-12): ");
    scanf("%d", &month);

    printf("Enter year: ");
    scanf("%d", &year);

    /* Leap year adjustment */
    if (month == 2 && isLeapYear(year))
        daysInMonth = 29;
    else
        daysInMonth = monthDays[month - 1];

    startDay = getStartDay(month, year);

    /* Display calendar */
    printf("\n    %s %d\n", months[month - 1], year);

    for (i = 0; i < 7; i++)
        printf("%s ", days[i]);

    printf("\n");

    /* Print initial spaces */
    for (i = 0; i < startDay; i++)
        printf("    ");

    /* Print dates */
    for (i = 1; i <= daysInMonth; i++)
    {
        printf("%3d ", i);

        if ((i + startDay) % 7 == 0)
            printf("\n");
    }

    printf("\n");

    return 0;
}
