#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getCriterionIndex(const string& ext) {
  if (ext == "code")    return 0;
  if (ext == "date")    return 1;
  if (ext == "maximum") return 2;
  if (ext == "remain")  return 3;
  return -1;
}

vector<vector<int> >  extractByCriterion(const vector<vector<int> >& data, const string& ext, int val_ext) {
  vector<vector<int>> ext_data;
  // 추출 카테고리 인덱스
  int                 index_for_ext = getCriterionIndex(ext);
  
  // 추출
  for (size_t i = 0; i < data.size(); i++) {
    if (data[i][index_for_ext] < val_ext) {
      ext_data.push_back(data[i]);
    }
  }
  return ext_data;
}

int index_for_sort_criterion = -1; // 비교 카테고리 인덱스

bool  cmp(const vector<int>& a, const vector<int>& b) {
  //use global var for criterion
  return a[index_for_sort_criterion] < b[index_for_sort_criterion];  
}

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
    vector<vector<int>> answer;

    answer = extractByCriterion(data, ext, val_ext);
    //set sort index
    index_for_sort_criterion = getCriterionIndex(sort_by);
    sort(answer.begin(), answer.end(), cmp);
    return answer;
}