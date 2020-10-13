# include<iostream>
# include<climits>

using namespace std;


int main() {
	int a1, a2, b1, b2;
	while (scanf("%i %i %i %i", &a1, &a2, &b1, &b2) == 4) {
		if ((a1 == a2) && (a2 == b1) && (b1==b2) && (b2 == 0) ) {
			break;
		}
		int p1 = -1;
		int p2 = -1;
		
		if((a1==1 && a2==2) || (a2==1 && a1==2)) {
			p1 = 200;
		} else if (a1 == a2) {
			p1 = 100 + a1;
			
		} else {
			p1 = max(a1, a2) *10 + min(a1, a2);
		}
		
		if((b1==1 && b2==2) || (b2==1 && b1==2)) {
			p2 = 200;
		} else if (b1 == b2) {
			p2 = 100 + b1;
			
		} else {
			p2 = max(b1, b2) * 10 + min(b1, b2);
		}

		if (p1 > p2) {
			printf("Player 1 wins.\n");
		} else if (p2 > p1) {
			printf("Player 2 wins.\n");			
		} else {
			printf("Tie.\n");
		}		
	}

	
/*	
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
	*/
    return 0;
}
