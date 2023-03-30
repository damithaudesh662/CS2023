
#include<bits/stdc++.h>

using namespace std::chrono;

using namespace std;
//Taking pivot location for Quicksort
int PivotLocation(int arr[],int min,int max){
    int pivot=arr[max];
    int i=min-1;
    int temp1;
    
    for(int j=min;j<max;j++){
        int temp2;
        
        if(arr[j]<pivot){
            i=i+1;
            
            temp2=arr[i];
            arr[i]=arr[j];
            arr[j]=temp2;
        }
    }
    
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
    cout<<"You can input Following inputs here"<<endl;
    cout<<"enter size of array";
    cin>>arrSize;
    
    for(int x=0;x<arrSize;x++){
        cout<<"enter number ";
        
        cin>>number;
        arr[x]=number;
        RecursiveQuicksort(arr,0,x+1);
        for(int i:arr){
            cout<<i<<"";
        }
        if(x==0){
            cout<<"median is: ";
            float a=arr[0];

            
            cout << fixed << setprecision(1) << a;
            
            cout<<endl;

        }
        
        else if(x%2==0){
            cout<<"median is :";
            float b=arr[(x+1)/2];
            
            cout << fixed << setprecision(1) << b;
            
            cout<<endl;
        }
        
        else{
            cout<<"median is :";
            float c=((arr[x/2]+arr[(x/2)+1])/2);
            cout << fixed << setprecision(1) << c;
            
            
          
            
            cout<<endl;
        }


    }
    
    return 0;
    
    
    
}