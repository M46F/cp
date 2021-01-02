# include<iostream>
# include<climits>
# include<stdio.h>
# include <math.h>


#define PI 3.14159265	

using namespace std;


int main() {
	double p, a, b, c, d;
	int n;
	scanf("%lf %lf %lf %lf %lf %i", &p, &a, &b, &c, &d, &n);
	double prices[n];
	for (int i = 0; i < n; i++) {
		int k = 1 + i;
		prices[i] = p * (sin(a * k + b) + cos(c* k + d) + 2);
	}
	
	
	double decline = 0.0;
	double cur_max = prices[0];
	for (int i = 1; i < n; i++) {
		double tmp = cur_max - prices[i];
		if  (tmp > decline) {decline = tmp;}
		if  (prices[i] > cur_max) {cur_max = prices[i];}
	}	
	printf("%.20g\n", decline);
    return 0;
}

