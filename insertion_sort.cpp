#include<iostream>
#include<time.h>
using namespace std;
int main()
{
    int i,j,k,l,m,n,temp;
    clock_t time_req;
    time_req=clock();
    cout<<"Enter the number of elements: ";
    cout<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: "; cout<<endl;
    for(k=0;k<n;k++)
    {
        cin>>arr[k];
    }
    for(i=1;i<n;i++)
    {
      temp=arr[i];
      j=i-1;
      while(j>-1 && arr[j]>temp)
      {
          arr[j+1]=arr[j];
          j--;
      }
      arr[j+1]=temp;
      cout<<"the array after pass"<<i<<endl;
      for(l=0;l<n;l++)
      {
        cout<<arr[l]<<" ";
      }
      cout<<endl;
    }
    cout<<"the sorted array is"<<endl;
      for(m=0;m<n;m++)
        {cout<<arr[m]<<" ";}
        cout<<endl;
        time_req=clock()-time_req;
        cout<<"the time taken is"<<endl;
        cout<<(float)time_req/CLOCKS_PER_SEC<<"seconds"<<endl;
        cout<<"The bytes occupied is"<<endl;
        cout<<(sizeof(arr[n])*n)+sizeof(temp)+sizeof(n)+sizeof(i)+sizeof(j)+sizeof(k)+sizeof(l)+sizeof(m);
    return 0;
}
