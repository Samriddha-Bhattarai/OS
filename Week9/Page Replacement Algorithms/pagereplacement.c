#include<stdio.h>

int hit(int f[],int m,int x){
    for(int i=0;i<m;i++)
        if(f[i]==x) return 1;
    return 0;
}

void show(int f[],int m){
    for(int i=0;i<m;i++)
        f[i]==-1?printf("- "):printf("%d ",f[i]);
    printf("\n");
}

void fifo(int p[],int n,int m){
    int f[10],i,j=0,pf=0;

    for(i=0;i<m;i++) f[i]=-1;

    printf("\nFIFO Page Replacement Process:\n");

    for(i=0;i<n;i++)
        if(!hit(f,m,p[i])){
            f[j]=p[i];
            j=(j+1)%m;

            printf("PF No. %d: ",++pf);
            show(f,m);
        }

    printf("FIFO Page Faults: %d\n",pf);
}

void lru(int p[],int n,int m){
    int f[10],t[10],i,j,min,pf=0,c=0;

    for(i=0;i<m;i++) f[i]=t[i]=-1;

    printf("\nLRU Page Replacement Process:\n");

    for(i=0;i<n;i++){
        c++;

        for(j=0;j<m;j++)
            if(f[j]==p[i]) t[j]=c;

        if(!hit(f,m,p[i])){
            min=0;

            for(j=1;j<m;j++)
                if(t[j]<t[min]) min=j;

            f[min]=p[i];
            t[min]=c;

            printf("PF No. %d: ",++pf);
            show(f,m);
        }
    }

    printf("LRU Page Faults: %d\n",pf);
}

void optimal(int p[],int n,int m){
    int f[10],i,j,k,pos,far,pf=0;

    for(i=0;i<m;i++) f[i]=-1;

    printf("\nOptimal Page Replacement Process:\n");

    for(i=0;i<n;i++)
        if(!hit(f,m,p[i])){
            pos=0; far=-1;

            for(j=0;j<m;j++){
                for(k=i+1;k<n;k++)
                    if(f[j]==p[k]) break;

                if(k>far)
                    far=k,pos=j;
            }

            f[pos]=p[i];

            printf("PF No. %d: ",++pf);
            show(f,m);
        }

    printf("Optimal Page Faults: %d\n",pf);
}

int main(){
    int n,m,i,p[20];

    printf("Enter the number of Frames: ");
    scanf("%d",&m);

    printf("Enter the length of reference string: ");
    scanf("%d",&n);

    printf("Enter the reference string: ");

    for(i=0;i<n;i++)
        scanf("%d",&p[i]);

    fifo(p,n,m);
    lru(p,n,m);
    optimal(p,n,m);

    return 0;
}
