import sys
input = sys.stdin.readline
N, M = map(int,input().split())
graph = []
 
def find(c):
	if par[c] == c:
		return c
	else:
		par[c] = find(par[c])
	return par[c]
 
def union(a, b):
	a, b = find(a), find(b)
	par[max(a, b)] = min(a, b)
 
def check(a, b):
	return find(a) == find(b)
 
par = [i for i in range(N+1)]
for _ in range(M):
	a, b, c = map(int,input().split())
	graph.append([-c, a, b])
ts, te = map(int,input().split())
 
graph.sort()
for i in graph:
	c, a, b = i[0], i[1], i[2]
	c = abs(c)
	union(a, b)
	if check(ts, te):
		print(c)
		break