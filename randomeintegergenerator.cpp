#include "randomeintegergenerator.h"

using namespace Hist;

RandomEintegerGenerator::RandomEintegerGenerator() :
    RandomEintegerGeneratorBase()
{
}

EInteger RandomEintegerGenerator::operator()()
{
    return static_cast<EInteger>(rand() % 5);
}
