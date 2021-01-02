# include<iostream>
# include<climits>
#include <stdio.h>
#include <math.h>
#include <string>
#include <bits/stdc++.h> 

#define PI 3.14159265	

using namespace std;


int main() {
	string str;
	getline(cin, str);
	int n = str.length();
	
	int i = 0;
	while (i < n) {
//		cout << i << endl;
		if (n - i >= 3) {
			bool combo = false;
			char out[3];
			
			bool R = false;
			bool B = false;
			bool L = false;
			
			for (int j = 0; j < 3; j++) {
				if (str[i+j] == 'R'){
					out[j] = 'S';
					R = true;
				} else if (str[i+j] == 'B') {
					out[j] = 'K';
					B = true;
				} else {
					out[j] = 'H';
					L = true;	
				}
			}
			if (R && B && L) {
				cout << 'C';
				combo = true;
				i += 3;
			} else {
				i += 1;
				cout << out[0];
			}
		} else {
			if (str[i] == 'R'){
					cout <<'S';
				} else if (str[i] == 'B') {
					cout <<'K';
				} else if (str[i] == 'L') {
					cout <<'H';
				}
	//		cout<< " " << i << str[i] << endl;
			i += 1;
		}
	}
	cout <<endl;
    return 0;
}

