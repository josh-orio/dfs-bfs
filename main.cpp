#include <deque>
#include <map>
#include <print>
#include <set>

void dfs(std::set<int> *visited, std::map<int, std::set<int>> graph, int node) {
  if (!visited->contains(node)) {
    visited->insert(node);
    std::print(" {0}", node);

    for (int nbor : graph[node]) {
      dfs(visited, graph, nbor);
    }
  }
}

void bfs(std::set<int> *visited, std::map<int, std::set<int>> graph, int node) {
  std::deque<int> queue{node};

  while (!queue.empty()) {
    node = queue.at(0);
    visited->insert(node);
    queue.pop_front();

    std::print(" {0}", node);

    for (int nbor : graph[node]) {
      if (!visited->contains(nbor)) {
        queue.push_back(nbor);
      }
    }
  }
}

int main() {
  /* EXAMPLE GRAPH
  0
  |
  1---2
  |-| |-|
  3 4 5 6
  */

  std::map<int, std::set<int>> graph{{0, {1, 2}}, {1, {3, 4}}, {2, {5, 6}}};

  std::set<int> visited{};

  std::print("(DFS) Traversal order:");
  dfs(&visited, graph, 0);
  std::println("");

//   for (const int v : visited) {
//     std::print("{0} ", v);
//   }
//   std::println("");

  visited.clear();

  std::print("(BFS) Traversal order:");
  bfs(&visited, graph, 0);
  std::println("");

  return 0;
}