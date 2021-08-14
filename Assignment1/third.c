#include <stdio.h>

int main() {
	int arr[20];
	for(int i=0; i<20; i++){
	    scanf("%d", &arr[i]);
	}
	
	int count = 0;
	
	for(int i=0; i<20; i++){
	    if(arr[i]%2 == 0){
	        count++;
	    }
	}
	
	printf("%d", count);
	return 0;
}
