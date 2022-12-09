#include<stdio.h>

int isLeapYear(int year) {
    return (year%400 == 0 || (year%4 == 0 && year%100 != 0));
}

int getDayOfMonth(int month, int leap) {
    if (month == 2) {
        return 28 + (leap ? 1 : 0);
    } else if (month <= 7) {
        if (month%2 == 0) return 30;
        else return 31;
    } else {
        if (month%2 == 0) return 31;
        else return 30;
    }
}

int getTotalDay(int year, int month, int day) {
    int result = 0;
    int leap = isLeapYear(year);
    for (int i = 1;i < month;i++) {
        result += getDayOfMonth(i, leap);
    }
    result += day;
    return result;
}

int main(void) {
    int year, month, day;
    scanf("%d/%d/%d", &year, &month, &day);
    int total = 0, cnt = 0, tmp;
    while (scanf("%d", &tmp) != EOF) {
        total += tmp;
        cnt++;
    }
    int avgDay = total / cnt;
    int curTotalDay = getTotalDay(year, month, day);
    int dayToYearEnd = getTotalDay(year, 12, 31) - curTotalDay;

    if (avgDay <= dayToYearEnd) {
        avgDay += day;
        day = 0;
        // calculate month and day
        while (1) {
            int dayOfMonth = getDayOfMonth(month, isLeapYear(year));
            if (avgDay <= dayOfMonth) {
                day = avgDay;
                break;
            }
            month++;
            avgDay -= dayOfMonth;
        }
    } else {
        avgDay += curTotalDay;
        month = 1, day = 0;
        // calculate year
        while (1) {
            int totalDayOfYear = getTotalDay(year, 12, 31);
            if (avgDay <= totalDayOfYear) {
                // printf("%d\n", avgDay);
                break;
            }
            year++;
            avgDay -= totalDayOfYear;
        }
        // calculate month and day
        while (1) {
            int dayOfMonth = getDayOfMonth(month, isLeapYear(year));
            if (avgDay <= dayOfMonth) {
                day = avgDay;
                break;
            }
            month++;
            avgDay -= dayOfMonth;
        }
    }

    printf("%d/%02d/%02d", year, month, day);
    return 0;
}