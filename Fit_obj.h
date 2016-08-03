#include "Data_heap.h"
#include "Minuit2/FCNBase.h"
#include "Minuit2/FunctionMinimum.h"
#include "Minuit2/MnUserParameterState.h"
#include "Minuit2/MnUserParameters.h"
#include "Minuit2/MnPlot.h"
#include "Minuit2/MnMigrad.h"
#include "Minuit2/MnMinimize.h"
#include "Minuit2/MnMinos.h"
#include "Minuit2/MnSimplex.h"
#include "Minuit2/MnContours.h"
#include "Minuit2/MnPrint.h"
#include "Minuit2/MnStrategy.h"

class Fit_obj :public ROOT::Minuit2::FCNBase
{
	double theErrorDef;
	all_data *model;
public:
	Fit_obj(all_data* p_m = NULL, double up = 1.) :model(p_m), theErrorDef(up) {};
	virtual double Up() const { return theErrorDef; }
	virtual double operator () (const std::vector<double> &pars) const;
	void setErrorDef(double def) { theErrorDef = def; }
};