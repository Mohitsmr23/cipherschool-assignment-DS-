//Approach to proceed using 'stack' data structure:
//Steps to code it down:
//1.We will store the whole input of brackets for each test case in a string type variable.
//2.Whenever we will be encountering the all types of opening brackets push it to the stack.
//3.Keep the track of the top element of the stack and when encounters the closing bracket
// of any type. 
//4.Then compare it with the top element of the stack.
//5.If both of them are of same type then pop out the top element else print NO(means not balanced).
//6.At last check if the stack is empty or not if empty the print YES(means balanced) else NO.
								//C++ code
//##################################################################################################

#include<bits/stdc++.h>
using namespace std;
int main()
{
	//functions for fast input/output basically do flushing operation for cin and cout
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);						
	cout.tie(NULL);
	//variable to store number of test cases:
	int test_case;
	//Taking value of test cases from the user
	cin>>test_case;

	while(test_case--)
	{
		//string type variable to store the input expression
		string str;
		//Taking user input  
		cin>>str;
		//Definig stack of character type
		stack<char>s;
		int i;
		char top;	//variable to store top element of the stack

		// traversing the input string 
		for(i=0;i<str.length();i++)
		{
			if(str[i]=='(' || str[i]=='{' || str[i]=='[')
			{
				s.push(str[i]);		//pushing all the open brackets in the stack
				continue;
			}
			//checking for if the input string starts with the closing bracket of any type
			//If so then expression will not be balanced ever
			if(s.empty())
			{
				break;
			}
			//conditions to check whether the current character is same as the top element
			// of the stack or not for all types of closing brackets
			if(str[i]==')')
			{
				//store the top element of stack in top variable
 				top=s.top(); 
				if(top=='(')
				{
					s.pop();
					continue;
				}
				else
				{
					break;
				}
			}
			if(str[i]=='}')
			{
				//store the top element of stack in top variable
				top=s.top();
				if(top=='{')
				{
					s.pop();
					continue;
				}
				else
				{
					break;
				}
			}
			if(str[i]==']')
			{
				//store the top element of stack in top variable
				top=s.top();
				if(top=='[')
				{
					s.pop();
					continue;
				}
				else
				{
					break;
				}
			}
		}
		//At last check whether the stack is empty or not with one extra condition i!=0
		// means input expression is not starting with closing the bracket as we have already 
		// handled that case above if stack empty print YES as it will be balanced else not
		if(s.empty() && i!=0)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}

//#################################################################################################
// Time complexity:O(n):- As we are traversing the input string equal to its length i.e n
// Space complexity:O(n):- As in worst case we might have to store all the elements of the input
//							string in the stack.