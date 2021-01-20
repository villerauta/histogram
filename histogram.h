#ifndef HISTOGRAM_H
#define HISTOGRAM_H


#include "histogrambase.h"
#include "map"

namespace Hist {

    class Histogram : public HistogramBase
    {
    public:
        /**
         * Constructor.
         * Constructs Histogram class object and moves the unique pointer of Logger to base class constructor.
         */
        Histogram(std::unique_ptr<Logger> );

        /**
         * Destructor
         */
        ~Histogram();

        /**
         * Function for adding values to the histogram.
         * @param var the EInteger to be added.
         */
        void add(EInteger var);


        /**
         * Function for fetching the mode of the histogram.
         * @attention Returns only one EInteger even if multiple EIntegers hold the same quantity.
         * @return Mode of the histogram data.
         */
        EInteger getMode() const;


        /**
         * Function for fetching the greatest value present in the histogram.
         * @attention In case of no data, returns the minimum EInteger value by default.
         * @return Greatest value present in histogram data.
         */
        EInteger getMaxValue() const;


        /**
         * Function for fetching the smallest value present in the histogram.
         * @attention In case of no data, returns the maximum EInteger value by default.
         * @return Smallest value present in histogram data.
         */
        EInteger getMinValue() const;


    private:
        /**
         * Map to store all the added EIntegers and their respective counts.
         */
        std::map<EInteger,int> m_dataMap;

    };
}
#endif // HISTOGRAM_H
