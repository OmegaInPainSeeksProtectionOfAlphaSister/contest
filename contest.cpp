#include<vector>
#include<queue>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<unordered_map>
#include<cstdio>
using std::vector;
using std::priority_queue;
using std::min;
using std::unordered_map;
struct cmp{
	bool operator()(int a,int b){
		return a>b;
	}
};
vector<int> GetTopScores(vector<int>& scores,int m){
	priority_queue<int,vector<int>,cmp> heap;
	for(int i=0;i<scores.size();i++){
		heap.push(scores[i]);
		if(heap.size()>m){
			heap.pop();
		}
	}
	int size=min(m,(int)scores.size());
	vector<int> ans(size);
	for(int i=0;i<size;i++){
		ans[size-1-i]=heap.top();
		heap.pop();
	}
	return ans;
}
void print_log(vector<int>& scores,int m,vector<int>& ans){
	for(int i=0;i<scores.size();i++){
		printf("%d ",scores[i]);
	}
	printf("\n%d\n",m);
	for(int i=0;i<ans.size();i++){
		printf("%d ",ans[i]);
	}
}
void check(vector<int>& scores,int m,vector<int>& ans){
	if((m<=scores.size()&&ans.size()!=m)||(m>scores.size()&&ans.size()!=scores.size())){
		print_log(scores,m,ans);
		exit(0);
	}
	for(int i=1;i<ans.size();i++){
		if(ans[i]>ans[i-1]){
			print_log(scores,m,ans);
			exit(0);
		}
	}
	unordered_map<int,int> a;
	for(int i=0;i<ans.size();i++){
		a[ans[i]]=1;
	}
	for(int i=0;i<scores.size();i++){
		if((!a.count(scores[i]))&&scores[i]>ans[ans.size()-1]){
			print_log(scores,m,ans);
			exit(0);
		}
	}
}
void test_zero_scores_size(){
	vector<int> scores;
	vector<int> ans=GetTopScores(scores,0);
	check(scores,0,ans);
} 
void test_larger_m(){
	int size=0x7fff;
	vector<int> scores;
	for(int i=0;i<size;i++){
		scores.push_back(i+1);
	}
	srand(time(0));
	for(int i=size-1;i>0;i--){
		int id=rand()%(i+1);
		int tmp=scores[id];
		scores[id]=scores[i];
		scores[i]=tmp;
	}
	int m=size+1+rand();
	vector<int> ans=GetTopScores(scores,m);
	check(scores,m,ans);
}
void test(){
	test_zero_scores_size();
	test_larger_m();
}
int main(){
	test();
	return 0;
}
