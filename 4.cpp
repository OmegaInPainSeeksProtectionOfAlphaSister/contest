//Ê±¼älog(m+n)¿Õ¼ä1 
#include<stdio.h>
#include<iostream>
using std::min;
int m,n;
int fireAbility[10000010];
int iceAbility[10000010];
double ans;
void init(){
	m=0x800000,n=0x800000;
	for(int i=0;i<m;i++){
		fireAbility[i]=i;
	}
	for(int i=0;i<n;i++){
		iceAbility[i]=i;
	}
}
int get(int x){
	int id1=0,id2=0;
	while(1){
		if(id1==m){
			return iceAbility[id2+x-1];
		}
		if(id2==n){
			return fireAbility[id1+x-1];
		}
		if(x==1){
			return min(fireAbility[id1],iceAbility[id2]);
		}
		int newid1=min(id1+x/2-1,m-1),newid2=min(id2+x/2-1,n-1);
		int val1=fireAbility[newid1],val2=iceAbility[newid2];
		if(val1<=val2){
			x-=newid1-id1+1;
			id1=newid1+1;
		}else{
			x-=newid2-id2+1;
			id2=newid2+1;
		}
	}
}
void FindMedianTalentIndex(){
	int sum=m+n;
	if(sum%2){
		ans=get(sum/2+1);
	} 
	ans=(double)(get(sum/2)+get(sum/2+1))/2;
}
void test(){
	if(ans!=(double)0x400000-0.5){
		printf("error");
		exit(0);
	}
}
int main(){
	init(),FindMedianTalentIndex(),test();
}
