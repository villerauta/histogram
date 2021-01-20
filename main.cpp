#include <iostream>
#include <histogram.h>
#include <memory.h>
#include "log.h"
#include "randomeintegergenerator.h"

using namespace std;

int main()
{

    int testAmount = 0;

    unique_ptr<Logger> log(new Logger());
    Hist::Histogram histogram(unique_ptr<Logger>(move(log)));

    Hist::RandomEintegerGenerator generator;

    for(int i = 0; i < testAmount ; ++i) {
        Hist::EInteger a = generator();
        histogram.add(a);
    }
    Hist::EInteger mode = histogram.getMode();
    Hist::EInteger max = histogram.getMaxValue();
    Hist::EInteger min = histogram.getMinValue();

    cout << "Mode of the set is " << mode << endl;
    cout << "Max value of the set is " << max << endl;
    cout << "Min value of the set is " << min << endl;

    return 0;
}
