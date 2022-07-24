#include<bits/stdc++.h>

using namespace std;



void build(int ind,int low,int high,int arr[],int seg[])
{


   if(low==high)
   {
   	seg[ind]=arr[low];
   	return;
   }

   int mid=(low+high)/2;

   build(2*ind+1,low,mid,arr,seg);
   build(2*ind+2,mid+1,high,arr,seg);

   seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);

}

int queries(int ind,int low,int high,int l,int r,int seg[])
{
	if(r < low || high < l)
	{
		return INT_MAX;
	}
	if(low >= l and r<=high)
	{
		 return seg[ind];
	}

	int mid=(low+high)/2;
	int left=queries(2*ind+1,low,mid,l,r,seg);
	int right=queries(2*ind+2,mid+1,high,l,r,seg);

	return left+right;
}






void update(int ind,int low,int high,int i,int val,int seg[])
{


   if(low==high)
   {
   	seg[ind]=val;
   	return;
   }

int mid=(low+high)>>1;
if(i<=mid) update(2*ind+1,low,mid,i,val,seg);
else update(2*ind+2,mid+1,high,i,val,seg);
seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);

}








void solve()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	int seg[4*n];

build(0,0,n-1,arr,seg);

int q;
cin>>q;
while(q--)
{
	// int l,r;
	// cin>>l>>r;
	// cout<<queries(0,0,n-1,l,r,seg)<<endl;


  int type;
  cin>>type;
  if(type==1)
  {
  	int l,r;
  	cin>>l>>r;
  	cout<<queries(0,0,n-1,l,r,seg)<<endl;
  }
  else
  {
  	int i,val;
  	cin>>i>>val;
  	update(0,0,n-1,i,val,seg);
  	arr[i]=val;
  }









}


void solve2()
{
	int n1;
	cin>>n1;
	int arr[n1];

   for(int i=0;i<n1,i++)
   {
   	cin>>arr1[i];
   }
   int n2;
   cin>>n2;
   int arr2[n2];
   for(int i=0;i<n2;i++)
   {
   	cin>>arr2[i];
   }

int q;
cin>>q;

while(q--)
{
	int type;
	cin>>type;
   if(type==1)
   {
   	int l1,r1,l2,r2;
   	cin>>l1>>r1>>l2>>r2;

   }
   else
   {
   	int arrno;
   	cin>>arrno;




   	
   }








}







}











}











int main()
{

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

solve();


    return 0;
}