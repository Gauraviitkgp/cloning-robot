#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include <trajectory_msgs/JointTrajectory.h>
#include "ros/time.h"
#include <geometry_msgs/Pose.h>
#include <sensor_msgs/Imu.h>
#include <tf/transform_datatypes.h>

// Message publication
#include <math.h>
#define JOINTS 12
#define PI  3.1415926535897931
#define WP 6


using namespace std;
float roll,pitch,yaw;//x,y,z
    // publisher declaration
ros::Publisher Hand;

void OrientationCallback(const sensor_msgs::Imu::ConstPtr& msg)
{
    float quatx= msg->orientation.x;
    float quaty= msg->orientation.y;
    float quatz= msg->orientation.z;
    float quatw= msg->orientation.w;
    //thetha=3*asin(2*(quatw*quaty-quatz*quatx));
    //thetha=quatz;
    // roll (x-axis rotation)
    double sinr = +2.0 * (quatw * quatx + quaty * quatz);
    double cosr = +1.0 - 2.0 * (quatx * quatx + quaty * quaty);
    roll = atan2(sinr, cosr);

    // pitch (y-axis rotation)
    double sinp = +2.0 * (quatw * quaty - quatz * quatx);
    if (fabs(sinp) >= 1)
        pitch = copysign(M_PI / 2, sinp); // use 90 degrees if out of range
    else
        pitch = asin(sinp);

    // yaw (z-axis rotation)
    double siny = +2.0 * (quatw * quatz + quatx * quaty);
    double cosy = +1.0 - 2.0 * (quaty * quaty + quatz * quatz);  
    yaw = atan2(siny, cosy);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "balance");
    ros::NodeHandle nh;

    // publisher declaration

    Hand = nh.advertise<trajectory_msgs::JointTrajectory>("/baby/Hand_controller/command",1);
    ros::Subscriber sub= nh.subscribe("/baby/imu",2,OrientationCallback); //For eg the publisher for servo data is /mavros/imu/data

    trajectory_msgs::JointTrajectory traj;
    ros::Rate rate(50.0); // frequency of operation

    traj.header.frame_id = "root";
    traj.joint_names.resize(JOINTS);
    traj.joint_names[0] ="Right_hand_y";
    traj.joint_names[1] ="Right_hand_x";
    traj.joint_names[2] ="Right_hand_z";
    traj.joint_names[3] ="Right_palm_y";
    traj.joint_names[4] ="Right_palm_x";
    traj.joint_names[5] ="Right_hinge";
    traj.joint_names[6] ="Left_hand_y";
    traj.joint_names[7] ="Left_hand_x";
    traj.joint_names[8] ="Left_hand_z";
    traj.joint_names[9] ="Left_palm_y";
    traj.joint_names[10]="Left_palm_x";
    traj.joint_names[11]="Left_hinge";

    traj.points.resize(1);

    ros::Duration(1).sleep();
    ros::Time T=ros::Time::now();
    
    ros::Duration D;
    ros::Duration TFS[WP];
    // ros::Duration sleep[WP];
    // ros::Duration cumilative[WP];

    TFS[0]=ros::Duration(0.5);//Secs for first program
    TFS[1]=ros::Duration(0.5);
    TFS[2]=ros::Duration(0.5);
    TFS[3]=ros::Duration(0.5);
    TFS[4]=ros::Duration(0.5);
    TFS[5]=ros::Duration(0.5);
    // sleep[0]=ros::Duration(0.0);
    // sleep[1]=ros::Duration(0.0);
    // sleep[2]=ros::Duration(0.0);
    // sleep[3]=ros::Duration(0.0);
    // sleep[4]=ros::Duration(0.0);
    // sleep[5]=ros::Duration(0.3);//sec for which position will be held
    
    // ros::Duration sum;
    
    // for (int i=0;i<WP;i++)
    // {
    //     sum=ros::Duration(0.0);
    //     for(int j=0;j<=i;j++)
    //         sum+=TFS[j]+sleep[j];
    //     cout<<sum;
    //     cumilative[i]=sum;
    // }
    int flag=-1;
    int flagprev=0;
    while (ros::ok())
    {
        traj.header.stamp = ros::Time::now();
        D=ros::Time::now()-T;
        cout<<"Yaw value:-"<<yaw<<endl;

        if(flag==flagprev)
        {
            T=ros::Time::now();
            if(pitch<-0.30)
            {
                traj.points[0].positions.resize(JOINTS);
                traj.points[0].positions={-PI/2,0,0,0,0,0,-PI/2,0,0,0,0,0};
                traj.points[0].velocities.resize(JOINTS);
                traj.points[0].velocities={0,0,0,0,0,0,0,0,0,0,0,0};
                traj.points[0].accelerations.resize(JOINTS);
                traj.points[0].accelerations={0,0,0,0,0,0,0,0,0,0,0,0};
                traj.points[0].effort.resize(JOINTS);
                traj.points[0].effort={0,0,0,0,0,0,0,0,0,0,0,0};
                traj.points[0].time_from_start = TFS[0];
                cout<<"Adjusting Hand"<<endl;
                flag=1;
            }
            else if(pitch>0.30)
            {
                traj.points[0].positions.resize(JOINTS);
                traj.points[0].positions={+PI/2,0,0,0,0,0,+PI/2,0,0,0,0,0};
                traj.points[0].velocities.resize(JOINTS);
                traj.points[0].velocities={0,0,0,0,0,0,0,0,0,0,0,0};
                traj.points[0].accelerations.resize(JOINTS);
                traj.points[0].accelerations={0,0,0,0,0,0,0,0,0,0,0,0};
                traj.points[0].effort.resize(JOINTS);
                traj.points[0].effort={0,0,0,0,0,0,0,0,0,0,0,0};
                traj.points[0].time_from_start = TFS[0];
                cout<<"Adjusting Hand invert"<<endl;
                flag=2;
            }

            else
            {
                traj.points[0].positions.resize(JOINTS);
                traj.points[0].positions={0,0,0,0,0,0,0,0,0,0,0,0};
                traj.points[0].velocities.resize(JOINTS);
                traj.points[0].velocities={0,0,0,0,0,0,0,0,0,0,0,0};
                traj.points[0].accelerations.resize(JOINTS);
                traj.points[0].accelerations={0,0,0,0,0,0,0,0,0,0,0,0};
                traj.points[0].effort.resize(JOINTS);
                traj.points[0].effort={0,0,0,0,0,0,0,0,0,0,0,0};
                traj.points[0].time_from_start = TFS[1];
                cout<<"Resetting Position"<<endl;
                flag=0;
            }
        }
        else
        {
            if(D>ros::Duration(4.0))
                flagprev=flag;
        }

        Hand.publish(traj);
        ros::spinOnce();
        rate.sleep();
    }
    return 0;

}
