#ifndef PHYSICS_H // header guard
#define PHYSICS_H

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

// Constants

const double e = 1.6e-19; 	// e is the charge of Proton or electrons
const double k = 9e9;  // coulomb's law constant [ k = 1/4*pi*e0 ]
const double e0 = 8.854e-12; 	// Electric Permitivity in free space
const double pi = 3.14;
const double nu0 = 12.56e-7 ;

						/*
							// Chapter 1 \\
					// Electric Charges and Fields \\
														*/
double q()  	//Quantization
{
	double q,n;
	cout << "\n Quantization :- " << endl;
	cout << " Enter no.of particles : ";
	cin >> n;		//No.of Protons or Electrons

	q = n*e;	//Quantization Of Charge (Eqn)
	cout <<" Charge = "<< q << " C" << endl; 	//charge on a body
	return q ;

}


double f() 	// Coulomb's Law
{
	double q1,q2,r,force; 	//q1,q2 : charges , r : distance b/w charges

	cout << "\n Force :- " << endl;
	cout << " Enter first charge : ";
	cin >> q1;
	cout << " Enter second charge : ";
	cin >> q2;
	cout <<" Enter the distance : ";
	cin >> r;

	force = k*q1*q2/(pow(r, 2));  	// Force b/w charges
	cout << " Force = " << force << " N " << endl;

	return force ;

}


double E()  	//Electric Field
{
	double electric_field,force,q;  	// choice is to determine Unknown force
	char choice;

	cout << "\n Electric Field :- " << endl;
	cout << " Do you know the value of force (y/n) \n > " ;
	x:  	// x is to repeatly type answer (if wrong)
	cin >> choice ;
	if ( choice == 'n' || choice == 'N' )
	{
		force = f();
	}
	else if ( choice == 'y' || choice == 'Y' )
	{
		cout << " Enter the Force : ";
		cin >> force ;
	}
	else
	{
		cout<< " Wrong Input \n > " ;
		goto x;
	}
	cout << " Enter the Charge : " ;
	cin >> q;  	// charge of particle

	electric_field = force/q;
	cout << " Electric Field = " << electric_field << " N/C " << endl;

	return electric_field ;

}


double Eflux()  	//Electric Flux
{
	double electric_flux,electric_field,area,angle ;
	char choice;

	cout << "\n Electric Flux :- " << endl;
	cout << " Do you know the value of Electric Field (y/n) \n > " ;
	x:  	// x is to repeatly type answer (if wrong)
	cin >> choice ;
	if ( choice == 'n' || choice == 'N' )
	{
		electric_field = E();
	}
	else if ( choice == 'y' || choice == 'Y' )
	{
		cout << " Enter the Electric Field : " ;
		cin >> electric_field ;
	}
	else
	{
		cout<< " Wrong Input \n > " ;
		goto x;
	}

	cout << " Enter the Area : ";
	cin >> area ;
	cout << " Enter Angle b/w Electric Field & Area ( In radian ) : " ;
	cin >> angle ;

	electric_flux = electric_field*area*cos(angle);
	cout << " Electric Flux = " << electric_flux << " Nm2/c " << endl;

	return electric_flux ;

}

double Edipole()
{
	double electric_dipole,q,a; 		// a is distance (represented as 2a)

	cout << "\n Electric Dipole :- " << endl;
	cout << " Enter Value of Charge : ";
	cin >> q;
	cout << " Enter the Distance (2a) : ";
	cin >> a;

    electric_dipole = q*a;
    cout << " Electric Dipole = " << electric_dipole << " Cm " << endl;

    return electric_dipole;

}

void torque()
{
	double torq,electric_dipole,electric_field,angle ;
	char choice1,choice2 ;

	cout << "\n Torque :- " << endl;
	cout << " Do you know the value of Electric Field (y/n) \n > " ;
	x:  	// x is to repeatly type answer (if wrong) for electric field
	cin >> choice1 ;
	if ( choice1 == 'n' || choice1 == 'N' )
	{
		electric_field = E();
	}
	else if ( choice1 == 'y' || choice1 == 'Y' )
	{
		cout << " Enter the Electric Field : " ;
		cin >> electric_field ;
	}
	else
	{
		cout<< " Wrong Input \n > " ;
		goto x;
	}

	cout << " Do you know the value of Electric Dipole (y/n) \n > " ;
	y:  	// y is to repeatly type answer (if wrong) for electric dipole
	cin >> choice2 ;
	if ( choice2 == 'n' || choice2 == 'N' )
	{
		electric_dipole = Edipole();
	}
	else if ( choice2 == 'y' || choice2 == 'Y' )
	{
		cout << " Enter the Electric Dipole : " ;
		cin >> electric_dipole ;
	}
	else
	{
		cout<< " Wrong Input \n > " ;
		goto y;
	}
	cout << " Enter Angle b/w Electric Dipole & Electric Field ( In radian ) : " ;
	cin >> angle ;

	torq = electric_dipole * electric_field *sin(angle) ;
	cout << " Torque = " << torq << " N/m" << endl ;
}

void EofDipole_al() 		// Electric Field OF An Electric Dipole At Axial Line (al)

{
	double electric_field,electric_dipole,r,a ;  	//r is distance , a is distance b/w charges
	char choice;

	cout << "\n Electric Field OF An Electric Dipole (At Axial Line):- " << endl;
	cout << " Do you know the value of Electric Dipole (y/n) \n > " ;
	x:  	// x is to repeatly type answer (if wrong)
	cin >> choice ;
	if ( choice == 'n' || choice == 'N' )
	{
		electric_dipole = Edipole();
	}
	else if ( choice == 'y' || choice == 'Y' )
	{
		cout << " Enter the Electric Dipole : " ;
		cin >> electric_dipole ;

	}
	else
	{
		cout<< " Wrong Input \n > " ;
		goto x;
	}
	cout << " Enter the Distance (r) : " ;
	cin >> r;
	cout << " Enter the Distance b/w Charges : ";
	cin >> a;

	electric_field = k*2*r*electric_dipole/(pow(pow(r,2)-pow(a/2,2),2));
	cout << " Electric Field = " << electric_field << " N/C" << endl ;

}

void EofDipole_el() 		// Electric Field OF An Electric Dipole At Equatorial Line (el)

{
	double electric_field,electric_dipole,r,a ;  	//r is distance , a is distance b/w charges
	char choice;

	cout << "\n Electric Field OF An Electric Dipole (At Equatorial Line):- " << endl;
	cout << " Do you know the value of Electric Dipole (y/n) \n > " ;
	x:  	// x is to repeatly type answer (if wrong)
	cin >> choice ;
	if ( choice == 'n' || choice == 'N' )
	{
		electric_dipole = Edipole();
	}
	else if ( choice == 'y' || choice == 'Y' )
	{
		cout << " Enter the Electric Dipole : " ;
		cin >> electric_dipole ;

	}
	else
	{
		cout<< " Wrong Input \n > " ;
		goto x;
	}
	cout << " Enter the Distance (r) : " ;
	cin >> r;
	cout << " Enter the Distance b/w Charges : ";
	cin >> a;

	electric_field = (-1) *k*electric_dipole/(pow(pow(r,2)-pow(a/2,2),3/2)); 	/* (-1) Indicate Electric Field is
																					Opposite to Electric Dipole */
	cout << " Electric Field = " << electric_field << " N/C" << endl ;

}

void Eflux_Glaw() 	// Electric Flux using Gauss's Law

{
	double electric_flux,q; 		// a is distance (represented as 2a)

	cout << "\n Electric Flux Guass's Law:- " << endl;
	cout << " Enter Value of Charge : ";
	cin >> q;

    electric_flux = q/e0 ;
    cout << " Electric Flux = " << electric_flux << " Nm2/C" << endl ;

 }

 double Ldensity()  	// Linear Charge Density

 {
	double linear_density,q,length ;

	cout << "\n Linear Charge Density :- " << endl;
	cout << " Enter Value of Charge : ";
	cin >> q;
	cout << " Enter the Length : " ;
	cin >> length ;

    linear_density = q/length ;
    cout << " Linear Charge Density = ";
		return linear_density;

 }

 double Sdensity() 	// Surface Charge Density

 {
	double surface_density,q,surface_area ;

	cout << "\n Surface Charge Density :- " << endl;
	cout << " Enter Value of Charge : ";
	cin >> q;
	cout << " Enter the surface Area : " ;
	cin >> surface_area ;

    surface_density = q/surface_area ;
    cout << " Surface Charge Density = "  << surface_density << " C/m " << endl;

    return surface_density ;

 }


 void Efield_inflong_w()  	// Electric Field due to an infinitely long straight uniformly charged wire

 {

	double electric_field, linear_density, distance ;
	char choice;

	cout << "\n Electric Field Charged Wire :- " << endl;
	cout << " Do you know the value of Linear Charge Density (y/n) \n > " ;
	x:  	// x is to repeatly type answer (if wrong)
	cin >> choice ;
	if ( choice == 'n' || choice == 'N' )
	{
		linear_density = Ldensity();
	}
	else if ( choice == 'y' || choice == 'Y' )
	{
		cout << " Enter the Linear Charge Density : " << linear_density << " C/m2 " << endl;
		cin >> linear_density ;

	}
	else
	{
		cout<< " Wrong Input \n > " ;
		goto x;
	}
	cout << " Enter the Distance : " ;
	cin >> distance ;

    electric_field = k * 2*linear_density/distance ;
    cout << " Electric Field = " << electric_field << " N/C" << endl ;

 }

 void Efield_infplane_s()  	// Electric Field due to an uniformly charged infinite plane sheet

 {

	double electric_field, surface_density ;
	char choice;

	cout << "\n Electric Field Plane Sheet :- " << endl;
	cout << " Do you know the value of Surface Charge Density (y/n) \n > " ;
	x:  	// x is to repeatly type answer (if wrong)
	cin >> choice ;
	if ( choice == 'n' || choice == 'N' )
	{
		surface_density = Sdensity();
	}
	else if ( choice == 'y' || choice == 'Y' )
	{
		cout << " Enter the Surface Charge Density : ";
		cin >> surface_density ;

	}
	else
	{
		cout<< " Wrong Input \n > " ;
		goto x;
	}

    electric_field = surface_density/ 2*e0 ;
    cout << " Electric Field = " << electric_field << " N/C" << endl ;

 }

void Efield_infplane_st()  	/* Electric Field due to an uniformly charged
								infinite plane sheet with finite thickness */

 {

	double electric_field, surface_density ;
	char choice;

	cout << "\n Electric Field Plane Sheet Finite Thickness:- " << endl;
	cout << " Do you know the value of Surface Charge Density (y/n) \n > " ;
	x:  	// x is to repeatly type answer (if wrong)
	cin >> choice ;
	if ( choice == 'n' || choice == 'N' )
	{
		surface_density = Sdensity();
	}
	else if ( choice == 'y' || choice == 'Y' )
	{
		cout << " Enter the Surface Charge Density : ";
		cin >> surface_density ;

	}
	else
	{
		cout<< " Wrong Input \n > " ;
		goto x;
	}

    electric_field = surface_density/ e0 ;
    cout << " Electric Field = " << electric_field << " N/C" << endl ;

 }

void Efield_s_shell()  	// Electric Field due to an uniformly charged thin spherical shell

{

	double electric_field, surface_density, R , r ;
	char choice;

	cout << "\n Electric Field Spherical Shell :- " << endl;
	cout << " Enter the Radius of Shell : " ;
	cin >> R; 	//  R is the Radius of Shell
	cout << " Enter the Distance From Cetre of Shell : " ;
	cin >> r;	//  r is the Distance From Cetre of Shell

	if ( r < R )
	{
		electric_field = 0 ;
		cout << " Electric Field = " << electric_field << endl ;
		exit(0) ;
	}
		cout << " Do you know the value of Surface Charge Density (y/n) \n > " ;
		x:  	// x is to repeatly type answer (if wrong)
		cin >> choice ;

		if ( choice == 'n' || choice == 'N' )
		{
			surface_density = Sdensity();
		}

		else if ( choice == 'y' || choice == 'Y' )
		{
			cout << " Enter the Surface Charge Density : ";
			cin >> surface_density ;

		}

		else
		{
		cout<< " Wrong Input \n > " ;
			goto x;
		}

	if ( r > R )
	{
		electric_field = surface_density *pow(R,2)/(e0*pow(r,2)) ;
		cout << " Electric Field = " << electric_field << endl ;
		exit(0);
	}

	if ( r == R )
	{
		electric_field = surface_density/e0 ;
		cout << " Electric Field = " << electric_field << endl ;
	}

}

			/*
				  // Chapter 1 Finished \\


						// Chapter 3 \\
				   // Current Electricity \\
												*/


double I()

{

	double time , current, qc;
	char choice ;
	cout << "\n Current :- " << endl;
	cout << " Enter the Time Taken : " ;
	cin >> time;
	cout << " Do you know the value of Charge (y/n) \n > " ;
	x:  	// x is to repeatly type answer (if wrong)
	cin >> choice ;

	if ( choice == 'n' || choice == 'N' )
	{
		qc = q();  		// qc is Charge
	}

	else if ( choice == 'y' || choice == 'Y' )
	{
		cout << " Enter the Charge : ";
		cin >> qc ;

	}

	else
	{
		cout<< " Wrong Input \n > " ;
		goto x;
	}


	current = qc / time ;
	cout << " Current = " << current << " A " << endl;
	return current ;

}

double Cdensity () 		// Current Density

{
	double current , area, cdens ;  	// cdens is current density
	char choice ;
	cout << "\n Current Density :- " << endl;
	cout << " Do you know the value of Current (y/n) \n > " ;
	x:  	// x is to repeatly type answer (if wrong)
	cin >> choice ;

	if ( choice == 'n' || choice == 'N' )
	{
		current = I();
	}

	else if ( choice == 'y' || choice == 'Y' )
	{
		cout << " Enter the Current : ";
		cin >> current ;

	}

	else
	{
		cout<< " Wrong Input \n > " ;
		goto x;
	}
	cout << " Enter the Area " ;
	cin >> area ;

	cdens = current / area ;
	cout << " Current Density = " << cdens << " A/m2 " << endl;

	return cdens ;

}

double vd() 	// Drift Velocity

{
	double vd , electric_field, mass, rt ; 	// rt -> relaxation time || E -> Electric Field
	char choice ;
	cout << "\n Drift Velocity :- " << endl;
	cout << " Enter the Mass : " ;
	cin >> mass;
	cout << " Enter Relaxation Time : " ;
	cin >> rt ;
	cout << " Do you know the value of Electric Field (y/n) \n > " ;
	x:  	// x is to repeatly type answer (if wrong)
	cin >> choice ;

	if ( choice == 'n' || choice == 'N' )
	{
		electric_field = E();
	}

	else if ( choice == 'y' || choice == 'Y' )
	{
		cout << " Enter the Electric Field : ";
		cin >> electric_field ;

	}

	else
	{
		cout<< " Wrong Input \n > " ;
		goto x;
	}

	vd = (-1)*e*electric_field*rt/mass ;
	cout << " Drift Velocity = " << vd << " m/s " << endl;

	return vd ;
}

void mob()  	//Mobility
{
	double Vd , electric_field , mobi ; 	// mobi is the mobility
	char choice;

	cout << " Do you know the value of Electric Field (y/n) \n > " ;
	x:  	// x is to repeatly type answer (if wrong)
	cin >> choice ;

	if ( choice == 'n' || choice == 'N' )
	{
		double mass , rt ;
		cout << " Enter the Mass : " ;
		cin >> mass;
		cout << " Enter Relaxation Time : " ;
		cin >> rt ;

		mobi = e * rt/mass;
		goto y;
	}


	else if ( choice == 'y' || choice == 'Y' )
	{
		cout << " Enter the Electric Field : ";
		cin >> electric_field ;

	}

	else
	{
		cout<< " Wrong Input \n > " ;
		goto x;
	}

	cout << " Do you know the value of Drift Velocity (y/n) \n > " ;
	z:  	// x is to repeatly type answer (if wrong)
	cin >> choice ;

	if ( choice == 'n' || choice == 'N' )
	{
		Vd = vd();
	}

	else if ( choice == 'y' || choice == 'Y' )
	{
		cout << " Enter the Drift Velocity : ";
		cin >> Vd ;

	}

	else
	{
		cout<< " Wrong Input \n > " << choice << endl;
		goto z;
	}

	mobi = Vd / electric_field ;
	y:
	cout << " Mobility = " << mobi << " mC/Ns" << endl;
}

double R()  	// Resistance

{
	double resistance , length , area , rst; 	//rst is the resistivity

	cout << " Enter the length of conductor : ";
	cin >> length ;
	cout << " Enter the Cross Sectional Area of the conductor : ";
	cin >> area ;
	cout << " Enter the Resistivity : " ;
	cin >> rst ;

	resistance = rst * length/area ;
	cout << " Resistance = " << resistance << " ohm" << endl;

	return resistance ;

}

double V() 		// OHM's Law (Potencial Difference)

{
	double potential_difference , current , resistance ;
	char choice, choice1 ;

	cout << " Do you know the value of Current (y/n) \n > " ;
	x:  	// x is to repeatly type answer (if wrong)
	cin >> choice ;

	if ( choice == 'n' || choice == 'N' )
	{
		current = I();
	}

	else if ( choice == 'y' || choice == 'Y' )
	{
		cout << " Enter the Current : " ;
		cin >> current ;
	}

	else
	{
		cout<< " Wrong Input \n > " ;
		goto x;
	}
	cout << " Do you know the value of Resistance (y/n) \n > " ;
	z:  	// x is to repeatly type answer (if wrong)
	cin >> choice1 ;

	if ( choice1 == 'n' || choice1 == 'N' )
	{
		resistance = R();
	}

	else if ( choice1 == 'y' || choice1 == 'Y' )
	{
		cout << " Enter the Resistance : " ;
		cin >> resistance ;

	}

	else
	{
		cout<< " Wrong Input \n > " ;
		goto z;
	}

	potential_difference = current * resistance ;
	cout << " Potential Difference = " << potential_difference << " V" << endl;

	return potential_difference ;
}

double rst()  	// Resistivity

{
	double resistance , length , area , rst; 	//rst is the resistivity

	cout << " Enter the length of conductor : ";
	cin >> length ;
	cout << " Enter the Cross Sectional Area of the conductor : ";
	cin >> area ;
	cout << " Enter the Resistance : " ;
	cin >> resistance ;

	rst = resistance * area/length ;
	cout << " Resistivity = " << rst << " ohm m"<< endl;

	return rst ;

}


void vohm()  	//Vector form of ohm's law

{
	double electric_field , charge_density , resistivity ;
	char choice , choice1;

	cout << " Do you know the value of Resistivity (y/n) \n > " ;
	x:  	// x is to repeatly type answer (if wrong)
	cin >> choice ;

	if ( choice == 'n' || choice == 'N' )
	{
		resistivity = rst();
	}

	else if ( choice == 'y' || choice == 'Y' )
	{
		cout << " Enter the Value of Resistivity : " ;
		cin >> resistivity ;
	}

	else
	{
		cout<< " Wrong Input \n > " ;
		goto x;
	}

	cout << " Do you know the value of Charge Density (y/n) \n > " ;
	z:  	// x is to repeatly type answer (if wrong)
	cin >> choice1 ;

	if ( choice1 == 'n' || choice1 == 'N' )
	{
		charge_density = Cdensity();
	}

	else if ( choice1 == 'y' || choice1 == 'Y' )
	{
		cout << " Enter the Value of Charge Density : " ;
		cin >> charge_density ;
	}

	else
	{
		cout<< " Wrong Input \n > " ;
		goto z;
	}

	electric_field = charge_density*resistivity ;
	cout << " Electric Field = " << electric_field << " V/m" << endl;

}

void G() 	// conductance

{
	double conductance , resistance ;
	char choice ;

	cout << " Do you know the value of Resistance (y/n) \n > " ;
	x:  	// x is to repeatly type answer (if wrong)
	cin >> choice ;

	if ( choice == 'n' || choice == 'N' )
	{
		resistance = R();
	}

	else if ( choice == 'y' || choice == 'Y' )
	{
		cout << " Enter the Resistance : ";
		cin >> resistance ;
	}

	else
	{
		cout<< " Wrong Input \n > " ;
		goto x;
	}

	conductance = 1/resistance ;
	cout << " Conductance = " << conductance << " S" << endl ; // unit is seimen or ohm(inverse)

}


void cndct() 	// conductivity

{
	double conductivity,resistivity ;
	char choice ;

	cout << " Do you know the value of Resistivity (y/n) \n > " ;
	x:  	// x is to repeatly type answer (if wrong)
	cin >> choice ;

	if ( choice == 'n' || choice == 'N' )
	{
		resistivity = rst();
	}

	else if ( choice == 'y' || choice == 'Y' )
	{
		cout << " Enter the Value of Resistivity : " ;
		cin >> resistivity ;
	}

	else
	{
		cout<< " Wrong Input \n > " ;
		goto x;
	}

	conductivity = 1/resistivity ;
	cout << " Conductivity = " << conductivity << " S/m" << endl ; // unit is seimen/metre or ohm(inverse) metre(inverse)

}


void codetocolor() 		// Convert Code to Color

{
	int i , j , digit[4];
	string first_color, second_color, third_color, fourth_color ;

	const char* color[] = {
			 "\033[1;30m Black ",
			 "\033[1;33m Brown ",
		 	 "\033[1;31m Red ",
			 "\033[1;31m Orange ",
			 "\033[1;33m Yellow ",
			 "\033[1;32m Green ",
			 "\033[1;34m Blue ",
			 "\033[1;35m Violet ",
			 "\033[1;30m Grey ",
			 "\033[1;37m White "};	 // Color codes included

	const char* tolore[] = {
		"\033[1;33m Gold ",
		"\033[1;37m Silver " };

	char reset[] = "\033[0m";

	cout << " Enter the First Number (10's place) : " ; 	//first digit
	cin >> digit[0] ;
	cout << " Enter the Second Number (1's place) : " ; 	//second digit
	cin >> digit[1] ;
	cout << " Enter the Number of Zero (Power of 10) : " ; 	//10 raised to?
	cin >> digit[2] ;
	cout << " Enter the Tolerance (only digit) : " ; 	// It will be in the Form ( + or - number % )
	cin >> digit[3] ;

	for( i=0 ; i<=3 ; i++ )
	{
		for( j=0 ; j<10 ; j++ )
		{
			if( i == 0 )
			{
				if( digit[i] == j )
				{
					first_color = color[j] ;
				}
			}
			else if( i == 1 )
			{
				if( digit[i] == j )
				{
					second_color = color[j] ;
				}
			}
			else if( i == 2 )
			{
				if( digit[i] == j )
				{
					third_color = color[j] ;
				}
			}
			else if( i == 3 )
			{
				if( digit[i] == 5 )
				{
					fourth_color = tolore[0];
				}
				else if(digit[i] == 10)
				{
					fourth_color = tolore[1];
				}
			}
		}
	}
	cout << first_color << '\t' << second_color << '\t' << third_color << '\t' << fourth_color << endl ;
	cout << " 10's " << '\t' << " 1's " << '\t' << " Power " << '\t' << " Tolerance " << reset <<endl ;

}

void colortocode () 		// Convert Color_Code to Code

{
	int i , j ;
	const char* color[] = {
			 "Black",
			 "Brown",
		 	 "Red",
			 "Orange",
			 "Yellow",
			 "Green",
			 "Blue",
			 "Violet",
			 "Grey",
			 "White"};
	const char* tolore[] = {
		"Gold",
		"Silver" };


	int first_number, second_number, third_number, fourth_number ;
	char choice ;
	string input;
	vector<string>colours;

	cout << " Enter the First Colour (1st Band) : " ; 	//first digit
	cin >> input;
	colours.push_back(input);
	cout << " Enter the Second Colour (2nd Band) : " ; 	//second digit
	cin >> input;
	colours.push_back(input);
	cout << " Enter the Third Colour (3rd Band) : " ; 	//10 raised to?
	cin >> input;
	colours.push_back(input);
	cout << " Does it have Colour (y/n) " ;
	x:
	cin >> choice ;

	if ( choice == 'n' || choice == 'N' )
	{
		fourth_number = 20 ;
	}

	else if ( choice == 'y' || choice == 'Y' )
	{
		cout << " Enter the Fourth Colour : " ;
		cin >> input;
		colours.push_back(input);
	}

	else
	{
		cout<< " Wrong Input \n > " ;
		goto x;
	}

	for( i=0 ; i<=3 ; i++ )
	{
		for( j=0 ; j<10 ; j++ )
		{
			if( i == 0 )
			{
				if( colours.at(i) == color[j] )
				{
					first_number = j ;
				}
			}
			else if( i == 1 )
			{
				if( colours.at(i) == color[j] )
				{
					second_number = j ;
				}
			}
			else if( i == 2 )
			{
				if( colours.at(i) == color[j] )
				{
					third_number = j ;
				}
			}
			else if( i == 3 )
			{
				if( colours.at(i) == tolore[0] )
				{
					fourth_number = 5 ;
				}
				else if(colours.at(i) == tolore[1])
				{
					fourth_number = 10 ;
				}
			}
		}
	}
	cout << first_number << second_number << " x 10^" << third_number << " +- " << fourth_number << "%" << endl ;

}


void ReqS() 		// Effective Resistance (Series Connection)
{
	double r1 , rn[20] , resistance ,total;
	int i;
	
	cout << " Enter Total Number of Resistance : " ;
	cin >> total ;
	
	cout << " Enter First Resistance : " ;
	cin >> r1;
	
	for (i=0 ; i<total ; i++)
	{
		cout << " Enter next Resistance : " ;
		cin >> rn[i];
	}
	
	resistance =r1;
	
	for (i=0 ; i<total ; i++)
	{
		resistance = resistance + rn[i];
	}
	
	cout << " Resistance = " << resistance << " ohm" ;
}


void ReqP() 		// Effective Resistance (Parallel Connection)
{
	double r1 , rn[20] , resistance ;
	int i, total ;
	
	z:
	cout << " \n Enter Total Number of Resistance (2 or 3) : " ;
	cin >> total ;
	
	if ( total > 3 || total < 1 )
	{
		goto z;
	}
	
	cout << " Enter First Resistance : " ;
	cin >> r1;
	
	for (i=0 ; i<total ; i++)
	{
		cout << " Enter next Resistance : " ;
		cin >> rn[i];
	}
	
	resistance =r1;
	
	
		if( total == 1)
			resistance = r1 ;
		else if ( total == 2 )
			resistance = rn[0]*r1 ;
		else
		{
			double denometer ;
			denometer = ( r1*rn[0] + rn[0]*rn[1] + rn[1]*r1 ) ;
			resistance = (resistance *rn[0]* rn[1] )/denometer ;
		}
	
	cout << " Resistance = " << resistance << " ohm" ;
}


void Emf()

{
	
	double emf, potential_difference , current , internal_resistance;
	char choice1;
	
	cout << "Enter the Internal resistance : " ;
	cin >> internal_resistance;
	
	cout << " Do you know the value of Current (y/n) \n > " ;
	x:  	// x is to repeatly type answer (if wrong)
	cin >> choice1 ;

	if ( choice1 == 'n' || choice1 == 'N' )
	{
		current = I();
	}

	else if ( choice1 == 'y' || choice1 == 'Y' )
	{
		cout << " Enter the Value of Current : " ;
		cin >> current ;
	}

	else
	{
		cout<< " Wrong Input \n > " ;
		goto x;
	}
	
	cout << " Enter the Potential Difference : ";
	cin >> potential_difference;
	
	emf = potential_difference + current * internal_resistance;

	cout << " EMF of Cell = " << emf ;

}


void MBridge_R() 		// Metre Bridge Unknown Resistance

{
	
	float resistance , unknown_resistance , length ;
	
	cout << " Enter the Known Resistance : "; 
	cin >> resistance ;
	
	cout << " Enter the Length (l) : " ;
	cin >> length ;
	
	unknown_resistance = resistance* length / (100-length) ;
	
	cout << " Unknown Resistance = " << unknown_resistance << " ohm";
	
}


void potentioM_emf() 		// Potentiometre Unknown EMF

{
	
	float emf , unknown_emf , length1 , length2 ;
	
	cout << " Enter the Known EMF : "; 
	cin >> emf ;
	
	cout << " Enter Balancing Length (l1) of Known EMF : " ;
	cin >> length1 ;
	
	cout << " Enter Balancing Length (l2) of Unknown EMF : " ;
	cin >> length2 ;
	
	unknown_emf = emf * length2/length1 ;
	
	cout << " Unknown EMF = " << unknown_emf << " V";
	
}


void inter_resist_cell() 		// Internal Resistance of a Cell

{
	
	float internal_resistance , resistance , length1 , length2 ;
	
	cout << " Enter the Resistance : "; 
	cin >> resistance ;
	
	cout << " Enter Balancing Length (l1) of Cell : " ;
	cin >> length1 ;
	
	cout << " Enter Balancing Length (l2) of Both Cell and Resistor : " ;
	cin >> length2 ;
	
	internal_resistance = (length1/length2 -1) * resistance ;
	
	cout << " Internal Resistance = " << internal_resistance << " ohm";
	
}


void poten_gradient()	 	// Potential Gradient (sensitivity of Potentiometre)

{
	
	float potential_gradient , length , voltage ;
	
	cout << " Enter the Voltage : " ;
	cin >> voltage ;
	
	cout << " Enter the Length : " ;
	cin >> length ;
	
	potential_gradient = voltage / length ;
	cout << " Potential Gradient (K) = " << potential_gradient << " v/m" ;
	
}


void Elect_Pow() 	// Electric Power

{
	
	// float power , current , resistance  ;
	int option , time_taken; 
	float power , work , voltage , charge , current , resistance ;
	
	cout << " \n \n Which way do you prefer : " << endl ;
	
	repeat :
	
	cout << " \n 1.Work & Time \n 2.Voltage , Charge & Time \n 3.Voltage & Current \n 4.Current & Resistance \n 5.Voltage & Resistance \n Your Answer : " ;
	cin >> option ;
	
	switch (option)
	{
		case 1:
			
			cout << " Enter the Work Done : " ;
			cin >> work ;
			cout << " Enter the Time Taken : " ;
			cin >> time_taken ;
			
			power = work / time_taken ;
			
			break ;
		
		case 2 :
			
			cout << " Enter the Voltage : " ;
			cin >> voltage ;
			cout << " Enter the Charge : " ;
			cin >> charge ;
			cout << " Enter the Time Taken : " ;
			cin >> time_taken ;
			
			power = voltage * charge / time_taken ;
			
			break ;
			
		case 3 :
			
			cout << " Enter the Voltage : " ;
			cin >> voltage ;
			cout << " Enter the Current : " ;
			cin >> current ;
			
			power = voltage * current ;
			
			break ;
		
		case 4 :
			
			cout << " Enter the Current : " ;
			cin >> current ;
			cout << " Enter the Resistance : " ;
			cin >> resistance ;
			
			power = current* current * resistance ;
			
			break ;
			
		case 5 :
			
			cout << " Enter the Voltage : " ;
			cin >> voltage ;
			cout << " Enter the Resistance : " ;
			cin >> resistance ;
			
			power = voltage* voltage / resistance ;
			
			break ;
			
		default :
		
			cout << "\n \n  Wrong Input  \n \n  " ;
			goto repeat ;
		
	}
	
	cout << " Power = " << power << " W" << endl ;
	
}
	
					/*
				  // Chapter 3 Finished \\


						// Chapter 4 \\
				   // Moving Charge & Magnetism \\
										   		 */
										   		 
										   		 

void m_lorrentz() 	// Magnetic Lorrentz Force

{
	
	float magnetic_force , velocity , charge , magnetic_field ;
	double angle ;
	
	cout << " Enter the Charge : " ;
	cin >> charge ;
	cout << " Enter the Velocity : " ;
	cin >> velocity ;
	cout << " Enter the Magnetic Flux Density (B) : " ;
	cin >> magnetic_field ;
	cout << " Enter the Angle b/w Velocity & Magnetic density in (Radian) : " ;
	cin >> angle ;
	
	magnetic_force = charge * velocity * magnetic_field * sin(angle) ;
	
	cout << " Magnetic Force = " << magnetic_force << " N" << endl ;
	
}


void lorrentz()

{
	float electric_field , electric_force , magnetic_force , velocity , charge , magnetic_field , lorrentz_force ;
	double angle ;
	
	cout << " Enter the Electric Field : " ; 
	cin >> electric_field ;	
	cout << " Enter the Charge : " ;
	cin >> charge ;	
	
	electric_force = charge * electric_field ;
	
	cout << " Enter the Velocity : " ;
	cin >> velocity ;
	cout << " Enter the Magnetic Flux Density (B) : " ;
	cin >> magnetic_field ;
	cout << " Enter the Angle b/w Velocity & Magnetic density in (Radian) : " ;
	cin >> angle ;
	
	magnetic_force = charge * velocity * magnetic_field * sin(angle) ;
	
	lorrentz_force = electric_force + magnetic_force ;
	
	cout << " Total Lorrentz Force = " << lorrentz_force << " N" << endl ;			
	
}				   		


void E4r_m()		// Eqn for radius due to Magnetic Field

{
	float mass , velocity , charge , magnetic_field , radius ;
	
	cout << " Enter the Mass : " ;
	cin >> mass ;
	cout << " Enter the Velocity : " ;
	cin >> velocity ;
	cout << " Enter the Charge : " ;
	cin >> charge ;
	cout << " Enter the Magnetic Field (B) : " ;
	cin >> magnetic_field ;
	
	radius = (mass * velocity) / (charge * magnetic_field) ;

	cout << " Radius = " << radius << " m" << endl ;
	
}


void E4v_m()		// Eqn for velocity due to Magnetic Field

{
	float mass , velocity , charge , magnetic_field , radius ;
	
	cout << " Enter the Mass : " ;
	cin >> mass ;
	cout << " Enter the Radius : " ;
	cin >> radius ;
	cout << " Enter the Charge : " ;
	cin >> charge ;
	cout << " Enter the Magnetic Field (B) : " ;
	cin >> magnetic_field ;
	
	velocity = (charge * magnetic_field * radius) / mass ;

	cout << " Velocity = " << velocity << " m/s" << endl ;
	
}


void t4circle_m() 	// Time Period of a Circular Motion due to Magnetic Field

{
	float time_period , mass , charge , magnetic_field ;
	
	cout << " Enter the Mass : " ;
	cin >> mass ;
	cout << " Enter the Charge : " ;
	cin >> charge ;
	cout << " Enter the Magnetic Field (B) : " ;
	cin >> magnetic_field ;
	
	time_period = (2*pi * mass) / (charge * magnetic_field) ;
	
	cout << " Time Period = " << time_period << " s" << endl ;
	
}


void f4circle_m() 	// Frequency of a Circular Motion due to Magnetic Field

{
	float frequency , mass , charge , magnetic_field ;
	
	cout << " Enter the Mass : " ;
	cin >> mass ;
	cout << " Enter the Charge : " ;
	cin >> charge ;
	cout << " Enter the Magnetic Field (B) : " ;
	cin >> magnetic_field ;
	
	frequency = (charge * magnetic_field) / (2*pi * mass) ;
	
	cout << " Frequency = " << frequency << " s-1" << endl ;
	
}


void pitch_helical() 	// Pitch On Helical Path

{
	float pitch , velocity , mass , charge , magnetic_field ;
	double angle ;
	
	cout << " Enter the Mass : " ;
	cin >> mass ;
	cout << " Enter the Charge : " ;
	cin >> charge ;
	cout << " Enter the Magnetic Field (B) : " ;
	cin >> magnetic_field ;
	cout << " Enter the Angle b/w Magnetic Field & Velocity : " ;
	cin >> angle ;
	
	pitch = velocity * cos(angle)  * (2*pi * mass) / (charge * magnetic_field) ;
	
	cout << " Pitch = " << pitch << " m" << endl ;
	
}
	
	
void ke_ac_ion() 	// Kinetic Energy of Accelerated Ion

{
	float mass , velocity , charge , magnetic_field , radius , kinetic_energy ;
	
	cout << " Enter the Mass : " ;
	cin >> mass ;
	cout << " Enter the Radius : " ;
	cin >> radius ;
	cout << " Enter the Charge : " ;
	cin >> charge ;
	cout << " Enter the Magnetic Field (B) : " ;
	cin >> magnetic_field ;
	
	velocity = (charge * magnetic_field * radius) / mass ;
	kinetic_energy = (mass * velocity * velocity) / 2 ;

	cout << " Kinetic Energy = " << kinetic_energy << " J" << endl ;
	
}


void velocity_selector() 	// Find the Selecting Velocity

{
	float velocity , electric_field , magnetic_field ;
	
	cout << " Enter the Magnetic Field : " ;
	cin >> magnetic_field ;
	cout << " Enter the Electric Field : " ;
	cin >> electric_field ;
	
	velocity = electric_field / magnetic_field ;
	
	cout << " The Velocity of Particles that undeviated = " << velocity << " m/s" << endl ;
}
	
void velocity_light() 		// Velocity Of Light

{
	double nu , exlon ;
	float velocity ;
	
	cout << " Enter the Permitivity : " ;
	cin >> exlon ;
	cout << " Enter the Permeability : " ;
	cin >> nu ;
	
	velocity = 1 / (sqrt( nu * exlon)) ;
	
	cout << " Velocity = " << velocity << " m/s" << endl ;
	
}

void m_circular_loop() 		// Magnetic Field on the axis of a circular current loop

{
	float current , radius , length , magnetic_field ;
	
	cout << " Enter the Current : " ;
	cin >> current;
	cout << " Enter the Radius of the circle : " ;
	cin >> radius ;
	cout << " Enter the distance of the point on the axis : " ;
	cin >> length ;
	
	magnetic_field = nu0 * current * radius / 2* pow(( radius*radius + length*length ),1.5) ;
	
	cout << " Magnetic Field = " << magnetic_field << " T" << endl ;
	
}

void m_centre_circular_loop() 		// Magnetic Field at the centre of a circular current loop

{
	float current , radius , magnetic_field ;
	
	cout << " Enter the Current : " ;
	cin >> current;
	cout << " Enter the Radius of the circle : " ;
	cin >> radius ;
	
	magnetic_field = nu0 * current / 2*radius ;
	
	cout << " Magnetic Field = " << magnetic_field << " T" << endl ;
	
}

void m_force_parallel_current() 	// Magnetic Force b/w two Parallel Current Carrying Conductors

{
	float current1,current2 , length ,distance , magnetic_force ;
	
	cout << " Enter the 1st Current : " ;
	cin >> current1 ;
	cout << " Enter the 2nd Current : " ;
	cin >> current2 ;
	cout << " Enter Total Length of the Wire : " ;
	cin >> length ;
	cout << " Enter the Distance b/w Them : " ;
	cin >> distance ;
	
	magnetic_force = nu0 * current1 * current2 * length / 2 * pi* distance ;
	
	cout << " Magnetic Force = " << magnetic_force << " N" << endl ;
	
}


void m_force_current()		 // Magnetic Force on a current carrying conductor 

{
	float magnetic_force , magnetic_field , current , length ;
	double angle ;
	
	cout << " Enter the Current : " ;
	cin >> current ;
	cout << " Enter the Magnetic Field : " ;
	cin >> magnetic_field ;
	cout << " Enter the Length : " ;
	cin >> length ;
	cout << " Enter the Angle b/w Current and Magnetic Field : " ;
	cin >> angle ;
	
	magnetic_force = current * length * magnetic_field * sin(angle) ;
	
	cout << " Magnetic Force = " << magnetic_force << " N" << endl ;
	
}

void m_field_long_wire() 	// Magnetic Field Due to Infinitely long staight wire carrying current

{
	float magnetic_field , current , radius ;

	cout << " Enter the current : " ;
	cin >> current ;
	cout << " Enter the distance to the point : " ;
	cin >> radius ;

	magnetic_field = nu0 * current / 2*pi * radius ;

	cout << " Magnetic Field = " << magnetic_field << " T" << endl;
}


void m_field_long_solenoid() 	// Magnetic Field to a Long Solenoid

{
	float current , turns , magnetic_field ;
	
	cout << " Enter the Current : " ;
	cin >> current ;
	cout << " Enter the No.of Turns : " ;
	cin >> turns ;
	
	magnetic_field = nu0 * turns * current ;
	
	cout << " Magnetic Field = " << magnetic_field << " T" << endl;
	
}


void current_electron() 	// Current of a revolving electron

{
	float current , velocity , radius;
	
	cout << " Enter the Velocity of Electron : " ;
	cin >> velocity ;
	cout << " Enter the Radius of circular orbit : " ;
	cin >> radius ;
	
	current = e*velocity / 2*pi * radius ;
	
	cout << " Current = " << current << " A" << endl;
	
}
	
	
	
#endif
