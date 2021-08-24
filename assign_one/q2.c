#include <stdio.h>

int main() {
	int arr[15];
	for(int i=0; i<15; i++){
	    scanf("%d", &arr[i]);
	}
	
	int max = arr[0];
	
	for(int i=1; i<15; i++){
	    if(arr[i]>max){
	        max = arr[i];
	    }
	}
	
	printf("%d", max);
}
