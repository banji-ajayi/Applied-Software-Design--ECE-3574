
//abstract base class (multiple pure virtual functions)
class Shape {
public:
  virtual double area() =0;
  virtual QString getName() =0;
  virtual QString getDimensions() =0;
  virtual ~Shape()
  { }
};

class Rectangle: public Shape {
public:
  Rectangle(double h, double w =0.0)
    :m_Height(h), m_Width(w) {
  if (!m_Width)
    m_Width = m_Height;
  }
  double area(); //TIP try to comment this line! A subclass should implement pure virtual functions from the base class
  QString getName() {
    return QString("Rectangle");
  }
  QString getDimensions() {
    return QString("[%1,%2]").arg(m_Height).arg(m_Width);
  }
  virtual ~Rectangle()
  { }
protected:
  double m_Height, m_Width;
};

class Square: public Rectangle {
public:
  Square(double h)
    :Rectangle(h)
  { }
  double area();
  QString getName() {
    return QString("Square");
  }
  QString getDimensions() {
    return QString("[%1]").arg(m_Height);
  }
};

class Circle: public Shape {
public:
  Circle(double r)
    :m_Radius(r)
  { }
  //double area();
  QString getName() {
    return QString("Circle");
  }
  QString getDimensions() {
    return QString("[%1]").arg(m_Radius);
  }
  virtual ~Circle()
  { }
private:
  double m_Radius;
};

//NOTE virtual destructure is very important

