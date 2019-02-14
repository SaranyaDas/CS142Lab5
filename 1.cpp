#include<iostream>
using namespace std;
void swap(int*a, int*b) {
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(int arr[], int low , int high) {
	int pivot = arr[high]; 
	int i = (low - 1); 
	for(int j = low;j <= high-1; j++) {
		if(arr[j] <= pivot) { 
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
		swap(&arr[i + 1], &arr[high]);
		return i + 1;
}
void QS(int arr[], int low, int high) {
	if(low < high) {
		int pi = partition(arr, low, high);	
		QS(arr, low, pi - 1);
		QS(arr, pi + 1, high);
	}
}
void display(int arr[], int size) {
	int i;
	for(i = 0 ; i < size; i++) {
		cout << arr[i] << " -> ";
	}
	cout << endl;
}
int main() {
	int arr[] = {9, 23, 45, 5, 543, 634, 24236, 34654, 53453, 445, 789,  567, 48};
	int n = sizeof(arr) / sizeof(arr[0]);  
	display(arr, n);
	QS(arr, 0, n-1);	
	cout << "Quick Sorted Array" << endl;	
	display(arr, n);
	cout << endl;
	return 0;
}
