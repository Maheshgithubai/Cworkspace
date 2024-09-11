#include<stdio.h>
#include<string.h>
int main(){
    char a[26];
    int count[26]={0};
    scanf("%s",a);
    int len=strlen(a);
    for(int i=0;i<len;i++){
        if(a[i]>='A' && a[i]<='Z'){
            count[a[i]-'A']++;
        }
    }
    for(int i=0;i<26;i++){
        char ch='A'+i;
        printf("%c -> %d\n",ch,count[i]);
    }
    
}