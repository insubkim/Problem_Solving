#include <iostream>
#include <unistd.h>
#include <string>
#include <string.h>

using namespace std;

int ignore_tag(char *input, int start)
{
    int i = start;

    while (input[i])
    {
        if (input[i] != '<') break;

        while (input[i] != '>')
            i++;
        i++;
    }

    return i;
}

void reverse_word(char *input, int start, int end)
{
    for (; start < end; start++, end--)
    {
        char tmp = input[start];
        input[start] = input[end];
        input[end] = tmp;
    }
}

int main(void)
{
    char input[100000+1] = {0,};
    
    int byte = read(0, input, sizeof(input));
    input[byte - 1] = 0;

    //find tag
    //store start
    //find end
    int i = 0;
    while (input[i])
    {
        int start = ignore_tag(input, i);

        while (input[start] == ' ')
            start++;
     
        int end = start;
        while (input[end] && input[end] != '<' && input[end] != ' ' )
            end++;
        
        reverse_word(input, start, end - 1);

        i = end;
    }


    write(1, input, strlen(input));
    write(1, "\n", 1);


    return 0;
}