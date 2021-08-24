#include <stdio.h>

int main() {
	int arr[20];
	for(int i=0; i<20; i++){
	    scanf("%d", &arr[i]);
	}
	
	for(int i=0; i<20; i++){
	    for (int j = i + 1; j < 20; j++){
	        if (arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
	        }
	    }
	}
	
	for(int i=0; i<20; i++){
	    printf("%d ", arr[i]);
	}

	return 0;
}
