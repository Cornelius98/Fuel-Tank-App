#include <stdio.h>
#include <stdlib.h>

int t_fuel = 0;
int t_miles = 0;
float t_fuel_per_mile = 0;

int menu();
int set_fuel ()
{
    int s_fuel;
    printf("\n\n Enter The Litres of Fuel, The Vehicle Consumed On The Trip:\n");
    scanf("%d",&s_fuel);
    s_fuel = s_fuel + s_fuel;
    return s_fuel;
}
int set_miles ()
{
    int s_miles;
    printf("\n\n Enter The Number Of Miles, The Driver Covered Driving On This Trip:\n");
    scanf("%d",&s_miles);
    s_miles = s_miles + s_miles;
    return s_miles;
}
double per_tankfuel_sum(int miles,float fuel)
{
    float fuel_per_mile;
    fuel_per_mile = (miles/fuel);
    return fuel_per_mile;
}
double trip_summary()
{
    t_miles = set_miles ();
    t_fuel = set_fuel ();
    t_fuel_per_mile = per_tankfuel_sum(t_miles,t_fuel);
    printf("\n\n Total Fuel Spent Per Mile on This Trip is:%f litres per mile \n\n",t_fuel_per_mile);
}
double all_trip_summary()
{
    int proceed;
    float fuel_gallons = 0.0;
    float gallon_proportion = 4.54609;
    if(t_fuel ==0 || t_miles ==0)
    {
         printf("\n\n Record Atleast a Single Trip To Find The Overral Total.\n\n");
         //menu();
    }
    else
    {
        fuel_gallons = (t_fuel/gallon_proportion);
        t_fuel_per_mile = per_tankfuel_sum(t_miles,fuel_gallons);
         printf("Total Gallons of Fuel Spent on Total Miles Of All The Trips You Recorded Are:%f gallons per mile. \n Do You Want To Add More Trips?\n 1. Yes \n 2.No \n\n\n Enter 1 to Add Trips  or 2 To Exit:\n",t_fuel_per_mile);
         scanf("%d",&proceed);
        if(proceed == 1)
            menu();
        else
            exit(1);
    }

}
void process_menu(int kill)
{
     while( kill!=9)
    {
        switch(kill)
        {
            case 1:
                trip_summary();
                menu();
                break;
            case 2:
                all_trip_summary();
                menu();
                break;
            case 9:
                exit;
                break;
            default:
                menu();
        }

    }
}
int menu()
{
    int kill;
    printf("***** TANKFUEL TRACKING MENU ***\n\n 1. Record a Trip\n 2. All Trips Summary\n 9. EXIT\n Enter Your option Below :\n");
    scanf("%d",&kill);
    if(kill>0 && kill<10)
        process_menu(kill);
    else
    {
        printf("\n\n You Must Enter One Of The Option Below\n\n");
        menu();
    }
}

int main()
{
    menu();
    return 0;
}
