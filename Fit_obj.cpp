#include "Fit_obj.h"

double Fit_obj::operator () (const std::vector<double> &pars) const
{
	return (*model)(pars);
}