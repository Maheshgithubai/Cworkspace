#include<stdio.h>
int main(){
    int  a[20];
    int count[20]={0};
    for(int i=0;i<20;i++){
    scanf("%d",&a[i]);
    }
    for(int i=0;i<20;i++){
        if(-10>=a[i] && a[i]<=10){
            count[a[i]+10]++;
        }
    }
    for(int i=0;i<20;i++){
        int n=-10+i;
        printf("%d->%d\n",n,count[i]);
    }

}
