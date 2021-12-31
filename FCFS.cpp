//Implementation for FIRST COME FIRST SERVE Using C++

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Schedule
{
	string pro_id;
	int artime,bt,ct,tat,wt;
	
	// artime = Arrival time,
	// bt = Burst time,
	// ct = Completion time,
	// tat = Turn around time,
	// wt = Waiting time
};

bool compare(Schedule p1,Schedule p2)
{
	return p1.artime < p2.artime;
	/* To sort the processes according to the order of their Arrival Times */
}

bool revind(Schedule p1,Schedule p2)
{
	return p1.pro_id < p2.pro_id;
	/* To revert back the processes in the order of process id */
}

int main()
{

	Schedule process[100];
	//An array of Processes

	int cpunon=0;

	int n,i;
	//n = number of processes, i= iteration variable

	float percentage;
    cout << "------\nINPUT\n------" << flush;
	cout << "\nEnter the number of processes: " << flush;
	cin >> n;

	cout << "Enter the Process id, Arrival time and Burst time of the " << n << " processes :" << endl;
	for(i=0;i<n;i++)
	{
		cin>>process[i].pro_id;
		cin >> process[i].artime;
		cin >> process[i].bt;
	}

	sort(process,process+n,compare);
	/* Sort is a predefined function defined in algorithm.h header file,
	it will sort the processes according to their arrival times */

	cpunon=process[0].artime-0;

	// initial values

	process[0].ct=process[0].artime+process[0].bt;
	process[0].tat=process[0].ct-process[0].artime;
	process[0].wt=0;

	for(i=1;i<n;i++)
	{
		if(process[i].artime<=process[i-1].ct)
		{
			process[i].ct=process[i-1].ct+process[i].bt;
			process[i].tat=process[i].ct-process[i].artime;
			process[i].wt=process[i].tat-process[i].bt;
		}
		else
		{
			process[i].ct=process[i].bt+process[i].artime;
			process[i].tat=process[i].ct-process[i].artime;
			process[i].wt=process[i].tat-process[i].bt;
			cpunon+=process[i].artime-process[i-1].ct;
		}
	}

	percentage=(float)((process[n-1].ct-cpunon)/process[n-1].ct)*100;

	cout<< endl << "-------\nOUTPUT\n-------" << endl;
	sort(process, process+n, revind);
	cout << "\n\tP#\t AT\t BT\t CT\t TAT\t WT\t\n\n" ;
	double total_tat = 0.0, total_wt = 0.0;
	for(i=0;i<n;i++)
	{
		//keep all statements in one line
		cout<<"\t"<<process[i].pro_id<<"\t "<<process[i].artime<<"\t "
		<<process[i].bt<<"\t "<<process[i].ct<<"\t "
		<<process[i].tat<<"\t "<<process[i].wt;
		total_tat += process[i].tat;
		total_wt += process[i].wt;

		cout<<endl;
	}
	cout << fixed << setprecision(2)<< endl;
    cout<<"Average Turn Around Time: "<<(total_tat/n)<<"\n";
    cout<<"Average Waiting Time: "<<(total_wt/n)<<"\n";
	return 0;
}
/*
5
1 3 4
2 5 3
3 0 2
4 5 1
5 4 3
*/