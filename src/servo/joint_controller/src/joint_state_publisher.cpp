#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/Twist.h>
#include <ros/console.h>
#include <tf/transform_datatypes.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/calib3d/calib3d.hpp"

// Message publication
#include <std_msgs/Float64.h>
#include <sstream>
#include <math.h>

using namespace cv;
using namespace std;
int thetha[10];

ros::Publisher jointt1;
ros::Publisher jointt2;
ros::Publisher joint11;
ros::Publisher joint12;
ros::Publisher joint21;
ros::Publisher joint22;
ros::Publisher joint31;
ros::Publisher joint32;
ros::Publisher joint41;
ros::Publisher joint42;


void ab()
{
  namedWindow("Slider", CV_WINDOW_NORMAL);
  createTrackbar("jointt1","Slider",&thetha[0],157);
  createTrackbar("jointt2","Slider",&thetha[1],157);
  createTrackbar("joint11","Slider",&thetha[2],157);
  createTrackbar("joint12","Slider",&thetha[3],157);
  createTrackbar("joint21","Slider",&thetha[4],157);
  createTrackbar("joint22","Slider",&thetha[5],157);
  createTrackbar("joint31","Slider",&thetha[6],157);
  createTrackbar("joint32","Slider",&thetha[7],157);
  createTrackbar("joint41","Slider",&thetha[8],157);
  createTrackbar("joint42","Slider",&thetha[9],157);
  waitKey(10);
}



int main(int argc, char** argv)
{
    ros::init(argc, argv, "arm_joints");
    ros::NodeHandle nh;

    // publisher declaration

    jointt1 = nh.advertise<std_msgs::Float64>("/servo/jointt1_position_controller/command", 1);
    jointt2 = nh.advertise<std_msgs::Float64>("/servo/jointt2_position_controller/command", 1);
    joint11 = nh.advertise<std_msgs::Float64>("/servo/joint11_position_controller/command", 1);
    joint12 = nh.advertise<std_msgs::Float64>("/servo/joint12_position_controller/command", 1);
    joint21 = nh.advertise<std_msgs::Float64>("/servo/joint21_position_controller/command", 1);
    joint22 = nh.advertise<std_msgs::Float64>("/servo/joint22_position_controller/command", 1);
    joint31 = nh.advertise<std_msgs::Float64>("/servo/joint31_position_controller/command", 1);
    joint32 = nh.advertise<std_msgs::Float64>("/servo/joint32_position_controller/command", 1);
    joint41 = nh.advertise<std_msgs::Float64>("/servo/joint41_position_controller/command", 1);
    joint42 = nh.advertise<std_msgs::Float64>("/servo/joint42_position_controller/command", 1);

    
    ros::Rate rate(50.0); // frequency of operation

    while (ros::ok())
    {
        ab();
        std_msgs::Float64 Jointt1;
        std_msgs::Float64 Jointt2;
        std_msgs::Float64 Joint11;
        std_msgs::Float64 Joint12;
        std_msgs::Float64 Joint21;
        std_msgs::Float64 Joint22;
        std_msgs::Float64 Joint31;
        std_msgs::Float64 Joint32;
        std_msgs::Float64 Joint41;
        std_msgs::Float64 Joint42;

        Jointt1.data = (float)thetha[0]/100;
        Jointt2.data = (float)thetha[1]/100;
        Joint11.data = (float)thetha[2]/100;
        Joint12.data = (float)thetha[3]/100;
        Joint21.data = (float)thetha[4]/100;
        Joint22.data = (float)thetha[5]/100;
        Joint31.data = (float)thetha[6]/100;
        Joint32.data = (float)thetha[7]/100;
        Joint41.data = (float)thetha[8]/100;
        Joint42.data = (float)thetha[9]/100;

        jointt1.publish(Jointt1);
        jointt2.publish(Jointt2);
        joint11.publish(Joint11);
        joint12.publish(Joint12);
        joint21.publish(Joint21);
        joint22.publish(Joint22);
        joint31.publish(Joint31);
        joint32.publish(Joint32);
        joint41.publish(Joint41);
        joint42.publish(Joint42);

        ros::spinOnce();
        rate.sleep();
    }
    return 0;

}
