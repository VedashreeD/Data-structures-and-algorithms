#include<iostream>

int compareVersion(std::string version1, std::string version2) 
{
    int m = version1.size(), n = version2.size();
    for (int i = 0, j = 0; (i < m) || (j < n); i++, j++) 
    {
        //convert the values to integers
        int value1 = 0, value2 = 0;
        while ((i < m) && (version1[i] != '.')) value1 = value1 * 10 + (version1[i++] - '0');
        while ((j < n) && (version2[j] != '.')) value2 = value2 * 10 + (version2[j++] - '0');
        // compare the values
        if (value1 < value2) return -1;
        if (value1 > value2) return 1;
    }
    return 0;
}

int main()
{
    std::string version1, version2;
    std::cout<<"Enter the 2 versions to be compared : "<<std::endl;
    std::cin>>version1>>version2;
    int res = compareVersion(version1, version2);
    if(res == -1)
    {
        std::cout<<version1<<" is greater than "<<version2<<std::endl;
    }
    else if(res == 1)
    {
        std::cout<<version2<<" is greater than "<<version1<<std::endl;
    }
    else
    {
    	std::cout<<"Both "<<version1<<" and "<<version2<<" are equal"<<std::endl;
    }


    return 0;
}
