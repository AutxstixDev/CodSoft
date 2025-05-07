#include<iostream>
using namespace std;

int add(int a,int b){
	return a+b;
}
int subtract(int a,int b){
	return a-b;
}
int multiply(int a,int b){
	return a*b;
}
int divide(int a,int b){
	if(b==0){
		cout<<"Division by zero not possible";
		return 1;
	}
	return a/b;
}


int main(){
	int a,b,choice;
	cout<<"Enter number 1:";
	cin>>a;
	cout<<"Enter number 2:";
	cin>>b;
	cout<<"Choose Operation:\n1.Add.\n2.Subtract\n3.Multiply\n4.Divide\n";
	cin>>choice;
	
	switch(choice){
		case 1:
			cout<<add(a,b);
			break;
		
		case 2:
			cout<<subtract(a,b);
			break;
		
		case 3:
			cout<<multiply(a,b);
			break;
		
		case 4:
			cout<<divide(a,b);
			break;
			
		default:
			cout<<"Invalid input";
			return 1;
	}
	return 0;
	
}