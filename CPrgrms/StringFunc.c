/*----------------------------
StringFunc.c

Rejeesh Koshy
26-07-2024
----------------------------*/

#include <stdio.h>
#include <string.h>

int StringLen(char s[]);
void StrCpy(char t[], char s[]);
void StrJoin(char t[], char s[]);

int main()
{
	char fs[20], ss[20], t[20];
	printf("PROGRAM TO COPY AND CONCATENATE STRINGS\n\n");
	
	printf("Enter first string : ");
	scanf("%s", &fs);

	printf("\nThe length of the string : %d\n\n", StringLen(fs));

	printf("Enter second string: ");
	scanf("%s", &ss);

	StrCpy(t,fs);
	printf("The string entered to source is : %s \n and is copied to Target : %s\n", fs, t);

	StrJoin(ss, fs);
	printf("\nThe string after concatination : %s", ss);

	return 0;
}

//----------------------------
int StringLen(char s[]){
	int i = 0;
	while(s[i]!='\0'){
		i++;
	}
	return i;
}
//----------------------------
void StrCpy(char t[], char s[]){
	int i=0;

	while(s[i]!='\0'){
		t[i] = s[i];
		i++;
	}

	t[i] = '\0';
}
//----------------------------
void StrJoin(char t[], char s[]){
	int i = StringLen(t);
	int j = 0;

	while(s[j]!='\0'){
		t[i] = s[j];
		i++;
		j++;
	}
	t[i] = '\0';
}
//------------------------------
int StrCmp(char t[], char s[]){
	int i = 0;
	while(t[i]='\0'){
		if (t[i] == s[i]){
			continue;
		}
		else{
			return t[i] - s[i];
		}
	}
	return 0;
}