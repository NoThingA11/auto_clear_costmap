#include <ros/ros.h>
#include <std_srvs/Empty.h>

int main(int argc, char **argv){
	ROS_INFO("Test Clear Costmap");
	ros::init(argc, argv, "clear_costmap_service");
	ros::NodeHandle nh;
	ros::service::waitForService("/move_base/clear_costmaps");
	ros::ServiceClient clearClient = nh.serviceClient<std_srvs::Empty>("/move_base/clear_costmaps");
        std_srvs::Empty srv;

	while(ros::ok()){
		clearClient.call(srv);
		ROS_INFO("Clear Costmap");
		ros::Duration(3).sleep();
	}
	
}
