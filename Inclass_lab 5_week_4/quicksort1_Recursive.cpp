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
    
    int arrSize;
    cout<<"Total elements in array: ";
    cin>> arrSize;
    int randArray[arrSize];
    for(int i=0;i<arrSize;i++)
      randArray[i]=rand()%100;
    auto start = high_resolution_clock::now();
    RecursiveQuicksort(randArray,0,arrSize-1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken is: "<< duration.count() << endl;
    return 0;
    
    
    
}
