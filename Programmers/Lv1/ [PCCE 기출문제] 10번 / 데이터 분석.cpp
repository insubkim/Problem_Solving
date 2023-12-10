#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/*
 *  parameter
 *  data    : ["코드 번호(code)", "제조일(date)", "최대 수량(maximum)", "현재 수량(remain)"]
 *  ext     : 상한 추출 기준 code  | date | maximum | remain
 *  val_ext : ext 기준 값
 *  sort_by : 오름차순 정렬 기준 code  | date | maximum | remain 
 * 
 *  return
 *  추출 정렬 배열
 */
vector<vector<int> > solution(vector<vector<int> > data, string ext, int val_ext, string sort_by) {
  unordered_map<string, int> criterion = 
  {
    {"code",    0},
    {"date",    1},
    {"maximum", 2},
    {"remain",  3},
  };

  auto remove_list_it = remove_if(data.begin(), data.end(), \
    [idx = criterion[ext], val_ext](const auto& row) -> bool {
      return !(row[idx] < val_ext);
    });
  data.erase(remove_list_it, data.end()); 
  
  sort(data.begin(), data.end(), \
    [idx = criterion[sort_by]](const auto&a, const auto&b) -> bool {
      return a[idx] < b[idx];
    });
  return data;
}
