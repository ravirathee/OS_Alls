
//Ravi Rathee
//16csu292
//Multiple Instance Multiple Resource

#include <stdio.h>
#define no_of_resources 3
int main() {
    
    int n,i,j,k;
    printf("\nEnter the number of processes :");
    scanf("%d",&n);
    
    int Allocation[][ no_of_resources ]={
        {0,1,0},
        {2,0,0},
        {3,0,2},
        {2,1,1},
        {0,0,2}
    };
    int Max[][ no_of_resources ]={
        {7,5,3},
        {3,2,2},
        {9,0,2},
        {2,2,2},
        {4,3,3}
    };
    int Need[n][no_of_resources];
    int Available[ no_of_resources ]={3,3,2};
    
    //    printf("\nEnter the Allocation Matrix : \n");
    //    for(i=0;i<n;i++){
    //        for(j=0;j<no_of_resources;j++)
    //            scanf("%d",&Allocation[i][j]);
    //    }
    
    printf("\nAllocation Matrix : \n");
    for(i=0;i<n;i++){
        for(j=0;j<no_of_resources;j++) {
            printf("%d ", Allocation[i][j]);
        }
        printf("\n");
    }
    
    //    printf("\nEnter the Max Matrix : ");
    //    for(i=0;i<n;i++){
    //        for(j=0;j<no_of_resources;j++)
    //            scanf("%d",&Max[i][j]);
    //
    //    }
    
    printf("\nMax Matrix : \n");
    for(i=0;i<n;i++){
        for(j=0;j<no_of_resources;j++) {
            printf("%d ", Max[i][j]);
        }
        printf("\n");
    }
    
    for(i=0;i<n;i++){
        for(j=0;j<no_of_resources;j++){
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }
    
    printf("\nNeed Matrix : \n");
    for(i=0;i<n;i++){
        for(j=0;j<no_of_resources;j++) {
            printf("%d ", Need[i][j]);
        }
        printf("\n");
    }
    
    
    //    printf("\nEnter the Available Array : ");
    //    for(i=0;i<no_of_resources;i++)
    //        scanf("%d",&Available[i]);
    
    
    printf("\nAvailable Array : ");
    for(i=0;i<no_of_resources;i++){
        printf("%d ", Available[i]);
    }
    
    printf("\n");
    
    //Main Code
    int count_processes = n;
    int count_resource = no_of_resources;
    int row_finish[5]={0};
    int turns = 0;
    
    for(;count_processes!=0 && turns<200 ; turns++) {
        //for loop will run on processes
        for(i=0;i<n;i++){
            //for loop with check is NEED < AVAILABLE or not
            if(row_finish[i]==1){
                continue;
            }
            
            for(j=0;j<no_of_resources;j++){
                if(Need[i][j] <= Available[j]){
                    count_resource--;
                }
            }
            
            if(count_resource == 0){
                for(j=0;j<no_of_resources;j++){
                    if(Need[i][j] <= Available[j]){
                        Available[j]+=Allocation[i][j];
                    }
                }
                
                
                printf("\nAvailable Array : ");
                for(k=0;k<no_of_resources;k++){
                    printf("%d ", Available[k]);
                }
                
                count_processes--;
                row_finish[i]=1;
                printf("P%d ",i);
            }
            
            count_resource = no_of_resources;
            
        }
    }
    
    return 0;
}

/*
 
 Enter the number of processes :
 5
 
 Allocation Matrix :
 0 1 0
 2 0 0
 3 0 2
 2 1 1
 0 0 2
 
 Max Matrix :
 7 5 3
 3 2 2
 9 0 2
 2 2 2
 4 3 3
 
 Need Matrix :
 7 4 3
 1 2 2
 6 0 0
 0 1 1
 4 3 1
 
 Available Array : 3 3 2
 
 Available Array : 5 3 2 P1
 Available Array : 7 4 3 P3
 Available Array : 7 4 5 P4
 Available Array : 7 5 5 P0
 Available Array : 10 5 7 P2
 
 */
