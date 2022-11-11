#include <iostream>
#include <iomanip>
#include "physics.h"
#include "chemistry.h"
#include "csc.h"

using namespace std;

class sub_menu{ // Menu to show chapters of each subject
    public:
        void sub_menu_physics();
        void sub_menu_chemistry();
        void sub_menu_csc();

        class problems_menu{ // Class to hold problems database from chapters
            public:
                void physics(int chapter); // with chapter number arguement
                void chemistry(int chapter);
                void csc(int chapter);
        };
};

sub_menu sb;
sub_menu::problems_menu pb; // Intializing variable to the subclass

const string alert = "\033[1;31m"; // red color
const string success = "\033[1;32m"; // green color
const string info = "\033[1;34m"; // blue color
const string yellow = "\033[1;33m";
const string clear_color = "\033[0m";

void main_menu()
{
    int op;
    cout << yellow << "\n MAIN MENU:- " << endl;
    cout << info << " Note :- While inputing values like 1.066*10^23 , " << endl;
    cout << "\t Please do in this form : 1.066e23 " << endl;
    cout << "\t If the exponent is negative , then form : 1.066e-23 . \n\n" << yellow;
    cout << " 1. Physics " << endl;
    cout << " 2. Chemistry " << endl;
    cout << " 3. Computer Science " << endl;
    cout << " 4. About the Program " << endl;
    cout << " 0. Exit the Program " << endl;
    cout << " Enter a Option : ";
    cin >> op;
    switch(op)
    {
        case 1:
            sb.sub_menu_physics(); // calling function inside the class
            break;
        case 2:
            sb.sub_menu_chemistry();
            break;
        case 3:
            sb.sub_menu_csc();
            break;
        case 4:
            cout << success << "\n\t\t\t ASC - Advanced Science Calculator \n\n";
            cout << info << " Build   : Pre-Alpha Build "  << endl;
            cout << " Version : v0.1 pre-alpha build " << endl;
            cout << "\n Description : A simple all in one science subject"<<endl;
            cout <<"                problem solver for +2 Students " << endl;
            cout << "               Developed by Mr. Unkn0wn , Ph0en1x and Salman " << endl;
            cout << "\n Thank You For using our program <3 <3 <3 \n\n" << clear_color << endl;
            exit(0);
            break;
        case 0:
            cout << alert << "\n Closing Program ...... " << clear_color << endl;
            exit(0);
            break;
        default:
            cout << alert << "\n Invalid option please try again " << endl;
    }
}

void sub_menu::sub_menu_physics() // Function inside a class
{
    int op;
    cout << "\n CHAPTER MENU:- " << endl;
    cout << " 1. Electric Charges and Fields " << endl;
    cout << " 3. Current Electricity " << endl;
    cout << " 4. Moving Charge & Magnetism " << endl ;
    cout << " 0. Back to Main Menu " << endl;
    cout << " Enter a Option : ";
    cin >> op;
    switch(op)
    {
	     case 0:
	          main_menu();
	          break;
       case 1:
            pb.physics(1);
            break;
       case 3:
            pb.physics(3);
            break;
       case 4:
			pb.physics(4);
			break;
       default:
            cout << alert << "\n Invalid option please try again " << endl;
    }
}

void sub_menu::sub_menu_chemistry()
{
    int op;
    cout << "\n CHAPTER MENU:- " << endl;
    cout << " 1. Solid States " << endl;
    cout << " 2. Solutions " << endl;
    cout << " 4. Chemical Kinetics " << endl;
    cout << " 0. Back to Main Menu " << endl;
    cout << " Enter a Option : ";
    cin >> op;
    switch(op)
    {
	    case 0:
	       main_menu();
	       break;
        case 1:
            pb.chemistry(1);
            break;
        case 2:
            pb.chemistry(2);
            break;
        case 4:
            pb.chemistry(4);
            break;
        default:
            cout << alert << "\n Invalid option please try again "<< endl;
    }
}

void sub_menu::sub_menu_csc()
{
  cout << "\n CHAPTER MENU:- " << endl;
  int o;
  cout << " 1. Structures and Pointers " << endl;
  cout << " 3. Data Structures " << endl; 
  cout << " 0. Back to Main Menu " << endl;
  cout << " Enter the option : ";
  cin >> o;
  switch(o)
  {
    case 0:
          main_menu();
    case 1:
          pb.csc(1);
          break;
    case 3:
          pb.csc(3);
          break;
    default:
          cout << alert << "\n Invalid option please try again " << endl;
  }
}


void sub_menu::problems_menu::physics( int chapter) // Initializing function inside a subclass
{
  int o;
  char ch;
  do{
    cout << "\n PROBLEMS MENU:- " << endl;
    if(chapter == 1)
    {
        cout << " 1. Find Quantization " << endl;
        cout << " 2. Find Force Between 2 charges " << endl;
        cout << " 3. Find Electric Field " << endl;
        cout << " 4. Find Electric Flux " << endl;
        cout << " 5. Find Electric Dipole " << endl;
        cout << " 6. Find Torque " << endl;
        cout << " 7. EField of EDipole at Axiel Line " << endl;
        cout << " 8. EField of EDipole at Equatorial Line " << endl;
        cout << " 9. Electric Flex using Guass's Law " << endl;
        cout << " 10. Linear Charge Density " << endl;
        cout << " 11. Surface Charge Density " << endl;
        cout << " 12. EField due to a long straight uniformly charged wire " << endl;
        cout << " 13. EField due to an uniformly charged infinite plane sheet " << endl;
        cout << " 14. \"\" plane sheet with finite thickness " << endl;
        cout << " 15. EField due to an uniformly charged thin spherical shell " << endl;
        cout << " 0. Back to Chapter Menu " << endl;
	      cout << " Enter a Option : ";
        cin >> o;
	      if(o == 0)
	          sb.sub_menu_physics();
	      else if(o == 1)
            q(); // Quantization
        else if(o == 2)
            f(); // Force
        else if(o == 3)
            E(); // Electric Field
        else if(o == 4)
            Eflux(); // Electric Flux
        else if(o == 5)
            Edipole(); // Electric Dipole
        else if(o == 6)
            torque(); // Torque
        else if(o == 7)
            EofDipole_al(); // Electric Field of Electric Dipole at Axiel Line
        else if(o == 8)
            EofDipole_el(); // Electric Field of Electric Dipole at Equatorial Line
        else if(o == 9)
            Eflux_Glaw(); // Electric Flux using Guass's Law
        else if(o == 10)
            Ldensity(); // Linear Density
        else if(o == 11)
            Sdensity(); // Surface Density
        else if(o == 12)
            Efield_inflong_w(); // Efield Charged Wire
        else if(o == 13)
            Efield_infplane_s(); // Efield Plane Sheet
        else if(o == 14)
            Efield_infplane_st(); // Efield Plane Sheet Finite Thickness
        else if(o == 15)
            Efield_s_shell(); // Efield Spherical Shell
        else
            cout << alert << "\n Invalid option please try again" << endl;
    }
    else if(chapter == 2)
    {

    }
    else if(chapter == 3)
    {
        cout << " 1. Current " << endl;
        cout << " 2. Current Density " << endl;
        cout << " 3. Drift Velocity " << endl;
        cout << " 4. Mobility " << endl;                        
        cout << " 5. Potential Difference (Ohm's Law) " << endl;
        cout << " 6. Electric Field by Vector Form of Ohm's Law " << endl;        
        cout << " 7. Resistance " << endl;
        cout << " 8. Resistivity " << endl;
        cout << " 9. Condantance " << endl;
        cout << " 10.Condactivity " << endl;
        cout << " 11.Find color of bands of Resistor " << endl; 
        cout << " 12.Find Resistance of bands of a Resistor " << endl; 
        cout << " 13.Total Resistance in Series Connection " << endl ;
        cout << " 14.Total Resistance in Parallel Connection " << endl ;        
        cout << " 15.Find E.M.F of Cell " << endl;
        cout << " 16.Find Unknown Resistance in a Metre Bridge " << endl ;
        cout << " 17.Find Unknown EMF in Potentiometre " << endl ;
        cout << " 18.Find Internal Resistance of a Cell using Potentiometre " << endl ;
        cout << " 19.Find Potential Gradient of a Potentiometre " << endl ;
        cout << " 20.Find Electric Power " << endl ;
        cout << " 0. Back to chapter menu " << endl ;
        cout << " Enter a Option : ";
        cin >> o;
        if(o == 0)
            sb.sub_menu_physics();
        else if(o == 1)
            I(); // Current
        else if(o == 2)
            Cdensity(); // Current Density
        else if(o == 3)
            vd(); // Drift Velocity
        else if(o == 4)
            mob(); // Mobility
        else if(o == 5)
            V(); // Potential Difference            
        else if(o == 6)
            R(); // Resistance
        else if(o == 7)
            rst(); // Resistivity
        else if(o == 8)
            vohm(); // Electric Field
        else if(o == 9)
            G(); // Conductance
        else if(o == 10)
            cndct(); // Condactivity
        else if(o == 11)
			codetocolor(); // color of bands
		else if(o == 12)
			colortocode(); // resistance of bands
		else if(o == 13)
			ReqS();		// Effective Resistance in Series Combination
		else if(o == 14)
			ReqP();		// Effective Resistance in Parallel Combination
		else if(o == 15)
			Emf();		// Emf of Cell (using simple eqn)
		else if(o == 16)
			MBridge_R();	// Unknown Resistance in metre bridge
		else if(o == 17)
			potentioM_emf(); 	// EMF of Cell Using Potentiometre
		else if(o == 18)
			inter_resist_cell(); 	// Internal Resistance of a Cell Using Potentiometre
		else if(o == 19)
			poten_gradient(); 		// Potential Gradient (sensitivity of potentiometre
		else if(o == 20)
			Elect_Pow(); 		// Electric Power using different method
        else
            cout << alert << " Invalid option please try again " << endl;
    }
    else if(chapter == 4)
    {
		cout << " 1. Magnetic Lorrentz Force " << endl ;
		cout << " 2. Total Lorrentz Force " << endl ;
		cout << " 3. Radius of Circular Path due to Perpendicular Magnetic Field " << endl ;
		cout << " 4. Velocity Circular Path due to Perpendicular Magnetic Field " << endl ;
		cout << " 5. Time Period of Circular Path due to Perpendicular Magnetic Field " << endl ;
		cout << " 6. Cyclotron Frequency (Frequency of Circular Path due to Perpendicular Magnetic Field " << endl ;
		cout << " 7. Pitch of Helical Path " << endl ;
		cout << " 8. Kinetic Energy of Accelerated Ion " << endl ;
		cout << " 9. Find the Selected Velocity of Particles in a Velocity Selector " << endl ;
		cout << " 10. Find Velocity of Light in a Medium " << endl ;
		cout << " 11. Find the Magnetic Field on the axis of a circular current loop " << endl ;
		cout << " 12. Find the Magnetic Field at the centre of a circular current loop " << endl ;
		cout << " 13. Find the Magnetic Force b/w two Parallel Current Carrying Conductors " << endl;
		cout << " 14. Find the Magnetic Force On a Current Carrying Conductors " << endl;
		cout << " 15. Find the Magnetic Field Due to Infinitely Long Staight wire Carrying Current " << endl;
		cout << " 16. Find the Magnetic Field of a Long Solenoid/Toroid " << endl;
		cout << " 17. Find the current of a revolving electron in a circular orbit " << endl;
		cout << " 0. Back to chapter menu " << endl ;		
		cout << " Enter a Option : ";
        cin >> o;
        if(o == 0)
            sb.sub_menu_physics();
        else if(o == 1)
			m_lorrentz(); 	// Magnetic Lorrentz Force
		else if(o == 2)
			lorrentz();		// Total Lorrentz Force
		else if(o == 3)
			E4r_m();		// Eqn for radius due to Magnetic Field
		else if(o == 4)
			E4v_m(); 		// Eqn for Velocity due to Magnetic Field
		else if(o == 5)
			t4circle_m(); 	// Time Period for Revolution due to Magnetic Field
		else if(o == 6)
			f4circle_m(); 	// Frequency of a Circular Motion due to Magnetic Field
		else if(o == 7)
			pitch_helical(); 	// Pitch of Helix
		else if(o == 8)
			ke_ac_ion(); 	// Kinetic Energy of Accelerated Ions
		else if(o == 9)
			velocity_selector(); 	// Selected Velocity
		else if(o == 10)
			velocity_light(); 	// Velocity of Light in a Medium
		else if(o == 11)
			m_circular_loop(); 	// Magnetic Field on the axis of a circular current loop
		else if(o == 12)
			m_centre_circular_loop(); 	// Magnetic Field at the centre of a circular current loop
		else if(o == 13)
			m_force_parallel_current();	 // Magnetic Force b/w two Parallel Current Carrying Conductors
		else if(o == 14)
			m_force_current(); 	 // Magnetic Force on a current carrying conductor 
		else if(o == 15)
			m_field_long_wire(); 	// Magnetic Field Due to Infinitely long staight wire carrying current
		else if(o == 16)
			m_field_long_solenoid(); 	// Magnetic Field of a Long Solenoid/toroid
		else if(o == 17)
			current_electron(); 	// Current of a revolving electron
		else
            cout << alert << " Invalid option please try again " << endl;
        
	}
    cout << "\n Do you want to continue the program (y/n) >  ";
    cin >> ch;
  }while(ch == 'y' || ch == 'Y');
}

void sub_menu::problems_menu::chemistry(int chapter)
{
  int o;
  char ch;
  do
  {
    cout << "\n PROBLEMS MENU:- " << endl;
    if(chapter == 1)
    {
        cout << " 1. Density of the unit cell " << endl;
        cout << " 2. Calculate atomic mass of a element " << endl;
        cout << " 3. Total number of atoms " << endl;
        cout << " 0. Back to Chapter Menu " << endl;
	    cout << " Enter a Option : ";
        cin >> o;
	    if(o == 0)
	        sb.sub_menu_chemistry();
	    else if(o == 1)
          density(); // Density of the unit cell
        else if(o == 2)
          atomic_mass();
        else if(o == 3)
          no_of_atoms();
        else
          cout << alert << "\n Invalid option please try again " << endl;
    }
    else if(chapter == 2)
    {
        cout << " 1. Mass Percentage " << endl;
        cout << " 2. Volume Percentage " << endl;
        cout << " 3. Mass by Volume Percentage " << endl;
        cout << " 4. Mole Fraction " << endl;
        cout << " 5. PPM " << endl;
        cout << " 6. Molarity " << endl;
        cout << " 0. Back to Chapter Menu " << endl;
        cout << " Enter a Option : ";
        cin >> o;
        if(o == 0)
            sb.sub_menu_chemistry();
        else if(o == 1)
            mass_percentage();
        else if(o == 2)
            volume_percentage();
        else if(o == 3)
            mass_by_volume_percentage();
        else if(o == 4)
            mole_fraction();
        else if(o == 5)
            ppm();
        else if(o == 6)
            molarity();
        else
            cout << alert << "\n Invalid option please try again " << endl;
    }
    else if(chapter == 4)
    {
        cout << " 1. Order of reaction " << endl;
        cout << " 2. t1/n life of first order reaction " << endl;
        cout << " 3. Activation Energy " << endl;
        cout << " 0. Back to Chapter Menu " << endl;
        cout << " Enter a Option : ";
        cin >> o;
        if(o == 0)
            sb.sub_menu_chemistry();
        else if(o == 1)
            order_of_reaction();
        else if(o == 2)
            life_of_first_order();
        else if(o == 3)
            activation_energy();
        else
            cout << alert << "\n Invalid option please try again " << endl;
    }
    cout << "\n Do you want to continue the program (y/n) > ";
    cin >> ch;
  }while(ch == 'y' || ch == 'Y');
}

void sub_menu::problems_menu::csc(int chapter)
{
  char ch;
  do{
    cout << "\n PROBLEMS MENU:- " << endl;
    if(chapter == 1)
    {
      int o;
      cout << " 1. Create marklist of a group of students " << endl;
      cout << " 0. Back to Chapter Menu " << endl;
      cout << " Enter a Option : ";
      cin >> o;
      if(o == 0)
          sb.sub_menu_csc();
      else if(o == 1)
          marklist();
      else
          cout << alert << "\n Invalid option please try again " << endl;
     }
     else if(chapter == 3)
     {
        int o;
        cout << " 1. Stacks Representation " << endl;
        cout << " 2. Queue Representation " << endl;
        cout << " 0. Back to Chapter Menu " << endl;
        cout << " Enter a Option : ";
        cin >> o;
        if(o == 0)
            sb.sub_menu_csc();
        else if(o == 1)
            stack_representation();
        else if(o == 2)
            queue_representation();
        else
            cout << alert << "\n Invalid option please try again " << endl;
     }
     cout << "\n Do you want to continue the program (y/n) > ";
     cin >> ch;
   }while(ch == 'y' || ch == 'Y');
}
