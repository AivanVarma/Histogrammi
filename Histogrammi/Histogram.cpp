#include "Histogram.h"

namespace Histderived
{
	Histogram::Histogram(std::unique_ptr<Logger> ptr) : Hist::HistogramBase(std::move(ptr))
	{
	}
	Histogram::Histogram(const Histogram& histogram) : Hist::HistogramBase(histogram)
	{
	}
	Histogram::Histogram(Histogram&& histogram) : Hist::HistogramBase(histogram)
	{
	}
	Histogram::~Histogram()
	{
	}

	void Histogram::add(Hist::EInteger value)
	{
		if (m_histogram.empty())
		{
			m_histogram.insert({ value, 1 });
		}
		
		if (!checkIfKeyExists(value))
		{
			m_histogram.insert({ value, 1 });
		}
		else
		{
			m_histogram.at(value) += 1;
		}

	}

	Hist::EInteger Histogram::getMode() const
	{
		if (m_histogram.empty())
		{
			return Hist::EInteger(0);
		}

		Hist::EInteger mode_key;
		int mode = 0;

		for (auto iter = m_histogram.begin(); iter != m_histogram.end(); ++iter)
		{
			if (iter->second > mode)
			{
				mode_key = iter->first;
				mode = iter->second;
			}
		}

		return mode_key;
	}

	Hist::EInteger Histogram::getMinValue() const
	{
		if (m_histogram.empty())
		{
			return Hist::EInteger(0);
		}

		return m_histogram.begin()->first;
	}

	Hist::EInteger Histogram::getMaxValue() const
	{
		if (m_histogram.empty())
		{
			return Hist::EInteger(0);
		}

		auto iter = --m_histogram.end();
		return iter->first;
	}

	bool Histogram::checkIfKeyExists(Hist::EInteger key)
	{
		if (m_histogram.find(key) == m_histogram.end())
		{
			return false;
		}

		return true;
	}
	std::map<Hist::EInteger, int> Histogram::getHistogram()
	{
		return m_histogram;
	}
}
