#include <ros/ros.h>
#include <trajectory_msgs/JointTrajectory.h>
#include "ros/time.h"

ros::Publisher Right_hand;

int setValeurPoint(trajectory_msgs::JointTrajectory* trajectoire,int id,int pos_tab, int val);

int main(int argc, char** argv) 
{
    ros::init(argc, argv, "state_publisher");
    ros::NodeHandle n;

    Right_hand = n.advertise<trajectory_msgs::JointTrajectory>("/baby/Right_hand_controller/command",1);
    
    ros::Rate loop_rate(1);

    trajectory_msgs::JointTrajectory traj;
    trajectory_msgs::JointTrajectoryPoint points_n;

    traj.header.frame_id = "chest";
    traj.joint_names.resize(2);
    traj.points.resize(2);

    traj.points[0].positions.resize(2);
    traj.points[1].positions.resize(2);

    traj.joint_names[0] ="Right_hand_y";
    traj.joint_names[1] ="Left_hand_y";

    
    while(ros::ok()) 
    {

        traj.header.stamp = ros::Time::now();
        traj.points[0].positions[0]=3.14;
        traj.points[0].positions[1]=3.14;
        traj.points[1].positions[0]=1;
        traj.points[1].positions[1]=1;
        traj.points[0].time_from_start = ros::Duration(6.0);
        traj.points[1].time_from_start = ros::Duration(1.0);

        Right_hand.publish(traj);
        ros::spinOnce();

        loop_rate.sleep();
    }

    return 0;
}

int setValeurPoint(trajectory_msgs::JointTrajectory* trajectoire,int id,int pos_tab, int val){
    trajectoire->points[id].positions[pos_tab] = val%2;
    return 0;
}