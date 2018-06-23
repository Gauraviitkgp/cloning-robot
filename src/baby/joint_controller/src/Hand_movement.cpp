#include <ros/ros.h>
#include <trajectory_msgs/JointTrajectory.h>
#include "ros/time.h"
#include <iostream>
#define JOINTS 12
#define PI  3.1415926535897931
using namespace std;

ros::Publisher Right_hand;

int setValeurPoint(trajectory_msgs::JointTrajectory* trajectoire,int id,int pos_tab, int val);

int main(int argc, char** argv) 
{
    ros::init(argc, argv, "Hand_publisher");
    ros::NodeHandle n;

    Right_hand = n.advertise<trajectory_msgs::JointTrajectory>("/baby/Hand_controller/command",1);
    
    ros::Rate loop_rate(50);

    trajectory_msgs::JointTrajectory traj;
    trajectory_msgs::JointTrajectoryPoint points_n;

    
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
    cout<<"T: "<<T<<endl;
    ros::Duration D;
    ros::Duration TFS[2];

    TFS[0]=ros::Duration(3.0);//Secs for first program
    TFS[1]=ros::Duration(4.0);

    while(ros::ok()) 
    {
        traj.header.stamp = ros::Time::now();
        D=ros::Time::now()-T;
        
        if(1)
        {
            traj.points[0].positions.resize(JOINTS);
            traj.points[0].positions={0,PI,PI,PI/2,0,0,0,PI,3*PI/2,PI/2,0,0};
            traj.points[0].velocities.resize(JOINTS);
            traj.points[0].velocities={0,0,0,0,0,0,0,0,0,0,0,0};
            traj.points[0].accelerations.resize(JOINTS);
            traj.points[0].accelerations={0,0,0,0,0,0,0,0,0,0,0,0};
            traj.points[0].effort.resize(JOINTS);
            traj.points[0].effort={0,0,0,0,0,0,0,0,0,0,0,0};
            traj.points[0].time_from_start = TFS[0];
        }
        // if(D.toSec()>TFS[0].toSec())
        // {
        //     traj.points[0].positions.resize(2);
        //     traj.points[0].positions={0,0};
        //     traj.points[0].velocities.resize(2);
        //     traj.points[0].velocities={0,0};
        //     traj.points[0].accelerations.resize(2);
        //     traj.points[0].accelerations={0,0}; 
        //     traj.points[0].effort.resize(2);
        //     traj.points[0].effort={0,0};
        //     traj.points[0].time_from_start = TFS[1];
        // }
        Right_hand.publish(traj);
        ros::spinOnce();

        //loop_rate.sleep();
    }

    return 0;
}

// #include <ros/ros.h>
// #include <pr2_controllers_msgs/JointTrajectoryAction.h>
// #include <actionlib/client/simple_action_client.h>

// typedef actionlib::SimpleActionClient< pr2_controllers_msgs::JointTrajectoryAction > TrajClient;

// class RobotArm
// {
// private:
//   // Action client for the joint trajectory action 
//   // used to trigger the arm movement action
//   TrajClient* traj_client_;

// public:
//   //! Initialize the action client and wait for action server to come up
//   RobotArm() 
//   {
//     // tell the action client that we want to spin a thread by default
//     traj_client_ = new TrajClient("/baby/Right_hand_controller/joint_trajectory_action", true);

//     // wait for action server to come up
//     while(!traj_client_->waitForServer(ros::Duration(5.0))){
//       ROS_INFO("Waiting for the joint_trajectory_action server");
//     }
//   }

//   //! Clean up the action client
//   ~RobotArm()
//   {
//     delete traj_client_;
//   }

//   //! Sends the command to start a given trajectory
//   void startTrajectory(pr2_controllers_msgs::JointTrajectoryGoal goal)
//   {
//     // When to start the trajectory: 1s from now
//     goal.trajectory.header.stamp = ros::Time::now() + ros::Duration(1.0);
//     traj_client_->sendGoal(goal);
//   }

//   //! Generates a simple trajectory with two waypoints, used as an example
//   /*! Note that this trajectory contains two waypoints, joined together
//       as a single trajectory. Alternatively, each of these waypoints could
//       be in its own trajectory - a trajectory can have one or more waypoints
//       depending on the desired application.
//   */
//   pr2_controllers_msgs::JointTrajectoryGoal armExtensionTrajectory()
//   {
//     //our goal variable
//     pr2_controllers_msgs::JointTrajectoryGoal goal;

//     // First, the joint names, which apply to all waypoints
//     goal.trajectory.joint_names.push_back("Right_hand_y");
//     goal.trajectory.joint_names.push_back("Left_hand_y");

//     // We will have two waypoints in this goal trajectory

//     // First trajectory point
//     // Positions
//     int ind = 0;
//     goal.trajectory.points[ind].positions.resize(2);
//     goal.trajectory.points[ind].positions[0] = 1.57;
//     goal.trajectory.points[ind].positions[1] = 3.14+1.57;
//     // Velocities
//     goal.trajectory.points[ind].velocities.resize(7);
//     for (size_t j = 0; j < 2; ++j)
//     {
//       goal.trajectory.points[ind].velocities[j] = 0.0;
//     }
//     // To be reached 1 second after starting along the trajectory
//     goal.trajectory.points[ind].time_from_start = ros::Duration(1.0);

//     // Second trajectory point
//     // Positions
//     ind += 1;
//     goal.trajectory.points[ind].positions.resize(2);
//     goal.trajectory.points[ind].positions[0] = 0.0;
//     goal.trajectory.points[ind].positions[1] = 0.0;
//     // Velocities
//     goal.trajectory.points[ind].velocities.resize(2);
//     for (size_t j = 0; j < 2; ++j)
//     {
//       goal.trajectory.points[ind].velocities[j] = 0.0;
//     }
//     // To be reached 2 seconds after starting along the trajectory
//     goal.trajectory.points[ind].time_from_start = ros::Duration(2.0);

//     //we are done; return the goal
//     return goal;
//   }

//   //! Returns the current state of the action
//   actionlib::SimpleClientGoalState getState()
//   {
//     return traj_client_->getState();
//   }
 
// };

// int main(int argc, char** argv)
// {
//   // Init the ROS node
//   ros::init(argc, argv, "robot_driver");

//   RobotArm arm;
//   // Start the trajectory
//   arm.startTrajectory(arm.armExtensionTrajectory());
//   // Wait for trajectory completion
//   while(!arm.getState().isDone() && ros::ok())
//   {
//     usleep(50000);
//   }
//   return 0;
// }