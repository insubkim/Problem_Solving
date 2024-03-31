#include <iostream>

using namespace std;

typedef struct s_node {
  int child[50];
  int child_num;
} t_node;

t_node nodes[50];
int N;

int leafs;

void  add_child(int parent, int child) {
  nodes[parent].child[child] = 1;
  nodes[parent].child_num++;
}

void count_leaf(int node, int del) {
  if (node == del) return ; //input == 0
  if (nodes[node].child[del]) { //delete child
    nodes[node].child[del] = 0;
    nodes[node].child_num--;
  }
  if (nodes[node].child_num == 0) {
    leafs++;
    return ;
  }

  for (int i = 0; i < N; i++) {
    if (nodes[node].child[i] == 0) continue;
    count_leaf(i, del);
  }
}

int main () {
  cin >> N;  

  int roots[50] = {0, };
  for (int i = 0; i < N; i++) {
    int p;
    cin >> p;
    if (p == -1) {
      roots[i] = 1;
      continue ;
    }
    add_child (p, i);
  }  
  
  int del;
  cin >> del;
  for (int i = 0; i < N; i++) {
    if (roots[i]) count_leaf(i, del);
  }
  cout << leafs << endl;  
}
