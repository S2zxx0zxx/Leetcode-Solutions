class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        from math import gcd
        
        def getSlope(p1, p2):
            dx = p2[0] - p1[0]
            dy = p2[1] - p1[1]
            if dx == 0: return (0, 1)
            if dy == 0: return (1, 0)
            g = gcd(abs(dx), abs(dy))
            if dx < 0: dx, dy = -dx, -dy
            return (dx // g, dy // g)
        
        n = len(points)
        if n <= 2: return n
        
        res = 2
        for i in range(n):
            slopes = defaultdict(int)
            for j in range(i+1, n):
                slope = getSlope(points[i], points[j])
                slopes[slope] += 1
                res = max(res, slopes[slope] + 1)
        
        return res