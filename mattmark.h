#pragma once
#include <chrono>
#include "mattcore.h"
namespace matt{namespace benchmark{class clock{private:std::chrono::high_resolution_clock::time_point beginPoint;bool wasEnded=0;
public:double durs=0;clock(void){beginPoint = std::chrono::high_resolution_clock::now();}
void start(){beginPoint = std::chrono::high_resolution_clock::now();}
void ends(){std::chrono::high_resolution_clock::time_point endPoint = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(endPoint- beginPoint);durs = time_span.count()*1000000;}};}}
