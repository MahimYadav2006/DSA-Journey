#include <bits/stdc++.h> 
#define MOD 1000000000+7
int add(int a,int b){
    return (((a%MOD) + (b%MOD))%MOD);
}
int multiply(int a,int b){
    return (((a%MOD) * 1LL * (b%MOD))%MOD);
}
int solve(int n,int k){
    if(n==1){
        return k;
    }
    if(n==2){
        return add(k,multiply(k,k-1));
    }
    return add(multiply(solve(n-2,k),k-1) , multiply(solve(n-1,k),k-1));
}
int solveTab(int n,int k){
    vector<int> dp(n+1,0);
    dp[1]=k;
    dp[2]=add(k,multiply(k,k-1));
    for(int i=3;i<=n;i++){
        dp[i]=add(multiply(dp[i-2],k-1) , multiply(dp[i-1],k-1))
    }
    return dp[n];
}
int solveTab(int n,int k){
    vector<int> dp(n+1,0);
    dp[1]=k;
    dp[2]=add(k,multiply(k,k-1));
    for(int i=3;i<=n;i++){
        dp[i]=add(multiply(dp[i-2],k-1) , multiply(dp[i-1],k-1));
    }
    return dp[n];
}
int solveSpaceOpt(int n,int k){
    int prev1=k;
    int prev2=add(k,multiply(k,k-1));
    if(n==1){
        return prev1;
    }
    if(n==2){
        return prev2;
    }
    for(int i=3;i<=n;i++){
        int ans=add(multiply(prev1,k-1) , multiply(prev2,k-1));
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
int solveMem(int n,int k,vector<int> &dp){
    if(n==1){
        // dp[1]=k;
        return k;
    }
    if(n==2){
        // dp[2]=;
        return add(k,multiply(k,k-1));
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=add(multiply(solveMem(n-2,k,dp),k-1) , multiply(solveMem(n-1,k,dp),k-1));
    return dp[n];
}
int numberOfWays(int n, int k) {
    // return solve(n,k);

    // Rec+ Mem
    vector<int> dp(n+1,-1);
    return solveMem(n,k,dp);

}





 // // / // / /// / // /Que 2 / // // // // // /
 #include <bits/stdc++.h> 
int solve(vector<int> &weight, vector<int> &value, int index, int maxWeight){
	if(index==0){
		if(weight[index]<=maxWeight){
			return value[index];
		}
		else{
			return 0;
		}
	}
	int include=0;
	if(weight[index]<=maxWeight){
		include=value[index]+solve(weight,value,index-1,maxWeight-weight[index]);
	}
	int exclude=solve(weight,value,index-1,maxWeight);
	return max(include,exclude);
}

int solveMem(vector<int> &weight, vector<int> &value, int index, int maxWeight,vector<vector<int>> &dp){
	if(index==0){
		if(weight[index]<=maxWeight){
			return value[index];
		}
		else{
			return 0;
		}
	}
	int include=0;
	if(dp[index][maxWeight]!=-1){
		return dp[index][maxWeight];
	}
	if(weight[index]<=maxWeight){
		include=value[index]+solveMem(weight,value,index-1,maxWeight-weight[index],dp);
	}
	int exclude=solveMem(weight,value,index-1,maxWeight,dp);
	dp[index][maxWeight]=max(include,exclude);
}
int solveTab(vector<int> &weight,vector<int> &value,int n,int capacity){
	// Creation of dp array
	vector<vector<int>> dp(n,vector<int>(capacity+1,0));

	// Analysing Base  Case
	// for 0th row set the base cases
	for(int w:weight[0];w<=capacity;w++){
		if(weight[0]<=capacity){
			dp[0][w]=value[0];
		}
		else{
			dp[0][w]=0;
		}
	}
	for(int index=1;index<n;index++){
		for(int w=0;w<capacity;w++){
			int include=0;
			if(weight[index]<=w){
				include=value[index]+dp[index-1][w-weight[index]];
			}
			int exclude=dp[index-1][w];
			dp[index][w]=max(exclude,include);
		}
	}
	return dp[n-1][capacity];

}
int solveTab2(vector<int> &weight,vector<int> &value,int n,int capacity){
	// Creation of dp array
	// vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
	vector<int> prev(capacity+1,0);
	vector<int> curr(capacity+1,0);

	// Analysing Base  Case
	// for 0th row set the base cases
	for(int w:weight[0];w<=capacity;w++){
		if(weight[0]<=capacity){
			prev[w]=value[0];
		}
		else{
			prev[w]=0;
		}
	}
	for(int index=1;index<n;index++){
		for(int w=0;w<capacity;w++){
			int include=0;
			if(weight[index]<=w){
				include=value[index]+prev[w-weight[index]];
			}
			int exclude=prev[w];
			curr[w]=max(exclude,include);
		}
		prev=curr;
	}
	return prev[capacity];

}
int solveTab3(vector<int> &weight,vector<int> &value,int n,int capacity){
	// Creation of dp array
	// vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
	// vector<int> prev(capacity+1,0);
	vector<int> curr(capacity+1,0);

	// Analysing Base  Case
	// for 0th row set the base cases
	for(int w:weight[0];w<=capacity;w++){
		if(weight[0]<=capacity){
			curr[w]=value[0];
		}
		else{
			curr[w]=0;
		}
	}
	for(int index=1;index<n;index++){
		for(int w=capacity;w>=0;w++){
			int include=0;
			if(weight[index]<=w){
				include=value[index]+curr[w-weight[index]];
			}
			int exclude=curr[w];
			curr[w]=max(exclude,include);
		}
		// prev=curr;
	}
	return curr[capacity];

}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{	int index=n;
	// return solve(weight,value,index,maxWeight);

	// Memosiation
	vector<vector<int>> dp(n,vector<int> (maxWeight+1,-1));
	return solveMem(weight,value,index,maxWeight,dp);
}


// #include<iostream>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* next;
//     Node(int data){
//         this->next=NULL;
//         this->data=data;
//     }
// };
// Node* flag(Node* &h1){
//     h1=h1->next;
//     h1=h1->next;
// }
// Node* mergeSortedLL(Node* h1,Node* h2){
//     // Node* ans=new Node(-1);
//     // Node* back=ans;
//     // while(h1!=NULL && h2!=NULL){
//     //     if(h1->data<h2->data){
//     //         back->next=h1;
//     //         h1=h1->next;
//     //         back=back->next;
//     //         back->next=NULL;
//     //     }
//     //     else{
//     //         back->next=h2;
//     //         h2=h2->next;
//     //         back=back->next;
//     //         back->next=NULL;
//     //     }
//     // }
//     // if(h1==NULL){
//     //     back->next=h2;
//     // }
//     // if(h2==NULL){
//     //     back->next=h2;
//     // }
//     // back->next=NULL;
//     // back=ans;
//     // ans=ans->next;
//     // delete back;
//     // return ans;

//     Node* dummy=new Node(-1);
//     Node* tail=dummy;
//     while(h1!=NULL && h2!=NULL){
//         if(h1->data<h2->data){
//             tail->next=h1;
//             h1=h1->next;
//         }
//         else{
//             tail->next=h2;
//             h2=h2->next;
//         }
//         tail=tail->next;
//     }
//     if(h1!=NULL){
//         tail->next=h1;
//     }
//     if(h2!=NULL){
//         tail->next=h2;
//     }
//     Node* ans=dummy->next;
//     delete dummy;
//     return ans;
// }
// void print(Node* root){
//     while(root!=NULL){
//         cout<<root->data<<" ";
//         root=root->next;
//     }
// }
// int main(){
//     Node* temp=new Node(1);
//     temp->next=new Node(3);
//     // temp->next->next=new Node();
//     Node* f=new Node(2);
//     f->next=new Node(4);
//     f->next->next=new Node(6);
//     Node* kite=mergeSortedLL(f,temp);
//     print(kite);
// }