#include<stdio.h>
#include<stdlib.h>
#define MIN(x,y) (x<y)?x:y

int main()
{
    int cap, output_rate, input_rate[50], i =0;
    int time_elapsed=0,ch,count=0,pending_data,droped_data;
    
    printf("Enter the Bucket Capacity\n");
    scanf("%d",&cap);
    
    printf("Enter the Output Rate\n");
    scanf("%d",&output_rate);

    do
    {
        printf("Enter the Input Rate\n");
        scanf("%d",&input_rate[i]);
        
        if(input_rate[i] > cap)
        {
            printf("Bucket Overflow\n");
            printf("Packet Discarded\n");
            
            exit(0);
        }
        i++;
        
        printf("Enter 1 to continue or 0 to stop");
        scanf("%d",&ch);
        
    }while(ch);
    
    time_elapsed = i;
    
    printf("\n Second \t Recieved \t Sent \t Dropped \tRemained \n");
    for(i=0;count || i<time_elapsed; i++)
    {
        printf("%d\t",i+1);
        printf("\t%d\t",input_rate[i]);
        printf("\t%d\t",MIN((input_rate[i]+count), output_rate));
        
        if(((pending_data=input_rate[i]+count-output_rate)> 0))
        {
            if(pending_data > cap)
            {
                count = cap;
                droped_data = pending_data-cap;
            }
            else
            {
                count =  pending_data;
                droped_data = 0;
            }
        }
        else
        {
            count = 0;
            droped_data = 0;
        }
        
        printf("\t%d\t",droped_data);
        printf("\t%d\t\n",count);
    }
    return 0;
}