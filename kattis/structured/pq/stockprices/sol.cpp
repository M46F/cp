# include<iostream>
# include<climits>
# include <stdio.h>
# include <math.h>
# include <string>
# include <bits/stdc++.h>

# define PI 3.14159265

using namespace std;

struct sellStock {
    int val;
    int ct;
    bool operator<(const sellStock & o) const {
         if(val != o.val) {
            return val > o.val;
        } else {
            return ct > o.ct;
        }
    }
    
};



struct buyStock {
    int val;
    int ct;
    bool operator<(const buyStock & o) const {
         if(val != o.val) {
            return val < o.val;
        } else {
            return ct > o.ct;
        }
    }
    
};

int main(){

    priority_queue<sellStock> sells;
    priority_queue<buyStock> buys;
    

    int TC;
    scanf("%i\n", &TC);
    for(int t = 0; t < TC; t++){
        
        int N;
        scanf("%i\n", &N);

        sells = priority_queue <sellStock>();
        buys = priority_queue <buyStock>();

        int last = -1;
        for(int n = 0; n < N; n++){
            string cmd, gb1, gb2;
            int ct, val;
            cin >> cmd >> ct >> gb1 >> gb2 >> val;
            if(cmd == "buy") {
                buys.push(buyStock{val, ct});
            } else if (cmd == "sell") {
                sells.push(sellStock{val, ct});
            }


            if(!sells.empty() && !buys.empty()){
               sellStock curr_sell = sells.top();
               buyStock curr_buy = buys.top();

           //         cout << "before transaction =  buy: " << buys.size() << " " << curr_buy.ct << " " << curr_buy.val << " sell: " << sells.size() << " " << curr_sell.ct << " " << curr_sell.val << endl;
               while(curr_sell.val <= curr_buy.val) {
                    last = curr_sell.val;
                    
                    buys.pop();
                    sells.pop();


                    int buy_ct =  min(curr_buy.ct, curr_sell.ct);
                    curr_sell.ct -= buy_ct;
                    curr_buy.ct -= buy_ct;
//                    cout << "after transaction =  buy: " << buys.size() << " " << curr_buy.ct << " " << curr_buy.val << " sell: " << sells.size() << " "  << curr_sell.ct << " " << curr_sell.val << endl;
                    if (curr_buy.ct > 0){
                        buys.push(buyStock{curr_buy.val, curr_buy.ct});
                    }
                    if (curr_sell.ct > 0) {
                        sells.push(sellStock{curr_sell.val, curr_sell.ct});
                    }
                    if(!sells.empty() && !buys.empty()){
                        curr_sell  = sells.top();
                        curr_buy = buys.top();
                    } else {
                        break;
                    }
               }
            }

            
            if(sells.empty()){
                cout << "-";
            }else {
                cout << sells.top().val;
            }
            
            if(buys.empty()){
                cout << " - ";
            } else {
                cout << " " << buys.top().val << " ";
            }

            if(last < 0) {
                cout << "-";
            } else {
                cout << last;
            }
            cout << endl;

            //cout << cmd << " ct: " << ct <<  " val: " << val << endl;
        }
    }

    return 0;
}
