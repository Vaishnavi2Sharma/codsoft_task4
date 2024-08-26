#include <iostream>
#include <string>
using namespace std;

string tasks[100];
bool isCompleted[100];
int taskCount=0;

void addTask(string taskDescription)
{
    tasks[taskCount]=taskDescription;
    isCompleted[taskCount]=false;
    taskCount++;
    cout<<"Task added:"<<taskDescription<<endl;
}

void viewTasks()
{
    if(taskCount==0)
	{
        cout<<"\nNo tasks to display"<<endl;
        return;
    }
    cout<<"\nTasks List:"<<endl;
    for(int i=0;i<taskCount;++i)
	{
        cout<<i+1<<"."<<tasks[i]<<"["<<(isCompleted[i]?"Completed":"Pending")<<"]"<<endl;
    }
}

void markTaskAsCompleted(int index)
{
    if(index>0&&index<=taskCount)
	{
        isCompleted[index-1]=true;
        cout<<"Task marked as completed:"<<tasks[index-1]<<endl;
    }
	else
	{
        cout<<"Invalid task number"<<endl;
    }
}

void removeTask(int index)
{
    if(index>0&&index<=taskCount)
	{
        cout<<"Task removed:"<<tasks[index-1]<<endl;
        for(int i=index-1;i<taskCount-1;++i)
		{
            tasks[i]=tasks[i+1];
            isCompleted[i]=isCompleted[i+1];
        }
        taskCount--;
    }
	else
	{
        cout<<"Invalid task number"<<endl;
    }
}

int main()
{
    int choice;
    string taskDescription;
    int taskNumber;

	cout<<"*****To-Do List Manager*****\n";
    cout<<"You can:\n";
    cout<<"1.Add Task\n";
    cout<<"2.View Tasks\n";
    cout<<"3.Mark Task as Completed\n";
    cout<<"4.Remove Task\n";
    cout<<"5.Exit\n";
    
    while(true)
	{
		cout<<"\nEnter your choice:";
    	cin>>choice;
        switch(choice)
		{
            case 1:
                cout<<"\nEnter task description:";
                cin.ignore(); //To ignore the newline character left by previous input
                getline(cin,taskDescription);
                addTask(taskDescription);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                cout<<"\nEnter task number to mark as completed:";
                cin>>taskNumber;
                markTaskAsCompleted(taskNumber);
                break;
            case 4:
                cout<<"\nEnter task number to remove:";
                cin>>taskNumber;
                removeTask(taskNumber);
                break;
            case 5:
                cout<<"Exiting the program"<<endl;
                return 0;
            default:
                cout<<"\nEnter a valid choice!";
        }
    }
}
