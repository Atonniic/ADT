#include <stdio.h>
#include <math.h>

int f(int w, int l) {
    int i, k, temp; 
    double r;
    if (w > l) {
        temp = w;
        w = l;
        l = temp;
    }

    r = log(l)/log(2);
    if (w == 0) {
        return 0;
    }
    if (w == 1) {
        return l;
    }
    for (i=r; i>=0; i--) {
        if (w >= pow(2, i)) {                
            k = pow(2, i);
            break;
        }
    }
    return 1+f(k, l-k)+f(w-k,l);
}

int main() {
    int w, l;
    scanf("%d %d", &w, &l);
    printf("%d", f(l, w));
}
//O(log(n))