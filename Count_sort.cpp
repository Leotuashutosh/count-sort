#include<bits/stdc++.h>
using namespace std;
void counts(int a[],int n,int k);
int main(){
	int n;
	cout<<"enter number of elements";
	cin>>n;
	int arr[n];
	cout<<"enter values";
	int max = INT_MIN;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]>max)
			max=arr[i];
	}
	counts(arr,n,max+1);
	cout<<"Sorted using count sort";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<' ';
	}
	return 0;

}
void counts(int a[],int n,int k){
	int count[k],i;
	for(i=0;i<k;i++)
		count[i]=0;
	for(i=0;i<n;i++)
		count[a[i]]++;
	for(i=1;i<k;i++)
		count[i]= count[i-1]+count[i];
	int output[n];
	for(i=n-1;i>=0;i--){
		output[count[a[i]]-1]=a[i];
		count[a[i]]--;
	}
	for(i=0;i<n;i++)
		a[i]=output[i];

}
