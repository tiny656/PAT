def GetDistanceSquare(p1, p2):
    return (p1.X - p2.X)**2 + (p1.Y - p2.Y)**2

def GetCross(p1, p2):
    return p1.X*p2.Y - p2.X*p1.Y

def GetVector(p1, p2):
    return Point(p2.X-p1.X, p2.Y-p1.Y)

class Point(object):
    def __init__(self, x, y):
        self.X = x
        self.Y = y
    
    def __eq__(self, o):
        if isinstance(o, Point):
            return self.X == o.X and self.Y == o.Y
        return NotImplemented
    
    def __repr__(self):
        return '(%d, %d)' % (self.X, self.Y)


class Polygon:
    def __init__(self, points):
        self.points = points
        self.count = len(self.points)

    def GetHypotenuse(self):
        hypotenuseEdges = []
        for i in range(self.count):
            p1, p2 = self.points[i], self.points[(i+1) % self.count]
            if p1.X != p2.X and p1.Y != p2.Y:
                hypotenuseEdges.append((p1, p2))
        return hypotenuseEdges

    def CheckRect(self, polygon):
        isRectangle = False

        # 3-3
        # 各自只有一条斜边且相等，三角形判全等，三边相等
        if self.count * polygon.count == 9:
            hypotenuse = self.GetHypotenuse()
            o_hypotenuse = polygon.GetHypotenuse()
            if len(hypotenuse) == 1 and len(o_hypotenuse) == 1:
                edgeLengthList, o_edgeLengthList = [], []
                for i in range(3):
                    p1, p2 = self.points[i], self.points[(i+1) % 3]
                    edgeLengthList.append(GetDistanceSquare(p1, p2))
                    p1, p2 = polygon.points[i], polygon.points[(i+1) % 3]
                    o_edgeLengthList.append(GetDistanceSquare(p1, p2))
                isRectangle = sorted(edgeLengthList) == sorted(o_edgeLengthList)
        
        # 3-4, 3-5
        # 各自只有一条斜边且相等，构造4,5边形的虚点，虚点和斜边之外的点要在斜边的两侧（确定虚点唯一位置），4,5边形斜边加虚点的三角形判全等
        if self.count * polygon.count in (12, 15):
            tri = self if self.count == 3 else polygon
            other = self if self.count != 3 else polygon
            tri_hypotenuse, o_hypotenuse = tri.GetHypotenuse(), other.GetHypotenuse()
            if len(tri_hypotenuse) == 1 and len(o_hypotenuse) == 1:
                tri_hypotenuse, o_hypotenuse = tri_hypotenuse[0], o_hypotenuse[0]
                remainPonits = other.points[:]
                remainPonits.remove(o_hypotenuse[0])
                remainPonits.remove(o_hypotenuse[1])
                refPoint = remainPonits[0]

                candidateVirtualPoints = (Point(o_hypotenuse[0].X, o_hypotenuse[1].Y), Point(o_hypotenuse[1].X, o_hypotenuse[0].Y))
                di = GetCross(GetVector(refPoint, o_hypotenuse[0]), GetVector(refPoint, o_hypotenuse[1]))
                di1 = GetCross(GetVector(candidateVirtualPoints[0], o_hypotenuse[0]), GetVector(candidateVirtualPoints[0], o_hypotenuse[1]))
                vp = candidateVirtualPoints[0] if di*di1 < 0 else candidateVirtualPoints[1]

                virtualTriangle = (vp, o_hypotenuse[0], o_hypotenuse[1])
                edgeLengthList, o_edgeLengthList = [], []
                for i in range(3):
                    p1, p2 = virtualTriangle[i], virtualTriangle[(i+1) % 3]
                    edgeLengthList.append(GetDistanceSquare(p1, p2))
                    p1, p2 = tri.points[i], tri.points[(i+1) % 3]
                    o_edgeLengthList.append(GetDistanceSquare(p1, p2))
                isRectangle = sorted(edgeLengthList) == sorted(o_edgeLengthList)

        # 4-4
        # 各自只有一条斜边且相等并且斜边相对的边相等 或者 没有斜边只要任意有一边相等
        if self.count * polygon.count == 16:
            hypotenuse, o_hypotenuse = self.GetHypotenuse(), polygon.GetHypotenuse()
            if len(hypotenuse) == 1 and len(o_hypotenuse) == 1:
                hypotenuse, o_hypotenuse = hypotenuse[0], o_hypotenuse[0]
                isHypotenuseEq = GetDistanceSquare(hypotenuse[0], hypotenuse[1]) == GetDistanceSquare(o_hypotenuse[0], o_hypotenuse[1])
                remainPoints = self.points[:]
                remainPoints.remove(hypotenuse[0])
                remainPoints.remove(hypotenuse[1])
                o_remainPoints = polygon.points[:]
                o_remainPoints.remove(o_hypotenuse[0])
                o_remainPoints.remove(o_hypotenuse[1])
                isOtherEdgeEq = GetDistanceSquare(remainPoints[0], remainPoints[1]) == GetDistanceSquare(o_remainPoints[0], o_remainPoints[1])
                isRectangle = isHypotenuseEq and isOtherEdgeEq

            elif len(hypotenuse) == 0 and len(o_hypotenuse) == 0:
                for i in range(self.count):
                    p1, p2 = self.points[i], self.points[(i+1) % self.count]
                    dis = GetDistanceSquare(p1, p2)
                    for j in range(self.count):
                        p1, p2 = polygon.points[j], polygon.points[(j+1) % self.count]
                        o_dis = GetDistanceSquare(p1, p2)
                        if dis == o_dis: isRectangle = True
        
        return isRectangle
        

n = int(input())
for i in range(0, 2*n, 2):
    points = []
    t = list(map(int, input().split()))[1:]
    for j in range(0, len(t), 2):
        points.append(Point(t[j], t[j+1]))
    p1 = Polygon(points)

    points = []
    t = list(map(int, input().split()))[1:]
    for j in range(0, len(t), 2):
        points.append(Point(t[j], t[j+1]))
    p2 = Polygon(points)

    print('YES' if p1.CheckRect(p2) else 'NO')