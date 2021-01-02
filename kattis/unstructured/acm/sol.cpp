# include<iostream>
# include<climits>
# include<stdio.h>
# include <math.h>
#include <bits/stdc++.h> 

#define PI 3.14159265	

using namespace std;


int main() {
	
	int minute;
	char c;
	char row[6];
	
	map<char, int> m;
	map<char, bool> correct;
	
	while (scanf("%i %c %5s", &minute, &c, row) == 3) {
		
		if ( m.find(c) == m.end() ) {
			m[c] = 0;
			correct[c] = false;
		}
		
		if (row[0] == 'r' ) {
			m[c] += minute;
			correct[c] = true;
		} else {
			m[c] += 20;
		}
	}
	
	int out = 0;
	int minutes = 0;
	
	for (auto const& x : correct) {
		char key = x.first;
		bool val = x.second;
		if (val) {
			out += 1;
			minutes += m[key]; 
		}
	}
	cout << out << " " << minutes << endl;
    return 0;
}

