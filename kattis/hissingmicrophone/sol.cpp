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
	int _len = (int) str.length();
	
	bool hiss = false;
	if (_len >= 2) {
		for (int i = 1; i < _len; i++){
			if ( (str[i] == str[i-1]) && (str[i] == 's') ){hiss = true; break;}
		}

	}
	if (hiss) {
		cout << "hiss" << endl;		
	} else {
				cout << "no hiss" << endl;	
	}

    return 0;
}

