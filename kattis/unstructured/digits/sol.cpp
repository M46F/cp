# include<iostream>
# include<climits>
# include<stdio.h>
# include <math.h>


#define PI 3.14159265	

using namespace std;


int main() {
	int x;
	while( scanf("%i", &x) == 1) {
		printf("%i\nuwu\n", x);
		int out = 0;
		while (true) {
			int digit = floor(log10(x)) + 1;
			out++;	
			if (digit == x) {
				break;
			}
			x = digit;
		}
		
		printf("%i\n", out);
	}
    return 0;
}

