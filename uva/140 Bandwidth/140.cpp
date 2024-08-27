#include <bits/stdc++.h>
#include <cstring>
using namespace std;

bool adjmat[26][26];
int computeBandwidth(char order[]) {
    int bandwidth = 0;
    for(int ui = 0; order[ui] != '\0'; ui++) {
        for(int vi = ui+1; order[vi] != '\0'; vi++) {
            int u = order[ui] - 'A';
            int v = order[vi] - 'A';
            if(adjmat[u][v]) {
                int val = vi - ui;
                if(val > bandwidth) bandwidth = val;
            }
        }
    }
    return bandwidth;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("errors.txt", "w", stderr);
#endif

    char str[27];
    while(true) {
        scanf("%s", str);
        if(str[0] == '#') break;

        int n = (int)strlen(str);

        for(int u = 0; u < 26; u++)
            for(int v = 0; v < 26; v++)
                adjmat[u][v] = false;

        // PREPARING THE INPUT //////////////////////////////////////////////////////
        int present[26] = {0};
        char delim[] = ";";
        char order[27];
        char *token = strtok(str, delim);

        while (token != NULL) {
            int u = token[0] - 'A';
            present[u] = 1;
            for(int i = 2; token[i] != '\0'; i++) {
                int v = token[i] - 'A';
                present[v] = 1;
                adjmat[u][v] = true, adjmat[v][u] = true;
            }

            token = strtok(NULL, delim);
        }

        int listLen = 0;
        for(int i = 0; i < 26; i++) if (present[i]) order[listLen++] = (char) ('A' + i);
        order[listLen] = '\0';

        int minB = -1;
        char res[27];
        do {
            int currB = computeBandwidth(order);
            if(minB < 0 || currB < minB) minB = currB, strcpy(res, order);
        } while(next_permutation(order, order+strlen(order)));

        for(int i = 0; res[i] != '\0'; i++) printf("%c ", res[i]);
        printf("-> %d\n", minB);
    }

    return 0;
}
