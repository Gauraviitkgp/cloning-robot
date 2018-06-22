#include <ros/ros.h>
#include <trajectory_msgs/JointTrajectory.h>
#include "ros/time.h"
#include <iostream>
#define JOINTS 6
#define JOINTS2 12
#define PI  3.1415926535897931
using namespace std;

ros::Publisher Leg;
ros::Publisher Hand;

int setValeurPoint(trajectory_msgs::JointTrajectory* trajectoire,int id,int pos_tab, int val);

int main(int argc, char** argv) 
{
    ros::init(argc, argv, "Leg_publisher");
    ros::NodeHandle n;

    Leg = n.advertise<trajectory_msgs::JointTrajectory>("/baby/Leg_controller/command",1);
    Hand = n.advertise<trajectory_msgs::JointTrajectory>("/baby/Hand_controller/command",1);

    ros::Rate loop_rate(50);

    trajectory_msgs::JointTrajectory traj;
    trajectory_msgs::JointTrajectory traj2; 
    trajectory_msgs::JointTrajectoryPoint points_n;

    
    traj.header.frame_id = "root";
    traj.joint_names.resize(JOINTS);
    traj.joint_names[0] ="Right_leg_y";
    traj.joint_names[1] ="Left_leg_y";
    traj.joint_names[2] ="Right_leg_hinge";
    traj.joint_names[3] ="Left_leg_hinge";
    traj.joint_names[4] ="Right_foot_y";
    traj.joint_names[5] ="Left_foot_y";
    
    traj.points.resize(1);

    traj2.header.frame_id = "root";
    traj2.joint_names.resize(JOINTS2);
    traj2.joint_names[0] ="Right_hand_y";
    traj2.joint_names[1] ="Right_hand_x";
    traj2.joint_names[2] ="Right_hand_z";
    traj2.joint_names[3] ="Right_palm_y";
    traj2.joint_names[4] ="Right_palm_x";
    traj2.joint_names[5] ="Right_hinge";
    traj2.joint_names[6] ="Left_hand_y";
    traj2.joint_names[7] ="Left_hand_x";
    traj2.joint_names[8] ="Left_hand_z";
    traj2.joint_names[9] ="Left_palm_y";
    traj2.joint_names[10]="Left_palm_x";
    traj2.joint_names[11]="Left_hinge";

    traj2.points.resize(1);

    ros::Duration(1).sleep();
    ros::Time T=ros::Time::now();
    
    ros::Duration D;
    ros::Duration TFS[7];
    ros::Duration sleep[6];

    TFS[0]=ros::Duration(3.0);//Secs for first program
    TFS[1]=ros::Duration(1.0);
    TFS[2]=ros::Duration(1.0);
    TFS[3]=ros::Duration(1.0);
    TFS[4]=ros::Duration(1.0);
    TFS[5]=ros::Duration(1.0);
    TFS[6]=ros::Duration(1.0);
    sleep[0]=ros::Duration(1.0);
    sleep[1]=ros::Duration(0.0);
    sleep[2]=ros::Duration(0.0);
    sleep[3]=ros::Duration(0.0);
    sleep[4]=ros::Duration(0.0);
    sleep[5]=ros::Duration(0.0);//sec for which position will be held
    while(ros::ok()) 
    {
        traj.header.stamp = ros::Time::now();
        traj2.header.stamp = ros::Time::now();
        D=ros::Time::now()-T;
        cout<<D.toSec()<<endl;
        cout<<TFS[0].toSec()+sleep[0].toSec()<<endl;

        if(D.toSec()<=TFS[0].toSec()+sleep[0].toSec())
        {
            traj.points[0].positions.resize(JOINTS);
            traj.points[0].positions={-PI/4,-PI/4,PI/2,PI/2,-PI/4,-PI/4};
            traj.points[0].velocities.resize(JOINTS);
            traj.points[0].velocities={0,0,0,0,0,0};
            traj.points[0].accelerations.resize(JOINTS);
            traj.points[0].accelerations={0,0,0,0,0,0};
            traj.points[0].effort.resize(JOINTS);
            traj.points[0].effort={0,0,0,0,0,0};
            traj.points[0].time_from_start = TFS[0];
            cout<<"Enter trajectory 0"<<endl;
        }//Initital Setting
        traj2.points[0].positions.resize(JOINTS2);
        traj2.points[0].positions={0,PI,PI,PI/2,0,0,0,PI,3*PI/2,PI/2,0,0};
        traj2.points[0].velocities.resize(JOINTS2);
        traj2.points[0].velocities={0,0,0,0,0,0,0,0,0,0,0,0};
        traj2.points[0].accelerations.resize(JOINTS2);
        traj2.points[0].accelerations={0,0,0,0,0,0,0,0,0,0,0,0};
        traj2.points[0].effort.resize(JOINTS2);
        traj2.points[0].effort={0,0,0,0,0,0,0,0,0,0,0,0};
        traj2.points[0].time_from_start = TFS[1];

        if(4<D.toSec() && D.toSec()<=5)
        {
            traj.points[0].positions.resize(JOINTS);
            traj.points[0].positions={-PI/2,-PI/4,PI/4,PI/2,0,-PI/4};//Lifting Right Leg
            traj.points[0].velocities.resize(JOINTS);
            traj.points[0].velocities={0,0,0,0,0,0};
            traj.points[0].accelerations.resize(JOINTS);
            traj.points[0].accelerations={0,0,0,0,0,0};
            traj.points[0].effort.resize(JOINTS);
            traj.points[0].effort={0,0,0,0,0,0};
            traj.points[0].time_from_start = TFS[2];
            cout<<"Enter trajectory 1"<<endl;
        }

        if(5<D.toSec() && D.toSec()<=6)
        {
            traj.points[0].positions.resize(JOINTS);
            traj.points[0].positions={-PI/4,-PI/4,PI/4,PI/2,0,-PI/4};//Pressing Right Leg
            traj.points[0].velocities.resize(JOINTS);
            traj.points[0].velocities={0,0,0,0,0,0};
            traj.points[0].accelerations.resize(JOINTS);
            traj.points[0].accelerations={0,0,0,0,0,0};
            traj.points[0].effort.resize(JOINTS);
            traj.points[0].effort={0,0,0,0,0,0};
            traj.points[0].time_from_start = TFS[3];
            cout<<"Enter trajectory 2"<<endl;
        }

        if(6<D.toSec() && D.toSec()<=7)
        {
            traj.points[0].positions.resize(JOINTS);
            traj.points[0].positions={-PI/4,-PI/2,PI/4,PI/4,0,0};//Lifting Left Leg
            traj.points[0].velocities.resize(JOINTS);
            traj.points[0].velocities={0,0,0,0,0,0};
            traj.points[0].accelerations.resize(JOINTS);
            traj.points[0].accelerations={0,0,0,0,0,0};
            traj.points[0].effort.resize(JOINTS);
            traj.points[0].effort={0,0,0,0,0,0};
            traj.points[0].time_from_start = TFS[4];
            cout<<"Enter trajectory 3"<<endl;
        }

        if(7<D.toSec() && D.toSec()<=8)
        {
            traj.points[0].positions.resize(JOINTS);
            traj.points[0].positions={-PI/4,-PI/4,PI/4,PI/4,0,0};//Pressing Left Leg
            traj.points[0].velocities.resize(JOINTS);
            traj.points[0].velocities={0,0,0,0,0,0};
            traj.points[0].accelerations.resize(JOINTS);
            traj.points[0].accelerations={0,0,0,0,0,0};
            traj.points[0].effort.resize(JOINTS);
            traj.points[0].effort={0,0,0,0,0,0};
            traj.points[0].time_from_start = TFS[5];
            cout<<"Enter trajectory 4"<<endl;
        }

        if(8<D.toSec())
        {
            traj.points[0].positions.resize(JOINTS);
            traj.points[0].positions={-PI/4,-PI/4,PI/2,PI/2,-PI/4,-PI/4};
            traj.points[0].velocities.resize(JOINTS);
            traj.points[0].velocities={0,0,0,0,0,0};
            traj.points[0].accelerations.resize(JOINTS);
            traj.points[0].accelerations={0,0,0,0,0,0};
            traj.points[0].effort.resize(JOINTS);
            traj.points[0].effort={0,0,0,0,0,0};
            traj.points[0].time_from_start = TFS[6];
            cout<<"Enter trajectory 5"<<endl;
            if(11<D.toSec())
                T=ros::Time::now()-ros::Duration(3.0);
        }

        Leg.publish(traj);
        Hand.publish(traj2);
        ros::spinOnce();

        //loop_rate.sleep();
    }

    return 0;
}
