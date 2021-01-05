# include<iostream>
# include<climits>
# include <stdio.h>
# include <math.h>
# include <string>
# include <bits/stdc++.h>

# define PI 3.14159265

using namespace std;


int main() {
    int arr[26];
    int N;
    scanf("%i\n", &N);


    for(int i = 0; i < N; i++){
        char tmp;
        cin >> tmp;
        if (tmp == 'T') {
            arr[i] = 1;
        } else {
            arr[i] = 0;
        }
    }
/*    for(int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
*/
    stack<int> value;



    string cmd_str;
    getline(cin, cmd_str);

    getline(cin, cmd_str);
    for(int i = 0; i < cmd_str.length(); i++){
        char cmd = cmd_str[i];
        if(cmd != ' ') {
            if(cmd == '+') {
                int a = value.top();
                value.pop();
                int b = value.top();
                value.pop();
               // cout << a << "+" << b;
                value.push(min(a+b,1));
                //cout << value.top() << endl;
            } else if (cmd == '*') {
                int a = value.top();
                value.pop();
                int b = value.top();
                value.pop();
                //cout << a << "*" <<b;
                value.push(a*b);
                //cout << value.top() << endl;
            } else if (cmd == '-') {
                int a = value.top();
                //cout << a << "-";
                value.pop();
                if (a == 0){
                    value.push(1);
                } else {
                    value.push(0);
                }
                //cout << value.top() << endl;
            } else {
                value.push(arr[cmd-65]);
                //cout << cmd << " " << arr[cmd-65] << endl;
            }
        }
    }
    if (value.top() == 0) {
        cout << "F";
    }else {
        cout << "T";
    }
    cout << endl;
    //cout << cmd_str << endl;

    return 0;
}
