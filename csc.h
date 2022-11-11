#ifndef CSC_H // header guard
#define CSC_H

#include<iostream>
#include <limits>
#include <ios>

using namespace std;

struct student
{
   int reg_no;
   char name[20];
   int ce,pe,te;
};

// Stacks Representation 
class stack
{
   private:
      int TOS = -1;
      int n;
   public:
      stack(int size) : n(size) {}
      void push(int array[], int val);
      void pop(int array[]);
      void top(int array[]);
      void show_stack(int array[]);
};

// Queue Representation
class queue
{
   private:
      int n;
      int rear = -1;
      int front = -1;
   public:
      queue(int size) : n(size) {} 
      void insert(int que[], int val);
      void deletion(int que[]);
      void show_queue(int que[]);
};

// STACKS
void stack::push(int array[], int val)
{
   if(TOS < n)
   {
      TOS++;
      array[TOS] = val;
   }
   else
   {
      cout << " Buffer Overflow " << endl;
   }
}

void stack::pop(int array[])
{
   int val;
   if(TOS > -1)
   {
      val = array[TOS];
      TOS--;
   }
   else
   {
      cout << " Buffer Underflow " << endl;
   }
}

void stack::top(int array[])
{
   if(TOS > -1)
      cout << array[TOS] << " ";
   else
      cout << " Stack is Empty " << endl;
}

void stack::show_stack(int array[])
{
   for(int i=TOS;i>-1;i--)
   {
      cout << array[i] << " ";
   }
}

void queue::insert(int que[], int val)
{
   if(rear == -1)
	{
		front = 0;
		rear = 0;
		que[rear] = val;
	}
	else if(rear < n)
	{
		rear++;
		que[rear] = val;
	}
	else
	{
		std::cout << " Queue Overflow " << std::endl;
	}

}

void queue::deletion(int que[])
{  
   int val;
	if(front > -1 && front < rear)
	{
		val = que[front];
		front++;
	}
	else
	{
		std::cout << " Queue Underflow " << std::endl;
	}

	if(front > rear)
	{
		front = -1;
		rear = -1;
	}

}

void queue::show_queue(int que[])
{
   cout << "\n Elements : ";
   for(int i=front;i<=rear;i++)
   {
      cout << que[i] << " ";
   }
   cout << "\n Front of the queue = " << que[front] << endl;
   cout << " Rear of the queue = " << que[rear] << endl;
}

// CHAPTER 3

void stack_representation()
{
   stack mystack(10);
   int array[10];
   mystack.push(array, 10);
   mystack.push(array, 20);
   mystack.push(array, 30);
   mystack.push(array, 40);
   mystack.push(array, 50);
   cout << " Elments in Stack : ";
   mystack.show_stack(array);
   mystack.pop(array);
   cout << "\n After Performing pop function :- " << endl;
   cout << " Elements in Stack : ";
   mystack.show_stack(array);
   mystack.pop(array);
   cout << "\n pop again :- " << endl;
   cout << " Elements in Stack : ";
   mystack.show_stack(array);
   cout << endl;
}

void queue_representation()
{
   queue myqueue(10);
   int data[10];
   myqueue.insert(data, 10);
   myqueue.insert(data, 20);
   myqueue.insert(data, 30);
   myqueue.insert(data, 40);
   myqueue.insert(data, 50);
   myqueue.show_queue(data);
   myqueue.deletion(data);
   cout << " Delete 1 element :- ";
   myqueue.show_queue(data);
   myqueue.deletion(data);
   cout << " Delete 2 elements :- ";
   myqueue.show_queue(data);
}

// CHAPTER 1

void marklist( )
{
   student s[50];
   int n,i,tot_score[50];
   cout << "\n Marklist:- " << endl;
   cout << " Enter the number of students : ";
   cin >> n;
   for(i=0;i<n;i++)
   {
      cout <<" Enter the register number : ";
      cin >> s[i].reg_no;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout <<" Enter the name : ";
      cin.getline(s[i].name,20);
      cout <<" Enter the scores in C.E,P.E and T.E. : ";
      cin >> s[i].ce >> s[i].pe >> s[i].te;
      tot_score[i] = s[i].ce + s[i].pe + s[i].te;
   }
   cout<<" The student details are......\n";
   for(i=0;i<n;i++)
   {
      cout<< " Register Number : " <<s[i].reg_no<<endl;
      cout<< " Name : " <<s[i].name<<endl;
      cout<< " C.E. score : "<<s[i].ce <<endl;
      cout<< " P.E. score : "<<s[i].pe<<endl;
      cout<< " T.E. score : "<<s[i].te<<endl;
      cout<< " Total score : "<<tot_score[i];
   }
}

#endif
