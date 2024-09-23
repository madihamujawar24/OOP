#include<iostream>
#include<stdexcept>

using namespace std;
class Stack{
  private:
     int size,res;
     int top;
     int  *sArray;
  public:
     int push(int data);
     int pop();
     bool isFull();
     bool isEmpty();
     Stack();
     Stack(int size);
};
 Stack::Stack(){
	 sArray=new int[10];
	 size=10;
	 top=-1;
}
 Stack::Stack(int size1){
	 sArray=new int[size1];
	 size=size1;
	 top=-1;
}
int Stack::push(int data){
     
	  top++;
	  sArray[top]=data;
	  return top;
 
}
int Stack::pop(){
		if(isEmpty()){
	       throw out_of_range("OUT OF RANGE");
	}
	 res= top;
	 top--;
	 return res;
}
bool Stack::isFull(){
	 if(top==(size-1)){
	   return true;
	 }
	 else 
	   return false;
}
bool Stack::isEmpty(){
	 if(top==-1)
	   return true;
	 else
	  return false;
}
int main(){
        int size,data,option,result,flag=1;
	Stack s1;
	cout<<"Enter size to allocate memory:"<<endl;
	cin>>size;
	Stack s(size);
 while(flag)
	{
        cout<<"\nChoose below operations to perform on stack:"<<endl<<"1.Push"<<endl<<"2.Pop"<<endl<<"3.Exit"<<endl;
        cin>>option;
       
	  	  switch(option)
		{
    
	                case 1:if(s.isFull()) 
						  cout<<"Error"<<endl;
				          else
				          {
								cout<<"Enter number to insert:"<<endl;
						        cin>>data;
		                        result=s.push(data);
								if(result>=0)
								  cout<<"Value inserted successfully at index="<<result<<endl;
					      }
				    break;
				    case 2:try{
								  result=s.pop();
								  if(result>=0)
									  	cout<<"value deleted successfully at index="<<result;
								  else
									  	cout<<"Error";
							} 
							catch(out_of_range e){
							  	   cout << e.what() << '\n';
							  }
						break;
					
				    break;
				    case 3:flag=0;
				    break;
		            default:cout<<"Invalid Input";
				    break;
		 }
        }       
 return 0;
}
