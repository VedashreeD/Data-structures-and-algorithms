#include<iostream>
#include<vector>
#include<queue>

std::vector<int> findOrder(int number_of_courses, std::vector<std::vector<int>>& prerequisites) 
{
    std::vector<std::vector<int>> courses(number_of_courses);                   
        // {prerequisite-course : [list of next courses]}
    std::vector<int> res, indegree(number_of_courses);               
        // indegree[i] denotes number of prerequisite courses for ith course
    for(auto& pre : prerequisites) 
    {
        // forming adjacency list graph
	//for every prerequisite, the current course and number of prerequisites(indegree) are mapped
	courses[pre[1]].push_back(pre[0]), indegree[pre[0]]++;       
    }
        
    std::queue<int> q;
    for(int i = 0; i < number_of_courses; i++)
    {
	//courses having no prequisites
	if(indegree[i] == 0) q.push(i);         
    } 
     
    while(!q.empty()) 
    {
        int cur = q.front(); 
	q.pop();
	//courses having no prerequisites are pushed to result
        res.push_back(cur);                     
        for(auto next_course : courses[cur])
	{
	    //remove current course from next course's prerequisite
	    //if there is no other dependency for next course, add it to queue
            if(--indegree[next_course] == 0)     
	    {
                q.push(next_course);     
	    }
	}

    }
    if(res.size() == number_of_courses) return res;              
    return {};                             
        
    }


int main()
{
    int number_of_courses;
    std::cout<<"Enter the number of courses: "<<std::endl;
    std::cin>>number_of_courses;
    int number_of_prerequisites;
    std::cout<<"Enter the number of prerequisites : "<<std::endl;
    std::cin>>number_of_prerequisites;
    int course_to_take = 0, course_prerequisite = 0;
    std::vector<std::vector<int>> prerequisites;
    for(int i = 0; i < number_of_prerequisites; i++)
    {
	std::cout<<"Enter the prerequisite [course_to_take, prerequisite_for_the_course] : "<<std::endl;
        std::cin>>course_to_take>>course_prerequisite;
        prerequisites.push_back({course_to_take, course_prerequisite});
    }
    std::cout<<prerequisites[0][0]<<" "<<prerequisites[0][1]<<std::endl;
    std::vector<int> res = findOrder(number_of_courses, prerequisites);
    if(res.size() == 0)
    {
	std::cout<<"There is no right order to take the courses!"<<std::endl;
    }
    else
    {
	std::cout<<"The order in which to take the courses : "<<std::endl;
        for(auto r : res)
        {
            std::cout<<r;
        }
    }


    return 0;
}
