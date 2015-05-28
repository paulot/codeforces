#!/usr/bin/env python2.6
from heapq import heappop, heappush

def add_node(graph, n1, n2, cost):
  graph[n1].append((n2, cost))
  graph[n2].append((n1, cost))

def dijkstra(graph, start, end):
  q, seen = [(0,start,'')], set()
  while q:
    (cost,v1,path) = heappop(q)
    if v1 not in seen:
      seen.add(v1)
      path = '%s %s' % (path, v1)
      if v1 == end: return path[1:]

      for v2, c in graph.get(v1, ()):
        if v2 not in seen:
          heappush(q, (cost+c, v2, path))
  return -1


nums = [int(i) for i in raw_input().split(' ')]
n = nums[0]
m = nums[1]
graph = dict((i, []) for i in range(1, n+1))
for _ in range(m):
  line = [int(i) for i in raw_input().split(' ')]
  add_node(*([graph]+line))

print dijkstra(graph, 1, n)
