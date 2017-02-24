#include <QString>
#include "shapes.h"
#include <math.h>

double Circle::area() {
  return(M_PI * m_Radius * m_Radius);
}

double Rectangle::area() { 
  return (m_Height * m_Width);
}

double Square::area() { 
  return (Rectangle::area());
}

