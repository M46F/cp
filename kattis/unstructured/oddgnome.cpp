# include<iostream>
# include<climits>

using namespace std;


int main() {
	int N;
	scanf("%i", &N);
	
	for(int i = 0; i < N; i ++) {
		int tot;
		scanf("%i", &tot);
		
		int lastpass;
		int king = -1;
		for (int c = 0; c < tot; c ++) {
			int current;
			scanf("%i", &current);
			if (c == 0) {lastpass = current; continue;}
			else if (c == tot - 1) {lastpass = current; continue;}
			else {
				if (current - lastpass != 1 &&  king == -1) {
					king = c + 1;
				}
				lastpass = current;
			}
		}
		printf("%i\n", king);
	}
	
    return 0;
}
