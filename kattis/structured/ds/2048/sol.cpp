# include<iostream>
# include<climits>
# include <stdio.h>
# include <math.h>
# include <string>
# include <bits/stdc++.h>

# define PI 3.14159265

using namespace std;

void rotate(int arr[4][4]){
    int L = 4;

    for(int outer = 0; outer < L / 2; outer ++){
        for(int i = outer; i < L - outer - 1; i++){
            int tmp = arr[outer][i];
            arr[outer][i] = arr[i][L-1-outer];
            arr[i][L-outer-1] = arr[L-outer-1][L-i-1];
            arr[L-outer-1][L-i-1] = arr[L-i-1][outer];
            arr[L-i-1][outer] = tmp;
        }
    }
}


int main() {
    int arr[4][4];
    for(int r = 0; r < 4; r++){
        for(int c = 0; c < 4; c++){
            scanf("%i", &arr[r][c]);
        }
    }

    int n;
    scanf("%i", &n);
    
    for(int rot = 0; rot < n; rot ++) { rotate(arr); }
        for(int r = 0; r < 4; r++){
            
            pair<int, int> idxval(0, arr[r][0]);

            for(int c = 1; c < 4; c++){
                if (arr[r][c] > 0) {
                    if (idxval.first == -1) {
                        idxval.first = c;
                        idxval.second = arr[r][c];
                    }else if(arr[r][c] == idxval.second) {
                        arr[r][idxval.first] = idxval.second * 2;
                        arr[r][c] = 0;

                        idxval.first = -1;
                        idxval.second = -1;
                    } else {
                        idxval.first = c;
                        idxval.second = arr[r][c];
                    }
                }
            }
            int curidx = 0;
            for(int c = 0; c < 4; c++) {
                if (arr[r][c] > 0) {
                    if (curidx == c){
                        curidx += 1;
                    } else {
                        arr[r][curidx] = arr[r][c];
                        arr[r][c] = 0;
                        curidx = c;
                    }
                }
             }
        }

    for(int rot = 0; rot < 4-n; rot ++) { rotate(arr); }
    
    for (int r = 0; r < 4; r++){
        for(int c = 0; c < 4; c++){
            cout << arr[r][c];
            if(c < 3){
                cout << " ";
            }
        }
        cout << endl;
    }


    return 0;
}
