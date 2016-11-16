# Problem: http://www.geeksforgeeks.org/given-sorted-dictionary-find-precedence-characters/ # noqa
# Input:  words[] = {"baa", "abcd", "abca", "cab", "cad"}
# Output: Order of characters is 'b', 'd', 'a', 'c'

from collections import defaultdict


class Graph:
    def __init__(self, V):
        self.num_vertices = V
        self.adj = defaultdict(list)
        """ All nodes adjacent to any given node """
        self.parent = {}
        """ Mapping of each node to it's parent """

    def add_edge(self, u, v):
        self.adj[u].append(v)

    def dfs_visit(self, s):
        if s not in self.adj:
            return
        for v in sorted(self.adj[s]):
            print('  dfs_visit for {}: {}'.format(v, self.parent))
            if v not in self.parent:
                self.parent[v] = s
                self.dfs_visit(v)

    def dfs(self):
        for s in sorted(self.adj.keys()):
            print('dfs for {}: {}'.format(s, self.parent))
            if s not in self.parent:
                self.parent[s] = None
                self.dfs_visit(s)

    def topo():
        print('Doing topo')


def make_graph(graph_type='cormen'):
    g = Graph(6)
    if graph_type == 'cormen':
        g.add_edge('u', 'v')
        g.add_edge('u', 'x')
        g.add_edge('v', 'y')
        g.add_edge('y', 'x')
        g.add_edge('x', 'v')
        g.add_edge('w', 'z')
        g.add_edge('w', 'y')
        g.add_edge('z', 'z')
    else:
        g.add_edge(1, 2)
        g.add_edge(1, 3)
        g.add_edge(2, 4)
        g.add_edge(3, 4)
    return g


def main():
    g = make_graph()
    from pprint import pprint
    print('graph: ', end='')
    pprint(g.adj)
    g.dfs()
    print(g.__dict__)
    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main())
