#include <iostream>

//for extended ASCII characters, alphabet size is 256
//this helps calculate the hash function of a 256 pattern size at once
#define ALPHABET_SIZE 256

class RabinKarp 
{
    public:
    void search(std::string pattern, std::string text, int prime) 
    {
        int patternLength = pattern.size();
        int textLength = text.size();
        int i, j;
        int patternHash = 0;
        int textHash = 0;
        //h : calculates the initial hash
        int hash = 1;

        for (i = 0; i < patternLength - 1; i++)
        {
            hash = (hash * ALPHABET_SIZE) % prime;
        }

        for (i = 0; i < patternLength; i++) 
        {
            patternHash = (ALPHABET_SIZE * patternHash + pattern[i]) % prime;
            textHash = (ALPHABET_SIZE * textHash + text[i]) % prime;
        }
        //window size = pattern size
        for (i = 0; i <= textLength - patternLength; i++) 
        {
            //if the calculated hashes are equal, patternis found in text
            if (patternHash == textHash) 
            {
                //start at i position and check if the characters are in correct positions
                for (j = 0; j < patternLength; j++) 
                {
                    if (text[i + j] != pattern[j])
                    {
                        break;
                    }
                }
                //if all the characters match, print the location of the match
                if (j == patternLength)
                {
		    std::cout << "Pattern found at index "<<i<<std::endl;
                }
            }
            //for each loop until we reach the last possible match
            if (i < textLength - patternLength) 
            {
                //calculate rolling hash
                // remove the ith char hash: (text[i] * hash) and add the [i + patternLength]th char hash
                textHash = (ALPHABET_SIZE * (textHash - text[i] * hash) + text[i + patternLength]) % prime;
                if (textHash < 0)
                {
                    textHash = (textHash + prime);
                }
            }
        }
    }
};

int main() 
{
    std::string text, pattern;
    int prime = 101;
    std::cout << "Enter the text: ";
    getline(std::cin, text);
    std::cout << "Enter the pattern to search for: ";
    getline(std::cin, pattern);

    //larger prime numbers reduce chance of hash collisions
    //good to choose larger prime number than alphabet size and the pattern size
    std::cout<<"Enter the prime number: ";
    std::cin>>prime;
    RabinKarp rk;
    rk.search(pattern, text, prime);
    
    return 0;
}

