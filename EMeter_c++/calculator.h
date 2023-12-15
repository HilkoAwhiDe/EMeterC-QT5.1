#ifndef CALCULATOR_H
#define CALCULATOR_H


class Calculator
{
public:
    Calculator();
    double deltaTaToTicks(double sense, double deltaTA);

private:
    double deltaOhmToTicks(double sense, double deltaOhm);
    double ohmToTAValue(double ohm);
};

#endif // CALCULATOR_H
