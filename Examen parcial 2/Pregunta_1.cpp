/*
Median plays an important role in the world of statistics. By definition, it is a value which divides
an array into two equal parts. In this problem you are to determine the current median of some long
integers. Suppose, we have five numbers {1,3,6,2,7}. In this case, 3 is the median as it has exactly two
numbers on its each side. {1,2} and {6,7}. If there are even number of values like {1,3,6,2,7,8}, only
one value cannot split this array into equal two parts, so we consider the average of the middle values
{3,6}. Thus, the median will be (3+6)/2 = 4.5. In this problem, you have to print only the integer
part, not the fractional. As a result, according to this problem, the median will be 4!
#include <bits/stdc++.h>
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

int mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
        if(arr.size()%2==0){
            int med = (arr[mid]+arr[mid+1])/2;
            return med;
        }else{
            int med = arr[mid];
            return med;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    vector<int> arr;
    for(int i=0;i<9;i++){
        arr.push_back(rand()%9);
    }
    int n = arr.size();

    cout << "Array original: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    cout<<mergeSort(arr, 0, n - 1)<<endl;

    cout << "Array ordenado: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
