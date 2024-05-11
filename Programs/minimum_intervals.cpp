#include<iostream>
#include<vector>
#include<algorithm>

int leastInterval(std::vector<char>& tasks, int interval) 
{
    // Create a frequency array to keep track of the count of each task
    std::vector<int> freq(26);
    for (char task : tasks) 
    {
        //increments count of all given tasks
	freq[task - 'A']++;
    }
    //Sort the freq in ascending order of frequency
    sort(freq.begin(), freq.end());
    // get the maximum frequency out of all task
    //Note that empty tasks will shift to front
    int maxFreq = freq[25] - 1;
    // Calculate required idle slots by checking frequency of max task * total tasks
    int idleSlots = maxFreq * interval;
    // Iterate over the frequency array from the second highest frequency to the lowest frequency
    for (int i = 24; i >= 0 && freq[i] > 0; i--) 
    {
        //Calculate the minimum alternate tasks possible by getting min of curr task/max freq task
        idleSlots -= std::min(maxFreq, freq[i]);
    }
    // If there are any idle slots left, add them to the total number of tasks
    return idleSlots > 0 ? idleSlots + tasks.size() : tasks.size();
        
}

int main()
{
    int n = 0;
    std::cout<<"Enter the number of tasks : "<<std::endl;
    std::cin>>n;
    std::vector<char> tasks;
    char input;
    for(int i = 0; i < n; i++)
    {
        std::cin>>input;
        tasks.push_back(input);
    }
    int interval = 0;
    std::cout<<"Enter the time interval to separate similar tasks :"<<std::endl;
    std::cin>>interval;
    std::cout<<"minimum time to complete all the tasks :"<<leastInterval(tasks, interval); 

}
