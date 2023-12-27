#include<iostream>
using namespace std;
int findUnique(int arr[], int size)
{
    int i,j;
    int cnt,ans[100];
    for(i=0;i<size;i++){
       ans[i]=-1;
        for(j=i+1;j<size;j++){
            if(arr[i]==arr[j]){
                ans[j]=0;
            }
        }
        if(ans[i]!=0){
            cnt = arr[i];
        }
    }
    return cnt;
}
int main()
{

	
		int size;
		cin >> size;
		int input[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		cout<<findUnique(input, size);
	

	return 0;
}
