
#include <string>
#include <vector>

using namespace std;

#include <iostream>


int cal_time(string s)
{
    int time = 0;
    
    time = (s[0] - '0')* 1000 + (s[1] - '0') * 100 + (s[3] - '0') * 10 + (s[4] - '0');
    return time;
}

string cal_time_hhmm(int time)
{
    string s = "00:00";
    
    s[0] = (time/1000) % 10 + '0';
    s[1] = (time/100) % 10 + '0';
    s[3] = (time/10) % 10 + '0';
    s[4] = time % 10 + '0';
    
    return s;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    //다음 pos 설정
    
    //처음, 마지막 경계 확인
    
    //오프닝 안인지 확인
    
    //안이면 끝이로 이동
    
    int video_len_time = cal_time(video_len);
    int op_start_time = cal_time(op_start);
    int op_end_time = cal_time(op_end);
    
    int time = cal_time(pos);
    for (auto &x: commands)
    {
        if (op_start_time <= time && time <= op_end_time)
            time = op_end_time;
        
        cout << time << " " << op_start_time << " " << op_end_time << endl;

        string p = "prev";
        if (x.compare(p) == 0)
        {
            time -= 10;
            if (time % 100 >= 60)
                time = (time / 100) * 100 + (time % 100) - 40;
        }
        else
        { 
            time += 10;
            if (time % 100 >= 60)
                time = (time / 100 + 1) * 100 + (time % 10);
        }
        
        if (time < 0)
            time = 0;
        if (time > video_len_time)
            time = video_len_time;
        
        if (op_start_time <= time && time <= op_end_time)
            time = op_end_time;
    }
    
    answer = cal_time_hhmm(time);   
    return answer;
}


int main()
{
    string s1 = "07:22"; 
    string s2 = "04:55"; 
    string s3 = "00:15"; 
    string s4 = "04:07";
    
    vector<string> l;
    l.push_back("next");
    cout << solution(s1,s2,s3,s4,l) << endl;
}