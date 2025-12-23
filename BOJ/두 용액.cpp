#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> p_arr;
vector<int> m_arr;

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int val;
        cin >> val;
        if (val >= 0) p_arr.push_back(val);
        else m_arr.push_back(-val);
    }
    
    sort(p_arr.begin(), p_arr.end());
    sort(m_arr.begin(), m_arr.end());

    int min = INT_MAX;

    int i = 0;
    int j = 0;

    int min_i = 0;
    int min_j = 0;
    while (1)
    {
        int val = p_arr[i] - m_arr[j];
        
        if (abs(min) > abs(val)) 
        {
            min = val;
            min_i = i;
            min_j = j;    
        }

        if (i != p_arr.size() && j != m_arr.size()) 
        {
            int val2 = p_arr[i + 1] - m_arr[j];
            int val3 = p_arr[i] - m_arr[j + 1];
            if (abs(val2) < abs(val3)) i++;
            else j++;
        }
        else if (i != p_arr.size() && j == m_arr.size()) i++;
        else if (i == p_arr.size() && j != m_arr.size()) j++;
        else break ;
    }

    // if (i != p_arr.size())
    // {
    //     int val = p_arr[i + 1] - m_arr[j];
    //     if (min > val) 
    //     {
    //         min = val;
    //         min_i = i;
    //         min_j = j;
    //     }
    // }
    
    // if (j != m_arr.size())
    // {
    //     int val = p_arr[i] - m_arr[j + 1];
    //     if (min > val) 
    //     {
    //         min = val;
    //         min_i = i;
    //         min_j = j;
    //     }
    // }

    int flag = 0;
    
    if (p_arr.size() > 1)
    {
        int val = p_arr[0] + p_arr[1];
        if (abs(min) > abs(val))
        {
            flag = 1;
        }
    }
    if (m_arr.size() > 1)
    {
        int val = m_arr[0] + m_arr[1];
        if (abs(min) > abs(val))
        {
            flag = 2;
        }
    }
    
    if (flag == 0) cout << -m_arr[min_j] << " " << p_arr[min_i] << endl; 
    else if (flag == 1) cout << p_arr[0] << " " << p_arr[1] << endl;
    else cout << -m_arr[1] << " " << -m_arr[0] << endl;
}