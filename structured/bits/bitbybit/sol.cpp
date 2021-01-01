# include<iostream>
# include<climits>
# include <stdio.h>
# include <math.h>
# include <string>
# include <bits/stdc++.h>

# define PI 3.14159265

using namespace std;


int main() {
    int N;
    while( scanf("%i/n", &N) != EOF){
        if(N < 1) {break;}
        char bits[32];
        for(int b = 0; b < 32; b++){ bits[b] = '?'; }
        for(int n = 0; n < N; n++){
            string cmd;
            int i;
            cin >> cmd >> i;
            if(cmd == "CLEAR") {
                bits[31-i] = '0';
                //cout << "clear" << " " << i << endl;
            } else if (cmd == "SET") {
                bits[31-i] = '1';
                //cout << "set" << " " << i << endl;
            } else if (cmd == "OR") {
                
                int j;
                cin >> j;

                if(bits[31-i] != '1') {
                    if (bits[31-j] == '1') {
                        bits[31-i] = '1';
                    } else if (bits[31-j] == '?') {
                        bits[31-i] = '?';
                    }
                }

            } else {
                int j;
                cin >> j;

                if(bits[31-i] != '0') {
                    if (bits[31-j] == '0') {
                        bits[31-i] = '0';
                    } else if (bits[31-j] == '?') {
                        bits[31-i] = '?';
                    }
                }
            }
        }
        for(int b = 0; b < 32; b++) {cout << bits[b];}
        cout << endl;
    }
    return 0;
}
