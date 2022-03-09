#pragma once
#include "HistogramBase.h"
#include <random>

namespace Histderived
{
	class RandomEintegerGenerator : Hist::RandomEintegerGeneratorBase
	{
		public:

			/**
			* Operator which returns Hist::EInteger type value picked pseudo-randomly.
			* 
			* Unknown behaviour if random number generation fails, otherwise guaranteed value.
			*/
			Hist::EInteger operator()() override;
	};
}