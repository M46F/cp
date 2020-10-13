# include<iostream>
# include<climits>

using namespace std;


int main() {
	int c = 0;
	int n = 0;
	while(scanf("%i", &n) == 1) {
		c++;
		int _max = INT_MIN + 1;
		int _min = INT_MAX - 1;
		for (int col = 0; col < n; col ++) {
			int curr = 0;
			scanf("%i", &curr);
			if (curr < _min) {
				_min = curr;
			}
			if (curr > _max) {
				_max = curr;
			}
		}
		printf("Case %i: %i %i %i\n", c, _min, _max, _max - _min);
	}
    return 0;
}
