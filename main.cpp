#include <iostream>
#include <cmath>

//OPERATING SYSTEMS ASSIGNMENT
//ENIANG GRACE ARCHIBONG 219IT02000233
//OKOH GIDEON 219EI01000022
//JOHN AGYEKUM KUFFOUR 219IT02000241

//GROUP WORK 1 ON EXPERIMENT 1, 2, 4, 5 AND 6.

using namespace std;

int main()
{
    //Declaring variables
    int Questions, availableMemory, blockSize, numberOfBlocks, external_fragmentation, numberOfProcesses, memoryProcess[10],totalInternalFragment=0;
    int memorySize, pageSize, no_ofPagesAvail, no_ofProcesses, rempages, i, j, ProNum, PageNum, physicalAddress, offset;
    int burstTime[20], waitingTime[20], turnAroundTime[20],systemUser[20], priOfPro[20], pp[20], k, temp, BurstTime[10], WaitingTime[10], TurnAroundTime[10], TimeSlice, ct[10], max, CPUScheduling;
    float waitingTimeavg, turnAroundTimeavg, avgWaitingTime=0, avgTurnAroundTime=0, Temp=0;
    double memoryTechnique;
    char ch= 'y';
    int p=0,n=0;
    int s[10], fno[10][20];

    //Asking the user to enter his preferred question number
    cout<<"Enter your preferred question 1. MVT and MFT"<<endl;
    cout<<"                              2. Paging technique of memory management"<<endl;
    cout<<"                              3. Turnaround time and waiting time"<<endl;
    cout<<"                              4. Multi-level queue scheduling"<<endl;
    cin>>Questions;

                if (Questions==1)
                    {
                        do {
                        //Asking the user to enter a preferred memory technique
                        cout<<"Choose your preferred memory management technique 1. Multiprogramming with a fixed number of Tasks"<<endl;
                        cout<<"                                                  2. Multiprogramming with a variable number of tasks"<<endl;
                        cin>>memoryTechnique;

                        // Using the if to make a decision

                        if (memoryTechnique==1)
                            {
                                cout<<"Enter the total memory available (in Bytes)\n"<<endl;
                                cin>>availableMemory;
                                cout<<"Enter the block size (in Bytes)\n"<<endl;
                                cin>>blockSize;

                                //Taking the number of process for computation
                                numberOfBlocks= availableMemory/blockSize;
                                external_fragmentation= availableMemory - numberOfBlocks*blockSize;
                                cout<<"\nEnter the number of processes\n"<<endl;
                                cin>>numberOfProcesses;
                                for(i=0;i<numberOfProcesses;i++)
                                    {
                                        cout<<"Enter memory required for process (in bytes)\n"<<i+1<<endl;
                                        cin>>memoryProcess[i];
                                    }
                                // Displaying the number of blocks available in memory
                                cout<<"\nNo. of Blocks available in memory\n"<<numberOfBlocks<<endl;
                                cout<<"\n\nPROCESS\tMEMORY REQUIRED\t ALLOCATED\tINTERNAL FRAGMENTATION"<<endl;
                                for(i=0;i<numberOfProcesses && p<numberOfBlocks;i++)
                                    {
                                        cout<<"\n"<<i+1<<"  \t\t"<<memoryProcess[i]<<endl;
                                        //Making decisions with the if else if
                                        if(memoryProcess[i] > blockSize)
                                        cout<<"\t\tNO\t\t--"<<endl;
                                        else
                                             {
                                                cout<<"\t\tYES\t"<<blockSize-memoryProcess[i]<<endl;
                                                totalInternalFragment = totalInternalFragment + blockSize-memoryProcess[i];
                                                p++;
                                             }
                                     }
                                if(i<numberOfProcesses)
                                    {
                                        cout<<"\nMemory is Full, Remaining Processes cannot be accommodated"<<endl;
                                        cout<<"\n\nTotal Internal Fragmentation is "<<totalInternalFragment<<endl;
                                        cout<<"\nTotal External Fragmentation is "<<external_fragmentation<<endl;
                                    }
                            }
                        else if(memoryTechnique==2)
                            {
                                cout<<"\nEnter the total memory available (in Bytes)\n "<<endl;
                                cin>>availableMemory;
                                temp=availableMemory;
                                for(i=0; ch=='y'; i++,n++)
                                    {
                                        cout<<"\nEnter memory required for process (in Bytes)\n"<<i+1<<endl;
                                        cin>>memoryProcess[i];

                                        if(memoryProcess[i]<=temp)
                                            {
                                                cout<<"\nMemory is allocated for Process "<<i+1<<endl;
                                                temp = temp - memoryProcess[i];
                                            }
                                        else
                                        {
                                            cout<<"\nMemory is Full"<<endl;
                                            break;
                                        }
                                        cout<<"\nDo you want to continue(Y/N) -- "<<endl;
                                        cin>>ch;
                                    }
                                while (ch == 'Y' || ch == 'y');
                                cout<<"\n\nTotal Memory Available "<<availableMemory<<endl;

                                cout<<"\n\n\tPROCESS\t\t MEMORY ALLOCATED "<<endl;
                                for(i=0; i<n; i++)
                                cout<<"\n \t"<<memoryProcess[i]<<"  \t\t"<<i+1<<endl;
                                cout<<"\n\nTotal Memory Allocated is "<<availableMemory-temp<<endl;
                                cout<<"\nTotal External Fragmentation is "<<temp<<endl;
                            }
                             cout<<"Wrong input. Enter 1 or 2"<<endl;
                             cin>>memoryTechnique;
                            }
                       while (memoryTechnique !=1 || memoryTechnique !=2);
                    }



    //Question 2 on paging technique of memory management

         if (Questions==2)
            {
            //This program simulates paging technique of memory management.
            cout<<"\nEnter the memory size -- "<<endl;
            cin>>memorySize;
            cout<<"\nEnter the page size -- "<<endl;
            cin>>pageSize;

            cout<<"\nThe no. of pages available in memory are -- "<<no_ofPagesAvail<<endl;
            //calculation for number of available pages
            no_ofPagesAvail = memorySize/pageSize;

            cout<<"\nEnter number of processes -- "<<endl;
            cin>>no_ofProcesses;

            //remaining pages same as available pages
            rempages = no_ofPagesAvail;
            // using the for loop
            for(i=1; i<=no_ofProcesses; i++)
            {
            cout<<"\nEnter no. of pages required for p-- "<<i<<endl;
            cin>>s[i];
            if(s[i] >rempages)
               {
                                cout<<"\nMemory is Full"<<endl;
                                break;
               }

              rempages = rempages - s[i];
              for(j=0;j<s[i];j++)
              cout<<"\nEnter page table for p--- "<<i<<endl;
              cin>>fno[i][j];
            }
        // asking the user to enter the logical address to find physical address
        cout<<"\nEnter Logical Address to find Physical Address "<<endl;
        cout<<"\nEnter process number --"<<endl;
        cin>>ProNum;
        cout<<"\Enter page number --"<<endl;
        cin>>PageNum;
        cout<<"\Enter offset -- "<<endl;
        cin>>offset;

         if ((ProNum>no_ofProcesses) || (PageNum>=s[i])|| (offset>=pageSize))
            cout<<"\nInvalid Process or Page Number or offset"<<endl;

             else
                {
                cout<<"\nThe Physical Address is -- "<<physicalAddress<<endl;
                //Calculation for the physical address
                physicalAddress=fno[ProNum][PageNum]*pageSize+offset;
                }
    }

            if (Questions==3)
                {
    cout<<" Choose your preferred non-preemptive CPU scheduling 1. FCFS"<<endl;
    cout<<"                                                     2. SJF"<<endl;
    cout<<"                                                     3. Round Robin"<<endl;
    cout<<"                                                     4. Priority"<<endl;
    cin>>CPUScheduling;

    if (CPUScheduling == 1)
        {
            cout<<"\nEnter the number of processes -- "<<endl;
            cin>>numberOfProcesses;

            for(i=0; i<numberOfProcesses; i++)
                {
                    cout<<"\nEnter Burst Time for Process -- "<<i<<endl;
                    cin>>burstTime[i];
                }

             //calculation for waiting time
            waitingTime[0] = waitingTimeavg = 0;
            //calculation for turn around time
            turnAroundTime[0] = turnAroundTimeavg = burstTime[0];

            for(i=1; i<numberOfProcesses; i++)
                {
                    waitingTime[i] = waitingTime[i-1] +burstTime[i-1];
                    turnAroundTime[i] = turnAroundTime[i-1] +burstTime[i];
                    waitingTimeavg = waitingTimeavg + waitingTime[i];
                    turnAroundTimeavg = turnAroundTimeavg + turnAroundTime[i];
                }

            cout<<"\t PROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n"<<endl;

            for(i=0; i<numberOfProcesses; i++)

            cout<<"\n\tP"<<i<<"  \t\t"<<burstTime[i]<<"  \t\t"<<waitingTime[i]<<"  \t\t"<<turnAroundTime[i]<<endl;
            cout<<"\nAverage Waiting Time --   "<<waitingTimeavg/numberOfProcesses<<endl;
            cout<<"\nAverage Turnaround Time --   "<<turnAroundTimeavg/numberOfProcesses<<endl;
        }

    else if (CPUScheduling == 2)
        {
            cout<<"\nEnter the number of processes -- "<<endl;
            cin>>numberOfProcesses;
            for(i=0; i<numberOfProcesses; i++)
                {
                    pp[i]=i;
                    cout<<"Enter Burst Time for Process  -- "<<i<<endl;
                    cin>>burstTime[i];
                }
            for(i=0; i<numberOfProcesses; i++)
            for(k=i+1; k<numberOfProcesses; k++)
            if (burstTime[i]>burstTime[k])
                {
                    temp=burstTime[i];
                    burstTime[i]=burstTime[k];
                    burstTime[k]=temp;
                    temp=pp[i];
                    pp[i]=pp[k];
                    pp[k]=temp;
                }
            waitingTime[0] = waitingTimeavg = 0;
            turnAroundTime[0] = turnAroundTimeavg = burstTime[0];
            for(i=1; i<numberOfProcesses ;i++)
                {
                    waitingTime[i] = waitingTime[i-1] +burstTime[i-1];
                    turnAroundTime[i] = turnAroundTime[i-1] +burstTime[i];
                    waitingTimeavg = waitingTimeavg + waitingTime[i];
                    turnAroundTimeavg = turnAroundTimeavg + turnAroundTime[i];
                }
            cout<<"\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n"<<endl;
            for(i=0; i<numberOfProcesses; i++)
            cout<<"\n\t P"<<pp[i]<<"  \t\t"<<burstTime[i]<<"  \t\t"<<waitingTime[i]<<"  \t\t"<<turnAroundTime[i]<<endl;
            cout<<"\nAverage Waiting Time -- "<<waitingTimeavg/numberOfProcesses<<endl;
            cout<<"\nAverage Turnaround Time -- "<<turnAroundTimeavg/numberOfProcesses<<endl;
        }

    else if (CPUScheduling ==3)
        {
            cout<<"Enter the no of processes -- "<<endl;
            cin>>numberOfProcesses;
            for(i=0; i<numberOfProcesses; i++)
                {
                    cout<<"\nEnter Burst Time for process  -- "<<i+1<<endl;
                    cin>>BurstTime[i];
                    ct[i]=BurstTime[i];
                }
            cout<<"\nEnter the size of time slice -- "<<endl;
            cin>>TimeSlice;
            max=BurstTime[0];
            for(i=1; i<numberOfProcesses; i++)
            if (max<BurstTime[i])
            max=BurstTime[i];
            for(j=0; j<(max/TimeSlice)+1; j++)
            for(i=0; i<numberOfProcesses; i++)
            if (BurstTime[i]!=0)
            if (BurstTime[i]<=TimeSlice)
                {
                    TurnAroundTime[i]= Temp + BurstTime[i];
                    Temp= Temp+BurstTime[i];
                    BurstTime[i]=0;
                }
            else {
                    BurstTime[i]= BurstTime[i]-TimeSlice;
                    Temp= Temp+TimeSlice;
             }
            for(i=0; i<numberOfProcesses; i++)
                {
                    WaitingTime[i]=TurnAroundTime[i]-ct[i];
                    avgTurnAroundTime+=TurnAroundTime[i];
                    avgTurnAroundTime+=WaitingTime[i];
                }
            cout<<"\nThe Average Turnaround time is -- "<<avgTurnAroundTime/numberOfProcesses<<endl;
            cout<<"\nThe Average Waiting time is --  "<<avgWaitingTime/numberOfProcesses<<endl;
            cout<<"\n\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME\n"<<endl;
            for(i=0; i<numberOfProcesses; i++)
            cout<<"\n"<<i+1<<"  \t\t"<<ct[i]<<"  \t\t"<<WaitingTime[i]<<  "\t\t"<<TurnAroundTime[i]<<endl;
        }

    else if (CPUScheduling ==4){
            cout<<"Enter the number of processes --- "<<endl;
            cin>>numberOfProcesses;
            for(i=0; i<numberOfProcesses; i++)
                {
                    pp[i] = i;
                    cout<<"Enter the Burst Time  --- "<<i<<endl;
                    cin>>burstTime[i];
                    cout<<"Enter the Priority of Process  ---"<<i<<endl;
                    cin>>priOfPro[i];
                }
            for(i=0; i<numberOfProcesses; i++)
            for(k=i+1; k<numberOfProcesses; k++)
            if (priOfPro[i] > priOfPro[k])
                {
                    temp=pp[i];
                    pp[i]=pp[k];
                    pp[k]=temp;
                    temp=burstTime[i];
                    burstTime[i]=burstTime[k];
                    burstTime[k]=temp;
                    temp=priOfPro[i];
                    priOfPro[i]=priOfPro[k];
                    priOfPro[k]=temp;
                }
            waitingTimeavg = waitingTime[0] = 0;
            turnAroundTimeavg = turnAroundTime[0] = burstTime[0];
            for(i=1; i<numberOfProcesses; i++)
                {
                    waitingTime[i] = waitingTime[i-1] + burstTime[i-1];
                    turnAroundTime[i] = turnAroundTime[i-1] + burstTime[i];
                    waitingTimeavg = waitingTimeavg + waitingTime[i];
                    turnAroundTimeavg = turnAroundTimeavg + turnAroundTime[i];
                }
            cout<<"\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME"<<endl;
            for(i=0; i<numberOfProcesses; i++)
            cout<<"\n"<<pp[i]<<"  \t\t"<<priOfPro[i]<<"  \t\t"<<burstTime[i]<<"  \t\t"<<waitingTime[i]<<"  \t\t"<<turnAroundTime[i]<<endl;
            cout<<"\nAverage Waiting Time is --- "<<waitingTimeavg/numberOfProcesses<<endl;
            cout<<"\nAverage Turnaround Time is --- "<<turnAroundTimeavg/numberOfProcesses<<endl;

        }
         else if (CPUScheduling !=1 || CPUScheduling !=2 || CPUScheduling !=3 || CPUScheduling !=4)
        cout<<"Wrong input. Enter a number from 1 to 4"<<endl;
        cin>>CPUScheduling;
    }

        if (Questions==4)
            {
    cout<<"Enter the number of processes --- "<<endl;
    cin>>numberOfProcesses;
    for(i=0; i<numberOfProcesses; i++)
        {
            pp[i] = i;
            cout<<"Enter the Burst Time of Process  --- "<<i<<endl;
            cin>>burstTime[i];
            cout<<"System/User Process (0/1) ? --- "<<endl;
            cin>>systemUser[i];
        }
    for(i=0; i<numberOfProcesses; i++)
    for(k=i+1; k<numberOfProcesses; k++)
    if (systemUser[i] > systemUser[k])
        {
           temp=pp[i];
           pp[i]=pp[k];
           pp[k]=temp;
           temp=burstTime[i];
           burstTime[i]=burstTime[k];
           burstTime[k]=temp;
           temp=systemUser[i];
           systemUser[i]=systemUser[k];
           systemUser[k]=temp;
        }
    waitingTimeavg = waitingTime[0] = 0;
    turnAroundTimeavg = turnAroundTime[0] = burstTime[0];
    for(i=1; i<numberOfProcesses; i++)
        {
            waitingTime[i] = waitingTime[i-1] + burstTime[i-1];
            turnAroundTime[i] = turnAroundTime[i-1] + burstTime[i];
            waitingTimeavg = waitingTimeavg + waitingTime[i];
            turnAroundTimeavg = turnAroundTimeavg + turnAroundTime[i];
        }
    cout<<"\nPROCESS\t\t SYSTEM/USER PROCESS \tBURST TIME\tWAITING TIME\tTURNAROUND TIME"<<endl;
    for(i=0; i<numberOfProcesses; i++)
    cout<<"\n"<<pp[i]<<"  \t\t"<<systemUser[i]<<"  \t\t"<<burstTime[i]<<"  \t\t"<<waitingTime[i]<<"  \t\t"<<turnAroundTime[i]<<endl;
    cout<<"\nAverage Waiting Time is --- "<<waitingTimeavg/numberOfProcesses<<endl;
    cout<<"\nAverage Turnaround Time is --- "<<turnAroundTimeavg/numberOfProcesses<<endl;
}


    return 0;
}
