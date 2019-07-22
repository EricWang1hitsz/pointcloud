#include <ros/ros.h>
#include <pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "pointcloud");
    ROS_INFO("Start PCL Reading Node...");

    ros::NodeHandle n;
    ros::Publisher pcl_pub = n.advertise<sensor_msgs::PointCloud2> ("pcl_output",1);

    sensor_msgs::PointCloud2 output;
    pcl::PointCloud<pcl::PointXYZ> cloud;


    pcl::io::loadPCDFile("/home/hit/catkin_ws_eric/src/pointcloud/src/blade.pcd",cloud);

    pcl::toROSMsg(cloud,output);
    output.header.frame_id = "point_cloud";

    ros::Rate loop_rate(1);
    while(ros::ok())
    {
        ROS_INFO("ROS is working...");
        pcl_pub.publish(output);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;

}
