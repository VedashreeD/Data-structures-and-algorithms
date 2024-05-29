#include<iostream>

int numSteps(std::string s) 
{
	int steps = 0;
	while(s != "1") 
    {
        //we need to reach 1 in the end, so delete 0, if it is in the end
		if(s.back() == '0') 
        {
            s.pop_back();
        }
        //if the last element is 1
        else 
        {
            //until we encounter 0 or string becomes empty, continue adding steps until string becomes even or empty
			while(!s.empty() && s.back() == '1') 
            {
			    s.pop_back();
			    steps++;
			}
            //string becomes empty, we add one to it, and return steps
			if(s.empty()) 
            {
                return steps + 1;
            }
            //if s becomes even, add 1 to continue reduction process
		    else 
            {
                s.back() = '1';
            }
		}
	    steps++;
	    }
    return steps;
}

int main()
{
    std::string s;
    std::cout<<"Enter the string in binary format :"<<std::endl;
    std::cin>>s;
    std::cout<<"The number of steps required to reduce the string to 1 : "<<numSteps(s);
    return 0;
}
