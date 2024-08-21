#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
  int min_val, max_val, mod_val;
  int mod_cnt[8001] {0, }; 
  int sum_val = 0;
  vector<int> vals; 

  int N;
  cin >> N;

  for (int i = 0; i < N; i++){
    int in;
    cin >> in;
    
    mod_cnt[in + 4000]++;
    sum_val += in;
    vals.push_back(in);

    if (i == 0){
      min_val = max_val = mod_val = in;
      continue ;
    }
    min_val = min(min_val, in);
    max_val = max(max_val, in);
    mod_val = mod_cnt[in + 4000] < mod_cnt[mod_val + 4000] ? mod_val : in;
  }
  
  sort(vals.begin(), vals.end());

  bool dup_mod_cnt = false;
  for (int i = -4000; i < 4001; i++){
    if (mod_cnt[i + 4000] == mod_cnt[mod_val + 4000]){
      if (dup_mod_cnt == true){
        mod_val = i;
        break;
      }
      dup_mod_cnt = true;
    }
  }

  cout << floor(((double)sum_val / N) + 0.5) << endl;
  cout << vals[vals.size() / 2] << endl;
  cout << mod_val << endl;
  cout << max_val - min_val << endl;

}
