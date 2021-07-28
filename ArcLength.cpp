
#include <iostream>
#include<cmath>


class Point     //класс для описания координат
{
public:
    Point(double lat, double lon)
    {
        this->lat = lat * 3.14159 / 180;
        this->lon = lon * 3.14159 / 180;
    }

    double lat{ 0. };
    double lon{ 0. };
};
double  lenght(const Point& p1, const Point& p2);       //вычисление расстояния по радиальным координатам
double  calcDistance(const double lat1, const  double  lon1, const  double lat2, const  double  lon2);      //по условия задачи растояние в угловых координатах


int main()
{

    double lat1{ -90}; //начальные значения для теста
    double  lon1{ 90 };
    double lat2{ 10 };
    double  lon2{ -10};

    std::cout << calcDistance(lat1, lon1, lat2, lon2) << std::endl;
    return 0;
}


double  calcDistance(const double lat1, const  double  lon1, const  double lat2, const  double  lon2) {
    Point p1(lat1, lon1);
    Point p2(lat2, lon2);
    return lenght(p1, p2);
}

double  lenght(const Point& p1, const Point& p2) {
    const double R = 6372.;     //радиус Зеемли
    double result;
    double deltaLon = p1.lon - p2.lon;      //разница координат долготы точек
    double deltaAngle = atan(
                            sqrt(
                                cos(p2.lat) * sin(deltaLon) * 
                                cos(p2.lat) * sin(deltaLon) +
                                (cos(p1.lat) * sin(p2.lat) - sin(p1.lat) * cos(p2.lat) * cos(deltaLon)) * 
                                (cos(p1.lat) * sin(p2.lat) - sin(p1.lat) * cos(p2.lat) * cos(deltaLon))
                                ) /
                                (sin(p1.lat) * sin(p2.lat) + cos(p1.lat )* cos(p2.lat) * cos(deltaLon))
                            );      // формула вычисления расстояния для самого общего случая
   
    return result = abs(deltaAngle*R);      
}
