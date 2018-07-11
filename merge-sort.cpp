#include<iostream>

using namespace std;

void merge(int a[],int start,int middle,int end) {
    
            int n1 = middle - start +1;
            int n2 = end - middle;
    
    int L[n1], R[n2];
    
    int i,j,k;
    
    for(i=0;i<n1;i++){
        cout<<L[i]<<" ";
        L[i] = a[start+i];
    }cout<<endl;
    for (j=0;j<n2; j++) {
        R[j] = a[middle+ 1 + j];
    }
    
    i=0;j=0;k=start;
    
    while(i<n1 && j<n2) {
        if(L[i]<R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i<n1) {
        a[k] = L[i];
        i++;k++;
    }
    
    while (j<n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[],int start, int end) {
    if(start < end){
    int middle = (start+ end)/2;
    mergeSort(a,start,middle);
    mergeSort(a,middle+1,end);
    
    merge(a,start,middle,end);
    }
    
}

int main() {
 int a[] = {7,8,5,56,33,11,77,43};
    
    mergeSort(a,0,7);
    for(int i=0;i<8;i++) {
        cout<<a[i]<<" ";
    }
}