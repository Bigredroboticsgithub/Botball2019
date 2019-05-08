#include <kipr/botball.h>

#define MV_SPEED -1000	
#define MV_FASTER -3200
#define BLACK 3900	//Lowest value for black
#define WHITE 2900	//Highest value for white
#define BLUE 3400	//Lowest value for blue
#define GREY
#define STOP ao()	//Stop all motors

void	move_until_encounter(int fin_color)
{
    while(1)
    {
        if (analog(0) < WHITE && analog(5) < WHITE)
        {
            mav(0, MV_SPEED);
            mav(1, MV_SPEED);
        }
        if (analog(0) > fin_color || analog(5) > fin_color)
        {
            STOP;
            break;
        }
    }
    return;
}

// follow line takes a color value and makes the robot follow it until encounters White color.
void	follow_line(int color)
{
    //robot is moving forward while both sensors see the color
    while (1)
    {
        if (analog(0)>color && analog(5)>color)
        {
            mav(0, MV_SPEED);
            mav(1, MV_SPEED);
        }
        //stopping the robot if both sensors see white
        else if (analog(0) < WHITE && analog(5) < WHITE)
        {
            STOP;
            break;
        }
        //if one of the sensors see white one wheel goes faster
        else if (analog(0) < WHITE)
        {
            mav(0, MV_FASTER);
            mav(1, MV_SPEED);
        }
        else if (analog(5) < WHITE)
        {
            mav(0, MV_SPEED);
            mav(1, MV_FASTER);
        }
    }
    return;
}



int main()
{
    //create_connect()
    follow_line(BLACK);
    move_until_encounter(BLACK); //black box line thing
    return 1;
}
