#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#include<unordered_set>
#define ull unsigned long long
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int k = 0; k < n; k++) {
        int n, m, max_happy = -1, max_index = 2000000000;
        cin >> n >> m;
        vector<int> happy(n+1);
        vector<unordered_set<int> > book(n+1);
        for(int i = 1; i <= n; i++) {
            cin >> happy[i];
            if(max_happy < happy[i]) {
                max_happy = happy[i];
                max_index = i;
            }
        }
        for(int i = 1; i <= n-1; i++) {
            int a, b;
            cin >> a >> b;
            book[a].insert(b);
            book[b].insert(a);
        }
        // imput finish
        while (m > 0) {
            int temp_max_index = max_index;
            int next_max = 0, next_idnex = 2000000000;
            bool is_equals = false;
            for (auto it = book[temp_max_index].begin(); it != book[temp_max_index].end(); it++) {
                if(*it != temp_max_index) {
                    if (happy[*it] == happy[temp_max_index]
                    && *it < temp_max_index) {
                        if(is_equals == false) next_idnex = *it;
                        else if(*it < next_idnex) next_idnex = *it;
                        is_equals = true;
                    } 
                    else if (is_equals == false
                    && happy[*it] != happy[temp_max_index]
                    && next_max < happy[*it]) {
                        next_max = happy[*it];
                        next_idnex = *it;
                    }
                }
            }
            if(happy[next_idnex] != happy[temp_max_index]) {
                int count = happy[temp_max_index] - happy[next_idnex];
                m -= count;
                for (auto it = book[temp_max_index].begin(); it != book[temp_max_index].end(); it++) {
                    if(*it != temp_max_index) {
                        happy[*it] += count;
                    }
                }
            }
            next_idnex = 2000000000;
            for (auto it = book[temp_max_index].begin(); it != book[temp_max_index].end(); it++) {
                if(*it != temp_max_index 
                && happy[*it] == happy[temp_max_index]) {
                    happy[*it]++;
                }
            }
            m--;
            cout << "h";
            // for (auto it = book[temp_max_index].begin(); it != book[temp_max_index].end(); it++) {
            //     happy[*it]++;
            //     if (max_happy < happy[*it]) {
            //         max_happy = happy[*it];
            //         max_index = *it;
            //     } else if (max_happy == happy[*it]) {
            //         max_index = min(max_index, *it);
            //     }
            // }
        }
        // cout << max_index << endl;
        printf("#%d#\n", max_index);
    }
    return 0;
}