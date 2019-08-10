#include <stdio.h>
#include <string.h>

void xor(char *input,int n){

	char xor_key[] = "A";

	for (int i = 0;i < n ;i++){
		input[i] = input[i] ^ xor_key[i % sizeof(xor_key - 1)];
	}
}

int main(int argc, const char **argv){

	if (argc < 2){
		printf("Usage: %s <message to encode>\n",argv[0]);
		return 1;
	}
	const char *input = argv[1];
	size_t input_sz = strlen(input);
	printf("This argv1 size is: %d ",(int) input_sz);
	char message[input_sz];
	strncpy(message,input,input_sz);
	printf("\n%s\n",message);
	xor(message,input_sz);
	printf("The message xor'd with 0xc is:\n");
	printf("%s\n\n",message);
	for (int i = 0; i < input_sz;i++){
		printf("\\x%x",message[i]);
				}

	printf("\nThe message xor'd back is:\n");
	xor(message,input_sz);
	printf("%s\n",message);

	return 0;
}
