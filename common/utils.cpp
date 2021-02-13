#include "utils.h"

bool Utils::generateRandomBool()
{
    std::random_device generator; // use a hardware entropy source if available, otherwise use PRNG
    std::bernoulli_distribution distribution(0.5);
    return distribution(generator);
}

long long Utils::generateRandomInt(long long min, long long max)
{
    std::random_device generator; // use a hardware entropy source if available, otherwise use PRNG
    std::uniform_int_distribution<size_t> distribution(min, max);
    return distribution(generator);
}
