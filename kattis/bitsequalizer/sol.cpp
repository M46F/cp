# include<iostream>
# include<climits>
# include<stdio.h>
# include <math.h>
#include <bits/stdc++.h> 

#define PI 3.14159265	

using namespace std;

int process(string S, string T, int idx, int len) {
	if (idx >= len) {
		return 0
	}
	else if (S[idx] == T[idx]) {
		return process(S, T, idx+1, len)
	} else {
		if S[idx]
	}
}

int main() {
	int n;
	scanf("%i\n", &n);	
	for (int i = 0; i < n; i++) {
		string S;
		string T;
		getline(cin, S);
		getline(cin, T);
		printf("Case %i: %i\n", i+1, -1);
		cout << S << " " << T<<endl;
		cout << "process"<< endl;
		process(S, T, 0);
		cout << S << " " << T<<endl;
		cout << "end"<< endl;
	}
	
    return 0;
}

