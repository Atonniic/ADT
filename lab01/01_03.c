#include <stdio.h>
int main () {
    int w, h;
    double bmi;
    scanf("%d %d" ,&w ,&h);
    bmi = w/ ((h/100.0) * (h/100.0));
    if (bmi >= 30) {
    printf("BMI: %.4f and you are obese" ,bmi);
    }
    else if (bmi >= 25) {
    printf("BMI: %.4f and you are overweight" ,bmi);
    }
    else if (bmi >= 18.6) {
    printf("BMI: %.4f and you are healthy" ,bmi);
    }
    else {
    printf("BMI: %.4f and you are underweight" ,bmi);
    }
    return 0;
}