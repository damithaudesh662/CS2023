#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <stack>
using namespace std::chrono;

using namespace std;
int PivotLocation(int arr[],int min,int max){
    int pivot=arr[max];
    int i=min-1;
    int temp1;
    
    for(int j=min;j<max-1;j++){
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
void IterativeQuicksort(int arr[],int min,int max){
    stack<int> stack;
    stack.push(min);
    stack.push(max);

    while (stack.empty()){
        max = stack.top();
        stack.pop();
        min = stack.top();
        stack.pop();
        int pivot_location = PivotLocation(arr, min, max);

        if (pivot_location - 1 > min)
            stack.push(min);
            stack.push(pivot_location - 1);
            
    
        if (pivot_location + 1 < max)
            stack.push(pivot_location + 1);
            stack.push(max);
            

        
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
    IterativeQuicksort(randArray,0,arrSize-1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken is: "<< duration.count() << endl;
    return 0;
}
