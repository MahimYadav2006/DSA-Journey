#include<bits\stdc++.h>
using namespace std;
int countPrimes(int n){
    int count=0;
    vector<bool>prime(n+1,true);
    prime[0]=false;
    prime[1]=false;
    for(int i=2;i<n;i++){
        if(prime[i]){
            count++;
            for(int j=2*i;j<n;j=j+i){
                prime[j]=false;
            }
        }
    }
    return count;
}
gcd(int a,int b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    
    while(a!=b){
        if(a>b){
            a=a-b;
        }
        else{
            b=b-a;
        }
    }
    return a;
}
int digitSum(int n){
    int sum=0;
    while(n!=0){
        sum+=n%10;
        n=n/10;
    }
    return sum;
}
int main(){
    // cout<<countPrimes(10);
    // cout<<gcd(72,24);
    int n=11;
    int count=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                if(i+j+k==n){
                    int isum=digitSum(i);
                    int jsum=digitSum(j);
                    int ksum=digitSum(k);
                    if(isum+jsum+ksum==digitSum(n)){
                        count++;
                        // cout<<i<<" "<<j<<" "<<k<<endl;
                    }
                }
            }
        }
    }
    cout<<count;

    
}