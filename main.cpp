#include "Fit_obj.h"
#include "Prefs_heap.h"
#include <qapplication.h>
#include <qtextedit.h>

#define NUM_OF_ITER 2

std::default_random_engine *gener;

//TODO: change class architecture: make corr_obj of diffrent type to be diffrent children. 
//TODO: need some proper testing
//TODO: make kind of manual (better in images) for myself at least. How to add things and general architecture
//Add all parcing info as well as par names in all_data (latter???) inside them
//Most definetly data strucure needs some reworking, but later. 
int main(int argv, char** args)
{
	//QApplication app(argv, args);
	//QTextEdit text_edit;
	//text_edit.show();
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	gener = &generator;
	all_data data;
	Fit_obj dd(&data);
	int res = data.test_f(0);

	ROOT::Minuit2::MnUserParameters pars;
	for (int h = 0; h < data.par_map.size(); h++)
	{
		double par = data.par_map.get_par_by_num(h, &data);
		double min = data.par_map.get_min_by_num(h);
		double max = data.par_map.get_max_by_num(h);
		std::cout << "MINUIT added: " << par << " in ( " << min << " , " << max << " )" << std::endl;
		pars.Add(std::to_string(h), data.par_map.get_par_by_num(h, &data), (data.par_map.get_max_by_num(h) - data.par_map.get_min_by_num(h) / 2));
		//pars.Add(std::to_string(h), data.par_map.get_par_by_num(h, &data), 1e-4*(data.par_map.get_max_by_num(h) - data.par_map.get_min_by_num(h) / 2));
		//pars.Add(std::to_string(h), data.par_map.get_par_by_num(h, &data), 1e+4*(data.par_map.get_max_by_num(h) - data.par_map.get_min_by_num(h) / 2));
		pars.SetLimits(h, data.par_map.get_min_by_num(h), data.par_map.get_max_by_num(h));
	}
	int num_of_mi = 0;
	ROOT::Minuit2::MnStrategy(2);
	ROOT::Minuit2::MnMigrad migrad(dd, pars);		//diffrent ways
	//ROOT::Minuit2::MnMinimize migrad(dd, pars);	//diffrent ways
	//ROOT::Minuit2::MnSimplex migrad(dd, pars);	//diffrent ways
	ROOT::Minuit2::FunctionMinimum* p_min;
	for (num_of_mi = 0; num_of_mi < NUM_OF_ITER; num_of_mi++)
	{
		ROOT::Minuit2::FunctionMinimum min=migrad();
		////std::cout << min;
		int ok = min.IsValid();
		ROOT::Minuit2::MnMinos errors(dd, min);
		for (int h = 0; h < data.par_map.size(); h++)
		{
			pars.SetValue(h, min.UserState().Value(h));
			pars.SetError(h, errors(h).second-errors(h).first);
		}
		if (!ok)
		{
			p_min = new ROOT::Minuit2::FunctionMinimum(min);
			break;
		}
		std::cout << min;
		//pars.SetValue(data.par_map.size() - 1, 0.007);//cheat
		//pars.Fix(data.par_map.size() - 1);
		//double erere = min.UserState().Value(data.par_map.size() - 1);
		//std::cout <<"\tSECOND MINIMIZAION***SECOND MINIMIZAION***SECOND MINIMIZAION " << std::endl;
		//ROOT::Minuit2::MnMigrad migrad2(dd, pars);		//diffrent ways
		//ROOT::Minuit2::MnMinimize migrad2(dd, pars);		//diffrent ways
		//ROOT::Minuit2::MnSimplex migrad2(dd, pars);	//diffrent ways
		//min = migrad2();
		//ok = min.IsValid(); //second minimization, without beam_x_initial
		if (num_of_mi == (NUM_OF_ITER - 1))
			p_min = new ROOT::Minuit2::FunctionMinimum(min);
	}
	std::cout << *p_min;
	std::cout << "Num_of_mi = " << num_of_mi << " out of " << NUM_OF_ITER<<std::endl;
	std::ofstream fssf;
	fssf.open("pars_fit.txt");

	int num_of_pars = data.par_map.size();
	std::cout << "Num of pars = " << num_of_pars << std::endl;
	double *temp = new double[data.par_map.size()];
	for (int h = 0; h < data.par_map.size(); h++)
	{
		temp[h] = p_min->UserState().Value(h);
		fssf << temp[h];
		if (h == data.par_map.size() - 1) fssf << std::endl;
		else fssf << "\t";
	}
	data.par_map.set_parameters(temp, &data);
	fssf.close();
	delete[]temp;

	data.calculate_beam();
	fssf.open("C:\\Users\\Bitch\\Desktop\\Top\\Global\\gnuplot\\bin\\beamf.txt");
	data.write_beam(fssf);
	fssf.close();

	data.build_theor_matrix(&data.matrix_exp,data.n_col,data.n_row);
	fssf.open("Mfitted.txt");
	data.write_global_pars(fssf);
	fssf.close();

	//fssf.open("func_view.txt");
	//std::vector<double> nam;
	//for (int dg = 0; dg < data.par_map.size(); dg++)
	//	nam.push_back(min.UserState().Value(dg));
	//nam[0] = -0.272; //setting true pars
	//nam[1] = 0.272;
	//nam[2] = -0.36;
	//nam[3] = 0.44;
	//nam[4] = -0.46;
	//nam[5] = 0.378;
	//nam[6] = 0.0012;

	//for (int h = 0; h < 100; h++)
	//	for (int g = 0; g < 100; g++)
	//	{
	//		double val_0 = data.par_map.get_min_by_num(3) + (h / 99.0)*(data.par_map.get_max_by_num(3) - data.par_map.get_min_by_num(3));
	//		double val_1 = data.par_map.get_min_by_num(5) + (g / 99.0)*(data.par_map.get_max_by_num(5) - data.par_map.get_min_by_num(5));
	//		nam[3] = val_0;
	//		nam[5] = val_1;
	//		fssf << val_0 << "\t" << val_1 << "\t" << data(nam) << std::endl;
	//	}
	//fssf.close();
	//std::ofstream d("prefs_test.txt");
	//preferences.write(d);
	//d.close();
	std::cout << "read result: " << res << std::endl;
	delete p_min;
	//return app.exec();
}