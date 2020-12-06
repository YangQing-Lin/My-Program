#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    while (k--)
    {
        int j = 1;
        stack<int> stock;
        for (int i = 1; i <= n; i++)
        {
            int t;
            scanf("%d", &t);
            if (t != j)
            {
                stock.push(t);
                if (stock.size() > m)
                    break;
            }
            else
            {
                j++;
                while (!stock.empty() && stock.top() == j)
                {
                    stock.pop();
                    j++;
                }
            }
        }
        if (!stock.empty())
            printf("NO\n");
        else
            printf("YES\n");
    }
}