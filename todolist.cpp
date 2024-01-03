//TASK-4: TO DO LIST
#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct Task{
    string description;
    bool completed;
    Task(const string& desc):description(desc),completed(false){}
};
//Creating a class and including all the functions
class ToDoList{
    private:
    vector<Task> tasks;
    public:
    void addTask(const string& description) {
        tasks.push_back(Task(description));
        cout<<"Task added successfully.\n";
    }
    //To view the added tasks by the user
    void viewTasks() const{
        if (tasks.empty()){
            cout<<"No tasks available.\n";
        } else {
            cout<<"Tasks:\n";
            for(size_t i=0;i<tasks.size();++i){
                cout<<"["<<(tasks[i].completed ? "*" : " ")<<"] "<<i+1<<". "<<tasks[i].description<<"\n";
            }
        }
    }
    //To mark the specific task as completed
    void markTaskAsCompleted(size_t index){
        if(index>=1 && index<=tasks.size()) {
            tasks[index-1].completed=true;
            cout<<"Task marked as completed.\n";
        } else {
            cout<<"Invalid task index.\n";
        }
    }
    //To remove a particular task
    void removeTask(size_t index){
        if(index>=1 && index<=tasks.size()) {
            tasks.erase(tasks.begin()+index-1);
            cout<<"Task removed successfully.\n";
        } else {
            cout<<"Invalid task index.\n";
        }
    }
};
//Main function
int main() {
    ToDoList toDoList;
    int choice;
    do {
        cout<<"\n-----To-Do List-----\n";
        cout<<"1. Add Task\n";
        cout<<"2. View Tasks\n";
        cout<<"3. Mark Task as Completed\n";
        cout<<"4. Remove Task\n";
        cout<<"0. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1: {
            //Add Task
                string taskDescription;
                cout<<"Enter task description: ";
                //To solve input bug while receiving lengthy lines
                cin.ignore();
                getline(cin,taskDescription);
                toDoList.addTask(taskDescription);
                break;
            }
            case 2:{
            //View Task
                toDoList.viewTasks();
                break;
            }
            case 3:{
            //Mark Task as Completed
                size_t taskIndex;
                cout<<"Enter the task index to mark as completed: ";
                cin>>taskIndex;
                toDoList.markTaskAsCompleted(taskIndex);
                break;
            }
            case 4: {
            //Remove Task
                size_t taskIndex;
                cout<<"Enter the task index to remove: ";
                cin>>taskIndex;
                toDoList.removeTask(taskIndex);
                break;
            }
            case 0: {
            //Exit from the program
                cout<<"Thank you for using To-Do List manager...\n";
                break;
                default:
                cout<<"Invalid choice.Please try again.\n";
            }
        }
    } while (choice != 0);
    return 0;
}