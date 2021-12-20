Point Point::vector(const Point a, const Point b)
{
        Fixed x(a.getX() - b.getX());
        Fixed y(a.getY() - b.getY());

        return (Point(x.toFloat(), y.toFloat()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
        Fixed outer1, outer2, outer3;

        outer1 = Point::outer2d(Point::vector(point, a), Point::vector(c, a));
        outer2 = Point::outer2d(Point::vector(point, b), Point::vector(a, b));
        outer3 = Point::outer2d(Point::vector(point, c), Point::vector(b, c));
        if (outer1 < Fixed(0) && outer2 < Fixed(0) && outer3 < Fixed(0))
                return (true);
        if (outer1 > Fixed(0) && outer2 > Fixed(0) && outer3 > Fixed(0))
                return (true);
        return (false);
}

CPP module02 ex03
