# include<iostream>
# include<climits>
# include <stdio.h>
# include <math.h>
# include <string>
# include <bits/stdc++.h>

# define PI 3.14159265

using namespace std;


struct Teque {
    long left;
    long right;
    deque<long> lque;
    deque<long> rque;
};

void check(Teque& tq){
    if (tq.right != tq.left) {
        while (tq.left > tq.right) {
            tq.rque.push_front(tq.lque.back());
            tq.lque.pop_back();
            tq.left -= 1;
            tq.right += 1;
        }

        while (tq.right > tq.left) {
            long front_right = tq.rque.front();
            tq.lque.push_back(front_right);
            tq.rque.pop_front();
            tq.left += 1;
            tq.right -= 1;
        }
    }
}


void push_back(Teque& tq, long val){
    tq.rque.push_back(val);
    tq.right += 1;
    check(tq);
}


void push_front(Teque& tq, long val) {
    tq.left += 1;
    tq.lque.push_front(val);
    check(tq);
}


void push_middle(Teque& tq, long val) {
    if (tq.left > tq.right){
        tq.rque.push_front(val);
        tq.right += 1;
    } else {
        tq.lque.push_back(val);
        tq.left += 1;
    }
    check(tq);
}


long get(Teque& tq, long idx) {
    if(idx >= tq.left) {
        return tq.rque.at(idx-tq.left);
    } else {
        return tq.lque.at(idx);
    }
}


int main(){
    deque<long> lque;
    deque<long> rque;
    struct Teque tq = {0,0, lque, rque};

    long N;
    scanf("%ld\n", &N);
    for(long i = 0; i < N; i++){
        string cmd;
        long val;
        cin >> cmd >> val;
        if(cmd == "push_back"){
            push_back(tq, val);
        } else if (cmd == "push_front") {
            push_front(tq, val);
        } else if (cmd == "push_middle") {
            push_middle(tq, val);
        } else {
            cout << get(tq, val)<<endl;
        }
    }

    return 0;
}
