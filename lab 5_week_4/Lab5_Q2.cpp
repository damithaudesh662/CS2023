#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std::chrono;

using namespace std;
int PivotLocation(int arr[],int min,int max){
    int pivot=arr[max];
    int i=min-1;
    int temp1;
    
    for(int j=min;j<max;j++){
        int temp2;
        
        if(arr[j]<pivot){
            i=i+1;
            //swap(arr[i], arr[j])
            temp2=arr[i];
            arr[i]=arr[j];
            arr[j]=temp2;
        }
    }
    //swap(arr[i + 1], arr[high])
    temp1=arr[i+1];
    arr[i+1]=arr[max];
    arr[max]=temp1;
    return i+1;

}

void RecursiveQuicksort(int arr[],int min,int max){
    if(min<max){
        int pivot_location=PivotLocation(arr,min,max);
        RecursiveQuicksort(arr,min,pivot_location-1);
        RecursiveQuicksort(arr,pivot_location+1,max);
    }
}
int main(){
    
    int arrSize=0;
    int arr [arrSize] ;
    int number;
    cout<<"you have to enter the elements in the array one by one"<<endl;
    cout<<"enter size of array";
    cin>>arrSize;
    
    for(int x=0;x<arrSize;x++){
        cout<<"enter number ";
        
        cin>>number;
        arr[x]=number;
        RecursiveQuicksort(arr,0,x+1);
        if(x==0){
            cout<<"median is: ";
            int a=arr[0];
            for(int i:arr){
                cout<<i<<" ";
            }
            cout<<a;
            cout<<endl;

        }
        
        else if(x%2==0){
            cout<<"median is :";
            int b=arr[(x+1)/2];
            for(int i:arr){
                cout<<i<<" ";
            }
            cout<<b;
            cout<<endl;
        }
        
        else{
            cout<<"median is :";
            int c=((arr[x/2]+arr[(x/2)+1])/2);
            for(int i:arr){
                cout<<i<<" ";
            }
            cout<<c;
            cout<<endl;
        }


    }
    
    
    
    
   
    
    return 0;
    
    
    
}
