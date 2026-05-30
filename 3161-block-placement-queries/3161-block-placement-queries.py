from sortedcontainers import SortedList

class Solution:
    def getResults(self, queries: list[list[int]]) -> list[bool]:
        MAXN = 50001
        tree = [0] * (2 * MAXN)

        def update(i, val):
            i += MAXN
            tree[i] = val
            while i > 1:
                i >>= 1
                tree[i] = max(tree[2*i], tree[2*i+1])

        def query(l, r):
            res = 0
            l += MAXN; r += MAXN + 1
            while l < r:
                if l & 1:
                    res = max(res, tree[l]); l += 1
                if r & 1:
                    r -= 1; res = max(res, tree[r])
                l >>= 1; r >>= 1
            return res

        obstacles = SortedList([0])
        results = []

        for q in queries:
            if q[0] == 1:
                pos = q[1]
                obstacles.add(pos)
                idx = obstacles.index(pos)
                left = obstacles[idx - 1]
                update(pos, pos - left)
                if idx + 1 < len(obstacles):
                    right = obstacles[idx + 1]
                    update(right, right - pos)
            else:
                x, sz = q[1], q[2]
                idx = obstacles.bisect_right(x) - 1
                left = obstacles[idx]
                gap_to_x = x - left
                max_gap = max(query(1, x), gap_to_x)
                results.append(max_gap >= sz)

        return results