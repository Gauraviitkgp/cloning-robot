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
int thetha[14];

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
ros::Publisher Right_hinge;
ros::Publisher Right_palm_x;
ros::Publisher Right_palm_y;
ros::Publisher Right_palm_z;


void ab()
{
    thetha[11]=thetha[12]=thetha[13]=157;
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
    createTrackbar("Right_hinge","Slider",&thetha[10],157);
    createTrackbar("Right_palm_x","Slider",&thetha[11],314);
    createTrackbar("Right_palm_y","Slider",&thetha[12],314);
    createTrackbar("Right_palm_z2","Slider",&thetha[13],314);
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
    Right_hinge = nh.advertise<std_msgs::Float64>("/servo/Right_hinge_position_controller/command", 1);
    Right_palm_x = nh.advertise<std_msgs::Float64>("/servo/Right_palm_x_position_controller/command", 1);
    Right_palm_y = nh.advertise<std_msgs::Float64>("/servo/Right_palm_y_position_controller/command", 1);
    Right_palm_z = nh.advertise<std_msgs::Float64>("/servo/Right_palm_z_position_controller/command", 1);

    
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
        std_msgs::Float64 right_hinge;
        std_msgs::Float64 right_palm_x;
        std_msgs::Float64 right_palm_y;
        std_msgs::Float64 right_palm_z;

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
        right_hinge.data = (float)thetha[10]/100;
        right_palm_x.data = (float)(thetha[11]-157)/100;
        right_palm_y.data = (float)(thetha[12]-157)/100;
        right_palm_z.data = (float)(thetha[13]-157)/100;

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
        Right_hinge.publish(right_hinge);
        Right_palm_x.publish(right_palm_x);
        Right_palm_y.publish(right_palm_y);
        Right_palm_z.publish(right_palm_z);
        ros::spinOnce();
        rate.sleep();
    }
    return 0;

}
