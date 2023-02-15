#include <stdio.h>
#include <stdlib.h>

int ag[100][100], vg[100], ab[100][100], vb[100], tgc[100], tbc[100], ans[100];
int n, m, res, tg, tb, tempt;

void dfs1(int node, int *t){
    int i;
    
    vg[node] = 1;
    for (i=0; i<n; i++) {
        if (ag[node][i] && !vg[i]) {
            dfs1(i, t);
        }
    }
    tgc[node] = *t;
    (*t) += 1;
}

void dfs2(int node, int *t, int *l) {
    int i;

    vb[node] = 1;
    for (i=0; i<n;i++) {
        if (ab[node][i] && !vb[i]) {
            dfs2(i, t, l);
        }
    }
    tbc[node] = *t;
    l[*t - tempt] = node;
    (*t) += 1;
}

void sortres() {
    int i, j, tmp;
    for (i=0; i<res; i++) {
        for (j=i+1; j<res; j++) {
            if (ans[i] > ans[j]) {
                tmp = ans[i];
                ans[i] = ans[j];
                ans[j] = tmp;
            }
        }
    }
}

int main() {
    int i, j, *l = malloc(sizeof(int)*100);

    scanf("%d %d",&n,&m);
    for (i=0; i<m; i++){
        int u, v;

        scanf("%d %d", &u, &v);
        ag[u][v] = 1;
        ab[v][u] = 1;
    }
    for (i=0; i<n; i++) {
        if (!vg[i]) {
            dfs1(i, &tg);
        }
    }
    for (i=0; i<n; i++) {
        int mxt = 0, idx = -1;

        for (j=0; j<n; j++) {
            if(!vb[j] && tgc[j] > mxt){
                mxt = tgc[j];
                idx = j;
            }
        }
        if (idx == -1) {
            break;
        }
        tempt = tb;
        dfs2(idx, &tb, l);

        int sz = tb - tempt;

        if (res < sz) {
            res = sz;
            for (j=0; j<sz; j++) {
                ans[j] = l[j];
            }
        }
    }
    sortres();
    for(i=0; i<res; i++){
        printf("%d ", ans[i]);
    }
}