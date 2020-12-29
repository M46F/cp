# include<iostream>
# include<climits>
#include <stdio.h>
#include <math.h>
#include <string>
#include <bits/stdc++.h>

#define PI 3.14159265

using namespace std;


void sol(char *str1, char *str2, int n) {

    int r = 0;
    int s = 0;

    std::map<char, int> h1;
    std::map<char, int> h2;

    for( int i = 0; i < n; i++) {
        if(str1[i] == str2[i]) {
            r += 1;
        } else {
            char c1 = str1[i];
            char c2 = str2[i];

            if (h1.find(c1) == h1.end()) {
                h1[c1] = 1;
            } else {
                h1[c1] += 1;
            }

            if (h2.find(c2) == h2.end()) {
                h2[c2] = 1;
            } else {
                h2[c2] += 1;
            }
        }
    }

    for (const auto& o1 : h1) {
        if (h2.find(o1.first) != h2.end() ) {
            int tmp = std::min(h1[o1.first], h2[o1.first]);
            s += tmp;
            h1[o1.first]  = h1[o1.first] - tmp;
            h2[o1.first]  = h2[o1.first] - tmp; 
        }
    }

    for (const auto& o1 : h2) {
        if (h1.find(o1.first) != h1.end() ) {
            int tmp = std::min(h1[o1.first], h2[o1.first]);
            s += tmp;
            h1[o1.first]  = h1[o1.first] - tmp;
            h2[o1.first]  = h2[o1.first] - tmp;
        }
    }

    /*for (const auto& o1 : h2) {
        cout << o1.first << " " << h2[o1.first] << endl;
    }
    cout << "uwuwuwu" << endl;
    for (const auto& o1 : h1) {
        cout << o1.first << " " << h1[o1.first] << endl;
    }

    cout << n<< endl;
    for( int i = 0; i < n; i++) {cout << str1[i];}
    cout << endl;
    for( int i = 0; i < n; i++) {cout << str2[i];}*/

    cout << r << " " << s << endl;
}
int main() {
    int n;
    scanf("%i", &n);
    if (n > 0) {
        char str1[n];
        char str2[n];
        scanf("%s ", str1);
        scanf("%s ", str2);

        sol(str1, str2, n);
    } else {
        cout << 0 << " " << 0 << endl;
    }


    return 0;
}
