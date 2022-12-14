#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/* さいしょうにじょうマシン */
/* 100個以下のデータの最小二乗法の回帰直線の切片・傾きを求めることができます． */

void LS(double x_i[100],double y_i[100], int kosuu) {
	int i;
	double sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0,a,b;
	for (i = 0; i < kosuu; i++) {
		sumx += x_i[i];
		sumx2 += x_i[i] * x_i[i];
		sumy += y_i[i];
		sumxy += x_i[i] * y_i[i];
	}
	a = (kosuu * sumxy - sumx * sumy) / (kosuu * sumx2 - sumx * sumx);
	b = (sumx2 * sumy - sumxy * sumx) / (kosuu * sumx2 - sumx * sumx);
	printf("a= %f ,b= %f\n", a, b);
}
int main(void) {
	double x_i[100] = { 0 }, y_i[100] = { 0 };
	int a;
	printf("y=ax+b型の回帰曲線の傾き，切片を求めます．\n");
	printf("データの個数: ");
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		printf("%d個めのx:",i+1);
		scanf("%lf", &x_i[i]);
		printf("%d個めのy:",i+1);
		scanf("%lf", &y_i[i]);
	}
	printf("最小二乗マシン起動!\n");
	LS(x_i, y_i,a);
	return0;
}
