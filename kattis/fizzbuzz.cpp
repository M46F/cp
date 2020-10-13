# include<iostream>
# include<climits>

using namespace std;


int main() {
	int left = 0;
	int right = 0;
	int total = 0;
	scanf("%i %i %i", &left, &right, &total);
	for(int i = 0; i < total; i++) {
		int x = i + 1;
		if (x%left == 0 && x%right == 0) {
			printf("FizzBuzz\n");
		} else if (x%left == 0) {
			printf("Fizz\n");
		} else if (x%right == 0) {
			printf("Buzz\n");
		} else {
			printf("%i\n", x);
		}
	}
    return 0;
}
