#include <iostream>
using namespace std;
float power(int a,int b){
    float ans=1;
    if(b>=0){
        for(int i=0;i<b;i++){
            ans*=a;
        }
    }
    if(b<0){
        b=-b;
        for(int i=0;i<b;i++){
            ans/=a;
        }
    }
return ans;
}


bool is_even(){
    int a;
    cin>>a;
    if(a%2==0){
        return true;
    }
    else{
        return false;
    }
}

int factorial(int a){
    int product=1;
    for(int i=a;i>0;i--){
        product*=i;
    }
    return product;
}
float bino(){
    int n,r;
    cin>>n>>r;
    return (factorial(n)/(factorial(r)*factorial(n-r)));
}

void counting(int a){
    for(int i=1;i<=a;i++){
        cout<<i<<endl;
    }
}

bool is_prime(){
    int a;
    cin>>a;
    if(a==0 | a==1){
        return true;
    }
    if(a<0){
        a=-a;
    }
    for(int i=2;i<a;i++){
        if(a%i==0){
            return false;
        }
    }
    return true;
}

int AP(int n){
    return 3*n+7;
}

int setBits(int a,int b){
    int count=0;
    while(a!=0){
        if(a&1==1){
            count++;
        }
        a=a>>1;
    }
    while(b!=0){
        if(b&1==1){
            count++;
        }
        b=b>>1;
    }
    return count;
}

int fibonacci_series(int n){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    if(n>2){
        return fibonacci_series(n-1)+fibonacci_series(n-2);
    }
}
int main(){
    // int num=2;
    // switch(num){
    //     case 1:cout<<"I am one."<<endl;
    //             break;
    //     case 2: cout<< " I am two."<<endl;
    //             break;
    //     default: cout<< " I am number 3. ";
    // }

    // // Calculator programm
    // int a,b;
    // char op;
    // cout<<"Enter the value of a: "<<endl;
    // cin>>a;
    // cout<<"Enter the value of b: "<<endl;
    // cin>>b;
    // cout<<"Enter the operation: "<<endl;
    // cin>>op;
    // switch(op){
    //     case '+': cout<<a+b<<endl;
    //             break;
    //     case '*': cout<<a*b<<endl;
    //             break;
    //     case '/': cout<<a/b<<endl;
    //             break;
    //     case '-': cout<<a-b<<endl;
    //             break;
    //     default: cout<<"Please Enter a valid operator."<<endl;
    //     }

    // // Counting number of notes
    // int a;
    // cout<<"Enter the amount of money"<<endl;
    // cin>>a;
    // cout<<"Number of 100 Rupees notes are: "<<a/100<<endl;
    // a=a%100;
    // cout<<"Number of 50 Rupees notes are: "<<a/50<<endl;
    // a=a%50;
    // cout<<"Number of 20 Rupees notes are: "<<a/20<<endl;
    // a=a%20;
    // cout<<"Number of 1 Rupees notes are: "<<a/1<<endl;

    // // pow(a,b)
    // int a,b;
    // cin>>a>>b;
    // cout<<power(a,b)<<endl;

    // // Even number programm
    // cout<<is_even()<<endl;

    // // Calculating nCr
    // cout<<bino()<<endl;

    // // Counting function
    // counting(100);

    // // Checking for prime numbers
    // cout<<is_prime()<<endl;

    // // nth term of AP
    // cout<<AP(3)<<endl;

    // // setbits
    // cout<<setBits(2,3)<<endl;
    // cout<<setBits(12,15)<<endl;
    // cout<<setBits(10,10);

    // // Fibonacci seires
    // cout<<fibonacci_series(5);

    
}