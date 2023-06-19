vector<string> solution(vector<vector<string>> p){
    vector<string> a;
    vector<pair<string, int>> stack;

    sort(p.begin(), p.end(), cmp);
    stack.push_back(make_pair(p[0][0], to_min(p[0][2])));
    int prev_time = to_min(p[0][1]);
    p.erase(p.begin());
    vector<string> cur;
    while (p.size() > 0){
        cur = p[0];
        p.erase(p.begin());
        while (stack.size() > 0){
            int elapse_time = to_min(cur[1]) - prev_time;
            if (elapse_time >= stack.back().second){
                a.push_back(stack.back().first);
                stack.pop_back();
            }else{
                stack.back().second = stack.back().second - elapse_time;
                break ;
            }
        }
        stack.push_back(make_pair(cur[0], to_min(cur[2])));
        prev_time = to_min(cur[1]); 
    }
    while (stack.size() > 0){
        a.push_back(stack.back().first);
        stack.pop_back();
    }
    return a;
}