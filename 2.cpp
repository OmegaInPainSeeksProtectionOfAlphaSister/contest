//Ê±¼änlogn¿Õ¼än 
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>
#include<math.h>
using std::vector;
using std::max;
int n;
int heights[500010];
vector<int> left;
vector<int> right;
double ans;
void init(){
	n=0x8000;
	for(int i=0;i<0x8000;i++){
		heights[i]=rand();
	}
}
void helper(int left_l,int left_r,int right_l,int right_r){
	if(left_l>left_r){
		return;
	}
	int mid=(left_l+left_r)/2;
	double res=-1e9;
	int id;
	for(int i=right_l;i<=right_r;i++){
		if(res<(double)(right[i]-left[mid])*(heights[right[i]]+heights[left[mid]])/2){
			res=(double)(right[i]-left[mid])*(heights[right[i]]+heights[left[mid]])/2;
			id=i;
		}
	}
	ans=max(ans,res);
	if(left_l==left_r){
		return;
	}
	helper(left_l,mid-1,id,right_r);
	helper(mid+1,left_r,right_l,id);
}
void MaxEnergyField(){
	left.push_back(0);
	for(int i=1;i<n;i++){
		if(heights[i]>heights[left[left.size()-1]]){
			left.push_back(i);
		}
	}
	right.push_back(n-1);
	for(int i=n-1;i>-1;i--){
		if(heights[i]>heights[right[right.size()-1]]){
			right.push_back(i);
		}
	}
	helper(0,left.size()-1,0,right.size()-1);
}
void test(){
	for(int i=0;i<0xf00000;i++){
		int x=rand(),y=rand();
		if(ans<(double)abs(x-y)*(heights[x]+heights[y])/2){
			printf("error");
			exit(0);
		}
	}
}
int main(){
	init(),MaxEnergyField(),test();
}
