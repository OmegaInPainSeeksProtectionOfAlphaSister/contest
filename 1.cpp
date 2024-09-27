//Ê±¼änlogm¿Õ¼äm 
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<vector>
using std::priority_queue;
using std::vector;
struct cmp{
	bool operator()(int a,int b){
		return a>b;
	}
};
int n;
int scores[500010];
int m;
priority_queue<int,vector<int>,cmp> q;
int ans[500010];
void init(){
	n=0x8000;
	for(int i=1;i<=0x7fff;i++){
    	scores[i]=i;
	}
	for(int i=0x7fff;i>0;i--){
		int id=rand()%(i+1);
		int tmp=scores[id];
		scores[id]=scores[i];
		scores[i]=tmp;
	}
	m=0x7fff;
}
void GetTopScores(){
	for(int i=0;i<n;i++){
		q.push(scores[i]);
		if(q.size()>m){
			q.pop();
		}
	}
	while(q.size()){
		ans[q.size()-1]=q.top();
		q.pop();
	}
}
void test(){
	for(int i=0;i<0x7fff;i++){
		if(ans[i]!=0x7fff-i){
			printf("error");
			exit(0);
		}
	}
}
int main(){
	init(),GetTopScores(),test(); 
} 
