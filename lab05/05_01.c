#include <stdio.h>

typedef struct datetime {
    int date;       // 1-31
    int month;      // 1-12
    int year;       // 1970++
    int dayOfWeek;  // 0-6 
    int hour;       // 0-23
    int minute;     // 0-59
    int second;     // 0-59
} datetime_t;

datetime_t createDate(int timestamp){
    datetime_t t;
    int m[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int i;
    t.second = timestamp % 60;  
    timestamp /= 60;
    t.minute = timestamp % 60;  
    timestamp /= 60;
    t.hour = timestamp % 24;    
    timestamp /= 24;
    t.dayOfWeek = (timestamp + 4) % 7;
    timestamp++;
    for (i=1970; timestamp>365; i++) {
        if (i%4 == 0 && i%100 != 0 || i%400 == 0) {
            timestamp -= 366;
        }
        else {
            timestamp -= 365;
        }
    }
    if (i%4 == 0 && i%100 != 0 || i%400 == 0) {
        m[1]++;
    }
    t.year = i;
    i = 1;
    while (timestamp > m[i]) {
        timestamp -= m[i];
        i++;
    }
    t.month = i;
    t.date = timestamp;
    return t;
}

void printDate(datetime_t inputDate){
    char D[8][4] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    char M[14][4] = {"","JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
    printf("%s %d %s %d %02d:%02d:%02d",D[inputDate.dayOfWeek],inputDate.date,M[inputDate.month],inputDate.year,inputDate.hour,inputDate.minute,inputDate.second);
}

int main(){
    datetime_t inputDate;
    int timestamp;

    scanf("%d",&timestamp);
    inputDate = createDate(timestamp);
    printDate(inputDate);
    return 0;
}