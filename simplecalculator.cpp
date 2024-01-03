//TASK-2: SIMPLE CALCULATOR 
#include<iostream>
using namespace std;
int main()
{
char choice;
do {
    cout<<"-----Simple Calculator-----"<<endl;
    cout<<"Here's a simple calculator where you can perform various arithmetic operations"<<endl;
    //Declare variables to store input from the user
    double num1,num2,result;
    char operation;
    //Get user input
    cout<<"Enter first number: ";
    cin>>num1;
    cout<<"Enter second number: ";
    cin>>num2;
    //Creating Legend for the user
    cout<<"-------"<<endl;
    cout<<"Legend:"<<endl;
    cout<<"-------"<<endl;
    cout<<"+ -> Additon"<<endl;
    cout<<"- -> Subtraction"<<endl;
    cout<<"* -> Multiplication"<<endl;
    cout<<"/ -> Division"<<endl;
    //Get the operator input from the user
    cout<<"Choose the operation to perform (+,-,*,/): ";
    cin>>operation;
    //Perform calculation based on the operation chosen
    switch(operation)
    {
        case '+':
            result = num1+num2;
            break;
        case '-':
            result = num1-num2;
            break;
        case '*':
            result = num1*num2;
            break;
        case '/':
            if (num2!=0){
            result = num1/num2;
            } else {
                cout<<"Error: Division by zero is not possible"<<endl;
            }
            break;
        default:
            cout<<"Invalid Operation. Please choose +,-,* or /"<<endl;
            continue;
    }
    //Displaying the result
    cout<<"Result: "<<result<<endl;
    //Asking the user if they want to perform another operation
    cout<<"Do you want to perform another calculation? (y/n): ";
    cin>>choice;
}   while(choice=='y'||choice=='Y');
    cout<<"Thank You...!!!"<<endl;
    return 0;
}