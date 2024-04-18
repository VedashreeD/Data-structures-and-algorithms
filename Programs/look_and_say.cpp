//Program to generate a sequence of numbers in the following order : 
//1, 11, 21, 1211, ... to represent <count_of_number><number>
#include <iostream>
#include <string>

std::string generateNextSeq(std::string curr_seq) 
{
    std::string next_seq;
    int count = 1;
    for (int i = 0; i < curr_seq.length(); i++) 
    {
        //get the count of current digit
        if (curr_seq[i] == curr_seq[i + 1])
        {
            count++;
        } 
	else 
        {
            //append the count of digit and the digit itself into the result string, next 
            //reset count to 1 for next digit
            next_seq += std::to_string(count) + curr_seq[i];
            count = 1;
        }
    }
    return next_seq;
}

int main() 
{
    //store the base sequence as 1
    std::string curr_seq = "1";
    int n;
    std::cout << "Enter the number of sequences to generate: ";
    std::cin >> n;
    for (int i = 0; i < n; i++) 
    {
        std::cout << curr_seq << std::endl;
        curr_seq = generateNextSeq(curr_seq);
    }
    return 0;
}
