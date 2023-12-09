#include <string>
#include <vector>

using namespace std;

/* 
 * 매개변수
 * bandage  [시전 시간, 초당 회복량, 추가 회복량]
 * health   최대 체력
 * attacks  [공격 시간, 피해량]
 * 
 * 리턴 값
 * 모든 공격이 끝난 직후 남은 체력을 return 하도록 solution 함수를 완성해 주세요. 
 * 만약 몬스터의 공격을 받고 캐릭터의 체력이 0 이하가 되어 죽는다면 -1을 return 해주세요.
 */

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    enum Attack_Index {
      SKILL_TIME          = 0,
      DAMAGE              = 1,
    };
    
    int bandage_duration  = bandage[0];
    int cure_per_sec      = bandage[1];
    int extra_cure        = bandage[2];
    int max_health        = health;

    int extra_cure_timer  = 1;
    vector<vector<int>>::iterator attack = attacks.begin();
    for (int sec = 1; health > 0 && attack != attacks.end(); sec++) {
      //check monster attack
      //continue ;
      if (attack->at(SKILL_TIME) == sec) {
        health -= attack->at(DAMAGE);
        extra_cure_timer = 1;
        ++attack;
        continue ;
      }
      
      //do cure
      //check extra cure 
      health += cure_per_sec;
      if (extra_cure_timer++ == bandage_duration) {
        health += extra_cure;
        extra_cure_timer = 1;
      }
      //check overflow
      health = health > max_health ? max_health : health;
    }
    return health <= 0 ? -1 : health;
}