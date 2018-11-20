//amitgomi
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

#define N 8
#define P 4
int pop[P][N];

int display(){
    for(int i=0;i<N;i++){
        cout<<i+1<<" ";
        for(int j=0;j<P;j++){
            for(int k=0;k<N;k++){
                if(pop[j][k]==i)
                    cout<<"* ";
                else 
                    cout<<". ";
            }
            cout<<"    ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    return 0;
}


int construct(){
    for(int i=0;i<P;i++){
        for(int j=0;j<N;j++){
            
            pop[i][j]=(rand())%N;
        }
    }
    return 0;
}

int fitness(int a){
    int res=0;
    
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            int x1=i,x2=j,y1=pop[a][i],y2=pop[a][j];
            if(x1==x2 ||y1==y2 || (abs(x1-x2)==abs(y1-y2)))
                res+=0;
            else res+=1;
        }
    }
    return res;
}
pair<int,int>  paren(){
    pair<int,int>  p;
    int ar[P+1]={0};
    int sum=0;
    for(int i=0;i<P;i++){
        ar[i]=fitness(i);
        sum+=ar[i];
    }
    cout<<endl;
    int r=rand()%sum;
    int s2=0;
    for(int i=0;i<P;i++){
        s2+=ar[i];
        if(r<s2){
            p.first=i;
            break;
        }
    }
    p.second=p.first;
    s2=0;
    while(p.second==p.first){
        r=rand()%sum;
        s2=0;
        for(int i=0;i<P;i++){
            s2+=ar[i];
            if(r<s2){
                p.second=i;
                break;
            }
        }
    }
    return p;
}
int reproduce(int x1,int x2,int child[]){
    
    int part=rand()%N;
    int i=0;
    for(i=0;i<part;i++){
        child[i]=pop[x1][i];
    }
    for(;i<N;i++){
        child[i]=pop[x2][i];
    }
    return 0;
}
int mutate(int child[]){
    int a=rand()%N;
    int b=rand()%N;

    child[a]=b;
    return 0;
}
int checkgoal(){
    int res=-1;
    int ar[P+1]={0};
    for(int i=0;i<P;i++){
        ar[i]=fitness(i);
        if(ar[i]==(N*(N-1))/2)
            return i;
    }
    return res;
}
int galgo(){
    while(1){
        int newpop[P][N];
        for(int i=0;i<P;i++){
            int x1,x2;
            pair<int,int>  p=paren();
            x1=p.first;
            x2=p.second;

            int child[N];
            reproduce(x1,x2,child);

            if((rand()%100) < 10){
                mutate(child);
            }
            for(int j=0;j<N;j++){
                newpop[i][j]=child[j];
            }
        }

    cout<<"fitness"<<endl<<"  ";
        for(int i=0;i<P;i++){
            for(int j=0;j<N;j++){
                pop[i][j]=newpop[i][j];
            }
    cout<<fitness(i)<<"                  ";
        }
        cout<<endl;

        int x=checkgoal();
        if(x!=-1){
            return x;
            break;
        }
        display();
    }
    return 0;
}

int main(){
    //srand(3);
    int t;
    construct();
    display();
    int ans=0;
    ans=galgo();
    cout<<"ans is "<<ans<<endl;
    display();

    return 0;
}