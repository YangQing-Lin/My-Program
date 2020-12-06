#include<stdio.h>
#include<math.h>
int main(void) {
	int number = 100;
	int* p_one = &number;
	int** p_two = &p_one;
	int*** p_three = &p_two;
	printf("point p_two = %p\n", p_two);
	printf("point p_two = %p\n", *p_two);
	printf("point p_two = %d\n", **p_two);
	printf("point p_one = %p\n", p_one);
	printf("point p_one = %d\n", *p_one);
	printf("point p_three = %p\n", p_three);
	printf("point p_three = %p\n", *p_three);
	printf("point p_three = %p\n", **p_three);
	printf("point p_three = %d\n", ***p_three);
	int* point[10] = {NULL};
	int** point_2[10] = {NULL};
	point[0] = &number;
	for(int i = 1; i < 10; i++) {
		point_2[i] = &point[i - 1];
	}
	for(int i = 1; i < 10; i++) {
		printf("point[%d] = %p\n", i, point[i]);
	}
	for(int i = 1; i < 10; i++) {
		printf("point_2[%d] = %p\n", i, point_2[i]);
	}
	return 0;
} 