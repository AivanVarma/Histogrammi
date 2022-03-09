#pragma once
#include "HistogramBase.h"
#include "RandomEintegerGenerator.h"
#include <map>

namespace Histderived
{
	class Histogram : public Hist::HistogramBase
	{
    public:

        /**
        * Constructors and destructor for the class.
        */
        Histogram(std::unique_ptr<Logger>);

        Histogram(const Histogram&);

        Histogram(Histogram&&);

        ~Histogram();

        /**
        * Function for adding a new Hist::EInteger value to the histogram.
        * 
        * The value will be saved as a key to a std::map, and its occurrancies as the data.
        */
        void add(Hist::EInteger) override;

        /**
        * Function for getting the mode of the histogram.
        * 
        * If the mode is ambiguous, that is there are more than one Hist::EInteger value with the same amount of occurrancies, 
        * the first one of those will be returned. No error message or anything else is given if this occures.
        * 
        * If the std::map is empty as default the function returns Hist::EInteger value zero (0).
        */
        Hist::EInteger getMode() const override;

        /**
        * Function for getting the minimum Hist::EInteger value of the histogram.
        * 
        * If the std::map is empty as default the function returns Hist::EInteger value zero (0).
        */
        Hist::EInteger getMinValue() const override;

        /**
        * Function for getting the maximum Hist::EInteger value of the histogram.
        * 
        * If the std::map is empty as default the function returns Hist::EInteger value zero (0).
        */
        Hist::EInteger getMaxValue() const override;

        /**
        * Function for getting the std::map containing the histogram. 
        */
        std::map<Hist::EInteger, int> getHistogram();

    private:

        /**
        * Function that checks if a particular Hist::EInteger type key already exists in the std::map containing the histogram.
        */
        bool checkIfKeyExists(Hist::EInteger key);

        std::map<Hist::EInteger, int> m_histogram;
	};
}
