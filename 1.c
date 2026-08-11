#include <stdio.h>
#include <string.h>

struct stuff{
	char name[100];
	int mass;
};

void swap(struct stuff *a, struct stuff *b){
	//name
	char d[100];
	strcpy(d, a->name);
	strcpy(a->name, b->name);
	strcpy(b->name, d);
	//mass
	int c = a->mass;
	a->mass = b->mass;
	b->mass = c;
}

int main(void){
	
	FILE *fp;
	
	fp = fopen("test.txt", "r");
	
	struct stuff salt[100];
	
	char s[1024];
	int input_mass;
	
	int stuff_size=0;
	
	while(fscanf(fp, "%s %d", s, &input_mass) != EOF){
		strcpy(salt[stuff_size].name, s);
		salt[stuff_size].mass = input_mass;
		stuff_size++;
	}
	
	for(int i=0;i<stuff_size;i++){
		printf("%s - %d (kg)\n", salt[i].name, salt[i].mass);
	}
	
	int flag = 1;
	
	for(int j = stuff_size; j>0;j--){
		for(int i = 1; i<j;i++){
			if(salt[i-1].mass > salt[i].mass){
				swap(&salt[i-1], &salt[i]);
				flag = 0;
			}
		}
		if(flag){
			break;
		}
		flag = 1;
	}
	
	printf("\nSorted version:\n");
	
	for(int i=0;i<stuff_size;i++){
		printf("%s - %d (kg)\n", salt[i].name, salt[i].mass);
	}
	
	//Write output into "output.txt"
	
	FILE *fpw;
	
	fpw = fopen("output.txt", "w");
	
	fputs("Test output\n", fpw);
	fputs("Sorted version:", fpw);
	fputc('\n', fpw);
	
	for(int i=0;i<stuff_size;i++){
		fprintf(fpw, "%s - %d (kg)\n", salt[i].name, salt[i].mass);
	}
	
	fclose(fp);
	fclose(fpw);
	
	getchar();
	return 0;
}

//cmd /k cd "C:\Users\kaizenak\Desktop\PracticeC" && gcc 1.c && a.exe