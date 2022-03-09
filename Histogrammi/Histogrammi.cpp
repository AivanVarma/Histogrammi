#include <iostream>
#include "Histogram.h"
#include "RandomEintegerGenerator.h"
#include "Log.h"
#include <map>

int main()
{
    // Initialize the log and histogram.
    std::unique_ptr<Logger> log = std::make_unique<Logger>();
    Histderived::Histogram* hist = new Histderived::Histogram(std::move(log));

    // Checks that return values are as they should in case of the histogram being empty.
    std::cout << "Mode: " << hist->getMode() << " Min: " << hist->getMinValue() << " Max: " << hist->getMaxValue() << std::endl;

    // Populate the histogram with 10 random values.
    for (int i = 0; i < 10; i++)
    {
        Hist::EInteger randomValue;
        Histderived::RandomEintegerGenerator rv;
        randomValue = rv();
        hist->add(randomValue);
    }

    // Print out the return values of different functions.
    std::cout << "Max: " << hist->getMaxValue() << " min: " << hist->getMinValue() << " mode: " << hist->getMode() << std::endl;
    
    // Prints the histogram out so that the previous values can be verified.
    std::map<Hist::EInteger, int> histo;
    histo = hist->getHistogram();
    for (auto i = histo.begin(); i != histo.end(); i++)
    {
        std::cout << "Key: " << i->first << " Value: " << i->second << std::endl;
    }
}
