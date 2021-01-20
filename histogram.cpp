#include "histogram.h"
#include "histogrambase.h"
#include "log.h"

using namespace Hist;

Histogram::Histogram(std::unique_ptr<Logger> log):
    HistogramBase(move(log))
{

}

Histogram::~Histogram()
{

}

void Histogram::add(EInteger var)
{
    std::map<EInteger,int>::iterator it;
    it = m_dataMap.find(var);
    if(it != m_dataMap.end()){
        it->second = ++it->second;
    }else{
        m_dataMap.insert(std::pair<EInteger,int>(var,1));
    };
}

EInteger Histogram::getMode() const
{
    EInteger mode;
    int largest = 0;
    for (auto const& x : m_dataMap) {
       if (x.second > largest) {
           largest = x.second;
           mode = x.first;
       }
    }
    return mode;
}

EInteger Histogram::getMaxValue() const
{
    EInteger mode = EInteger::Zero;
    for (auto const& x : m_dataMap){
        if(x.first > mode){
            mode = x.first;
        }
    }
    return mode;
}

EInteger Histogram::getMinValue() const
{
    EInteger mode = EInteger::Four;
    for (auto const& x : m_dataMap){
        if(x.first < mode){
            mode = x.first;
        }
    }
    return mode;
}
