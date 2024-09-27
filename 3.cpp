//Ê±¼än¿Õ¼ä10 
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using std::max;
int n;
int treasures[10000010];
long long dp[10000010];
long long ans;
void init(){
	n=0x80000;
	for(int i=0;i<n;i++){
		treasures[i]=rand();
	}
}
void MaxTreasureValue(){
	if(!n){
		ans=treasures[0];
	}
	dp[0]=treasures[0];
	dp[1]=max(treasures[0],treasures[1]);
	for(int i=2;i<n;i++){
		dp[i]=max(dp[i-1],dp[i-2]+treasures[i]);
	}
	ans=dp[n-1];
}
void test(){
	for(int i=0;i<0x10;i++){
		long long sum=0;
		int id=-2;
		while(1){
			id+=2+rand()%2;
			if(id>=n){
				break;
			}
			sum+=treasures[id];
		}
		if(ans<sum){
			printf("error");
			exit(0);
		}		
	}
}
int main(){
	init(),MaxTreasureValue(),test();
}
