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
int thetha_right[17];
int thetha_left[17];
int thetha_other[15];

ros::Publisher Right_jointt1;
ros::Publisher Right_jointt2;
ros::Publisher Right_joint11;
ros::Publisher Right_joint12;
ros::Publisher Right_joint21;
ros::Publisher Right_joint22;
ros::Publisher Right_joint31;
ros::Publisher Right_joint32;
ros::Publisher Right_joint41;
ros::Publisher Right_joint42;
ros::Publisher Right_hinge;
ros::Publisher Right_palm_x;
ros::Publisher Right_palm_y;
ros::Publisher Right_palm_z;
ros::Publisher Right_hand;
ros::Publisher Right_hand_x;
ros::Publisher Right_hand_z;

ros::Publisher Left_jointt1;
ros::Publisher Left_jointt2;
ros::Publisher Left_joint11;
ros::Publisher Left_joint12;
ros::Publisher Left_joint21;
ros::Publisher Left_joint22;
ros::Publisher Left_joint31;
ros::Publisher Left_joint32;
ros::Publisher Left_joint41;
ros::Publisher Left_joint42;
ros::Publisher Left_hinge;
ros::Publisher Left_palm_x;
ros::Publisher Left_palm_y;
ros::Publisher Left_palm_z;
ros::Publisher Left_hand_y;
ros::Publisher Left_hand_x;
ros::Publisher Left_hand_z;

ros::Publisher Neck_y;
ros::Publisher Head_z;
ros::Publisher Head_x;
ros::Publisher Right_leg_y;
ros::Publisher Right_leg_z;
ros::Publisher Right_leg_x;
ros::Publisher Right_leg_hinge;
ros::Publisher Right_foot_y;
ros::Publisher Left_leg_y;
ros::Publisher Left_leg_z;
ros::Publisher Left_leg_x;
ros::Publisher Left_leg_hinge;
ros::Publisher Left_foot_y;


void ab()
{
    // thetha_right[12]=thetha_left[12]=thetha_right[14]=thetha_left[14]=157;
    namedWindow("Right Hand Sliders", CV_WINDOW_NORMAL);
    createTrackbar("Right_jointt1","Right Hand Sliders",&thetha_right[0],157);
    createTrackbar("Right_jointt2","Right Hand Sliders",&thetha_right[1],157);
    createTrackbar("Right_joint11","Right Hand Sliders",&thetha_right[2],157);
    createTrackbar("Right_joint12","Right Hand Sliders",&thetha_right[3],157);
    createTrackbar("Right_joint21","Right Hand Sliders",&thetha_right[4],157);
    createTrackbar("Right_joint22","Right Hand Sliders",&thetha_right[5],157);
    createTrackbar("Right_joint31","Right Hand Sliders",&thetha_right[6],157);
    createTrackbar("Right_joint32","Right Hand Sliders",&thetha_right[7],157);
    createTrackbar("Right_joint41","Right Hand Sliders",&thetha_right[8],157);
    createTrackbar("Right_joint42","Right Hand Sliders",&thetha_right[9],157);
    createTrackbar("Right_hinge","Right Hand Sliders",&thetha_right[10],314);
    createTrackbar("Right_palm_y","Right Hand Sliders",&thetha_right[12],314);
<<<<<<< HEAD
    //createTrackbar("Right_palm_z","Right Hand Sliders",&thetha_right[13],314);
    createTrackbar("Right_hand","Right Hand Sliders",&thetha_right[14],314);
    //createTrackbar("Right_hand_x","Right Hand Sliders",&thetha_right[15],314);
    //createTrackbar("Right_hand_z","Right Hand Sliders",&thetha_right[16],314);
=======
    createTrackbar("Right_palm_x","Right Hand Sliders",&thetha_right[11],314);
    createTrackbar("Right_hand_y","Right Hand Sliders",&thetha_right[14],628);
    createTrackbar("Right_hand_x","Right Hand Sliders",&thetha_right[15],628);
    createTrackbar("Right_hand_z","Right Hand Sliders",&thetha_right[16],628);
>>>>>>> a1be921752e1b1a103237c6e8eefa59f6623a261

    namedWindow("Left Hand Sliders", CV_WINDOW_NORMAL);
    createTrackbar("Left_jointt1","Left Hand Sliders",&thetha_left[0],157);
    createTrackbar("Left_jointt2","Left Hand Sliders",&thetha_left[1],157);
    createTrackbar("Left_joint11","Left Hand Sliders",&thetha_left[2],157);
    createTrackbar("Left_joint12","Left Hand Sliders",&thetha_left[3],157);
    createTrackbar("Left_joint21","Left Hand Sliders",&thetha_left[4],157);
    createTrackbar("Left_joint22","Left Hand Sliders",&thetha_left[5],157);
    createTrackbar("Left_joint31","Left Hand Sliders",&thetha_left[6],157);
    createTrackbar("Left_joint32","Left Hand Sliders",&thetha_left[7],157);
    createTrackbar("Left_joint41","Left Hand Sliders",&thetha_left[8],157);
    createTrackbar("Left_joint42","Left Hand Sliders",&thetha_left[9],157);
    createTrackbar("Left_hinge","Left Hand Sliders",&thetha_left[10],314);
    createTrackbar("Left_palm_y","Left Hand Sliders",&thetha_left[12],314);
    createTrackbar("Left_palm_z","Left Hand Sliders",&thetha_left[13],628);
    createTrackbar("Left_palm_x","Left Hand Sliders",&thetha_left[11],314);
    createTrackbar("Left_hand_y","Left Hand Sliders",&thetha_left[14],628);
    createTrackbar("Left_hand_x","Left Hand Sliders",&thetha_left[15],628);
    createTrackbar("Left_hand_z","Left Hand Sliders",&thetha_left[16],628);

    namedWindow("Other Sliders", CV_WINDOW_NORMAL);
    createTrackbar("Neck_y","Other Sliders",&thetha_other[0],314);
    createTrackbar("Head_x","Other Sliders",&thetha_other[1],314);
    createTrackbar("Head_z","Other Sliders",&thetha_other[2],314);
    createTrackbar("Right_leg_y","Other Sliders",&thetha_other[3],314);
    createTrackbar("Right_leg_z","Other Sliders",&thetha_other[9],314);
    createTrackbar("Right_leg_x","Other Sliders",&thetha_other[10],314);
    createTrackbar("Right_leg_hinge","Other Sliders",&thetha_other[4],157);
    createTrackbar("Right_foot_y","Other Sliders",&thetha_other[5],314);
    createTrackbar("Left_leg_y","Other Sliders",&thetha_other[6],314);
    createTrackbar("Left_leg_hinge","Other Sliders",&thetha_other[7],157);
    createTrackbar("Left_foot_y","Other Sliders",&thetha_other[8],314);
    createTrackbar("Left_leg_z","Other Sliders",&thetha_other[11],314);
    createTrackbar("Left_leg_x","Other Sliders",&thetha_other[12],314);
    waitKey(10);
}



int main(int argc, char** argv)
{
    ros::init(argc, argv, "arm_joints");
    ros::NodeHandle nh;

    Right_jointt1 = nh.advertise<std_msgs::Float64>("/baby/Right_jointt1_position_controller/command", 1);
    Right_jointt2 = nh.advertise<std_msgs::Float64>("/baby/Right_jointt2_position_controller/command", 1);
    Right_joint11 = nh.advertise<std_msgs::Float64>("/baby/Right_joint11_position_controller/command", 1);
    Right_joint12 = nh.advertise<std_msgs::Float64>("/baby/Right_joint12_position_controller/command", 1);
    Right_joint21 = nh.advertise<std_msgs::Float64>("/baby/Right_joint21_position_controller/command", 1);
    Right_joint22 = nh.advertise<std_msgs::Float64>("/baby/Right_joint22_position_controller/command", 1);
    Right_joint31 = nh.advertise<std_msgs::Float64>("/baby/Right_joint31_position_controller/command", 1);
    Right_joint32 = nh.advertise<std_msgs::Float64>("/baby/Right_joint32_position_controller/command", 1);
    Right_joint41 = nh.advertise<std_msgs::Float64>("/baby/Right_joint41_position_controller/command", 1);
    Right_joint42 = nh.advertise<std_msgs::Float64>("/baby/Right_joint42_position_controller/command", 1);
    Right_hinge = nh.advertise<std_msgs::Float64>("/baby/Right_hinge_position_controller/command", 1);
    Right_palm_x = nh.advertise<std_msgs::Float64>("/baby/Right_palm_x_position_controller/command", 1);
    Right_palm_y = nh.advertise<std_msgs::Float64>("/baby/Right_palm_y_position_controller/command", 1);
    Right_palm_z = nh.advertise<std_msgs::Float64>("/baby/Right_palm_z_position_controller/command", 1);
    Right_hand = nh.advertise<std_msgs::Float64>("/baby/Right_hand_controller/command", 1);
    Right_hand_x = nh.advertise<std_msgs::Float64>("/baby/Right_hand_x_position_controller/command", 1);
    Right_hand_z = nh.advertise<std_msgs::Float64>("/baby/Right_hand_z_position_controller/command", 1);
    
    Left_jointt1 = nh.advertise<std_msgs::Float64>("/baby/Left_jointt1_position_controller/command", 1);
    Left_jointt2 = nh.advertise<std_msgs::Float64>("/baby/Left_jointt2_position_controller/command", 1);
    Left_joint11 = nh.advertise<std_msgs::Float64>("/baby/Left_joint11_position_controller/command", 1);
    Left_joint12 = nh.advertise<std_msgs::Float64>("/baby/Left_joint12_position_controller/command", 1);
    Left_joint21 = nh.advertise<std_msgs::Float64>("/baby/Left_joint21_position_controller/command", 1);
    Left_joint22 = nh.advertise<std_msgs::Float64>("/baby/Left_joint22_position_controller/command", 1);
    Left_joint31 = nh.advertise<std_msgs::Float64>("/baby/Left_joint31_position_controller/command", 1);
    Left_joint32 = nh.advertise<std_msgs::Float64>("/baby/Left_joint32_position_controller/command", 1);
    Left_joint41 = nh.advertise<std_msgs::Float64>("/baby/Left_joint41_position_controller/command", 1);
    Left_joint42 = nh.advertise<std_msgs::Float64>("/baby/Left_joint42_position_controller/command", 1);
    Left_hinge = nh.advertise<std_msgs::Float64>("/baby/Left_hinge_position_controller/command", 1);
    Left_palm_x = nh.advertise<std_msgs::Float64>("/baby/Left_palm_x_position_controller/command", 1);
    Left_palm_y = nh.advertise<std_msgs::Float64>("/baby/Left_palm_y_position_controller/command", 1);
    Left_palm_z = nh.advertise<std_msgs::Float64>("/baby/Left_palm_z_position_controller/command", 1);
    Left_hand_y = nh.advertise<std_msgs::Float64>("/baby/Left_hand_y_position_controller/command", 1);
    Left_hand_x = nh.advertise<std_msgs::Float64>("/baby/Left_hand_x_position_controller/command", 1);
    Left_hand_z = nh.advertise<std_msgs::Float64>("/baby/Left_hand_z_position_controller/command", 1);
    
    thetha_other[0]=157;//Neck joints
    thetha_other[1]=157;
    thetha_right[14]=314;//RIght_hand_y
    thetha_right[15]=314+157;//Right_hand_x
    thetha_left[14]=314+157;//Left_hand_y
    thetha_left[15]=157;//Left_hand_x


    Neck_y = nh.advertise<std_msgs::Float64>("/baby/Neck_y_position_controller/command", 1);
    Head_x = nh.advertise<std_msgs::Float64>("/baby/Head_x_position_controller/command", 1);
    Head_z = nh.advertise<std_msgs::Float64>("/baby/Head_z_position_controller/command", 1);
    Left_leg_y = nh.advertise<std_msgs::Float64>("/baby/Left_leg_y_position_controller/command", 1);
    Left_foot_y = nh.advertise<std_msgs::Float64>("/baby/Left_foot_y_position_controller/command", 1);
    Left_leg_hinge = nh.advertise<std_msgs::Float64>("/baby/Left_leg_hinge_position_controller/command", 1);    
    Right_leg_y = nh.advertise<std_msgs::Float64>("/baby/Right_leg_y_position_controller/command", 1);
    Right_foot_y = nh.advertise<std_msgs::Float64>("/baby/Right_foot_y_position_controller/command", 1);
    Right_leg_hinge = nh.advertise<std_msgs::Float64>("/baby/Right_leg_hinge_position_controller/command", 1);    
    Left_leg_x = nh.advertise<std_msgs::Float64>("/baby/Left_leg_x_position_controller/command", 1);
    Left_leg_z = nh.advertise<std_msgs::Float64>("/baby/Left_leg_z_position_controller/command", 1);
    Right_leg_x = nh.advertise<std_msgs::Float64>("/baby/Right_leg_x_position_controller/command", 1);
    Right_leg_z = nh.advertise<std_msgs::Float64>("/baby/Right_leg_z_position_controller/command", 1);

    ros::Rate rate(50.0); // frequency of operation

    while (ros::ok())
    {
        ab();
        std_msgs::Float64 right_jointt1;
        std_msgs::Float64 right_jointt2;
        std_msgs::Float64 right_joint11;
        std_msgs::Float64 right_joint12;
        std_msgs::Float64 right_joint21;
        std_msgs::Float64 right_joint22;
        std_msgs::Float64 right_joint31;
        std_msgs::Float64 right_joint32;
        std_msgs::Float64 right_joint41;
        std_msgs::Float64 right_joint42;
        std_msgs::Float64 right_hinge;
        std_msgs::Float64 right_palm_x;
        std_msgs::Float64 right_palm_y;
        std_msgs::Float64 right_palm_z;
        std_msgs::Float64 right_hand;
        std_msgs::Float64 right_hand_x;
        std_msgs::Float64 right_hand_z;

        std_msgs::Float64 left_jointt1;
        std_msgs::Float64 left_jointt2;
        std_msgs::Float64 left_joint11;
        std_msgs::Float64 left_joint12;
        std_msgs::Float64 left_joint21;
        std_msgs::Float64 left_joint22;
        std_msgs::Float64 left_joint31;
        std_msgs::Float64 left_joint32;
        std_msgs::Float64 left_joint41;
        std_msgs::Float64 left_joint42;
        std_msgs::Float64 left_hinge;
        std_msgs::Float64 left_palm_x;
        std_msgs::Float64 left_palm_y;
        std_msgs::Float64 left_palm_z;
        std_msgs::Float64 left_hand_y;
        std_msgs::Float64 left_hand_x;
        std_msgs::Float64 left_hand_z;
        
        std_msgs::Float64 neck_y;
        std_msgs::Float64 head_x;
        std_msgs::Float64 head_z;
        std_msgs::Float64 left_leg_y;
        std_msgs::Float64 left_foot_y;
        std_msgs::Float64 left_leg_hinge;
        std_msgs::Float64 right_leg_y;
        std_msgs::Float64 right_foot_y;
        std_msgs::Float64 right_leg_hinge;
        std_msgs::Float64 left_leg_z;
        std_msgs::Float64 left_leg_x;
        std_msgs::Float64 right_leg_z;
        std_msgs::Float64 right_leg_x;

        right_jointt1.data = (float)thetha_right[0]/100;
        right_jointt2.data = (float)thetha_right[1]/100;
        right_joint11.data = (float)thetha_right[2]/100;
        right_joint12.data = (float)thetha_right[3]/100;
        right_joint21.data = (float)thetha_right[4]/100;
        right_joint22.data = (float)thetha_right[5]/100;
        right_joint31.data = (float)thetha_right[6]/100;
        right_joint32.data = (float)thetha_right[7]/100;
        right_joint41.data = (float)thetha_right[8]/100;
        right_joint42.data = (float)thetha_right[9]/100;
        right_hinge.data = (float)thetha_right[10]/100;
        right_palm_x.data = (thetha_right[11])/100.0;
        right_palm_y.data = (thetha_right[12])/100.0;
        right_palm_z.data = (thetha_right[13])/100.0;
        right_hand.data= (float)(thetha_right[14])/100;
        right_hand_x.data= (float)(thetha_right[15])/100;
        right_hand_z.data= (float)(thetha_right[16])/100;

        Right_jointt1.publish(right_jointt1);
        Right_jointt2.publish(right_jointt2);
        Right_joint11.publish(right_joint11);
        Right_joint12.publish(right_joint12);
        Right_joint21.publish(right_joint21);
        Right_joint22.publish(right_joint22);
        Right_joint31.publish(right_joint31);
        Right_joint32.publish(right_joint32);
        Right_joint41.publish(right_joint41);
        Right_joint42.publish(right_joint42);
        Right_hinge.publish(right_hinge);
        Right_palm_x.publish(right_palm_x);
        Right_palm_y.publish(right_palm_y);
        Right_palm_z.publish(right_palm_z);
        Right_hand.publish(right_hand);
        Right_hand_x.publish(right_hand_x);
        Right_hand_z.publish(right_hand_z);

        left_jointt1.data = (float)thetha_left[0]/100;
        left_jointt2.data = (float)thetha_left[1]/100;
        left_joint11.data = (float)thetha_left[2]/100;
        left_joint12.data = (float)thetha_left[3]/100;
        left_joint21.data = (float)thetha_left[4]/100;
        left_joint22.data = (float)thetha_left[5]/100;
        left_joint31.data = (float)thetha_left[6]/100;
        left_joint32.data = (float)thetha_left[7]/100;
        left_joint41.data = (float)thetha_left[8]/100;
        left_joint42.data = (float)thetha_left[9]/100;
        left_hinge.data = (float)thetha_left[10]/100;
        left_palm_x.data = (thetha_left[11])/100.0;
        left_palm_y.data = (thetha_left[12])/100.0;
        left_palm_z.data = (thetha_left[13])/100.0;
        left_hand_y.data= (float)(thetha_left[14])/100;
        left_hand_x.data= (float)(thetha_left[15])/100;
        left_hand_z.data= (float)(thetha_left[16])/100;

        Left_jointt1.publish(left_jointt1);
        Left_jointt2.publish(left_jointt2);
        Left_joint11.publish(left_joint11);
        Left_joint12.publish(left_joint12);
        Left_joint21.publish(left_joint21);
        Left_joint22.publish(left_joint22);
        Left_joint31.publish(left_joint31);
        Left_joint32.publish(left_joint32);
        Left_joint41.publish(left_joint41);
        Left_joint42.publish(left_joint42);
        Left_hinge.publish(left_hinge);
        Left_palm_x.publish(left_palm_x);
        Left_palm_y.publish(left_palm_y);
        Left_palm_z.publish(left_palm_z);
        Left_hand_y.publish(left_hand_y);
        Left_hand_x.publish(left_hand_x);
        Left_hand_z.publish(left_hand_z);

        neck_y.data= (float)(thetha_other[0]-157)/100;
        head_x.data= (float)(thetha_other[1]-157)/100;
        head_z.data= (float)(thetha_other[2])/100;

        Neck_y.publish(neck_y);
        Head_x.publish(head_x);
        Head_z.publish(head_z);

        left_leg_y.data= (float)(thetha_other[3])/100;
        left_leg_hinge.data= (float)(thetha_other[4])/100;
        left_foot_y.data= (float)(thetha_other[5])/100;
        right_leg_y.data= (float)(thetha_other[6])/100;
        right_leg_hinge.data= (float)(thetha_other[7])/100;
        right_foot_y.data= (float)(thetha_other[8])/100;
        left_leg_z.data= (float)(thetha_other[9])/100;
        left_leg_x.data= (float)(thetha_other[10])/100;
        right_leg_z.data= (float)(thetha_other[11])/100;
        right_leg_x.data= (float)(thetha_other[12])/100;

        Left_leg_y.publish(left_leg_y);
        Left_leg_hinge.publish(left_leg_hinge);
        Left_foot_y.publish(left_foot_y);
        Right_leg_y.publish(right_leg_y);
        Right_leg_hinge.publish(right_leg_hinge);
        Right_foot_y.publish(right_foot_y);
        Left_leg_z.publish(left_leg_z);
        Left_leg_x.publish(left_leg_x);
        Right_leg_z.publish(right_leg_z);
        Right_leg_x.publish(right_leg_x);

        ros::spinOnce();
        rate.sleep();
    }
    return 0;

}
