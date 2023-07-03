#include <stdio.h>
#include <string.h>
int main() {

	int n;
	printf("Enter the number of names you want: ");
	scanf(" %d", &n);
	char names[500][500];
	for(int i=0;i<n;i++) {
        	printf("Enter names:\n");
       	scanf(" %s", names[i]);
	}
	
	char ch;
	printf("Enter the char from which you want to search the array: ");
	scanf(" %c", &ch);
	printf("The names that start from %c is:",ch);
	for(int i = 0; i < n; i++) {
        if( ch == names[i][0]) {
            printf("%s\n", names[i]);
        }
	}
	printf(" None");
return 0;
}