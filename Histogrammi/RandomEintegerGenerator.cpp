#include "RandomEintegerGenerator.h"

namespace Histderived
{
	Hist::EInteger RandomEintegerGenerator::operator()()
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distrib(0, 4);
		
		return Hist::EInteger(distrib(gen));
	}
}