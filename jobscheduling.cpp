#include<bits/stdc++.h>
using namespace std;

void jobScheduling(priority_queue<pair<int, pair<int,int>>> &q, vector<bool> &done){

    int min_days = 0;
    int max_profit = 0;

    cout << "Job Sequence : " << "\n";
    cout << "ID" << " " << "Deadline" << " " << "Profit" << "\n";

    while( !q.empty() ){
       
       pair<int, pair<int,int>> data = q.top();

       int curr_profit = data.first;
       int curr_id = data.second.first;
       int curr_deadline = data.second.second;


       q.pop();

        if(!done[curr_deadline]){
            done[curr_deadline] = true;
            min_days++;
            max_profit += curr_profit; 

            cout << curr_id  << " "<< curr_deadline << " " << curr_profit << "\n";
        }
        else{
            for(int i = curr_deadline - 1; i >= 0; i--){
                if(!done[i]){
                    done[i] = true;
                    min_days++;
                    max_profit += curr_profit;

                    cout << curr_id  << " "<< curr_deadline << " " << curr_profit << "\n";
                    
                    break;
                }
            }
        }
    }   

    cout << "\n";
    cout << min_days << " " << max_profit << "\n";
    
}


int main(){


    int jobs;
    cout << "Enter number of jobs : ";
    cin >> jobs ;

    priority_queue<pair<int, pair<int,int>>> q;

    int maxi = INT_MIN;
    
    cout << "Enter id deadline and profit : " << "\n";
    for(int i = 1; i <= jobs; i++){
        int id, deadline, profit;
        cin >> id >> deadline >> profit;

        if(deadline > maxi) maxi = deadline;
        q.push(make_pair(profit,make_pair(id,deadline)));
    }

    vector<bool> done(maxi+1, false);
    done[0] = true;

    jobScheduling(q,done);


    return 0;
}