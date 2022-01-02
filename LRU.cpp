#include<iostream>
using namespace std;
int main()
{
    int nopages, nofaults, page[20],i ,count=0;
    cout<<"Enter the Number of pages :\t";
    cin>> nopages;  //it will store the number of Pages
    cout<<"\nEnter the Reference String :\t";
    for(i=0;i< nopages;i++)
    {
        cout<<"";
        cin>>page[i];
    }
    cout<<"\nEnter the Number of frames:\t";
    cin>> nofaults;
    int frame[nofaults],fcount[nofaults];
    for(i=0;i< nofaults;i++)
    {
        frame[i]=-1;
        fcount[i]=0; //it will keep the track of when the page was last used
    }
    i=0;
    while(i< nopages)
    {
        int j=0,flag=0;
        while(j< nofaults)
        {
            if(page[i]==frame[j])  //it will check whether the page already exist in frames or not
            {
                flag=1;
                fcount[j]=i+1;
            }
            j++;
        }
        j=0;
        cout<<"\n\t\n";
        cout<<"\t"<<page[i]<<"  ->";
        if(flag==0)
        {
            int min=0,k=0;
            while(k<nofaults-1)
            {
                if(fcount[min]>fcount[k+1]) //It will calculate the page which is least recently used
                min=k+1;
                k++;
            }
            frame[min]=page[i];
            fcount[min]=i+1;  //Increasing the time
            count++;          //it will count the total Page Fault
            while(j< nofaults)
            {
                cout<<"\t|"<<frame[j]<<"|";
                j++;
            }
        }
        i++;
    }
    cout<<"\n\nNumber of Page Faults :"<<count;
    cout<<"\n\nNumber of Hits :"<<nopages - count;
    cout<<"\n" << endl;
    cout << "Hit Ratio: " << (nopages-count)*100/nopages << "%" << endl;
    cout << "Miss Ratio: " << count/nopages*100 << "%" << endl;

    return 0;
 }
/*
8
7 0 1 2 0 3 0 5
3
*/
