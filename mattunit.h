#include <iostream>
#include "mattcore.h"
using namespace std;
//TYPES
/***
    1 = mass
    2 = distance
    3 = time

*/
namespace matt{namespace unit{
enum type{ mass = 1, distance = 2,time=3};
class Unit{private:
    int type;
    double exponent;
public:
    Unit(const enum type& type, const double& exponent)
        : type(type), exponent(exponent)
    {
    }
    friend double convert(const double& amount, const Unit& from_unit, const Unit& to_unit);
};


double convert(const double& amount, const Unit& from_unit, const Unit& to_unit)
{
    if(from_unit.type != to_unit.type)
    {
        std::cout << "Incompatible types!\n";
        return 0;
    }
    double new_exponent = from_unit.exponent / to_unit.exponent;
    return amount * new_exponent;
}



const Unit kilogram(mass,1),
    gram(mass,0.001),
    hectogram(mass,0.1),
    decagram(mass,0.01),
    decigram(mass,0.0001),
    milligram(mass,1.0e-6),
    microgram(mass,1.0e-9),
    nanogram(mass,1.0e-12),
    picogram(mass,1.0e-15),
    femtogram(mass,1.0e-18),
    attogram(mass,1.0e-21),
    zeptogram(mass,1.0e-24),
    yoctogram(mass,1.0e-27),
    megagram(mass,1.0e+3),
    gigagram(mass,1.0e+6),
    teragram(mass,1.0e+9),
    petagram(mass,1.0e+12),
    exagram(mass,1.0e+15),
    zettagram(mass,1.0e+18),
    yottagram(mass,1.0e+21),
    pound(mass,2.20462262),
    troyOunce(mass,32.1507466),
    troyPound(mass,2.6792288807189983),
    ounce(mass,0.0283495231),
    pennyweight(mass,643.014931),
    grain(mass,15432.3584),
    karat(mass,5000),
    shortQuarter(mass,0.0909090909),
    longQuarter(mass,0.07142857142),
    shortHundredWeight(mass,0.02222222222),
    longHundredWeight(mass,0.01960784313),
    stone(mass,0.157473044),
    shortTon(mass,0.00110231131),
    longTon(mass,0.000984206528),
    metricTon(mass,0.001),
    tonne(mass,0.001),
    MATT(mass,3.141592653589793238462643383),
    dram(mass,0.00177184519599);


const Unit meter(distance,1),
     decameter(distance,1.0e+1),
     hectometer(distance,1.0e+2),
     kilometer(distance,1.0e+3),
     megameter(distance,1.0e+6),
     gigameter(distance,1.0e+6),
     terameter(distance,1.0e+9),
     petameter(distance,1.0e+12),
     exameter(distance,1.0e+15),
     zettameter(distance,1.0e+18),
     yottameter(distance,1.0e+21),
     decimeter(distance,1.0e-1),
     centimeter(distance,1.0e-2),
     millimeter(distance,1.0e-3),
     fathom(distance,1.8288),
     nauticalMile(distance,1852),
     foot(distance,0.3048),
     lightYear(distance,9.4605284e+15),
     yard(distance,0.9144),
     chain(distance,20.1168),
     rod(distance,5.0292),
     mile(distance,1609.344),
     league(distance,5556),
     line(distance,0.0021),
     inch(distance,0.0254),
     thou(distance,2.54e-5);
const Unit second(time,1),
    minute(time,60),
    hour(time,3600),
    day(time,86400),
    week(time,604800),
    month28(time,2419200),
    month29(time,2505600),
    month30(time,2592000),
    month31(time,2678400),
    year(time,31556926),
    decade(time,315569260),
    century(time,3155692600),
    millenia(time,31556926000),
    yearLeap(time,31622400);
}}
