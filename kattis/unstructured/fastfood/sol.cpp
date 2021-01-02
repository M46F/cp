# include<iostream>
# include<climits>
# include<stdio.h>
# include <math.h>
#include <bits/stdc++.h> 

#define PI 3.14159265	

using namespace std;


int main() {
	int N;
	scanf("%i\n", &N);	
	for (int i = 0; i < N; i++) {
		int n, m;
		scanf("%i %i\n", &n, &m);
		int prices[n];
		int stickers[m];
		
		map<int, vector<int>> vis;
		

		for (int j = 0; j < n; j++) {
			int k;
			scanf("%i ", &k);
			vector<int> vect;
			for (int l = 0; l < k; l++){
				int tmp;
				scanf("%i ", &tmp);
				vect.push_back(tmp);
			}
			vis[j] = vect;
			scanf("%i\n", &prices[j]);
		}
		for (int j = 0; j < m; j++) {
			scanf("%i", &stickers[j]);			
		}
		
		int out = 0;
		for (auto const& x : vis) {
			int idx = x.first;
			vector<int> vect = x.second;
			
			int curr_min = INT_MAX;
			for(int sticker : vect) {
				curr_min = min(curr_min, stickers[sticker-1]);
			}
			out += prices[idx] * curr_min;
		}
		cout << out << endl;

	}
	
    return 0;
}

