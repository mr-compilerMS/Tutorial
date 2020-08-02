#include"stdio.h"
#include"conio.h"

int main(){
    int no;
    printf("Enter No : ");
    scanf("%d",&no);
    int arr[20];
    int c=1,j=0;
    while (no>0)
    {
        int i=no%10;
        arr[j]=i*c;
        j++;
        printf(" + %d ",i*c);
        no/=10;
        c*=10;
    }
    j--;
    printf("\n");
    for (;j >-1;j--)
    {
        printf(" %d +",arr[j]);
    }
    getch();
}