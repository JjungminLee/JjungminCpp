#include <bits/stdc++.h>

using namespace std;
int r,c,k;
int ans=0;
int arr[101][101];
int rowCnt=3;
int colCnt=3;

void colCompare(){
    for(int i=1;i<=colCnt;i++){
        /*첫 번째 인자 기준으로 오름차순 정렬,
        같다면 두 번째 인자 기준으로 오름차순 정렬*/
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int>v;
        int nRowCnt=1;
        for(int j=1;j<=rowCnt;j++){
            int std = arr[j][i];
            bool flag=true;
            for(int k=0;k<v.size();k++){
                if(v[k]==std){
                    //이미 방문한애
                    flag=false;
                    
                }
            }
            if(flag){
                v.push_back(std);
                int cnt=0;
                for(int k=1;k<=rowCnt;k++){
                        if(std==arr[k][i]){
                            cnt++;
                        }
                }
                // 횟수,숫자
                pq.push({cnt,std});
            }
             cout<<"col"<<endl;
            for(int k=0;k<v.size();k++){
                cout<<v[k]<<" ";
            }
            while(!pq.empty()){
                int num = pq.top().second;
                int numCnt = pq.top().first;
                // cout<<"col"<<endl;
                // cout<<"num: "<<num<<"numCnt: "<<numCnt<<endl;
                pq.pop();
                arr[i][nRowCnt]=num;
                nRowCnt+=1;
                arr[i][nRowCnt]=numCnt;
                nRowCnt+=1;

            }
            rowCnt=max(rowCnt,nRowCnt);
            

        }
       
    }

}

void rowCompare(){
    for(int i=1;i<=rowCnt;i++){
        /*첫 번째 인자 기준으로 오름차순 정렬,
        같다면 두 번째 인자 기준으로 오름차순 정렬*/
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int>v;
        int nColCnt=1;
        for(int j=1;j<=colCnt;j++){
            int std = arr[i][j];
            bool flag=true;
            for(int k=0;k<v.size();k++){
                if(v[k]==std){
                    //이미 방문한애
                    flag=false;
                    
                }
            }
            if(flag){
                v.push_back(std);
                int cnt=0;
                for(int k=1;k<=colCnt;k++){
                        if(std==arr[i][k]){
                            cnt++;
                        }
                }
                // 횟수,숫자
                pq.push({cnt,std});
            }
            cout<<"row"<<endl;
            for(int k=0;k<v.size();k++){
                cout<<v[k]<<" ";
            }
            cout<<endl;
            while(!pq.empty()){
                int num = pq.top().second;
                int numCnt = pq.top().first;
                // cout<<"row"<<endl;
                // cout<<"num: "<<num<<"numCnt: "<<numCnt<<endl;
                pq.pop();
                arr[i][nColCnt]=num;
                nColCnt+=1;
                arr[i][nColCnt]=numCnt;
                nColCnt+=1;

            }
            colCnt=max(colCnt,nColCnt);
            

        }
       
    }
    

}
int main(){
    cin>>r>>c>>k;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cin>>arr[i][j];
        }
    }
    while(true){
        if(arr[r][c]==k){
            break;
        }
        if(ans>100){
            cout<<-1<<endl;
            break;
        }
        ans++;
        if(rowCnt>=colCnt){
            rowCompare();
        }else{
            colCompare();
        }
        cout<<"ans: "<<ans<<endl;
        cout<<"rowCnt: "<<rowCnt<<"colCnt: "<<colCnt<<endl;
        for(int i=1;i<=rowCnt;i++){
            for(int j=1;j<=colCnt;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    cout<<ans<<endl;

}