#include <stdio.h>

int a[100001], n, m, edge[200001][3];

int graph(int x, int y) {
    int i;

    for (i=0; i<2*m; i++) {
        if (edge[i][0]==x && edge[i][1]==y) {
            return 1;
        }
    }
    return 0;
}

int is_clique(int b) {
    int i, j;

    for (i=1; i<b; i++) {
        for (j=i+1; j<b; j++) {
            if (!graph(a[i], a[j])) {
                return 0;
            }
        }
    }
    return 1;
}

int Maxclique(int i, int l){
    int mx = 0;
    int j;

    for (j=i+1; j<=n; j++) {
        a[l] = j;
        if (is_clique(l+1)) {
            if (l > mx) {
                mx = l;
            }
            int mxclique = Maxclique(j, l+1);
            if (mxclique > mx) {
                mx = mxclique;
            }
        }
    }
    return mx;
}

int main() {
    int i, u, v;

    scanf("%d %d", &n, &m);
    for (i=0; i<2*m; i+=2) {
        scanf("%d %d", &u, &v);
        u += 1; 
        v += 1;
        edge[i][0] = u;
        edge[i][1] = v;
        edge[i+1][0] = v;
        edge[i+1][1] = u;
    }
    printf("%d", Maxclique(0, 1));
    return 0;
}