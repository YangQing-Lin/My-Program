#include<stdio.h>
int main() {
	int n, i, j, p, q, k, t;
	int arr[10005] = {0};
	char ch;
	scanf("%d", &n);
	getchar();
	for(i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		getchar();
	}
	scanf("%d", &k);
	getchar();
	//printf("#%d#\n", k);
	for(i = 0; i < k; i++) {
		scanf("%c %d %d %d", &ch, &p, &q, &t);
		getchar();
		//printf("^#%c# %d %d^\n", ch, p, q, t);
		for(j = p; j <= q; j++) {
			if(ch == '+') arr[j] += t;
			else if(ch == '-') arr[j] -= t;
			else arr[j] = t;
		}
	} 
	for(i = 0; i < n; i++) {
		if(i != 0) printf(" ");
		printf("%d", arr[i]);
	}
	return 0;
} 
/*
10
1 2 3 4 5 6 7 8 9 10
3
- 1 3 5
+ 8 10 2
= 3 6 0
*/
