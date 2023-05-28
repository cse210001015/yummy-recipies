#include <bits/stdc++.h>
using namespace std;

int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}
void countSort(int arr[], int n, int exp)
{
	vector<int> output(n,0);
	int i, count[10] = { 0 };
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++)
		arr[i] = output[i];
		
	output.clear();	
}

void radixsort(int arr[], int n,int x)
{
	int m = getMax(arr, n);
	int exp = 1;
	while(x--){
		countSort(arr,n,exp);
		exp*=10;
	}
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

	int n;
	cin >> n;
	int a[n];
	map<int,int> ind;
	for(int i=0;i<n;i++){
		cin >> a[i];
		ind[a[i]]=i;
	}
	
	int m;
	cin >> m;
	int q[m][2];
	for(int i=0;i<m;i++){
		cin >> q[i][0] >> q[i][1] ;
	}
	for(int i=0;i<m;i++){
		int d[n];
		for(int i=0;i<n;i++) d[i]=a[i];
		radixsort(d,n,q[i][1]);
		cout<< ind[d[q[i][0]-1]] << endl;
	}
	
}


