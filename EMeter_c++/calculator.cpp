#include "calculator.h"
#include <math.h>

Calculator::Calculator()
{

}

double Calculator::deltaTaToTicks(double sense, double deltaTA)
{
    const double refDeltaTA = 0.5;
    //                    0        1       2      3      4      5       6
    double arr[7][7] = {{1,2.0},{2,4.0},{3,6.4},{4,8},{8,16},{15,25},{40,400}};
    int index = 0;
    if(sense < 1)
    {
        index = 0;
    }
    else if (sense >= 2 && sense < 3)
    {
        index = 1;
    }else if (sense >= 3 && sense < 4)
    {
        index = 2;
    }
    else if (sense >= 4 && sense < 8)
    {
        index = 3;
    }
    else if (sense >= 8 && sense < 15)
    {
        index = 4;
    }
    else if (sense >= 15 )
    {
        index = 5;
    }
    double & y1( arr[index][1]);
    double & y2( arr[index+1][1]);
    double & x1( arr[index][0]);
    double & x2( arr[index+1][0]);
    double b = 0.0;
    double m = 0.0;
    m = (y2 -y1) / (x2 - x1);
    b = y1 - m * x1;
    double ticks = sense * m + b;
    return ticks/refDeltaTA * deltaTA;

/*  xi = Sense  , yi = Ticks delOhm 370 Constand, y(x) = Ticks
    xi	yi
    1    2
    2    4
    3    6,6
    4    8
    8    16
    15   25
    40   400
    Polynom:
    y(x) = 0.01168x3 - 0.3141x2 + 3.941x - 2.568
    https://valdivia.staff.jade-hs.de/interpol.html
  */
}

double Calculator::deltaOhmToTicks(double sense, double deltaOhm)
{
    const double refDeltaOhm = 370.370;
    //                    0        1       2      3      4      5       6
    double arr[7][7] = {{1,2.0},{2,4.0},{3,6.4},{4,8},{8,16},{15,25},{40,400}};
    int index = 0;
    if(sense < 1)
    {
        index = 0;
    }
    else if (sense >= 2 && sense < 3)
    {
        index = 1;
    }else if (sense >= 3 && sense < 4)
    {
        index = 2;
    }
    else if (sense >= 4 && sense < 8)
    {
        index = 3;
    }
    else if (sense >= 8 && sense < 15)
    {
        index = 4;
    }
    else if (sense >= 15 )
    {
        index = 5;
    }
    double & y1( arr[index][1]);
    double & y2( arr[index+1][1]);
    double & x1( arr[index][0]);
    double & x2( arr[index+1][0]);
    double b = 0.0;
    double m = 0.0;
    m = (y2 -y1) / (x2 - x1);
    b = y1 - m * x1;
    double ticks = sense * m + b;
    return ticks/refDeltaOhm * deltaOhm;

/*  xi = Sense  , yi = Ticks delOhm 370 Constand, y(x) = Ticks
    xi	yi
    1    2
    2    4
    3    6,6
    4    8
    8    16
    15   25
    40   400
    Polynom:
    y(x) = 0.01168x3 - 0.3141x2 + 3.941x - 2.568
    https://valdivia.staff.jade-hs.de/interpol.html
  */
}

double Calculator::ohmToTAValue(double ohm)
{
    //                    0           1        2         3          4        5          6      7
    double arr[8][8] = {{0,0.0},{395,1.0},{5000,2},{12500,3},{27500,4},{60000,5},{225000,6},{3000000,6.4}};
    int index = 0;
    if(ohm < 395)
    {
        index = 0;
    }
    else if (ohm >= 395 && ohm < 5000)
    {
        index = 1;
    }else if (ohm >= 5000 && ohm < 12500)
    {
        index = 2;
    }
    else if (ohm >= 12500 && ohm < 27000)
    {
        index = 3;
    }
    else if (ohm >= 27000 && ohm < 60000)
    {
        index = 4;
    }
    else if (ohm >= 60000 && ohm < 225000)
    {
        index = 5;
    }
    else if (ohm >= 225000 )
    {
        index = 6;
    }
    double & y1( arr[index][1]);
    double & y2( arr[index+1][1]);
    double & x1( arr[index][0]);
    double & x2( arr[index+1][0]);
    double b = 0.0;
    double m = 0.0;
    m = (y2 -y1) / (x2 - x1);
    b = y1 - m * x1;
    return ohm * m + b;
    /*
     * http://elsenaju.info/Rechner/Ausgleichsgerade.htm
    xi	    yi
    5000    2
    12500   3
    27500   4
    60000   5
    225000  6

    xi	    yi
    5000    2
    13500   3
    27000   4
a=0.060403
b=0.410828
Potenzfunktion

y=a⋅x^b=0.060403⋅x0.410828
Standardabweichung

σ=0.005068

    xi	    yi
    27000   4
    60000   5
    3000000 6,4
Parameter der Potenzfunktion

a=1.745566
b=0.088062
Potenzfunktion

y=a⋅x^b=1.745566⋅x0.088062
Standardabweichung

σ=0.354395

    */

}
